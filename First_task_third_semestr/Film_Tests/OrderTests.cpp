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
    };
}