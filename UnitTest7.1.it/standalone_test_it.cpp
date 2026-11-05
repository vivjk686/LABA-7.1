#include <iostream>
#include <cassert>

#define UNIT_TESTING
#include "../LABA-7.1.it/LABA-7.1.it.cpp"

using namespace std;

void TestCriterion()
{
    cout << "Testing Criterion()... ";
    // Додатні: true
    assert(Criterion(1) == true);
    assert(Criterion(3) == true);
    assert(Criterion(15) == true);
    assert(Criterion(37) == true);

    // Від'ємні не кратні 3: true
    assert(Criterion(-1) == true);
    assert(Criterion(-2) == true);
    assert(Criterion(-4) == true);
    assert(Criterion(-5) == true);
    assert(Criterion(-7) == true);

    // Від'ємні кратні 3: false
    assert(Criterion(-3) == false);
    assert(Criterion(-6) == false);
    assert(Criterion(-9) == false);
    assert(Criterion(-12) == false);

    // Нуль: false (0 % 3 == 0)
    assert(Criterion(0) == false);

    cout << "PASSED!" << endl;
}

void TestCalc()
{
    cout << "Testing Calc()... ";
    int** m = new int*[2];
    m[0] = new int[3]{ -3, 2, -1 };
    m[1] = new int[3]{ -6, 4, 0 };

    int S = 0, k = 0;
    Calc(m, 2, 3, S, k);

    assert(k == 3);
    assert(S == 5);
    assert(m[0][0] == -3); // не змінився
    assert(m[0][1] == 0);  // 2 -> 0
    assert(m[0][2] == 0);  // -1 -> 0
    assert(m[1][0] == -6); // не змінився
    assert(m[1][1] == 0);  // 4 -> 0
    assert(m[1][2] == 0);  // 0 не змінився

    delete[] m[0];
    delete[] m[1];
    delete[] m;

    cout << "PASSED!" << endl;
}

void TestChange()
{
    cout << "Testing Change()... ";
    int** m = new int*[2];
    m[0] = new int[2]{ 10, 20 };
    m[1] = new int[2]{ 30, 40 };

    Change(m, 0, 1, 2);

    assert(m[0][0] == 20 && m[0][1] == 10);
    assert(m[1][0] == 40 && m[1][1] == 30);

    delete[] m[0];
    delete[] m[1];
    delete[] m;

    cout << "PASSED!" << endl;
}

void TestSort()
{
    cout << "Testing Sort()... ";
    int** m = new int*[3];
    m[0] = new int[3]{ 5, 2, 5 };
    m[1] = new int[3]{ 1, 4, 0 };
    m[2] = new int[3]{ 7, 3, 2 };

    Sort(m, 3, 3);

    // Стовпчик з m[0][i]=2 має стати першим (індекс 0)
    assert(m[0][0] == 2 && m[1][0] == 4 && m[2][0] == 3);
    // При рівності m[0]: другий стовпчик має m[1]=0 < 1
    assert(m[0][1] == 5 && m[1][1] == 0 && m[2][1] == 2);
    // Третій стовпчик має m[1]=1
    assert(m[0][2] == 5 && m[1][2] == 1 && m[2][2] == 7);

    delete[] m[0];
    delete[] m[1];
    delete[] m[2];
    delete[] m;

    cout << "PASSED!" << endl;
}

int main()
{
    cout << "===============================================" << endl;
    cout << "  RUNNING UNIT TESTS FOR LAB 7.1 IT (VAR 32)  " << endl;
    cout << "===============================================" << endl;
    TestCriterion();
    TestCalc();
    TestChange();
    TestSort();
    cout << "===============================================" << endl;
    cout << "  ALL 4 UNIT TESTS COMPLETED SUCCESSFULLY!    " << endl;
    cout << "===============================================" << endl;
    return 0;
}
