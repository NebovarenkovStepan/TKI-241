#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <variant>
#include "Film.h"

using namespace std;

namespace film
{
    class Film;
    class Storage;

    class Storage final : public enable_shared_from_this<Storage>
    {

    private:

        vector<Movie*> movies;
        string name;

    public:

        Storage(const string& name);

        static shared_ptr<Storage> create_storage(const string& name);

        void add_movie(shared_ptr<Movie> movie);

        string search_by_title(const string& title); 

        vector<Movie> search_by_genre(const string& genre); 

        vector<Movie> search_by_director(const string& director);

        vector<Movie> search_by_actor(const string& actor);

        /*vector<shared_ptr<Movie>> get_top_selling_movies(int top);

        double get_total_sales();*/
    };
}