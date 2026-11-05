#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TESTING
#include "../LABA-7.1.it/LABA-7.1.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71it
{
    TEST_CLASS(UnitTest71it)
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

        TEST_METHOD(TestCalc)
        {
            int** m = new int*[2];
            m[0] = new int[3]{ -3, 2, -1 };
            m[1] = new int[3]{ -6, 4, 0 };

            int S = 0, k = 0;
            Calc(m, 2, 3, S, k);

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

        TEST_METHOD(TestChange)
        {
            int** m = new int*[2];
            m[0] = new int[2]{ 10, 20 };
            m[1] = new int[2]{ 30, 40 };

            Change(m, 0, 1, 2);

            Assert::AreEqual(20, m[0][0]);
            Assert::AreEqual(10, m[0][1]);
            Assert::AreEqual(40, m[1][0]);
            Assert::AreEqual(30, m[1][1]);

            delete[] m[0];
            delete[] m[1];
            delete[] m;
        }

        TEST_METHOD(TestSort)
        {
            int** m = new int*[3];
            m[0] = new int[3]{ 5, 2, 5 };
            m[1] = new int[3]{ 1, 4, 0 };
            m[2] = new int[3]{ 7, 3, 2 };

            Sort(m, 3, 3);

            Assert::AreEqual(2, m[0][0]);
            Assert::AreEqual(4, m[1][0]);
            Assert::AreEqual(3, m[2][0]);

            Assert::AreEqual(5, m[0][1]);
            Assert::AreEqual(0, m[1][1]);
            Assert::AreEqual(2, m[2][1]);

            Assert::AreEqual(5, m[0][2]);
            Assert::AreEqual(1, m[1][2]);
            Assert::AreEqual(7, m[2][2]);

            delete[] m[0];
            delete[] m[1];
            delete[] m[2];
            delete[] m;
        }
    };
}
