import {Component, OnInit} from "@angular/core";
import {PostService} from "../post.service";
import {Router} from "@angular/router";
import {BlogPost} from "../BlogPost";

@Component({
  selector: "app-posts-table-component",
  templateUrl: "./posts-table-component.component.html",
  styleUrls: ["./posts-table-component.component.css"],
})
export class PostsTableComponentComponent implements OnInit {
  blogPosts: Array<BlogPost>;

  constructor(private data: PostService, private router: Router) {}

  rowClicked(e, id) {
    this.router.navigate(["/admin/post", id]);
  }

  ngOnInit(): void {
    this.data.getAllPosts().subscribe(data => (this.blogPosts = data));
  }
}
