#include <iostream>
#include "pch.h"
#include "CppUnitTest.h"
#include "..//Library/Pair.h"
#include "..//Library/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace queue;
using namespace std;

namespace Tests
{
	TEST_CLASS(PairTest)
	{
	public:
		
		TEST_METHOD(IntToString_ZeroData_Success)
		{
			// arrange
			Pair<int, int> pair(0, 0);
			string expected{ "0, 0" };

			// act
			auto actual = pair.ToString();

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(IntPairAreEqual_SamePairs_Success)
		{
			// arrange
			Pair<int,int> pair1(0, 0);
			Pair<int, int> pair2(0, 0);

			// assert
			Assert::AreEqual(pair1, pair2);
		}

		TEST_METHOD(IntPairFirst_GetFirstElement_Success)
		{
			// arrange
			Pair<int, int> pair(10, 0);
			int expected = 10;

			//act
			auto actual = pair.first();

			// assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(IntPairSecond_GetSecondElement_Success)
		{
			// arrange
			Pair<int, int> pair(0, 10);
			int expected = 10;

			//act
			auto actual = pair.second();

			// assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(StringToString_ZeroData_Success)
		{
			// arrange
			Pair<string, string> pair("0", "0");
			string expected{ "0, 0" };

			// act
			auto actual = pair.ToString();

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(StringPairAreEqual_SamePairs_Success)
		{
			// arrange
			Pair<string, string> pair1("0", "0");
			Pair<string, string> pair2("0", "0");

			// assert
			Assert::AreEqual(pair1, pair2);
		}

		TEST_METHOD(StringPairFirst_GetFirstElement_Success)
		{
			// arrange
			Pair<string, string> pair("10", "0");
			string expected = "10";

			//act
			auto actual = pair.first();

			// assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(StringPairSecond_GetSecondElement_Success)
		{
			// arrange
			Pair<string, string> pair("2", "4");
			string expected = "4";

			//act
			auto actual = pair.second();

			// assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(VectorToString_ZeroData_Success)
		{
			// arrange
			Pair<Vector<int>, Vector<int>> pair({0, 0}, {0, 0});
			string expected{ "0, 0" };

			// act
			auto actual = pair.ToString();

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(VectorPairAreEqual_SamePairs_Success)
		{
			// arrange
			Pair<Vector<int>, Vector<int>> pair1({1, 2}, {1, 2});
			Pair<Vector<int>, Vector<int>> pair2({1, 2}, {1, 2});

			// assert
			Assert::AreEqual(pair1, pair2);
		}

		TEST_METHOD(VectorPairFirst_GetFirstElement_Success)
		{
			// arrange
			Pair<Vector<int>, Vector<int>> pair({ 1, 2 }, { 1, 2 });
			Vector<int> expected = { 1, 2 };

			//act
			auto actual = pair.first();

			// assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(VectorPairSecond_GetSecondElement_Success)
		{
			// arrange
			Vector<int> a = { 1, 2, 3 };
			Vector<int> b = { 4, 5, 6 };
			Pair<Vector<int>, Vector<int>> pair(a, b);
			Vector<int> expected = { 4, 5, 6 };

			//act
			auto actual = pair.second();

			// assert
			Assert::AreEqual(actual, expected);
		}
	};
}
