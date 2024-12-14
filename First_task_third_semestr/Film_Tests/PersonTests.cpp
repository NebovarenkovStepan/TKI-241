#include "pch.h"
#include "CppUnitTest.h"
#include "../Film/Person.h"
#include "../Film/Movie.h"
#include "../Film/Genre.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FilmTests
{
    TEST_CLASS(PersonTests)
    {
    public:

        TEST_METHOD(CreatePerson_Success)
        {
            // Arrange
            std::string name = "Christopher";
            std::string surname = "Nolan";
            std::optional<std::string> patronymic = "Edward";

            // Act
            Movie::Person person(name, surname, patronymic);

            std::string a = "Christopher Nolan Edward";
            // Assert
            Assert::AreEqual(a, person.to_string());
        }

        TEST_METHOD(CreatePerson_WithoutPatronymic_Success)
        {
            // Arrange
            std::string name = "Leonardo";
            std::string surname = "DiCaprio";
            std::optional<std::string> patronymic = std::nullopt;

            // Act
            Movie::Person person(name, surname, patronymic);

            std::string a = "Leonardo DiCaprio";
            // Assert
            Assert::AreEqual(a, person.to_string());
        }

        TEST_METHOD(AddFilmAsDirector_Success)
        {
            // Arrange
            Movie::Person person("Christopher", "Nolan");
            auto genre = Movie::Genre::create_genre("Action");
            std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
            std::vector<std::shared_ptr<Movie::Person>> directors = { std::make_shared<Movie::Person>(person) };
            auto movie = Movie::Movie::create_movie("Inception", 14.99, genres, directors, {});

            // Act
            person.add_film_directors(movie);

            // Assert
            Assert::IsTrue(movie->get_directors().size() == 1);
            Assert::AreEqual("Christopher Nolan", movie->get_directors()[0]->to_string().c_str());
        }

        TEST_METHOD(AddFilmAsActor_Success)
        {
            // Arrange
            Movie::Person person("Leonardo", "DiCaprio");
            auto genre = Movie::Genre::create_genre("Drama");
            std::vector<std::shared_ptr<Movie::Genre>> genres = { genre };
            std::vector<std::shared_ptr<Movie::Person>> directors;
            auto movie = Movie::Movie::create_movie("Titanic", 19.99, genres, directors, {});

            // Act
            person.add_film_actors(movie);

            // Assert
            Assert::IsTrue(movie->get_actors().size() == 1);
            Assert::AreEqual("Leonardo DiCaprio", movie->get_actors()[0]->to_string().c_str());
        }
    };
}