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
	TEST_CLASS(VectorTest)
	{
	public:

		TEST_METHOD(IntIndexOperator_ZeroData_Success)
		{
			// arrange
			Vector<int> vect{ 0, 1 };

			// act
			auto actual = 0;
			auto expected = vect[0];

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(StringIndexOperator_ZeroData_Success)
		{
			// arrange
			Vector<string> vect{ "0", "1"};

			// act
			string actual = "0";
			auto expected = vect[0];

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PairIndexOperator_ZeroData_Success)
		{
			// arrange
			Pair<int, int> a(0, 0);
			Pair<int, int> a1(0, 1);
			Vector<Pair<int, int>> vect{ a, a1 };

			// act
			auto actual = a.ToString();
			auto expected = vect[0].ToString();

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(IntIndexOperator_ZeroData_Fail)
		{
			// arrange
			Vector<int> vect{ 0, 1 };

			// act
			auto func = [&vect] { vect[3]; };
			// assert
			Assert::ExpectException<logic_error>(func);
		}

		TEST_METHOD(IntToString_ZeroData_Success)
		{
			// arrange
			Vector<int> vect{ 0, 1 };
			string expected{ "[0, 1]" };

			// act
			auto actual = vect.to_string();

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(StringToString_ZeroData_Success)
		{
			// arrange
			Vector<string> vect{ "0", "1"};
			string expected{ "[0, 1]" };

			// act
			auto actual = vect.to_string();

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PairToString_ZeroData_Success)
		{
			// arrange
			Pair<int, int> a(0, 0);
			Vector<Pair<int, int>> vect{ a, a };
			string expected{ "[(0; 0), (0; 0)]" };

			// act
			auto actual = vect.to_string();

			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(IntAreEqual_SameVectors_Success)
		{
			// arrange
			Vector<int> vect1{ 0, 1 };
			Vector<int> vect2{ 0, 1 };

			// assert
			Assert::AreEqual(vect1.to_string(), vect2.to_string());
		}

		TEST_METHOD(StringAreEqual_SameVectors_Success)
		{
			// arrange
			Vector<string> vect1{ "0", "1"};
			Vector<string> vect2{ "0", "1"};

			// assert
			Assert::AreEqual(vect1.to_string(), vect2.to_string());
		}

		TEST_METHOD(PairAreEqual_SameVectors_Success)
		{
			// arrange
			Pair<int, int> a(0, 0);
			Vector<Pair<int, int>> vect1{ a, a };
			Pair<int, int> a(0, 0);
			Vector<Pair<int, int>> vect2{ a, a };

			// assert
			Assert::AreEqual(vect1.to_string(), vect2.to_string());
		}

		TEST_METHOD(AssignOperator_ZeroData_Success)
		{
			// arrange
			Vector<int> vect1{ 0, 1 };

			//act
			Vector<int> vect2 = vect1;

			//assert
			Assert::AreEqual(vect1.to_string(), vect2.to_string());
		}

		TEST_METHOD(PushBack_ZeroData_Success)
		{
			//arrenge
			Vector<int> vect{ 0, 1 };
			
			//act
			vect.push_back(2);
			string expected{ "[0, 1, 2]" };
			auto actual = vect.to_string();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetSize_ZeroData_Success)
		{
			//arrenge
			Vector<int> vect{ 0, 1 };

			//act
			size_t expected = 2;
			auto actual = vect.get_size();

			//assert
			Assert::AreEqual(expected, actual);
		}
	};
}
