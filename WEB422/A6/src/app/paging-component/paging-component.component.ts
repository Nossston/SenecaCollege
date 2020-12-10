import { Component, OnInit, Output, EventEmitter, Input } from '@angular/core';

@Component({
  selector: 'app-paging-component',
  templateUrl: './paging-component.component.html',
  styleUrls: ['./paging-component.component.css'],
})
export class PagingComponentComponent implements OnInit {
  @Input() page: number;
  @Output() newPage = new EventEmitter();
  constructor() {}

  btnLeft() {
    if (this.page > 1) {
      this.newPage.emit(this.page - 1);
    }
  }
  btnRight() {
    this.newPage.emit(this.page + 1);
  }

  ngOnInit(): void {}
}
