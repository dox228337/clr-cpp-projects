#include "pch.h"
using namespace System;

int main(array<String^>^ args)
{
    // Використовую UTF-8 для українських повідомлень та введення даних.
    Console::OutputEncoding = Text::Encoding::UTF8;
    Console::InputEncoding = Text::Encoding::UTF8;

    while (true)
    {
        Console::WriteLine(L"\n================== МЕНЮ ==================");
        Console::WriteLine(L"1. Завдання 1 (Обчислення ціни покриття)");
        Console::WriteLine(L"2. Завдання 2 (Об'єднання рядків)");
        Console::WriteLine(L"3. Завдання 3 (Порівняння рядків)");
        Console::WriteLine(L"4. Завдання 4 (Додавання слів 'begin' та 'end')");
        Console::WriteLine(L"5. Завдання 5 (Рядок у зворотному порядку)");
        Console::WriteLine(L"6. Завдання 6 (Визначення довшого рядка)");
        Console::WriteLine(L"0. Вихід з програми");
        Console::Write(L"Оберіть номер завдання: ");

        int n = Int32::Parse(Console::ReadLine());

        if (n == 0) {
            Console::WriteLine(L"Вихід з програми...");
            break;
        }

        switch (n)
        {
        case 1:
        {
            Console::WriteLine(L"\nЗавдання 1");

            double L = 19.0;
            double W = 14.0;
            double C = 9.0;

            // Обчислюю площу кімнати, а потім загальну вартість покриття.
            double area = L * W;
            double total = area * C;

            Console::WriteLine(L"Розмір кімнати {0:F2} метрів на {1:F2} метрів", L, W);
            Console::WriteLine(L"Площа кімнати {0:F2} квадратних метрів", area);
            Console::WriteLine(L"Ціна килимового покриття {0:F2} грн", total);
            break;
        }
        case 2:
        {
            Console::WriteLine(L"\nЗавдання 2");
            Console::Write(L"Введіть перший рядок: ");
            String^ s1 = Console::ReadLine();

            Console::Write(L"Введіть другий рядок: ");
            String^ s2 = Console::ReadLine();

            String^ res = s1 + s2;
            Console::WriteLine(L"Об'єднаний рядок: {0}", res);
            break;
        }
        case 3:
        {
            Console::WriteLine(L"\nЗавдання 3");
            Console::Write(L"Введіть перший рядок для порівняння: ");
            String^ s1 = Console::ReadLine();

            Console::Write(L"Введіть другий рядок для порівняння: ");
            String^ s2 = Console::ReadLine();

            int res = String::Compare(s1, s2);

            if (res < 0) {
                Console::WriteLine(L"Результат: Перший рядок менший за другий (за алфавітом).");
            }
            else if (res > 0) {
                Console::WriteLine(L"Результат: Перший рядок більший за другий (за алфавітом).");
            }
            else {
                Console::WriteLine(L"Результат: Рядки однакові.");
            }
            break;
        }
        case 4:
        {
            Console::WriteLine(L"\nЗавдання 4");
            Console::Write(L"Введіть вихідний рядок: ");
            String^ s1 = Console::ReadLine();

            String^ s2 = L"begin " + s1 + L" end";

            Console::WriteLine(L"Одержаний рядок: {0}", s2);
            Console::WriteLine(L"Довжина одержаного рядка: {0} символів", s2->Length);
            break;
        }
        case 5:
        {
            Console::WriteLine(L"\nЗавдання 5");
            Console::Write(L"Введіть рядок для реверсу: ");
            String^ s1 = Console::ReadLine();
            String^ s2 = L"";

            // Читаю символи з кінця, щоб отримати рядок у зворотному порядку.
            for (int i = s1->Length - 1; i >= 0; i--) {
                s2 += s1[i];
            }

            Console::WriteLine(L"Рядок у зворотному порядку: {0}", s2);
            break;
        }
        case 6:
        {
            Console::WriteLine(L"\nЗавдання 6");
            Console::Write(L"Введіть перший рядок: ");
            String^ s1 = Console::ReadLine();

            Console::Write(L"Введіть другий рядок: ");
            String^ s2 = Console::ReadLine();

            Console::WriteLine(L"Довжина першого рядка: {0}", s1->Length);
            Console::WriteLine(L"Довжина другого рядка: {0}", s2->Length);

            if (s1->Length > s2->Length) {
                Console::WriteLine(L"Результат: Перший рядок довший.");
            }
            else if (s1->Length < s2->Length) {
                Console::WriteLine(L"Результат: Другий рядок довший.");
            }
            else {
                Console::WriteLine(L"Результат: Рядки однакової довжини.");
            }
            break;
        }
        default:
        {
            Console::WriteLine(L"Помилка: Завдання з таким номером не існує. Спробуйте ще раз.");
            break;
        }
        }
    }

    return 0;
}