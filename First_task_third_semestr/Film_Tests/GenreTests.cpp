#include "pch.h"
#include "CppUnitTest.h"
#include "../Film/Genre.h"
#include "../Film/Movie.h"
#include "../Film/Person.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FilmTests
{
    TEST_CLASS(GenreTests)
    {
    public:
        TEST_METHOD(EqualityOperator_Success)
        {
            // Arrange
            auto genre1 = Movie::Genre::create_genre("Sci-Fi");
            auto genre2 = Movie::Genre::create_genre("Sci-Fi");

            // Act & Assert
            Assert::IsTrue(*genre1 == *genre2); 
        }

        TEST_METHOD(EqualityOperator_Failure)
        {
            // Arrange
            auto genre1 = Movie::Genre::create_genre("Sci-Fi");
            auto genre2 = Movie::Genre::create_genre("Action");

            // Act & Assert
            Assert::IsFalse(*genre1 == *genre2); 
        }
    };
}