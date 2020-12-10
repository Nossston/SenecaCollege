import {Component, OnInit} from "@angular/core";
import {PostService} from "../post.service";
import {Router} from "@angular/router";
import {BlogPost} from "../BlogPost";
import {ActivatedRoute} from "@angular/router";

@Component({
  selector: "app-new-post-component",
  templateUrl: "./new-post-component.component.html",
  styleUrls: ["./new-post-component.component.css"],
})
export class NewPostComponentComponent implements OnInit {
  blogPost = new BlogPost();
  tags: Array<string>;
  constructor(private data: PostService, private router: Router) {}

  formSubmit() {
    // this.blogPost.tags = this.tags.split(",").map(tag => tag.trim());
    this.tags.forEach(e => {
      this.blogPost.tags.push(e);
    });
    // this.blogPost.tags = this.blogPost.tags.split(",").map(tag => tag.trim());
    this.blogPost.isPrivate = false;
    this.blogPost.postDate = new Date().toLocaleDateString();
    this.blogPost.postedBy = "WEB422 Student";
    this.blogPost.views = 0;
    console.log(this.blogPost);

    this.data.newPost(this.blogPost).subscribe();
    alert("New Post");
    this.router.navigate(["/admin"]);
  }

  ngOnInit(): void {}
}
