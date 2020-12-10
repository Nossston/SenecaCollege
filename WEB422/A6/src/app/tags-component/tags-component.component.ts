import { Component, OnInit } from '@angular/core';
import { PostService } from '../post.service';

@Component({
  selector: 'app-tags-component',
  templateUrl: './tags-component.component.html',
  styleUrls: ['./tags-component.component.css'],
})
export class TagsComponentComponent implements OnInit {
  constructor(private data: PostService) {}
  tags: Array<string>;
  ngOnInit(): void {
    this.data.getTags().subscribe((data) => {
      this.tags = data;
    });
  }
}
