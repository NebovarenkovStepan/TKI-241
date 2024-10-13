#include <iostream>
#include "..\Library\Pair.h"
#include "..\Library\Vector.h"

using namespace std;
using namespace queue;

int main()
{
	Pair<int, double> a = { 1, 1.5 };
	Vector<int> p = { 1, 2, 3 };
	Vector<Pair<int, double>> u{a, a, a};
	//Pair<Vector<int>, Vector<int>> vect({ 0, 0 }, { 0, 0 });
	//cout << vect.ToString();
	return 0;
}
