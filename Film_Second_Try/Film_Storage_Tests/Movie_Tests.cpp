
#include "pch.h"
#include "CppUnitTest.h"
#include "../Film_Storage/Movie.h"
#include "../Film_Storage/Genre.h"
#include "../Film_Storage/Person.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    TEST_CLASS(MovieTest)
    {
    public:

        TEST_METHOD(CreateMovie_Success)
        {
            // arrange
            std::string title = "Inception";
            double price = 9.99;
            std::vector<std::shared_ptr<Movie::Genre>> genres;
            std::vector<std::shared_ptr<Movie::Director>> directors;
            std::vector<std::shared_ptr<Movie::Actor>> actors;

            // act
            auto movie = Movie::Movie::create_movie(title, price, genres, directors, actors);

            // assert
            Assert::AreEqual(title, movie->get_title());
            Assert::AreEqual(price, movie->get_price());
        }

        TEST_METHOD(ToString_ReturnsCorrectFormat)
        {
            // arrange
            std::string title = "Inception";
            double price = 9.99;
            std::vector<std::shared_ptr<Movie::Genre>> genres;
            std::vector<std::shared_ptr<Movie::Director>> directors;
            std::vector<std::shared_ptr<Movie::Actor>> actors;

            auto movie = Movie::Movie::create_movie(title, price, genres, directors, actors);

            // act
            std::string result = movie->to_string();

            // assert
            std::string expected = "Title: Inception\nDirectors: .\nGenres: .\nActors: .\n";
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(IncreaseSales_Success)
        {
            // arrange
            std::string title = "Inception";
            double price = 9.99;
            std::vector<std::shared_ptr<Movie::Genre>> genres;
            std::vector<std::shared_ptr<Movie::Director>> directors;
            std::vector<std::shared_ptr<Movie::Actor>> actors;

            auto movie = Movie::Movie::create_movie(title, price, genres, directors, actors);

            // act
            movie->increase_sales(5);
            int sales = movie->get_sales();

            // assert
            Assert::AreEqual(5, sales);
        }

        TEST_METHOD(EqualityOperator_Success)
        {
            // arrange
            std::string title = "Inception";
            double price = 9.99;
            std::vector<std::shared_ptr<Movie::Genre>> genres;
            std::vector<std::shared_ptr<Movie::Director>> directors;
            std::vector<std::shared_ptr<Movie::Actor>> actors;

            auto movie_1 = Movie::Movie::create_movie(title, price, genres, directors, actors);
            auto movie_2 = Movie::Movie::create_movie(title, price, genres, directors, actors);
            Assert::IsTrue(*movie_1 == *movie_2);
        }
    };
}

