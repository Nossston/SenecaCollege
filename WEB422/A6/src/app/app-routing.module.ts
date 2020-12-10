import {NgModule} from "@angular/core";
import {Routes, RouterModule} from "@angular/router";
import {HomeComponentComponent} from "./home-component/home-component.component";
import {BlogComponentComponent} from "./blog-component/blog-component.component";
import {PostComponentComponent} from "./post-component/post-component.component";
import {PageNotFoundComponentComponent} from "./page-not-found-component/page-not-found-component.component";
import {PostsTableComponentComponent} from "./posts-table-component/posts-table-component.component";
import {EditPostComponentComponent} from "./edit-post-component/edit-post-component.component";
import {NewPostComponentComponent} from "./new-post-component/new-post-component.component";
const routes: Routes = [];

@NgModule({
  imports: [
    RouterModule.forRoot(
      [
        {path: "", component: HomeComponentComponent},
        {path: "home", component: HomeComponentComponent},
        {path: "blog", component: BlogComponentComponent},
        {path: "admin", component: PostsTableComponentComponent},
        {path: "admin/post/:id", component: EditPostComponentComponent},
        {path: "admin/newPost", component: NewPostComponentComponent},
        {path: "post/:id", component: PostComponentComponent},
        {path: "**", component: PageNotFoundComponentComponent},
      ],
      {scrollPositionRestoration: "enabled"}
    ),
  ],
  exports: [RouterModule],
})
export class AppRoutingModule {}
