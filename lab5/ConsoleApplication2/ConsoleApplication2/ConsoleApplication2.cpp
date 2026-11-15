#include "pch.h"

using namespace System;

int main(array<System::String^>^ args)
{
    Console::OutputEncoding = System::Text::Encoding::UTF8;

    Console::Write(L"Введіть кількість робітників M: ");
    int M = Convert::ToInt32(Console::ReadLine());

    // Зберігаю дані одного працівника за однаковим індексом у всіх масивах.
    array<int>^ N = gcnew array<int>(M);
    array<double>^ UnitCost = gcnew array<double>(M);
    array<int>^ Quantity = gcnew array<int>(M);
    array<double>^ Salary = gcnew array<double>(M);

    for (int i = 0; i < M; i++)
    {
        Console::WriteLine(L"\nРобітник {0}:", i + 1);
        Console::Write(L"  Табельний номер: ");
        N[i] = Convert::ToInt32(Console::ReadLine());
        Console::Write(L"  Вартість одиниці виробу (крб): ");
        UnitCost[i] = Convert::ToDouble(Console::ReadLine());
        Console::Write(L"  Кількість виробів: ");
        Quantity[i] = Convert::ToInt32(Console::ReadLine());
    }

    Console::WriteLine(L"\nТабельний номер | Заробітна платня (крб)");
    Console::WriteLine(L"----------------------------------------");

    for (int i = 0; i < M; i++)
    {
        // Множу вартість одиниці виробу на кількість виготовлених виробів.
        Salary[i] = UnitCost[i] * Quantity[i];
        Console::WriteLine(L"{0,15} | {1,15:F2}", N[i], Salary[i]);
    }

    Console::ReadLine();
    return 0;
}