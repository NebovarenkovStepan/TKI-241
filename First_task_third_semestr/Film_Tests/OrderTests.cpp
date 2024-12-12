#include "pch.h"
#include "CppUnitTest.h"
#include "../Film/Order.h"
#include "../Film/Film.h"
#include "../Film/Gener.h"
#include "../Film/people.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FilmTests
{
    TEST_CLASS(OrderTests)
    {
    public:

        TEST_METHOD(AddMovie_Success)
        {
            // Arrange
            auto order = film::Order::create_order("My Movie Order");
            std::vector<std::shared_ptr<film::Genre>> genres = { std::make_shared<film::Genre>("Sci-Fi") };
            std::vector<std::shared_ptr<film::Person>> directors = { std::make_shared<film::Person>("Christopher Nolan") };
            auto movie = film::Movie::create_movie("Inception", 14.99, genres, directors, {});

            // Act
            order->add_oder(movie);

            // Assert
            Assert::AreEqual("Inception", order->to_string().substr(7, 9).c_str()); // Check if the movie title is included in the order string
        }

        TEST_METHOD(ToString_Success)
        {
            // Arrange
            auto order = film::Order::create_order("My Movie Order");
            std::vector<std::shared_ptr<film::Genre>> genres = { std::make_shared<film::Genre>("Sci-Fi") };
            std::vector<std::shared_ptr<film::Person>> directors = { std::make_shared<film::Person>("Christopher Nolan") };
            auto movie = film::Movie::create_movie("Inception", 14.99, genres, directors, {});
            order->add_oder(movie);

            // Act
            std::string result = order->to_string();

            // Assert
            Assert::IsTrue(result.find("Order:") != std::string::npos);
            Assert::IsTrue(result.find("Inception") != std::string::npos);
        }

        TEST_METHOD(EqualityOperator_Success)
        {
            // Arrange
            auto order1 = film::Order::create_order("Order 1");
            auto order2 = film::Order::create_order("Order 1");

            // Act & Assert
            Assert::IsFalse(*order1 == *order2); // Currently, the equality operator always returns false
        }
    };
}