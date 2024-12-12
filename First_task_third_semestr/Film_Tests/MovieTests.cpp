#include "pch.h"
#include "CppUnitTest.h"
#include "../Film/Film.h"
#include "../Film/Gener.h"
#include "../Film/people.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FilmTests
{
    TEST_CLASS(MovieTests)
    {
    public:
        TEST_METHOD(CreateMovie_Success)
        {
            // Arrange
            std::vector<std::shared_ptr<film::Genre>> genres = { std::make_shared<film::Genre>("Sci-Fi") };
            std::vector<std::shared_ptr<film::Person>> directors = { std::make_shared<film::Person>("Christopher Nolan") };
            std::vector<std::shared_ptr<film::Person>> actors = { std::make_shared<film::Person>("Leonardo DiCaprio") };

            // Act
            auto movie = film::Movie::create_movie("Inception", 14.99, genres, directors, actors);

            // Assert
            Assert::AreEqual("Inception", movie->get_title().c_str());
            Assert::AreEqual(14.99, movie->get_price());
        }

        TEST_METHOD(ToString_Success)
        {
            // Arrange
            std::vector<std::shared_ptr<film::Genre>> genres = { std::make_shared<film::Genre>("Sci-Fi") };
            std::vector<std::shared_ptr<film::Person>> directors = { std::make_shared<film::Person>("Christopher Nolan") };
            std::vector<std::shared_ptr<film::Person>> actors = { std::make_shared<film::Person>("Leonardo DiCaprio") };
            auto movie = film::Movie::create_movie("Inception", 14.99, genres, directors, actors);

            // Act
            std::string result = movie->to_string();

            // Assert
            Assert::IsTrue(result.find("Title: Inception") != std::string::npos);
            Assert::IsTrue(result.find("Directors: Christopher Nolan") != std::string::npos);
            Assert::IsTrue(result.find("Genres: Sci-Fi") != std::string::npos);
            Assert::IsTrue(result.find("Actors: Leonardo DiCaprio") != std::string::npos);
        }

        TEST_METHOD(GetGenres_Success)
        {
            // Arrange
            std::vector<std::shared_ptr<film::Genre>> genres = { std::make_shared<film::Genre>("Sci-Fi"), std::make_shared<film::Genre>("Action") };
            auto movie = film::Movie::create_movie("Inception", 14.99, genres, {}, {});

            // Act
            auto retrieved_genres = movie->get_genres();
            size_t expected_size = 2;

            // Assert
            Assert::AreEqual(expected_size, retrieved_genres.size());
            Assert::AreEqual("Sci-Fi", retrieved_genres[0]->to_string().c_str());
            Assert::AreEqual("Action", retrieved_genres[1]->to_string().c_str());
        }

        TEST_METHOD(GetDirectors_Success)
        {
            // Arrange
            std::vector<std::shared_ptr<film::Person>> directors = { std::make_shared<film::Person>("Christopher Nolan") };
            auto movie = film::Movie::create_movie("Inception", 14.99, {}, directors, {});

            // Act
            auto retrieved_directors = movie->get_directors();
            size_t expected_size = 1;
            // Assert
            Assert::AreEqual(expected_size, retrieved_directors.size());
            Assert::AreEqual("Christopher Nolan", retrieved_directors[0]->to_string().c_str());
        }

        TEST_METHOD(GetActors_Success)
        {
            // Arrange
            std::vector<std::shared_ptr<film::Person>> actors = { std::make_shared<film::Person>("Leonardo DiCaprio") };
            auto movie = film::Movie::create_movie("Inception", 14.99, {}, {}, actors);

            // Act
            auto retrieved_actors = movie->get_actors();
            size_t expected_size = 1;
            // Assert
            Assert::AreEqual(expected_size, retrieved_actors.size());
            Assert::AreEqual("Leonardo DiCaprio", retrieved_actors[0]->to_string().c_str());
        }

        TEST_METHOD(EqualityOperator_Success)
        {
            // Arrange
            std::vector<std::shared_ptr<film::Genre>> genres = { std::make_shared<film::Genre>("Sci-Fi") };
            std::vector<std::shared_ptr<film::Person>> directors = { std::make_shared<film::Person>("Christopher Nolan") };
            auto movie1 = film::Movie::create_movie("Inception", 14.99, genres, directors, {});
            auto movie2 = film::Movie::create_movie("Inception", 14.99, genres, directors, {});

            // Act & Assert
            Assert::IsTrue(*movie1 == *movie2);
        }
    };
}