#include "pch.h"
#include "CppUnitTest.h"
#include "../Film/Movie.h"
#include "../Film/Genre.h"
#include "../Film/Person.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FilmTests
{
    TEST_CLASS(MovieTests)
    {
    public:

        TEST_METHOD(CreateMovie_Success)
        {
            // Arrange
            auto genre = Movie::Genre::create_genre("Sci-Fi");
            Movie::Person director("Christopher", "Nolan");
            std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
            std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(director) };
            std::vector<std::shared_ptr<Movie::Person>> actors; 
            double price = 14.99;

            // Act
            auto movie = Movie::Movie::create_movie("Inception", price, genres, directors, actors);

            // Assert
            Assert::AreEqual("Inception", movie->get_title().c_str());
            Assert::AreEqual(price, movie->get_price());
        }

        TEST_METHOD(ToString_Success)
        {
            // Arrange
            auto genre = Movie::Genre::create_genre("Sci-Fi");
            Movie::Person director("Christopher", "Nolan");
            std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
            std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(director) };
            std::vector<std::shared_ptr<Movie::Person>> actors;
            auto movie = Movie::Movie::create_movie("Inception", 14.99, genres, directors, {});

            // Act
            std::string result = movie->to_string();

            // Assert
            Assert::IsTrue(result.find("Title: Inception") != std::string::npos);
            Assert::IsTrue(result.find("Directors: Christopher Nolan") != std::string::npos);
            Assert::IsTrue(result.find("Genres: Sci-Fi") != std::string::npos);
        }

        TEST_METHOD(IncreaseSales_Success)
        {
            // Arrange
            auto genre = Movie::Genre::create_genre("Sci-Fi");
            Movie::Person director("Christopher", "Nolan");
            std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
            std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(director) };
            auto movie = Movie::Movie::create_movie("Inception", 14.99, genres, directors, {});

            // Act
            movie->increase_sales();
            movie->increase_sales(); 

            // Assert
            Assert::AreEqual(2, movie->get_sales());
        }

        TEST_METHOD(EqualityOperator_Success)
        {
            // Arrange
            auto genre = Movie::Genre::create_genre("Sci-Fi");
            Movie::Person director("Christopher", "Nolan");
            std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
            std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(director) };
            auto movie1 = Movie::Movie::create_movie("Inception", 14.99, genres, directors, {});
            auto movie2 = Movie::Movie::create_movie("Inception", 14.99, genres, directors, {});

            // Act & Assert
            Assert::IsTrue(*movie1 == *movie2); 
        }

        TEST_METHOD(EqualityOperator_Failure)
        {
            // Arrange
            auto genre1 = Movie::Genre::create_genre("Sci-Fi");
            auto genre2 = Movie::Genre::create_genre("Action");
            Movie::Person director("Christopher", "Nolan");
            std::vector<std::shared_ptr<Movie::Genre>> genres1 = { genre1 };
            std::vector<std::shared_ptr<Movie::Genre>> genres2 = { genre2 };
            std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(director) };
            auto movie1 = Movie::Movie::create_movie("Inception", 14.99, genres1, directors, {});
            auto movie2 = Movie::Movie::create_movie("Inception", 14.99, genres2, directors, {});

            // Act & Assert
            Assert::IsFalse(*movie1 == *movie2);
        }
    };
}