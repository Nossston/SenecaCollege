import {Component, OnInit} from "@angular/core";
import {PostService} from "../post.service";
import {Router} from "@angular/router";
import {BlogPost} from "../BlogPost";
import {ActivatedRoute} from "@angular/router";

@Component({
  selector: "app-edit-post-component",
  templateUrl: "./edit-post-component.component.html",
  styleUrls: ["./edit-post-component.component.css"],
})
export class EditPostComponentComponent implements OnInit {
  blogPost: BlogPost;
  tags: string;

  constructor(
    private data: PostService,
    private route: ActivatedRoute,
    private router: Router
  ) {}

  ngOnInit(): void {
    this.route.params.subscribe(params => {
      this.data.getPostbyId(params["id"]).subscribe(data => {
        this.blogPost = data;
        this.tags = this.blogPost.tags.toString();
        // this.tags.forEach(e => {this.blogPost.tags.push(e);});
      });
    });
  }
  deleteClick() {
    this.data.deletePostById(this.blogPost._id).subscribe();
    alert("Deleted");
    this.router.navigate(["/admin"]);
  }
  formSubmit() {
    this.tags.split(",").map(tag => tag.trim());

    this.data
      .updatePostById(this.blogPost._id, this.blogPost)
      .subscribe(data => (this.blogPost = data));
    alert("Updated");
    this.router.navigate(["/admin"]);
  }
}
