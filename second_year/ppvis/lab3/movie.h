#ifndef _MOVIE_H
#define _MOVIE_H

#include <iomanip>
#include <iostream>
#include <string>

class Movie {
private:
  std::string name;
  std::string producer;
  int minutes;

public:
  Movie();

  Movie(const std::string &name_input, const std::string &producer_input,
        int min);

  void set(const std::string &name_input, const std::string producer_input,
           int p);

  std::string &get_name();

  std::string &get_producer();

  int get_minutes();

  void display();

  void operator=(const Movie &movie);
};

#endif