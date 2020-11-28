#include "book.h"
#include "collection.h"
#include "movie.h"

int main() {
  std::cout << "\nusing constructor with parameters\n\n";

  Book book1("book1", "author1", 234), book2("book2", "author2", 376),
      book3("book3", "author3", 345), book4("book4", "author4", 134),
      book5("book5", "author5", 353);

  std::initializer_list<Book> books_list = {book1, book2, book3, book4, book5};

  Collection<Book> book_collection("Books", books_list);

  book_collection.display();

  Movie movie1("movie1", "producer1", 156), movie2("movie2", "producer2", 124),
      movie3("movie3", "producer3", 65), movie4("movie4", "producer4", 87);

  std::initializer_list<Movie> movie_list = {movie1, movie2, movie3, movie4};

  Collection<Movie> movie_collection("Movies", movie_list);

  movie_collection.display();

  std::cout << "\n\nusing default constructor\n\n";
  Book default_book;
  Movie default_movie;
  Collection<Book> default_collection;

  default_book.display();
  default_movie.display();
  default_collection.display();

  std::cout << "\n\nusing copy constructor\n\n";
  Collection<Book> copy_collection(book_collection);

  copy_collection.display();

  return 0;
}