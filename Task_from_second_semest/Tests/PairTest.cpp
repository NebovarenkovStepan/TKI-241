#include <iostream>
#include "pch.h"
#include "CppUnitTest.h"
#include "..//Library/Pair.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace queue;
using namespace std;

namespace Tests
{
	TEST_CLASS(PairTest)
	{
	public:
		
		TEST_METHOD(ToString_ZeroData_Success)
		{
			// arrange
			Pair<int, int> pair(0, 0);
			string expected{ "0, 0" };

			// act
			auto actual = pair.ToString();

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PairAreEqual_SamePairs_True)
		{
			// arrange
			Pair<int,int> pair1(0, 0);
			Pair<int, int> pair2(0, 0);

			// act & assert
			Assert::AreEqual(pair1.ToString(), pair2.ToString());
		}

		TEST_METHOD(PairFirst_GetFirstElement_True)
		{
			// arrange
			Pair<int, int> pair(10, 0);
			int first = 10;

			// act & assert
			Assert::AreEqual(pair.first(), first);
		}

		TEST_METHOD(PairSecond_GetSecondElement_True)
		{
			// arrange
			Pair<int, int> pair(0, 10);
			int second = 10;

			// act & assert
			Assert::AreEqual(pair.second(), second);
		}
	};
}
