// LABA-7.1.cpp
// Шах Владислав Ігорьович
// Лабораторна робота № 7.1
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 32 (Рекурсивний спосіб)

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Рекурсивне заповнення одного рядка матриці випадковими числами
void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < colCount - 1)
        CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}

// Рекурсивний обхід усіх рядків для заповнення матриці
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, colCount, Low, High, 0);
    if (rowNo < rowCount - 1)
        CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}

// Рекурсивне виведення одного рядка матриці на екран
void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
    cout << setw(5) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

// Рекурсивний обхід усіх рядків для виведення матриці
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    PrintRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

// Перевірка критерію варіанта 32:
// всі додатні або крім кратних 3 (тобто додатні АБО не кратні 3)
bool Criterion(int x)
{
    return (x > 0 || !(x % 3 == 0));
}

// Рекурсивне опрацювання елементів одного рядка:
// обчислення суми, кількості та заміни елементів нулями
void CalcRow(int** a, const int rowNo, const int colCount, int colNo, int& S, int& k)
{
    if (colNo >= colCount)
        return;

    if (Criterion(a[rowNo][colNo]))
    {
        S += a[rowNo][colNo];
        k++;
        a[rowNo][colNo] = 0;
    }
    CalcRow(a, rowNo, colCount, colNo + 1, S, k);
}

// Рекурсивний обхід усіх рядків для обчислення S і k та заміни нулями
void CalcRows(int** a, const int rowCount, const int colCount, int rowNo, int& S, int& k)
{
    if (rowNo >= rowCount)
        return;

    CalcRow(a, rowNo, colCount, 0, S, k);
    CalcRows(a, rowCount, colCount, rowNo + 1, S, k);
}

// Рекурсивний обмін елементів двох стовпців для одного рядка
void ChangeColElem(int** a, const int col1, const int col2, const int rowCount, int rowNo)
{
    if (rowNo >= rowCount)
        return;

    int tmp = a[rowNo][col1];
    a[rowNo][col1] = a[rowNo][col2];
    a[rowNo][col2] = tmp;

    ChangeColElem(a, col1, col2, rowCount, rowNo + 1);
}

// Функція обміну двох стовпчиків місцями
void ChangeCols(int** a, const int col1, const int col2, const int rowCount)
{
    ChangeColElem(a, col1, col2, rowCount, 0);
}

// Рекурсивний внутрішній прохід сортування бульбашкою стовпчиків
void SortColPass(int** a, const int rowCount, const int colCount, const int i0, int j1)
{
    if (j1 >= colCount - i0 - 1)
        return;

    // Ключі впорядкування: → → → (за зростанням)
    // 1-й рядок a[0]: якщо a[0][j1] > a[0][j1+1] -> міняємо
    // якщо рівні -> порівнюємо 2-й рядок a[1]: якщо a[1][j1] > a[1][j1+1] -> міняємо
    // якщо і вони рівні -> порівнюємо 3-й рядок a[2]: якщо a[2][j1] > a[2][j1+1] -> міняємо
    if ((a[0][j1] > a[0][j1 + 1]) ||
        (a[0][j1] == a[0][j1 + 1] && a[1][j1] > a[1][j1 + 1]) ||
        (a[0][j1] == a[0][j1 + 1] && a[1][j1] == a[1][j1 + 1] && a[2][j1] > a[2][j1 + 1]))
    {
        ChangeCols(a, j1, j1 + 1, rowCount);
    }

    SortColPass(a, rowCount, colCount, i0, j1 + 1);
}

// Рекурсивний зовнішній цикл сортування стовпчиків
void SortCols(int** a, const int rowCount, const int colCount, int i0)
{
    if (i0 >= colCount - 1)
        return;

    SortColPass(a, rowCount, colCount, i0, 0);
    SortCols(a, rowCount, colCount, i0 + 1);
}

#ifndef UNIT_TESTING
int main()
{
    srand((unsigned)time(NULL));

    // Параметри за варіантом 32:
    // Матриця 7х9, діапазон [-12, 37]
    const int rowCount = 7;
    const int colCount = 9;
    const int Low = -12;
    const int High = 37;

    // Виділення динамічної пам'яті для матриці
    int** a = new int*[rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    cout << "================================================================" << endl;
    cout << "  Laboratorna robota No 7.1 (Recursive method)" << endl;
    cout << "  Student: Shakh Vladyslav, Group: RI-13, Variant: 32" << endl;
    cout << "  Matrix dimension: " << rowCount << " x " << colCount << ", Range: [" << Low << ", " << High << "]" << endl;
    cout << "  Criterion: all positive OR not multiple of 3" << endl;
    cout << "================================================================" << endl << endl;

    // 1. Формування матриці
    CreateRows(a, rowCount, colCount, Low, High, 0);

    // 2. Виведення початкової матриці
    cout << "Pochatkova matrytsia:" << endl;
    PrintRows(a, rowCount, colCount, 0);

    // 3. Впорядкування стовпчиків
    SortCols(a, rowCount, colCount, 0);

    // 4. Виведення впорядкованої матриці
    cout << "Vporiadkovana matrytsia (za kliuchamy -> -> ->):" << endl;
    PrintRows(a, rowCount, colCount, 0);

    // 5. Обчислення кількості, суми та заміна нулями
    int S = 0;
    int k = 0;
    CalcRows(a, rowCount, colCount, 0, S, k);

    cout << "Suma (S)     = " << S << endl;
    cout << "Kilkist (k)  = " << k << endl << endl;

    // 6. Виведення модифікованої матриці
    cout << "Modyfikovana matrytsia (elementy kryteriiu zamineno nulyamy):" << endl;
    PrintRows(a, rowCount, colCount, 0);

    // Звільнення динамічної пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
#endif
