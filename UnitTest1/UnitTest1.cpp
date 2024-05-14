#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP Lab 6.4/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Vector<double> v(3);

			v[0] = 1; v[1] = 2; v[2] = 2;

			double expectedNorma = sqrt(1 + 4 + 4);

			double result = v.norm();

			Assert::AreEqual(expectedNorma, result);
		}
	};
}