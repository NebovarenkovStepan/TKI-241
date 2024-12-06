#include <memory>
#include <iostream>
#include "../Film/film.h"
#include "../Film/people.h"
#include "pch.h"
#include "CppUnitTest.h"
#include <optional>


using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace film;


namespace FilmTests
{
	TEST_CLASS(PersonTests)
	{
	public:
		TEST_METHOD(ConstructorWithPatronymic_ZeroData_Success)
        {
            // arrange
            string name = "John";
            string surname = "Doe";
            optional<string> patronymic = "Smith";

            // act
            Person person(name, surname, patronymic);
            string expected = "John Doe Smith";

            // assert
            Assert::AreEqual(expected, person.to_string());
        }

        TEST_METHOD(ConstructorWithoutPatronymic_ZeroData_Success)
        {
            // arrange
            string name = "Jane";
            string surname = "Doe";
            optional<string> patronymic = nullopt;

            // act
            Person person(name, surname, patronymic);

            string expected = "Jane Doe";

            // assert
            Assert::AreEqual(expected, person.to_string());
        }

        TEST_METHOD(ToString_ZeroData_Success)
        {
            // arrange
            Person person("Alice", "Wonderland", nullopt);

            // act
            string actual = person.to_string();

            string expected = "Alice Wonderland";

            // assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(GetPatronymic_Patronymic_Success)
        {
            // arrange
            Person person("John", "Doe", "Smith");

            // act
            string actual = person.get_patronymic();
            string expected = "Smith";

            // assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(GetPatronymic_ZeroData_Success)
        {
            // arrange
            Person person("Jane", "Doe", nullopt);

            // act
            string actual = person.get_patronymic();
            string expected = "Empty";

            // assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(AreEqual_ZeroData_Success)
        {
            // arrange
            Person person1("John", "Doe", "Smith");
            Person person2("John", "Doe", "Smith");

            // act & assert
            Assert::IsTrue(person1 == person2);
        }
    };
}
