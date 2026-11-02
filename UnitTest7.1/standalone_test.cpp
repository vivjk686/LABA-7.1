#include <iostream>
#include <cassert>

#define UNIT_TESTING
#include "../LABA-7.1/LABA-7.1.cpp"

using namespace std;

void TestCriterion()
{
    cout << "Testing Criterion()... ";
    assert(Criterion(1) == true);
    assert(Criterion(3) == true);
    assert(Criterion(6) == true);
    assert(Criterion(10) == true);

    assert(Criterion(-1) == true);
    assert(Criterion(-2) == true);
    assert(Criterion(-4) == true);
    assert(Criterion(-5) == true);
    assert(Criterion(-7) == true);

    assert(Criterion(-3) == false);
    assert(Criterion(-6) == false);
    assert(Criterion(-9) == false);
    assert(Criterion(-12) == false);

    assert(Criterion(0) == false);

    cout << "PASSED!" << endl;
}

void TestCalcRows()
{
    cout << "Testing CalcRows()... ";
    int** m = new int*[2];
    m[0] = new int[3]{ -3, 2, -1 };
    m[1] = new int[3]{ -6, 4, 0 };

    int S = 0, k = 0;
    CalcRows(m, 2, 3, 0, S, k);

    assert(k == 3);
    assert(S == 5);
    assert(m[0][0] == -3);
    assert(m[0][1] == 0);
    assert(m[0][2] == 0);
    assert(m[1][0] == -6);
    assert(m[1][1] == 0);
    assert(m[1][2] == 0);

    delete[] m[0];
    delete[] m[1];
    delete[] m;

    cout << "PASSED!" << endl;
}

void TestChangeCols()
{
    cout << "Testing ChangeCols()... ";
    int** m = new int*[3];
    m[0] = new int[2]{ 10, 20 };
    m[1] = new int[2]{ 30, 40 };
    m[2] = new int[2]{ 50, 60 };

    ChangeCols(m, 0, 1, 3);

    assert(m[0][0] == 20 && m[0][1] == 10);
    assert(m[1][0] == 40 && m[1][1] == 30);
    assert(m[2][0] == 60 && m[2][1] == 50);

    for (int i = 0; i < 3; i++) delete[] m[i];
    delete[] m;

    cout << "PASSED!" << endl;
}

void TestSortCols()
{
    cout << "Testing SortCols()... ";
    int** m = new int*[3];
    m[0] = new int[3]{ 5, 2, 2 };
    m[1] = new int[3]{ 1, 8, 3 };
    m[2] = new int[3]{ 7, 4, 9 };

    SortCols(m, 3, 3, 0);

    assert(m[0][0] == 2 && m[0][1] == 2 && m[0][2] == 5);
    assert(m[1][0] == 3 && m[1][1] == 8 && m[1][2] == 1);
    assert(m[2][0] == 9 && m[2][1] == 4 && m[2][2] == 7);

    for (int i = 0; i < 3; i++) delete[] m[i];
    delete[] m;

    cout << "PASSED!" << endl;
}

int main()
{
    cout << "==========================================" << endl;
    cout << "  RUNNING UNIT TESTS FOR LAB 7.1 (VAR 32) " << endl;
    cout << "==========================================" << endl;
    TestCriterion();
    TestCalcRows();
    TestChangeCols();
    TestSortCols();
    cout << "==========================================" << endl;
    cout << "  ALL 4 UNIT TESTS COMPLETED SUCCESSFULLY! " << endl;
    cout << "==========================================" << endl;
    return 0;
}
