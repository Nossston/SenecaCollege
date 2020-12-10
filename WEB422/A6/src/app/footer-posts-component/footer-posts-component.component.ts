import { Component, Input, OnInit } from '@angular/core';
import { BlogPost } from '../BlogPost';
import { PostService } from '../post.service';
@Component({
  selector: 'app-footer-posts-component',
  templateUrl: './footer-posts-component.component.html',
  styleUrls: ['./footer-posts-component.component.css'],
})
export class FooterPostsComponentComponent implements OnInit {
  constructor(private data: PostService) {}

  posts: Array<BlogPost>;
  ngOnInit(): void {
    this.data.getPosts(1, null, null).subscribe((data) => {
      this.posts = data.slice(0, 3);
    });
  }
}
