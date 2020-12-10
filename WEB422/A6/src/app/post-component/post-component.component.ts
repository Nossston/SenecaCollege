import {Component, OnInit} from "@angular/core";
import blogData from "../blogData.json";
import {BlogPost} from "../BlogPost";
import {PostService} from "../post.service";
import {ActivatedRoute} from "@angular/router";

@Component({
  selector: "app-post-component",
  templateUrl: "./post-component.component.html",
  styleUrls: ["./post-component.component.css"],
})
export class PostComponentComponent implements OnInit {
  querySub: any;
  post: BlogPost;

  constructor(private data: PostService, private route: ActivatedRoute) {}

  ngOnInit(): void {
    this.querySub = this.route.params.subscribe(params => {
      //TODO: Get post by Id params['id'] and store the result in this.post
      this.data.getPostbyId(params["id"]).subscribe(data => (this.post = data));
    });
  }

  ngOnDestroy() {
    if (this.querySub) {
      this.querySub.unsubscribe();
    }
  }
}
