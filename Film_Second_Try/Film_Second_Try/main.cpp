#include "..//Film_Storage/Actor.h"

#include "..//Film_Storage/Genre.h"

using namespace Movie;

int main()
{
	const std::string name = "D";
	const std::string surname = "D";
	const std::optional<std::string> patronymic = "D";
	auto actor = Actor::create_actor(name, surname, patronymic);
	auto genre = Genre::create_genre("S")->to_string();
	std::cout << actor->to_string();
	return 0;
}