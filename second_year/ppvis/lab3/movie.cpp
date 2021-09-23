#include "movie.h"

Movie::Movie() : name("unknown"), producer("unknown"), minutes(0) {}

Movie::Movie(const std::string &name_input, const std::string &producer_input,
             int p)
    : name(name_input), producer(producer_input), minutes(p) {}

void Movie::set(const std::string &name_input, const std::string producer_input,
                int p) {
  name = name_input;
  producer = producer_input;
  minutes = p;
};

std::string &Movie::get_name() { return name; }

std::string &Movie::get_producer() { return producer; }

int Movie::get_minutes() { return minutes; }

void Movie::display() {
  std::cout << std::left << std::setw(30) << name << std::setw(30) << producer
            << std::setw(15) << minutes << "\n";
}

void Movie::operator=(const Movie &movie) {
  name = movie.name;
  producer = movie.producer;
  minutes = movie.minutes;
}