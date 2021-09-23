#include <cstring>
#include <iostream>

class Movie {
public:
  char title[64];
  char genre[64];
  int duration;

public:
  Movie() : title("unknown"), genre("unknown"), duration(0) {}

  Movie(const char title_input[], const char genre_input[]) {
    strcpy(title, title_input);
    strcpy(genre, genre_input);
  }

  Movie(int min) : duration(min) {}

  void set_movie_features() {
    std::cout << "\nEnter movie title: ";
    std::cin.getline(title, 64);
    std::cout << "Enter movie genre: ";
    std::cin.getline(genre, 64);
    std::cout << "Enter duration in min: ";
    std::cin >> duration;
    std::cin.get();
  }

  void show_movie_features() {
    std::cout << "Movie title: " << title << "\n";
    std::cout << "Movie genre: " << genre << "\n";
    std::cout << "Movie duration: " << duration << "\n";
  }

  bool operator==(Movie movie2) {
    bool result = false;

    if (strcmp(title, movie2.title) == 0) {
      result = true;
    }

    return result;
  }

  int operator+(Movie movie2) {
    int common_duration = duration + movie2.duration;

    return common_duration;
  }

  Movie operator++(int) { return Movie(duration++); }
};

class Route {
private:
  int kilometers;
  float meters;
  int minutes;

public:
  Route() : kilometers(0), meters(0.0), minutes(0) {}

  Route(int km, float m, int min) : kilometers(km), meters(m), minutes(min) {}

  Route(int min) : minutes(min) {}

  void set_route_parameters() {
    std ::cout << "\nEnter kilometers: ";
    std::cin >> kilometers;
    std::cout << "Enter meters: ";
    std::cin >> meters;
    std::cout << "Enter minutes: ";
    std::cin >> minutes;
  }

  void show_route_parameters() {
    std::cout << "Kilometers " << kilometers << "\n";
    std::cout << "Meters: " << meters << "\n";
    std::cout << "Minutes: " << minutes << "\n";
  }

  void operator=(Route route2) {
    kilometers = route2.kilometers;
    meters = route2.meters;
    minutes = route2.meters;
  }

  Route operator+(Route route2) {
    int km = kilometers + route2.kilometers;
    float m = meters + route2.meters;
    int min = minutes + route2.minutes;

    return Route(km, m, min);
  }

  Route operator++(int) { return Route(minutes++); }
};

int main() {
  // Task1
  Movie movie;
  std::cout << "Task 1\n";
  std::cout << "constructor without parameters:\n";
  movie.show_movie_features();

  Movie movie1("The Hobbit", "fantasy");
  std::cout << "\nconstructor with title and genre parameters:\n";
  movie1.show_movie_features();

  Movie movie2(345);
  std::cout << "\nconstructor with duration parameter:\n";
  movie2.show_movie_features();

  std::cout << "\nset & show methods:\n";
  movie1.set_movie_features();
  std::cout << "\n";
  movie1.show_movie_features();
  std::cout << "\n";
  movie2.set_movie_features();
  std::cout << "\n";
  movie2.show_movie_features();

  std::cout << "\noverloaded operator ==, compares titles:\n";
  bool comparison = movie1 == movie2;
  std::cout << comparison;

  std::cout << "\noverloaded operator +, returns common duration of movies:\n";
  std::cout << movie1 + movie2;

  std::cout << "\noverloaded operator ++, increments movie1 duration:\n";
  movie1++;
  std::cout << movie1.duration << "\n";

  // Task2
  Route route;
  std::cout << "\nTask 2\n";
  std::cout << "constructor without parameters:\n";
  route.show_route_parameters();

  Route route1(15, 68.45, 20);
  std::cout << "\nconstructor with 3 parameters(km, m, min):\n";
  route1.show_route_parameters();

  Route route2(15);
  std::cout << "\nconstructor with time parameter:\n";
  route2.show_route_parameters();

  std::cout << "set & show methods:\n";
  route2.set_route_parameters();
  route2.show_route_parameters();

  std::cout
      << "\noverloaded operator =, assigns values of one route to another:\n";
  route1 = route2;
  std::cout << "route1:\n";
  route1.show_route_parameters();
  std::cout << "\nroute2:\n";
  route2.show_route_parameters();

  std::cout << "\noverloaded operator +, sums values and returns a new temp "
               "object of the class with the result values\n";
  route = route1 + route2;
  route.show_route_parameters();

  std::cout << "overloaded operator ++, increments route time\n";
  route++;
  route.show_route_parameters();

  return 0;
}
