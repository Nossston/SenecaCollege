import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { PostService } from '../post.service';
import { BlogPost } from '../BlogPost';

@Component({
  selector: 'app-blog-component',
  templateUrl: './blog-component.component.html',
  styleUrls: ['./blog-component.component.css'],
})
export class BlogComponentComponent implements OnInit {
  page: number = 1;
  tag: string = null;
  category: string = null;
  querySub: any;
  blogPosts: Array<BlogPost>;

  constructor(private data: PostService, private route: ActivatedRoute) {}

  getPage(num) {
    // console.log(this.category);
    this.querySub = this.data
      .getPosts(num, this.tag, this.category)
      // .sort(a, (b) => {getPost(num, this.tag, this.category);})
      .subscribe((data) => {
        // console.log("The first data's category " + data[0].category);
        if (data.length > 0) {
          this.blogPosts = data;
          this.page = num;
        }
      });
  }

  ngOnInit(): void {
    this.querySub = this.route.queryParams.subscribe((params) => {
      // from prof
      if (params['tag']) {
        this.tag = params['tag'];
        this.category = null;
      } else {
        this.tag = null;
      }
      if (params['category']) {
        this.category = params['category'];
        this.tag = null;
      } else {
        this.category = null;
      }
      this.getPage(+params['page'] || 1);
    });
  }
  ngOnDestroy(): void {
    if (this.querySub) this.querySub.unsubscribe();
  }
}
