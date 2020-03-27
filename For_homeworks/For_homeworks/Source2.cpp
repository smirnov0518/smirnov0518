#include<iostream>
#include <math.h>
#include <ctime>
#include <string>
#include <list>
#include<fstream>
#include "Partners.h"
using namespace std;
// 5 hours +8,5h

int main()
{
	int choise = 0;
	do {
		choise = init(); // повторюємо введення допоки не буде знайдено файл (поки ініт не поверне 0)
	} while (choise);

	do {
		cout << "1. Add a partner \n2. Redact \n3. Delete a partner \n4. Search\n5. Save changes\n0. Exit\n";
		cin >> choise;
		system("cls");
		switch (choise) {

		case 1: {
			adding(1,0);
			break;
		}
		case 2: {
			redact();
			break;
		}
		case 3: {
			deleting();
			break;
		}
		case 4: {
			searching();
			break;
		}
		case 5: {
			exit_init(0);
		}
		}

	} while (choise != 0);
	exit_init(1);





	system("pause");
	return 0;
}