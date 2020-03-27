#include "Partners.h"
#pragma once

int count = 0;
part* partner=new part[count];
string filename;
string name = "";
void temping(bool mode,int ind) //
{
	/*mode �������� ���������� (1), ��� ���������� (0) ����� ������, ��������� ����������
	��� �������� ������� �������� �� �������� ind */

	int change = 0;
	if (!mode)change = -1;
	else change = 1;
	part* temp = new part[count+change];
	for (int i = 0; i < count; i++) {
		if (i>=ind && !mode) {             //���� ���=0 ���������� ������� ������� ���� ����� ��������
			if (i == count - 1)break;     // �������� � �������� �������� ��� �� ����� �� ��� ������
			temp[i] = partner[i + 1];
		}
		else temp[i] = partner[i];
	}
	count+=change;
	partner = new part[count];
	for (int i = 0; i < count; i++) {
		partner[i] = temp[i];
	}

	delete[] temp;
}


int init()
{
	cout << "Enter file name: ";
	cin >> filename;
	filename += ".txt";       // �������� ������� ����� ��� ����������
	fstream fs(filename);
	if (!fs) {
		cout << "Not found!" << endl;
		return 1;  
	}

	part temp;
	string buff = "";
	while (!fs.eof()) {
		buff = "";
		fs >> buff;
		if (buff == "")break;

		temping(1, 0);            //��������� ������ ������ �� 1
		temp.surname=buff;
		fs >> temp.name;
		fs >> temp.age;
		fs >> temp.work;
		fs >> temp.id;
		partner[count - 1] = temp;
	}
	fs.close();
	return 0;
}

void adding(int mode,int ind) // ������� ����������� ���� ��������� ��������� �� ����, ������ ���� � ������ ������
{								// ���� ������ ���� ���(1) ��������� ������ ����������, ���(0) ����������� ������� ����������
	string for_id = "";
	bool control = 1;
	int index = 0;

	if (mode)temping(1, 0);
	if(!mode)index = ind;
	else index = count - 1;
	cin.ignore();
	getline(cin,partner[index].surname);
	cout << "And surname: ";
	getline(cin, partner[index].surname);
	cout << "Enter name: ";
	getline(cin, partner[index].name);
	cout << "Age: ";
	getline(cin, partner[index].age);
	cout << "Profession: ";
	getline(cin, partner[index].work);
	cout << "And yout ID: ";
	do {
		getline(cin, for_id);
		control = 1;
		for (int i = 0; i < count; i++) {         // �������� �� ������ ���
			if (for_id == partner[i].id) {
				cout << "This ID already exist! Create another ID: ";
				control = 0;
			}
		}
	} while (!control);
	partner[index].id = for_id;
}

void exit_init(bool mode) //��� �������� ��� �� ��� ��������� �������� ����� ��� ����� ���
{
	fstream fs(filename);
	fstream(filename, fstream::out);   //���� �������� ���������� �� �������� �� �����, ���� ������ ���� ����� �������
	for (int i = 0; i < count;i++) { 
		fs << partner[i].surname<<endl;
		fs << partner[i].name<<endl;
		fs << partner[i].age << endl;
		fs << partner[i].work << endl;
		fs << partner[i].id << endl;
	}
	fs.close();
	if(mode)delete[] partner; //  ���� ����� � ���� ������� �� ��� ��������� �������� �� ���������� �� ����� ��������
							//	��� ����� �� ���������
}

void redact() {
	string for_id;
	bool control = 0;
	cout << "Enter ID: ";
	cin >> for_id;
	for (int i = 0; i < count;i++) {
		if (partner[i].id == for_id) {
			adding(0, i);                   // ������ ������� ��������� ���� ��� ��������
			control = 1;
		}
	}
	if (!control) cout << "Not found!" << endl;
}

void deleting() {
	string bufer;
	bool chek = 0;
	cout << "Enter id: ";
	cin >> bufer;
	for (int i = 0; i < count; i++) {
		if (bufer == partner[i].id) {
			temping(0, i);
			chek = 1;
		}
	}
	if (!chek)cout << "Not found!" << endl;
}

void searching() {
	string bufer = "";
	
	bool control = 0;

	cout << "Enter age or first letter of surname: ";   
	cin >> bufer;
	
	for (int i = 0; i < count; i++) {
		if (bufer == partner[i].age || bufer[0] == partner[i].surname[0]) {
			cout << "Name:\t\t" << partner[i].name << endl;
			cout << "Surname:\t" << partner[i].surname << endl;
			cout << "Age:\t\t" << partner[i].age << endl;
			cout << "Posision:\t" << partner[i].work << endl;
			control = 1;
		}
	}
	if (!control) {
		cout << "Not found!" << endl;
		return;
	}
	cout << "Save founded information? (1-yes/0-no) ";     // ��������� �� ���������� �������� ����������
	cin >> control;
	if (!control)return;
		
		cout << "Create name for your file: ";
		cin >> name;
		name += ".txt";
		std::ofstream ff;
		ff.open(name);
		if (!ff.is_open()) {
			cout << "Wrong name!" << endl;
			return;
		}
		for (int i = 0; i < count; i++) {
			if (bufer == partner[i].age || bufer[0] == partner[i].surname[0]) {
					ff << partner[i].surname << endl;
					ff << partner[i].name << endl;
					ff << partner[i].age << endl;
					ff << partner[i].work << endl;
					ff << partner[i].id << endl;
			}
		}
		ff.close();
}
