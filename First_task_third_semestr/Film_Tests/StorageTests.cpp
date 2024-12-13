#include "pch.h"
#include "CppUnitTest.h"
#include "../Film/Storage.h"
#include "../Film/Movie.h"
#include "../Film/Genre.h"
#include "../Film/Person.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StorageTests
{
    TEST_CLASS(StorageTests)
    {
    public:
        TEST_METHOD(AddMovie_Success)
        {
            // Arrange
            auto storage = Movie::Storage::create_storage("My Movie Storage");
            auto genre = Movie::Genre::create_genre("Sci-Fi");
            Movie::Person director("Christopher", "Nolan");
            std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
            std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(director) };
            auto movie = Movie::Movie::create_movie("Inception", 14.99, genres, directors, {});

            // Act
            storage->add_movie(movie);

            // Assert
            Assert::AreEqual("Inception", storage->search_by_title("Inception").find("Inception") != std::string::npos ? "Inception" : "Not Found");
        }

        TEST_METHOD(RemoveMovie_Success)
        {
            // Arrange
            auto storage = Movie::Storage::create_storage("My Movie Storage");
            auto genre = Movie::Genre::create_genre("Sci-Fi");
            Movie::Person director("Christopher", "Nolan");
            std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
            std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(director) };
            auto movie = Movie::Movie::create_movie("Inception", 14.99, genres, directors, {});
            storage->add_movie(movie);

            // Act
            storage->remove_movie(movie);

            std::string a = "There are no movies with this title.";
            // Assert
            Assert::AreEqual(a, storage->search_by_title("Inception"));
        }

        TEST_METHOD(SearchByTitle_Found)
        {
            // Arrange
            auto storage = Movie::Storage::create_storage("My Movie Storage");
            auto genre = Movie::Genre::create_genre("Sci-Fi");
            Movie::Person director("Christopher", "Nolan");
            std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
            std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(director) };
            auto movie = Movie::Movie::create_movie("Inception", 14.99, genres, directors, {});
            storage->add_movie(movie);

            // Act
            std::string result = storage->search_by_title("Inception");

            // Assert
            Assert::IsTrue(result.find("Inception") != std::string::npos);
        }

        TEST_METHOD(SearchByTitle_NotFound)
        {
            // Arrange
            auto storage = Movie::Storage::create_storage("My Movie Storage");

            // Act
            std::string result = storage->search_by_title("Nonexistent Movie");

            // Assert
            Assert::AreEqual("There are no movies with this title.", result.c_str());
        }

        TEST_METHOD(SearchByGenre_Found)
        {
            // Arrange
            auto storage = Movie::Storage::create_storage("My Movie Storage");
            auto genre = Movie::Genre::create_genre("Sci-Fi");
            Movie::Person director("Christopher", "Nolan");
            std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
            std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(director) };
            auto movie = Movie::Movie::create_movie("Inception", 14.99, genres, directors, {});
            storage->add_movie(movie);

            // Act
            auto results = storage->search_by_genre("Sci-Fi");

            // Assert
            Assert::IsTrue(results.size() > 0);
            Assert::AreEqual("Inception", results[0].get_title().c_str());
        }

        TEST_METHOD(SearchByDirector_Found)
        {
            // Arrange
            auto storage = Movie::Storage::create_storage("My Movie Storage");
            auto genre = Movie::Genre::create_genre("Sci-Fi");
            Movie::Person director("Christopher", "Nolan");
            std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
            std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(director) };
            auto movie = Movie::Movie::create_movie("Inception", 14.99, genres, directors, {});
            storage->add_movie(movie);

            // Act
            auto results = storage->search_by_director("Christopher Nolan");

            // Assert
            Assert::IsTrue(results.size() > 0);
            Assert::AreEqual("Inception", results[0].get_title().c_str());
        }

        TEST_METHOD(SearchByActor_Found)
        {
            // Arrange
            auto storage = Movie::Storage::create_storage("My Movie Storage");
            auto genre = Movie::Genre::create_genre("Sci-Fi");
            Movie::Person actor("Leonardo", "DiCaprio");
            Movie::Person director("Christopher", "Nolan");
            std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
            std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(director) };
            std::vector<std::shared_ptr<Movie::Person>> actors = { std::make_shared<Movie::Person>(actor) };
            auto movie = Movie::Movie::create_movie("Inception", 14.99, genres, directors, actors);
            storage->add_movie(movie);

            // Act
            auto results = storage->search_by_actor("Leonardo DiCaprio");

            // Assert
            Assert::IsTrue(results.size() > 0);
            Assert::AreEqual("Inception", results[0].get_title().c_str());
        }

        TEST_METHOD(GetTopSaleMovie_NoSales_ThrowsException)
        {
            // Arrange
            auto storage = Movie::Storage::create_storage("My Movie Storage");

            // Act & Assert
            Assert::ExpectException<std::out_of_range>([&]() {
                storage->get_top_sale_movie();
                });
        }

        TEST_METHOD(GetTopSaleMovie_Success)
        {
            // Arrange
            auto storage = Movie::Storage::create_storage("My Movie Storage");
            auto genre = Movie::Genre::create_genre("Sci-Fi");
            Movie::Person director("Christopher", "Nolan");
            std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
            std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(director) };
            auto movie1 = Movie::Movie::create_movie("Inception", 14.99, genres, directors, {});
            auto movie2 = Movie::Movie::create_movie("The Dark Knight", 19.99, genres, directors, {});
            storage->add_movie(movie1);
            storage->add_movie(movie2);
            movie1.get()->increase_sales();

            // Act
            std::string top_movie = storage->get_top_sale_movie().to_string();

            std::string a = "The Dark Knight";
            // Assert
            Assert::AreEqual(a, top_movie);
        }
    };
}