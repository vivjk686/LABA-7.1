// LABA-7.1.it.cpp
// Шах Владислав Ігорьович
// Лабораторна робота № 7.1
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 32 (Ітераційний спосіб)

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Функція формування матриці за допомогою генератора випадкових чисел (ітераційно)
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Функція виведення матриці на екран (ітераційно)
void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// Функція обміну елементів двох стовпчиків (ітераційно)
void Change(int** a, const int col1, const int col2, const int rowCount)
{
    int tmp;
    for (int i = 0; i < rowCount; i++)
    {
        tmp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = tmp;
    }
}

// Функція впорядкування стовпчиків матриці за зростанням (ітераційно)
// Завдання 32: напрям ключів -> -> -> (0-й рядок, 1-й рядок, 2-й рядок)
void Sort(int** a, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < colCount - 1; i0++)
    {
        for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
        {
            if ((a[0][i1] > a[0][i1 + 1]) ||
                (a[0][i1] == a[0][i1 + 1] && a[1][i1] > a[1][i1 + 1]) ||
                (a[0][i1] == a[0][i1 + 1] && a[1][i1] == a[1][i1 + 1] && a[2][i1] > a[2][i1 + 1]))
            {
                Change(a, i1, i1 + 1, rowCount);
            }
        }
    }
}

// Предикат варіанта 32:
// всі додатні або крім кратних 3 (тобто додатні АБО не кратні 3)
bool Criterion(int x)
{
    return (x > 0) || !(x % 3 == 0);
}

// Функція обчислення суми S, кількості k та заміни елементів нулями (ітераційно)
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (Criterion(a[i][j]))
            {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
        }
    }
}

#ifndef UNIT_TESTING
int main()
{
    srand((unsigned)time(NULL));

    const int rowCount = 7;
    const int colCount = 9;
    const int Low = -12;
    const int High = 37;

    // Виділення динамічної пам'яті для матриці
    int** a = new int*[rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    cout << "================================================================" << endl;
    cout << "  Laboratorna robota No 7.1 (Iterative method)" << endl;
    cout << "  Student: Shakh Vladyslav, Group: RI-13, Variant: 32" << endl;
    cout << "  Matrix dimension: " << rowCount << " x " << colCount << ", Range: [" << Low << ", " << High << "]" << endl;
    cout << "  Criterion: all positive OR not multiple of 3" << endl;
    cout << "================================================================" << endl;

    // 1. Формування матриці
    Create(a, rowCount, colCount, Low, High);

    // 2. Виведення початкової матриці
    cout << "Pochatkova matrytsia:";
    Print(a, rowCount, colCount);

    // 3. Впорядкування стовпчиків
    Sort(a, rowCount, colCount);

    // 4. Виведення впорядкованої матриці
    cout << "Vporiadkovana matrytsia (za kliuchamy -> -> ->):";
    Print(a, rowCount, colCount);

    // 5. Обчислення кількості, суми та заміна нулями
    int S = 0;
    int k = 0;
    Calc(a, rowCount, colCount, S, k);

    cout << "Suma (S)     = " << S << endl;
    cout << "Kilkist (k)  = " << k << endl;

    // 6. Виведення модифікованої матриці
    cout << "Modyfikovana matrytsia (elementy kryteriiu zamineno nulyamy):";
    Print(a, rowCount, colCount);

    // Звільнення динамічної пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
#endif
