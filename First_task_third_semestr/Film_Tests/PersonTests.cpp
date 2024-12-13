#include "../Film/Person.h"
#include "pch.h"
#include "CppUnitTest.h"
#include <optional>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PerosnTests
{
    TEST_CLASS(PersonTests)
    {
    public:
        TEST_METHOD(ConstructorWithPatronymic_ZeroData_Success)
        {
            // arrange
            std::string name = "John";
            std::string surname = "Doe";
            std::optional<std::string> patronymic = "Smith";

            // act
            Movie::Person person(name, surname, patronymic);
            std::string expected = "John Doe Smith";

            // assert
            Assert::AreEqual(expected, person.to_string());
        }

        TEST_METHOD(ConstructorWithoutPatronymic_ZeroData_Success)
        {
            // arrange
            std::string name = "Jane";
            std::string surname = "Doe";
            std::optional<std::string> patronymic = std::nullopt;

            // act
            Movie::Person person(name, surname, patronymic);

            std::string expected = "Jane Doe";

            // assert
            Assert::AreEqual(expected, person.to_string());
        }

        TEST_METHOD(ToString_ZeroData_Success)
        {
            // arrange
            Movie::Person person("Alice", "Wonderland", std::nullopt);

            // act
            std::string actual = person.to_string();

            std::string expected = "Alice Wonderland";

            // assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(GetPatronymic_Patronymic_Success)
        {
            // arrange
            Movie::Person person("John", "Doe", "Smith");

            // act
            std::string actual = person.get_patronymic();
            std::string expected = "Smith";

            // assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(GetPatronymic_ZeroData_Success)
        {
            // arrange
            Movie::Person person("Jane", "Doe", std::nullopt);

            // act
            std::string actual = person.get_patronymic();
            std::string expected = "Empty";

            // assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(AreEqual_ZeroData_Success)
        {
            // arrange
            Movie::Person person1("John", "Doe", "Smith");
            Movie::Person person2("John", "Doe", "Smith");

            // act & assert
            Assert::IsTrue(person1 == person2);
        }
    };
}
