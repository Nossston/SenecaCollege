import { Component, Input, OnInit } from '@angular/core';
import { BlogPost } from '../BlogPost';

@Component({
  selector: 'app-post-card-component',
  templateUrl: './post-card-component.component.html',
  styleUrls: ['./post-card-component.component.css'],
})
export class PostCardComponentComponent implements OnInit {
  constructor() {}

  @Input() post: BlogPost;
  ngOnInit(): void {}
}
