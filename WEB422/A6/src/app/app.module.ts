import {BrowserModule} from "@angular/platform-browser";
import {NgModule} from "@angular/core";

import {AppRoutingModule} from "./app-routing.module";
import {AppComponent} from "./app.component";
import {HeaderComponentComponent} from "./header-component/header-component.component";
import {FooterComponentComponent} from "./footer-component/footer-component.component";
import {HomeComponentComponent} from "./home-component/home-component.component";
import {BlogComponentComponent} from "./blog-component/blog-component.component";
import {PostComponentComponent} from "./post-component/post-component.component";
import {PageNotFoundComponentComponent} from "./page-not-found-component/page-not-found-component.component";
import {PostCardComponentComponent} from "./post-card-component/post-card-component.component";
import {SearchWidgetComponentComponent} from "./search-widget-component/search-widget-component.component";
import {LatestPostsComponentComponent} from "./latest-posts-component/latest-posts-component.component";
import {CategoriesComponentComponent} from "./categories-component/categories-component.component";
import {TagsComponentComponent} from "./tags-component/tags-component.component";
import {PostDataComponentComponent} from "./post-data-component/post-data-component.component";
import {HttpClientModule} from "@angular/common/http";
import {PagingComponentComponent} from "./paging-component/paging-component.component";
import {FooterPostsComponentComponent} from "./footer-posts-component/footer-posts-component.component";
import {AdminComponent} from "./admin/admin.component";
import {FormsModule} from "@angular/forms";
import { PostsTableComponentComponent } from './posts-table-component/posts-table-component.component';
import { EditPostComponentComponent } from './edit-post-component/edit-post-component.component';
import { NewPostComponentComponent } from './new-post-component/new-post-component.component';

@NgModule({
  declarations: [
    AppComponent,
    HeaderComponentComponent,
    FooterComponentComponent,
    HomeComponentComponent,
    BlogComponentComponent,
    PostComponentComponent,
    PageNotFoundComponentComponent,
    PostCardComponentComponent,
    SearchWidgetComponentComponent,
    LatestPostsComponentComponent,
    CategoriesComponentComponent,
    TagsComponentComponent,
    PostDataComponentComponent,
    PagingComponentComponent,
    FooterPostsComponentComponent,
    AdminComponent,
    PostsTableComponentComponent,
    EditPostComponentComponent,
    NewPostComponentComponent,
  ],
  imports: [BrowserModule, AppRoutingModule, HttpClientModule, FormsModule],
  providers: [],
  bootstrap: [AppComponent],
})
export class AppModule {}
