import {Component, Input, OnInit} from "@angular/core";
import {BlogPost} from "../BlogPost";
import {Comment} from "../Comment";
import {PostService} from "../post.service";
import {ActivatedRoute} from "@angular/router";
@Component({
  selector: "app-post-data-component",
  templateUrl: "./post-data-component.component.html",
  styleUrls: ["./post-data-component.component.css"],
})
export class PostDataComponentComponent implements OnInit {
  querySub: any;
  post: BlogPost;
  comment: Comment;
  commentName: string;
  commentText: string;
  constructor(private data: PostService, private router: ActivatedRoute) {}

  ngOnInit(): void {
    this.router.params.subscribe(params => {
      this.data.getPostbyId(params["id"]).subscribe(data => {
        this.post = data;
        this.post.views++;
        this.data.updatePostById(this.post._id, this.post).subscribe();
      });
    });
  }
  submitComment() {
    this.comment = new Comment();
    this.comment.author = this.commentName;
    this.comment.comment = this.commentText;
    this.comment.date = new Date().toLocaleDateString();
    this.post.comments.push(this.comment);
    this.data.updatePostById(this.post._id, this.post).subscribe(data => {
      this.commentName = data.commentName;
      this.commentText = data.commentText;
    });
  }
  ngOnDestroy() {
    if (this.querySub) this.querySub.unsubscribe();
  }
}
