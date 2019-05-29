#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>
#include<vector>

using namespace std;


struct Doctor
{
	std::string FirstName, SecondName, LastName;
	std::string kind_of_job, enter;

	int card_number, cost, mark, indebtedness;

	void Print()
	{
			std::cout << "First Name: ";
			std::cout << FirstName;
			std::cout << "\n";

			std::cout << "Second Name: ";
			std::cout << SecondName;
			std::cout << "\n";

			std::cout << "Last Name: ";
			std::cout << LastName;
			std::cout << "\n";

			std::cout << "Kind of job: ";
			std::cout << kind_of_job;
			std::cout << "\n";

			std::cout << "Number of a card: ";
			std::cout << card_number;
			std::cout << "\n";

			std::cout << "Cost: ";
			std::cout << cost;
			std::cout << "\n";

			std::cout << "Mark: ";
			std::cout << mark;
			std::cout << "\n";

			std::cout << "Indebtedness: ";
			std::cout << indebtedness;
			std::cout << "\n" << "\n";

	};
};

void menu(vector<Doctor> &pacient, int number);
void Save(vector<Doctor> &pacient, int number);

void Search(vector<Doctor> &pacient, int number)
{
	std::cout << "Введите нужный вид работы с пациентом." << "\n";
	string str;
	cin >> str;
	int count = 0;
	std::cout << "Выведенная информация: " << "\n";
	for (int i = 0; i < pacient.size(); i++)
	{
		if (pacient[i].kind_of_job == str)
		{
			pacient[i].Print();
			count++;
		}
	}
	if (count == 0)
		cout << "Информация не найдена";
	menu(pacient, number);
}

int Check_Number()
{
	int choice = 0;

	while (!(cin >> choice))
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Не верный ввод!!! Введите число : ";
	}
	return choice;
}

void Delete_Information(vector<Doctor> &pacient, int number)
{
	/*for (size_t i = 0; i < number; i++)
	{
		if (pacient[i].indebtedness == 0)
		{
			pacient.erase(pacient.begin() + i);
		}
	}*/

	int number1 = pacient.size();
	Save(pacient, number1);
}

void Data_Input(vector<Doctor> &pacient, int number)
{
	std::cout << "Запишите данные..." << "\n";
	std::cout << "\n";
	for (size_t i = 0; i < number; i++)
	{
		std::cout << "First Name:" << "\n";
		std::cin >> pacient[i].FirstName;
		std::cout << "\n";

		std::cout << "Second Name:" << "\n";
		std::cin >> pacient[i].SecondName;
		std::cout << "\n";

		std::cout << "Last Name:" << "\n";
		std::cin >> pacient[i].LastName;
		std::cout << "\n";

		std::cout << "Kind of job:" << "\n";
		std::cin >> pacient[i].kind_of_job;
		std::cout << "\n";

		pointer:
		std::cout << "Number of a card:" << "\n";
		pacient[i].card_number = Check_Number();
		std::cout << "\n";

		std::cout << "Cost:" << "\n";
		pacient[i].cost = Check_Number();
		std::cout << "\n";

		std::cout << "Mark:" << "\n";
		pacient[i].mark = Check_Number();
		std::cout << "\n";

		std::cout << "Indebtedness:" << "\n";
		pacient[i].indebtedness = Check_Number();
		std::cout << "\n";
	}

	Save(pacient, number);
}

void Save(vector<Doctor> &pacient, int number)
{
	std::cout << "Введите имя существующего или будущего файла..." << "\n";
	std::string name;
	std::cin >> name;
	ofstream database;
	database.open(name, std::ios::app);
	if (!database.is_open())
	{
		std::cout << "Ошибка создания/октрытия файла!" << "\n";
	}
	else
	{
		std::cout << "Успешное создание/открытие файла!" << "\n";
	}

	std::cout << "Запись информации в файл..." << "\n";
	for (size_t i = 0; i < number; i++)
	{
		std::cout << "First Name:" << "\n";
		database << pacient[i].FirstName << " ";
		std::cout << "\n";

		std::cout << "Second Name:" << "\n";
		database << pacient[i].SecondName << " ";
		std::cout << "\n";

		std::cout << "Last Name:" << "\n";
		database << pacient[i].LastName << " " << "\n";
		std::cout << "\n";

		std::cout << "Kind of job:" << "\n";
		database << pacient[i].kind_of_job << " ";
		std::cout << "\n";

		std::cout << "Number of a card:" << "\n";
		database << pacient[i].card_number << " ";
		std::cout << "\n";

		std::cout << "Cost:" << "\n";
		database << pacient[i].cost << " ";
		std::cout << "\n";

		std::cout << "Mark:" << "\n";
		database << pacient[i].mark << " ";
		std::cout << "\n";

		std::cout << "Indebtedness:" << "\n";
		database << pacient[i].indebtedness << "\n";
		std::cout << "\n";

		database << "========================" << "\n";
	}
	std::cout << "Успешная запись в файл!" << "\n";
	std::cout << "Закрытие файла" << "\n";
	database.close();
	menu(pacient, number);
}

void Data_Read(vector<Doctor> &pacient, int number)
{
	
	std::cout << "Введите название файла." << "\n" << "\n";
	std::string name;
	std::cin >> name;
	ifstream database;
	database.open(name);
	if (!database.is_open())
	{
		std::cout << "Ошибка создания/октрытия файла!" << "\n";
	}
	else
	{
		std::cout << "Успешное создание/открытие файла!" << "\n";
	}
	std::cout << "Происходит считывание информации из файла..." << "\n";

	for (size_t i = 0; i < number; i++)
	{
		database >> pacient[i].FirstName;
		
		database >> pacient[i].SecondName;
		
		database >> pacient[i].LastName;
		
		database >> pacient[i].kind_of_job;
		
		database >> pacient[i].card_number;
		
		database >> pacient[i].cost;
		
		database >> pacient[i].mark;
		
		database >> pacient[i].indebtedness;
		
		database >> pacient[i].enter;
	}
	std::cout << "Успешное считывание из файла информации" << "\n" << "\n";
	std::cout << "Выведенная информация: " << "\n";
	for (size_t i = 0; i < number; i++)
	{
		pacient[i].Print();
	}
	database.close();
	menu(pacient, number);
}

void menu(vector<Doctor> &pacient, int number)
{
	std::cout << "Что вы хотите сделать?" << "\n";
	std::cout << "1. Внести данные." << "\n";
	std::cout << "2. Считать данные." << "\n";
	std::cout << "======================================" << "\n";
	std::cout << "Возможно только после выполнения либо 1, либо 2 пункта." << "\n";
	std::cout << "3. Удалить данные." << "\n";
	std::cout << "4. Вывести данные об определенном пациенте." << "\n";
	std::cout << "5. Вывести информацию о пациентах по видам работ." << "\n";
	std::cout << "6. Вывести информацию о пациентах с задолжность." << "\n";

	int num = Check_Number();
	if (num == 1)
	{
		Data_Input(pacient, number);
	}
	else if (num == 2)
	{
		Data_Read(pacient, number);
	}
	else if (num == 3)
	{
		Delete_Information(pacient, number);
	}
	else if (num == 4)
	{
		Search(pacient, number);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Начало работы." << "\n" << "\n";
	std::cout << "Введите колличество пациентов:" << "\n";
	
	int number = Check_Number();
	vector<Doctor> pacient(number);
	
	
	menu(pacient, number);
}