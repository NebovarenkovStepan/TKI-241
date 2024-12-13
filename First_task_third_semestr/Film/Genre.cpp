#include "Genre.h"
#include "Movie.h"

#include <sstream>


namespace Movie
{
    void Genre::add_movie(std::shared_ptr<Movie>& movie)
    {
        this->movies.push_back(movie.get());
        movie->get_genres().push_back(shared_from_this());
    }

    Genre::Genre(const std::string& genre) : genre(genre){}

    std::shared_ptr<Genre> Genre::create_genre(std::string genre)
    {
        return make_shared<Genre>(Genre{ genre });
    }

    Genre::Genre(const std::string& geners, std::shared_ptr<Movie> movie) : genre(genre), movie(movie)
    {
    }

    std::string Genre::to_string() const
    {
        std::stringstream buffer;
        buffer << "Genre: \n";
        buffer << genre;
        buffer << ".\n";
        return buffer.str();
    }

    bool operator==(const Genre& lha, const Genre& rha)
    {
        return lha.to_string() == rha.to_string();
    }

    bool operator==(const std::shared_ptr<Genre>& lha, const std::shared_ptr<Genre>& rha)
    {
        return lha.get()->to_string() == rha.get()->to_string();
    }
}