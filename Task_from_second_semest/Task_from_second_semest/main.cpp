#include "../Library/Pair.cpp"
#include "../Library/Vector.cpp"
#include <iostream>

using namespace std;
using namespace queue;

int main()
{
	Pair<int, double> a = { 1, 1.5 };
	Vector<int> p = { 1, 2, 3 };
	cout << p;
	return 0;
}
