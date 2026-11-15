#include "pch.h"

using namespace System;

int main(array<System::String^>^ args)
{
    Console::OutputEncoding = System::Text::Encoding::UTF8;

    Console::Write(L"Введіть кількість рядків N: ");
    int rows = Convert::ToInt32(Console::ReadLine());
    Console::Write(L"Введіть кількість стовпців M: ");
    int cols = Convert::ToInt32(Console::ReadLine());

    array<int, 2>^ matrix = gcnew array<int, 2>(rows, cols);
    array<int>^ rowSums = gcnew array<int>(rows);
    array<int>^ indices = gcnew array<int>(rows);

    Console::WriteLine(L"\nВведіть елементи матриці:");
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < cols; j++)
        {
            Console::Write(L"Елемент [{0},{1}]: ", i, j);
            matrix[i, j] = Convert::ToInt32(Console::ReadLine());
            sum += matrix[i, j];
        }
        rowSums[i] = sum;
        indices[i] = i;
    }

    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = i + 1; j < rows; j++)
        {
            if (rowSums[indices[j]] > rowSums[indices[i]])
            {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    Console::WriteLine(L"\nМатриця після перестановки рядків (за спаданням сум):");
    for (int i = 0; i < rows; i++)
    {
        int originalRow = indices[i];
        for (int j = 0; j < cols; j++)
        {
            Console::Write(L"{0,3} ", matrix[originalRow, j]);
        }
        Console::WriteLine(L" | Сума: {0}", rowSums[originalRow]);
    }

    Console::ReadLine();
    return 0;
}