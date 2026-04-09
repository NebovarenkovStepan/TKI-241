#include "pch.h"
#include "CppUnitTest.h"
#include "../Film_Storage/Genre.h"
#include "../Film_Storage/Movie.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GenreTests
{
    TEST_CLASS(GenreTests)
    {
    public:
        TEST_METHOD(CreateGenre_ValidName_Success)
        {
            // Arrange
            std::string genreName = "Action";

            // Act
            auto genre = Movie::Genre::create_genre(genreName);

            // Assert
            Assert::AreEqual(genreName, genre->to_string());
        }

        TEST_METHOD(ToString_ValidGenre_Success)
        {
            // Arrange
            auto genre = Movie::Genre::create_genre("Drama");

            // Act
            std::string genreString = genre->to_string();

            // Assert
            Assert::AreEqual(std::string("Drama"), genreString);
        }

        TEST_METHOD(EqualityOperator_SameGenres_True)
        {
            // Arrange
            auto genre1 = Movie::Genre::create_genre("Comedy");
            auto genre2 = Movie::Genre::create_genre("Comedy");

            // Act & Assert
            Assert::IsTrue(*genre1 == *genre2);
        }

        TEST_METHOD(EqualityOperator_DifferentGenres_False)
        {
            // Arrange
            auto genre1 = Movie::Genre::create_genre("Horror");
            auto genre2 = Movie::Genre::create_genre("Thriller");

            // Act & Assert
            Assert::IsFalse(*genre1 == *genre2);
        }
    };
}