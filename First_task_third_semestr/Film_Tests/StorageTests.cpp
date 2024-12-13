#include "pch.h"
#include "CppUnitTest.h"
#include "../Film/Storage.h"
#include "../Film/Movie.h"

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
            auto movie = std::make_shared<Movie::Movie>("Inception", "Sci-Fi", "Christopher Nolan");

            // Act
            storage->add_movie(movie);

            // Assert
            Assert::AreEqual("Inception", storage->search_by_title("Inception").c_str());
        }

        TEST_METHOD(RemoveMovie_Success)
        {
            // Arrange
            auto storage = Movie::Storage::create_storage("My Movie Storage");
            auto movie = std::make_shared<Movie::Movie>("Inception", "Sci-Fi", "Christopher Nolan");
            storage->add_movie(movie);

            // Act
            storage->remove_movie(movie);

            // Assert
            Assert::AreEqual("There are no movies with this title.", storage->search_by_title("Inception").c_str());
        }

        TEST_METHOD(SearchByTitle_Found)
        {
            // Arrange
            auto storage = Movie::Storage::create_storage("My Movie Storage");
            auto movie = std::make_shared<Movie::Movie>("Inception", "Sci-Fi", "Christopher Nolan");
            storage->add_movie(movie);

            // Act
            std::string result = storage->search_by_title("Inception");

            // Assert
            Assert::AreEqual("Inception", result.c_str());
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
            auto movie = std::make_shared<Movie::Movie>("Inception", "Sci-Fi", "Christopher Nolan");
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
            auto movie = std::make_shared<Movie::Movie>("Inception", "Sci-Fi", "Christopher Nolan");
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
            auto movie = std::make_shared<Movie::Movie>("Inception", "Sci-Fi", "Leonardo DiCaprio");
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
                storage->get_top_sale_movie({});
                });
        }

        TEST_METHOD(GetTopSaleMovie_Success)
        {
            // Arrange
            auto storage = Movie::Storage::create_storage("My Movie Storage");
            auto movie1 = std::make_shared<Movie::Movie>("Inception", "Sci-Fi", "Christopher Nolan");
            auto movie2 = std::make_shared<Movie::Movie>("The Dark Knight", "Action", "Christopher Nolan");
            std::vector<std::pair<std::shared_ptr<Movie::Movie>, int>> sales = {
                {movie1, 100},
                {movie2, 200}
            };

            // Act
            auto top_movie = storage->get_top_sale_movie(sales);

            // Assert
            Assert::AreEqual("The Dark Knight", top_movie.get_title().c_str());
        }
    };
}