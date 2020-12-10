import {Injectable} from "@angular/core";
import {BlogPost} from "./BlogPost";
import {Observable} from "rxjs";
import {HttpClient, HttpParams} from "@angular/common/http";
const perPage = 6;
const PERPAGE = Number.MAX_SAFE_INTEGER;

@Injectable({
  providedIn: "root",
})
export class PostService {
  constructor(private http: HttpClient) {}

  getPosts(page, tag, category): Observable<BlogPost[]> {
    const url = `https://web422-noston-a5.herokuapp.com/api/posts`;
    let params = {
      page: page,
      perPage: perPage.toString(),
    };
    if (tag) {
      params["tag"] = tag;
    }
    if (category) {
      params["category"] = category;
    }

    return this.http.get<BlogPost[]>(url, {params});
  }

  getPostbyId(id): Observable<BlogPost> {
    return this.http.get<BlogPost>(
      `https://web422-noston-a5.herokuapp.com/api/posts/${id}`
    );
  }
  getCategories(): Observable<any> {
    return this.http.get<any>(
      `https://web422-noston-a5.herokuapp.com/api/categories`
    );
  }
  getTags(): Observable<string[]> {
    return this.http.get<string[]>(
      `https://web422-noston-a5.herokuapp.com/api/tags`
    );
  }

  // A6
  getAllPosts(): Observable<BlogPost[]> {
    return this.http.get<BlogPost[]>(
      `https://web422-noston-a5.herokuapp.com/api/posts?page=1&perPage=${PERPAGE}`
    );
  }
  newPost(data: BlogPost): Observable<any> {
    return this.http.post<any>(
      `https://web422-noston-a5.herokuapp.com/api/posts`,
      data
    );
  }
  updatePostById(id: string, data: BlogPost): Observable<any> {
    return this.http.put<any>(
      `https://web422-noston-a5.herokuapp.com/api/posts/${id}`,
      data
    );
  }
  deletePostById(id: string): Observable<any> {
    return this.http.delete<any>(
      `https://web422-noston-a5.herokuapp.com/api/posts/${id}`
    );
  }
}
