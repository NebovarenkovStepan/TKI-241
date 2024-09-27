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

	cout << u;
	return 0;
}
