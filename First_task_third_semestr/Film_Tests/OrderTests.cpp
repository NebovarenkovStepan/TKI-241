#include "pch.h"
#include "CppUnitTest.h"
#include "../Film/Order.h"
#include "../Film/Movie.h"
#include "../Film/Person.h"
#include "../Film/Genre.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FilmTests
{
    TEST_CLASS(OrderTests)
    {
    public:

        TEST_METHOD(CreateOrder_Success)
        {
            // Arrange
            auto order = Movie::Order::create_order("My First Order");

            // Act
            std::string orderTitle = order->to_string();

            // Assert
            Assert::IsTrue(orderTitle.find("Order Title: My First Order") != std::string::npos);
        }

        TEST_METHOD(AddMovie_Success)
        {
            // Arrange
            auto order = Movie::Order::create_order("My Movie Order");
            auto genre = Movie::Genre::create_genre("Action");
            Movie::Person director("Christopher", "Nolan");
            std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
            std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(director) };
            auto movie = Movie::Movie::create_movie("Inception", 14.99, genres, directors, {});

            // Act
            order->add_oder(movie);
            order->add_price(movie);

            // Assert
            Assert::AreEqual("Inception", order->to_string().find("Movie: Inception") != std::string::npos ? "Inception" : "Not Found");
        }

        TEST_METHOD(ToString_Success)
        {
            // Arrange
            auto order = Movie::Order::create_order("My Movie Order");
            auto genre = Movie::Genre::create_genre("Action");
            Movie::Person director("Christopher", "Nolan");
            std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
            std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(director) };
            auto movie = Movie::Movie::create_movie("Inception", 14.99, genres, directors, {});
            order->add_oder(movie);
            order->add_price(movie);

            // Act
            std::string result = order->to_string();

            // Assert
            Assert::IsTrue(result.find("Order Title: My Movie Order") != std::string::npos);
            Assert::IsTrue(result.find("Price of Movie: 14.99") != std::string::npos);
            Assert::IsTrue(result.find("Movie: Inception") != std::string::npos);
        }

        TEST_METHOD(EqualityOperator_Success)
        {
            // Arrange
            auto order1 = Movie::Order::create_order("Order 1");
            auto order2 = Movie::Order::create_order("Order 1");

            // Act & Assert
            Assert::IsTrue(*order1 == *order2);
        }

        TEST_METHOD(EqualityOperator_Failure)
        {
            // Arrange
            auto order1 = Movie::Order::create_order("Order 1");
            auto order2 = Movie::Order::create_order("Order 2");

            // Act & Assert
            Assert::IsFalse(*order1 == *order2);
        }
    };
}