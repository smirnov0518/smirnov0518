#include "Bonus_tasks.h"
#include<Windows.h>
void converting_text()
{
	fstream key("key.txt");
	fstream text("text.txt", std::ios::app);
	fstream("text.txt", fstream::out);
	string bufer="";
	string comparison;
	string from_key;
	cout << "Enter text: ";
	getline(cin, bufer);
	int j = 0;
	for (int i = 0;; i++) {
		bool result = 1;

		if (bufer[i] == 32 || bufer[i] == '\0') {  // ���� ������� ����� �� ������, ��� �� ������ ����� �� ��������� ��������
			key.seekg(0);   
			while (!key.eof()) {

				key >> from_key;
				if (comparison == from_key) {   
					result = 0;
					break;
				}
			}
			if (result) {
				text << comparison << " ";  //���� ����� ��� �������, �� �������� � � ����� � ���-������ �� ������ �������� �����
			}
			else {
				for (int f = 1; f < j; f++) {   // ������ �������� �� ������ �� ����� ����� ������������� �����
					text << "*";
				}
				text << " ";
			}
			comparison = "";
			j = 0;
		}
		else comparison += bufer[i];
		j++;
		if (bufer[i] == '\0')break;
	}
	text.close();
	key.close();
	fstream result("text.txt");   // ���� �������������� ������ � �����
	while (!result.eof()) {
		result>>bufer;
		if (bufer == "")break;
		cout << bufer<<" ";
		bufer = "";
	}
	cout << endl;
	
	result.close();
	
	
}

void translyt() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // ������� ��� ���������� �������� � �����
	int temp = 0;
	string bufer = "", name = "";
	char key[4] = {};
	cout << "Write the text: ";
	
	getline(cin, bufer);
	cout << "ru-en press 1\nen-ru press 0\n";
	cin >> temp;
	if (temp)name = "ru-en.txt"; // ���� ���==1 �� ��������� ������ �������, ������ ���-���������
	else name = "en-ru.txt";


		fstream tran_text(name);   // ��������� ������� �������������
		for (int i = 0;bufer[i]!='\0'; i++) {
			if (bufer[i] == 32) { // ����� �� ��� ������ ������, ������� �� ���� ������
				cout << " ";
				continue;
			}
			tran_text.seekg(0);
			while (!tran_text.eof()) {
				tran_text >> key;
				if (key[0] == bufer[i]) { // ���� ���� � �������� �������� � ������ � ������, �������� ���� �������� � ��������
					tran_text >> key;
					cout << key;
					memset(key, 0, 4);  // ������� ����� �������
					break;
				}
				memset(key, 0, 4);
			}
		}

		cout << endl << endl;
		tran_text.close();

}

