#include <iostream>
#include "../Film/Genre.h"
#include "../Film/Person.h"
#include "../Film/Movie.h"

//using namespace Movie;

int main()
{
    auto genre = Movie::Genre::create_genre("Sci-Fi");
    std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
    Movie::Person person("B", "E", "N");
    std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(person) };
    auto movie = Movie::Movie::create_movie("Inception", 14.99, genres, directors, directors);

    genre->add_movie(movie);

    std::cout << movie.get()->to_string();

    auto storage = Movie::Storage::create_storage("My Movie Storage");

    // Act
    storage->add_movie(movie);

    std::cout << storage.get()->search_by_actor("B E N")[0].to_string();
}