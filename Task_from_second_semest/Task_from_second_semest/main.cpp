#include <iostream>
#include "..\Library\Pair.h"
#include "..\Library\Vector.h"

using namespace std;
using namespace queue;

int main()
{
	Pair<int, double> a( 0, 0 );
	Vector<int> p = { 1, 2, 3 };
	p.push_back(4);
	p.push_back(5);
	p.push_back(6);
	p.push_back(7);
	Vector<Pair<int, double>> u{ a, a};
	u.push_back(a);
	Pair<Vector<Pair<int, double>>, Vector<Pair<int, double>>> vect( u, u );
	cout << vect;
	return 0;
};
