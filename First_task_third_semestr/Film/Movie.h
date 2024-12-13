#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Person.h"

using namespace std;

namespace Movie
{

    class Movie;

    std::wstring ToString(const Movie& movie);
    bool operator==(const Movie& lha, const Movie& rha);
    bool operator==(const std::shared_ptr<Movie>& lha, const std::shared_ptr<Movie>& rha);

    class Order;
    class Genre;
    class Person;
    class Storage;

    class Movie final : public std::enable_shared_from_this<Movie>
    {
    private:
        std::string title;
        double price;
        std::vector<std::shared_ptr<Genre>> genres{};
        std::vector<std::shared_ptr<Person>> directors{};
        std::vector<std::shared_ptr<Person>> actors{};

    public:
        Movie(const std::string& title, const double price, std::vector<std::shared_ptr<Genre>> genres, std::vector<std::shared_ptr<Person>> directors, std::vector<std::shared_ptr<Person>> actors);

        static std::shared_ptr<Movie>create_movie(const std::string& title, const double price, std::vector<std::shared_ptr<Genre>> genres, std::vector<std::shared_ptr<Person>> directors, std::vector<std::shared_ptr<Person>> actors);
        std::string get_title() const;
        std::shared_ptr<Storage> storage;
        std::shared_ptr<Order> order;
        std::string to_string() const;
        std::vector<std::shared_ptr<Genre>> get_genres() const;
        std::vector<std::shared_ptr<Person>> get_directors() const;
        std::vector<std::shared_ptr<Person>> get_actors() const;
        double get_price() const;
    };

}