#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Director.h"
#include "Actor.h"
#include "Genre.h"
#include "Storage.h"
#include "Order.h"

namespace Movie
{
    class Movie;

    std::wstring ToString(const Movie& movie);
    bool operator==(const Movie& lha, const Movie& rha);

    class Genre;
    class Person;
    class Storage;
    class Order;

    class Movie final : public std::enable_shared_from_this<Movie>
    {
    private:
        std::string title;
        double price;
        int sales;
        std::vector<std::shared_ptr<Genre>> genres{};
        std::vector<std::shared_ptr<Director>> directors{};
        std::vector<std::shared_ptr<Actor>> actors{};
        Movie(const std::string title, const double price, std::vector<std::shared_ptr<Genre>> genres, std::vector<std::shared_ptr<Director>> directors, std::vector<std::shared_ptr<Actor>> actors);

    public:

        static std::shared_ptr<Movie>create_movie(const std::string& title, const double price, std::vector<std::shared_ptr<Genre>> genres, std::vector<std::shared_ptr<Director>> directors, std::vector<std::shared_ptr<Actor>> actors);
        std::string get_title() const;
        std::string to_string() const;
        std::shared_ptr<Storage> storage;
        Movie();
        std::vector<std::shared_ptr<Genre>> get_genres() const;
        std::vector<std::shared_ptr<Director>> get_directors() const;
        std::vector<std::shared_ptr<Actor>> get_actors() const;
        double get_price() const;
        void increase_sales(int amount);
        int get_sales() const;
    };

}