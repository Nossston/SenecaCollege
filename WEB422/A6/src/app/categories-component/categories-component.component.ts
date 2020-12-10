import { Component, OnInit } from '@angular/core';
import { PostService } from '../post.service';

@Component({
  selector: 'app-categories-component',
  templateUrl: './categories-component.component.html',
  styleUrls: ['./categories-component.component.css'],
})
export class CategoriesComponentComponent implements OnInit {
  constructor(private data: PostService) {}
  categories: Array<any>;
  ngOnInit(): void {
    this.data.getCategories().subscribe((data) => {
      this.categories = data;
    });
  }
}
