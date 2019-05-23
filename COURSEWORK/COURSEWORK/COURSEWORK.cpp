#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Doctor
{
	std::string FirstName, SecondName, LastName;
	std::string kind_of_job, enter;
	

	int card_number, cost, mark, indebtedness;
};

void menu(Doctor *pacient, int number);

int Check_Number(Doctor *pacient, int number)
{
	char choice;
	int num;

	pointer:
	std::cin >> choice;

	if (choice < '0' || choice > '9')
	{
		system("cls");
		std::cerr << "Неверный ввод! Введите еще раз!" << "\n";
		goto pointer;
	}

	num = choice - '0';
	return num;
}

void Data_Input(Doctor *pacient, int number)
{
	std::cout << "Введите имя существующего или будущего файла..." << "\n";
	std::string name;
	std::cin >> name;
	ofstream database;
	database.open(name);
	if (!database.is_open())
	{
		std::cout << "Ошибка создания/октрытия файла!" << "\n";
	}
	else
	{
		std::cout << "Успешное создание/открытие файла!" << "\n";
	}

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
		std::cin >> pacient[i].card_number;
		std::cout << "\n";

		std::cout << "Cost:" << "\n";
		std::cin >> pacient[i].cost;
		std::cout << "\n";

		std::cout << "Mark:" << "\n";
		std::cin >> pacient[i].mark;
		std::cout << "\n";

		std::cout << "Indebtedness:" << "\n";
		std::cin >> pacient[i].indebtedness;
		std::cout << "\n";
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
}

void Data_Read(Doctor *pacient, int number)
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
		std::cout << "First Name:" << "\n";
		database >> pacient[i].FirstName;
		std::cout << "\n";

		std::cout << "Second Name:" << "\n";
		database >> pacient[i].SecondName;
		std::cout << "\n";

		std::cout << "Last Name:" << "\n";
		database >> pacient[i].LastName;
		std::cout << "\n";

		std::cout << "Kind of job:" << "\n";
		database >> pacient[i].kind_of_job;
		std::cout << "\n";

		std::cout << "Number of a card:" << "\n";
		database >> pacient[i].card_number;
		std::cout << "\n";

		std::cout << "Cost:" << "\n";
		database >> pacient[i].cost;
		std::cout << "\n";

		std::cout << "Mark:" << "\n";
		database >> pacient[i].mark;
		std::cout << "\n";

		std::cout << "Indebtedness:" << "\n";
		database >> pacient[i].indebtedness;
		std::cout << "\n";

		database >> pacient[i].enter;
	}
	std::cout << "Успешное считывание из файла информации" << "\n";

	std::cout << "Выведенная информация: " << "\n";
	for (size_t i = 0; i < number; i++)
	{
		std::cout << "First Name: " ;
		std::cout << pacient[i].FirstName;
		std::cout << "\n";

		std::cout << "Second Name: ";
		std::cout << pacient[i].SecondName;
		std::cout << "\n";

		std::cout << "Last Name: ";
		std::cout << pacient[i].LastName;
		std::cout << "\n";

		std::cout << "Kind of job: ";
		std::cout << pacient[i].kind_of_job;
		std::cout << "\n";

		std::cout << "Number of a card: ";
		std::cout << pacient[i].card_number;
		std::cout << "\n";

		std::cout << "Cost: ";
		std::cout << pacient[i].cost;
		std::cout << "\n";

		std::cout << "Mark: ";
		std::cout << pacient[i].mark;
		std::cout << "\n";

		std::cout << "Indebtedness: ";
		std::cout << pacient[i].indebtedness;
		std::cout << "\n";
	}

}

void menu(Doctor *pacient, int number)
{
	std::cout << "Что вы хотите сделать?" << "\n";
	std::cout << "1. Внести данные." << "\n";
	std::cout << "2. Считать данные." << "\n";
	std::cout << "3. Удалить данные." << "\n";
	std::cout << "4. Вывести данные об определенном пациенте." << "\n";
	std::cout << "5. Вывести информацию о пациентах по видам работ." << "\n";
	std::cout << "6. Вывести информацию о пациентах с задолжность." << "\n";

	int num = Check_Number(pacient, number);
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
		Data_Read(pacient, number);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Начало работы." << "\n" << "\n";
pointer:
	std::cout << "Введите колличество пациентов:" << "\n";
	char choice_in_start;
	std::cin >> choice_in_start;

	int number;

	if (choice_in_start < '0' || choice_in_start > '9') {
		system("cls");
		std::cerr << "Неверный ввод!";
		goto pointer;
	}
	number = choice_in_start - '0';

	Doctor *pacient = new Doctor[number];

	menu(pacient, number);
}