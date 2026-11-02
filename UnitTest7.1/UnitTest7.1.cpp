#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TESTING
#include "../LABA-7.1/LABA-7.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71
{
    TEST_CLASS(UnitTest71)
    {
    public:
        TEST_METHOD(TestCriterion)
        {
            Assert::IsTrue(Criterion(1));
            Assert::IsTrue(Criterion(3));
            Assert::IsTrue(Criterion(15));
            Assert::IsTrue(Criterion(37));

            Assert::IsTrue(Criterion(-1));
            Assert::IsTrue(Criterion(-2));
            Assert::IsTrue(Criterion(-4));
            Assert::IsTrue(Criterion(-5));
            Assert::IsTrue(Criterion(-7));

            Assert::IsFalse(Criterion(-3));
            Assert::IsFalse(Criterion(-6));
            Assert::IsFalse(Criterion(-9));
            Assert::IsFalse(Criterion(-12));

            Assert::IsFalse(Criterion(0));
        }

        TEST_METHOD(TestCalcRows)
        {
            int** m = new int*[2];
            m[0] = new int[3]{ -3, 2, -1 };
            m[1] = new int[3]{ -6, 4, 0 };

            int S = 0, k = 0;
            CalcRows(m, 2, 3, 0, S, k);

            Assert::AreEqual(3, k);
            Assert::AreEqual(5, S);
            Assert::AreEqual(-3, m[0][0]);
            Assert::AreEqual(0, m[0][1]);
            Assert::AreEqual(0, m[0][2]);
            Assert::AreEqual(-6, m[1][0]);
            Assert::AreEqual(0, m[1][1]);
            Assert::AreEqual(0, m[1][2]);

            delete[] m[0];
            delete[] m[1];
            delete[] m;
        }

        TEST_METHOD(TestChangeCols)
        {
            int** m = new int*[3];
            m[0] = new int[2]{ 10, 20 };
            m[1] = new int[2]{ 30, 40 };
            m[2] = new int[2]{ 50, 60 };

            ChangeCols(m, 0, 1, 3);

            Assert::AreEqual(20, m[0][0]);
            Assert::AreEqual(10, m[0][1]);
            Assert::AreEqual(40, m[1][0]);
            Assert::AreEqual(30, m[1][1]);
            Assert::AreEqual(60, m[2][0]);
            Assert::AreEqual(50, m[2][1]);

            for (int i = 0; i < 3; i++) delete[] m[i];
            delete[] m;
        }

        TEST_METHOD(TestSortCols)
        {
            int** m = new int*[3];
            m[0] = new int[3]{ 5, 2, 2 };
            m[1] = new int[3]{ 1, 8, 3 };
            m[2] = new int[3]{ 7, 4, 9 };

            SortCols(m, 3, 3, 0);

            Assert::AreEqual(2, m[0][0]);
            Assert::AreEqual(2, m[0][1]);
            Assert::AreEqual(5, m[0][2]);

            Assert::AreEqual(3, m[1][0]);
            Assert::AreEqual(8, m[1][1]);
            Assert::AreEqual(1, m[1][2]);

            Assert::AreEqual(9, m[2][0]);
            Assert::AreEqual(4, m[2][1]);
            Assert::AreEqual(7, m[2][2]);

            for (int i = 0; i < 3; i++) delete[] m[i];
            delete[] m;
        }
    };
}
