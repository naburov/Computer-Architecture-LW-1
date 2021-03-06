﻿// Задача 10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <iostream>
#include "Задача 10.h"

using namespace std;


int main()
{
	int choice;

	setlocale(LC_ALL, "RUS");
	cout << "Выберите операцию" << endl;
	cout << "1) F(m,k) = m*2^k" << endl;
	cout << "2) F(m,k) = m/2^k" << endl;
	scanf("%d", &choice);

	switch (choice) {
	case  1:
		Multiply();
		break;
	case 2:
		Division();
		break;
	}
}

void Multiply() {
	int m, k, result;

	cout << "Введите m" << endl;
	scanf("%d", &m);
	cout << "Введите k" << endl;
	scanf("%d", &k);

	if (k != 0) {

		_asm {
			push eax;
			push ebx;

			xor eax, eax;
			xor ebx, ebx;

			mov eax, m;
			mov edx, k;
			mov ecx, k;
		LOOPPLBL:
			sal eax, 1;
			loop LOOPPLBL;

			mov result, eax;

			pop eax;
			pop ebx;
		}
		cout << result;
	}
	else cout << m;
}

void Division() {
	int m, k, result;

	cout << "Введите m" << endl;
	scanf("%d", &m);
	cout << "Введите k" << endl;
	scanf("%d", &k);

	if (k != 0) {

		_asm {
			push eax;
			push ebx;

			xor eax, eax;
			xor ebx, ebx;

			mov eax, m;
			mov edx, k;
			mov ecx, k;
		LOOPPLBL:
			sar eax, 1;
			loop LOOPPLBL;

			mov result, eax;

			pop eax;
			pop ebx;
		}
		cout << result;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
