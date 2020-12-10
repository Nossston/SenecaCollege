import {Component, Input, OnInit} from "@angular/core";
import {BlogPost} from "../BlogPost";
import {PostService} from "../post.service";

@Component({
  selector: "app-latest-posts-component",
  templateUrl: "./latest-posts-component.component.html",
  styleUrls: ["./latest-posts-component.component.css"],
})
export class LatestPostsComponentComponent implements OnInit {
  constructor(private data: PostService) {}

  posts: Array<BlogPost>;
  ngOnInit(): void {
    this.data.getPosts(1, null, null).subscribe(data => {
      this.posts = data.slice(0, 3);
    });
  }
}
