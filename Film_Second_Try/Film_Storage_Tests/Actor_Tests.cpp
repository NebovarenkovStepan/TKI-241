#include "pch.h"
#include "CppUnitTest.h"
#include "../Film_Storage/Actor.h"
#include "../Film_Storage/Movie.h"
#include "../Film_Storage/Genre.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ActorTests
{
    TEST_CLASS(ActorTests)
    {
    public:
        TEST_METHOD(CreateActor_ValidParameters_Success)
        {
            // Arrange
            std::string name = "Leonardo";
            std::string surname = "DiCaprio";
            std::optional<std::string> patronymic = "Wilhelm";

            // Act
            auto actor = Movie::Actor::create_actor(name, surname, patronymic);

            // Assert
            Assert::AreEqual(name, actor->get_name());
            Assert::AreEqual(surname, actor->get_surname());
            Assert::AreEqual(patronymic.value_or(""), actor->get_patronymic());
        }

        TEST_METHOD(Equality_EqualActors_Success)
        {
            // Arrange
            auto actor1 = Movie::Actor::create_actor("Leonardo", "DiCaprio", std::nullopt);
            auto actor2 = Movie::Actor::create_actor("Leonardo", "DiCaprio", std::nullopt);

            // Act
            bool areEqual = (*actor1 == *actor2);

            // Assert
            Assert::IsTrue(areEqual);
        }

        TEST_METHOD(Equality_DifferentActors_Success)
        {
            // Arrange
            auto actor1 = Movie::Actor::create_actor("Leonardo", "DiCaprio", std::nullopt);
            auto actor2 = Movie::Actor::create_actor("Brad", "Pitt", std::nullopt);

            // Act
            bool areEqual = (*actor1 == *actor2);

            // Assert
            Assert::IsFalse(areEqual);
        }
    };
}