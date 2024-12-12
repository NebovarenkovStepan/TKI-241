#include "pch.h"
#include "CppUnitTest.h"
#include "../Film/Gener.h"
#include "../Film/Film.h"
#include "../Film/people.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FilmTests
{
    TEST_CLASS(GenreTests)
    {
    public:

        TEST_METHOD(AddMovie_Success)
        {
            // Arrange
            auto genre = film::Genre::create_genre("Sci-Fi");
            std::vector<std::shared_ptr<film::Genre>> genres = { genre };
            std::vector<std::shared_ptr<film::Person>> directors = { std::make_shared<film::Person>("Christopher Nolan") };
            auto movie = film::Movie::create_movie("Inception", 14.99, genres, directors, {});

            // Act
            genre->add_movie(movie);

            // Assert
            Assert::AreEqual("Inception", genre->to_string().find("Inception") != std::string::npos ? "Inception" : "Not Found");
        }

        TEST_METHOD(ToString_Success)
        {
            // Arrange
            auto genre = film::Genre::create_genre("Sci-Fi");

            // Act
            std::string result = genre->to_string();

            // Assert
            Assert::IsTrue(result.find("Genre:") != std::string::npos);
            Assert::IsTrue(result.find("Sci-Fi") != std::string::npos);
        }

        TEST_METHOD(EqualityOperator_Success)
        {
            // Arrange
            auto genre1 = film::Genre::create_genre("Sci-Fi");
            auto genre2 = film::Genre::create_genre("Sci-Fi");

            // Act & Assert
            Assert::IsTrue(*genre1 == *genre2); // Check if two genres with the same name are considered equal
        }

        TEST_METHOD(EqualityOperator_Failure)
        {
            // Arrange
            auto genre1 = film::Genre::create_genre("Sci-Fi");
            auto genre2 = film::Genre::create_genre("Action");

            // Act & Assert
            Assert::IsFalse(*genre1 == *genre2); // Check if two genres with different names are not considered equal
        }
    };
}