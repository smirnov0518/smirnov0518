#include<iostream>
#include <math.h>
#include <ctime>
#include <string>
#include <list>
#include<fstream>
#include "Partners.h"
#include"Bonus_tasks.h"
using namespace std;

int main()
{
	/*converting_text();*/
	/*translyt();*/

	

	int choise = 0;   
	
	init(); 
	

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
	exit_init(0);
	exit_init(1);





	system("pause");
	return 0;
}