// Actor.h
#pragma once
#include "Person.h" 
#include <vector>
#include <memory>   
#include <optional>
#include <string>

class Movie;


class Actor final : public Person, public std::enable_shared_from_this<Actor>
{
private:
    // Конструктор приватный, чтобы использовать фабричный метод create
    Actor(const std::string& name, const std::string& surname, const std::optional<std::string>& patronymic = std::nullopt);

    // Актер может сниматься во многих фильмах.
    // Храним weak_ptr, чтобы не создавать циклы сильных ссылок (Movie -> Actor -> Movie)
    std::vector<std::weak_ptr<Movie>> m_movies;

public:
    // Статический фабричный метод для создания актеров
    static std::shared_ptr<Actor> create(const std::string& name, const std::string& surname, const std::optional<std::string>& patronymic = std::nullopt);

    // Метод для установления двусторонней связи между Актером и Фильмом
    void add_movie(const std::shared_ptr<Movie>& movie);

    // Получить список фильмов (возвращаем копию, чтобы нельзя было изменить внутренний вектор)
    std::vector<std::shared_ptr<Movie>> get_movies();
};
