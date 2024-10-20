#include<iostream>
#include"..//Library/HashTable.h"


using namespace std;
using namespace hash;

int main()
{
	HashTable<int> Table(10);
	cout << Table.ToString();
};