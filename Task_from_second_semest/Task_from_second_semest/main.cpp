#include "../Library/Pair.cpp"
#include "../Library/Vector.cpp"
#include <iostream>

using namespace std;
using namespace queue;

int main()
{
	Vector<Pair<int, int>> a = { {1, 2}, {1, 2} };
	cout << a[0];
	return 0;
}
