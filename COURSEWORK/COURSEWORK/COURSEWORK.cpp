#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

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

void menu(vector<Doctor> &pacient, int number, int password);
void Save(vector<Doctor> &pacient, int number, int password);
void Data_Input(vector<Doctor> &pacient, int number, int password);
int Check_Number();

void Save_new_data(vector<Doctor> &pacient, vector<Doctor> &pacient2, int final_size, int password)
{
	system("cls");
	std::cout << "Добавление новых записей..." << "\n";
	for (size_t i = 0; i < final_size; i++)
	{
		pacient.push_back(pacient[i]);
	}
	std::cout << "Записи добавлены!" << "\n";
	for (size_t i = 0; i < final_size; i++)
	{
		pacient[i].Print();
	}

	std::cout << "Вы хотите записать информацию в файл?" << "\n";
	std::cout << "1. Да" << "\n";
	std::cout << "2. Нет" << "\n";
	int choice = Check_Number();
	if (choice == 1)
	{
		std::cout << "Сохранение в файл. Введите имя существующего или будущего файла..." << "\n";
		std::string name;
		std::cin >> name;
		ofstream database;
		database.open(name, ios::app);
		if (!database.is_open())
		{
			std::cout << "Ошибка создания/октрытия файла!" << "\n";
		}
		else
		{
			system("cls");
			std::cout << "Успешное создание/открытие файла!" << "\n";
		}

		std::cout << "Запись информации в файл..." << "\n";
		for (size_t i = 0; i < final_size; i++)
		{
			database << pacient[i].FirstName << " ";

			database << pacient[i].SecondName << " ";

			database << pacient[i].LastName << " " << "\n";

			database << pacient[i].kind_of_job << " ";

			database << pacient[i].card_number << " ";

			database << pacient[i].cost << " ";

			database << pacient[i].mark << " ";

			database << pacient[i].indebtedness << "\n";

			database << "========================" << "\n";
		}
		std::cout << "Успешная запись в файл!" << "\n";
		std::cout << "Закрытие файла" << "\n";
		database.close();
		menu(pacient, final_size, password);
	}
	else if (choice == 2)
	{
		std::cout << "Продолжение работы..." << "\n";
	}	
}

void Add_Information(vector<Doctor> &pacient, int password)
{
	std::cout << "Сколько нужно добавить?" << "\n";
	int choice = Check_Number();
	vector<Doctor> pacient2(choice);
	Data_Input(pacient2, choice, password);
	int final_size = pacient2.size() + pacient.size();
	Save_new_data(pacient, pacient2, final_size, password);
}

void Search_mark(vector<Doctor> &pacient, int number, int password)
{
	std::cout << "Введите примерную отметку об оплате." << "\n";
	std::cout << "(введенная отметка об оплате не должна быть меньшей, чем 200)" << "\n";
	int mark = Check_Number();
	int count = 0;
	std::cout << "Выведенная информация: " << "\n";
	for (int i = 0; i < pacient.size(); i++)
	{
		if (pacient[i].mark >= mark - 200 && pacient[i].mark <= mark + 200)
		{
			pacient[i].Print();
			count++;
		}
	}
	if (count == 0)
		cout << "Информация не найдена";
	menu(pacient, number, password);
}

void Search_cost(vector<Doctor> &pacient, int number, int password)
{
	std::cout << "Введите примерную стоимость выполненой работы." << "\n";
	std::cout << "(введенная стоимость не должна быть меньшей, чем 500)" << "\n";
	int cost = Check_Number();
	int count = 0;
	std::cout << "Выведенная информация: " << "\n";
	for (int i = 0; i < pacient.size(); i++)
	{
		if (pacient[i].cost >= cost - 500 && pacient[i].cost <= cost + 500)
		{
			pacient[i].Print();
			count++;
		}
	}
	if (count == 0)
		cout << "Информация не найдена";
	menu(pacient, number, password);
}

void Search_indebtedness(vector<Doctor> &pacient, int number, int password)
{
	std::cout << "Поиск пациентов с задолжностью по оплате." << "\n";
	int count = 0;
	std::cout << "Выведенная информация: " << "\n";
	for (int i = 0; i < pacient.size(); i++)
	{
		if (pacient[i].indebtedness == 0)
		{
			pacient[i].Print();
			count++;
		}
	}
	if (count == 0)
		cout << "Информация не найдена!" << "\n";
	menu(pacient, number, password);
}

void Search_Name(vector<Doctor> &pacient, int number, int password)
{
	std::cout << "Введите фамилию нужного пациента." << "\n";
	string str;
	cin >> str;
	int count = 0;
	std::cout << "Выведенная информация: " << "\n";
	for (int i = 0; i < pacient.size(); i++)
	{
		if (pacient[i].LastName == str)
		{
			pacient[i].Print();
			count++;
		}
	}
	if (count == 0)
		cout << "Информация не найдена";
	menu(pacient, number, password);
}

void Search_Kind(vector<Doctor> &pacient, int number, int password)
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
	menu(pacient, number, password);
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

void Delete_Information(vector<Doctor> &pacient, int number, int password)
{
	std::cout << "Поиск пациентов без задолжности..." << "\n";
	for (size_t i = 0; i < number; i++)
	{
		if (pacient[i].indebtedness == 0)
		{
			std::cout << "Удаление найденного пациента из списка..." << "\n";
			pacient.erase(pacient.begin() + i);
			std::cout << "Готово!" << "\n";
			break;
		}
	}
	
pointer2:
	std::cout << "Записи удалены. Продолжить?" << "\n";
	std::cout << "1. Да" << "\n";
	int choice = Check_Number();
	if (choice == 1)
	{
		system("cls");
		std::cout << "Обновленная информация: " << "\n";
		for (int i = 0; i < pacient.size(); i++)
		{
			pacient[i].Print();
		}
	}
	else
	{
		system("cls");
		std::cout << "Некорректный ввод! Сделайте выбор еще раз" << "\n";
		goto pointer2;
	}
	int number1 = pacient.size();
	Save(pacient, number1, password);
}

void Data_Input(vector<Doctor> &pacient, int number, int password)
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
		system("cls");
	
	}
	
	std::cout << "Вы хотите записать информацию в файл?" << "\n";
	std::cout << "1. Да" << "\n";
	std::cout << "2. Нет" << "\n";
	int choice = Check_Number();
	if (choice == 1)
	{
		Save(pacient, number, password);
	}
	else if (choice == 2)
	{
		std::cout << "Продолжение работы..." << "\n";
	}	
}

void Save(vector<Doctor> &pacient, int number, int password)
{
	std::cout << "Сохранение в файл. Введите имя существующего или будущего файла..." << "\n";
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
		system("cls");
		std::cout << "Успешное создание/открытие файла!" << "\n";
	}

	std::cout << "Запись информации в файл..." << "\n";
	for (size_t i = 0; i < number; i++)
	{
		database << pacient[i].FirstName << " ";
		
		database << pacient[i].SecondName << " ";
		
		database << pacient[i].LastName << " " << "\n";

		database << pacient[i].kind_of_job << " ";
	
		database << pacient[i].card_number << " ";
		
		database << pacient[i].cost << " ";
		
		database << pacient[i].mark << " ";
		
		database << pacient[i].indebtedness << "\n";

		database << "========================" << "\n";
	}
	std::cout << "Успешная запись в файл!" << "\n";
	std::cout << "Закрытие файла" << "\n";
	database.close();
	menu(pacient, number, password);
}

void Data_Read(vector<Doctor> &pacient, int number, int password)
{
	
	std::cout << "Введите название файла." << "\n" << "\n";
	std::string name;
	std::cin >> name;
	ifstream database;
	database.open(name);
	if (!database.is_open())
	{
		system("cls");
		std::cout << "Ошибка создания/октрытия файла!" << "\n";
	}
	else
	{
		system("cls");
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
	menu(pacient, number, password);
}

void menu(vector<Doctor> &pacient, int number, int password)
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
	std::cout << "7. Вывести информацию по отметке об оплате." << "\n";
	std::cout << "8. Вывести информацию по стоимости услуг." << "\n";
	std::cout << "9. Добавить информацию и сохранить данные." << "\n";

	int num = Check_Number();
	if (num == 1)
	{
		system("cls");
		Data_Input(pacient, number, password);
	}
	else if (num == 2)
	{
		system("cls");
		Data_Read(pacient, number, password);
	}
	else if (num == 3)
	{
		system("cls");
		
pointer:
		std::cout << "Введите указанный ранее пароль для редактирования записей." << "\n";
		int password1 = Check_Number();
		if (password1 == password)
		{
			system("cls");
			std::cout << "Вы ввели верный пароль. Продолжение работы..." << "\n";
			Delete_Information(pacient, number, password);
		}
		else
		{
			system("cls");
			std::cout << "Неверный пароль. Повторите попытку еще раз." << "\n";
			goto pointer;
		}
	}
	else if (num == 4)
	{
		system("cls");
		Search_Name(pacient, number, password);
	}
	else if (num == 5)
	{
		system("cls");
		Search_Kind(pacient, number, password);
	}
	else if (num == 6)
	{
		system("cls");
		Search_indebtedness(pacient, number, password);
	}
	else if (num == 7)
	{
		system("cls");
		Search_mark(pacient, number, password);
	}
	else if (num == 8)
	{
		system("cls");
		Search_cost(pacient, number, password);
	}
	else if (num == 9)
	{
		system("cls");

pointer2:
		std::cout << "Введите указанный ранее пароль для редактирования записей." << "\n";
		int password1 = Check_Number();
		if (password1 == password)
		{
			system("cls");
			std::cout << "Вы ввели верный пароль. Продолжение работы..." << "\n";
			Add_Information(pacient, password);
		}
		else
		{
			system("cls");
			std::cout << "Неверный пароль. Повторите попытку еще раз." << "\n";
			goto pointer2;
		}
		
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Начало работы." << "\n" << "\n";

	std::cout << "!СПРАВКА ПО РАБОТЕ С ПРОГРАММОЙ!" << "\n";
	std::cout << "1. После запуска программы, выберите количество пациентов, которое вы хотите занести в базу и нажмите Enter." << "\n";
	std::cout << "2. Запомните пароль, который сгенерирует программа после ввода количества пациентов." << "\n";
	std::cout << "3. При переносе в главное меню Вы можете сделать выбор: записать данные в файл или считать данные из файла." << "\n" << "Пока один из этих пунктов не будет выбран и информация не будет считана в программе - НЕ ВЫБИРАТЬ пункты 3-9." << "\n";
	std::cout << "4. После считывания или внесения данных в базу данных, открывается доступ к редактированию, а так же поиску информации в базе данных." << "\n";
	std::cout << "5. Файл, в который будет записываться или же считываться информация, находится в папке CORSEWORK." << "\n";
	std::cout << "6. Убедительная просьба указывать формат файла в его названии. На пример, final.txt." << "\n";
	std::cout << "Вполне допускается ввод названия файла и без его формата, но в таком случае, при попытке открыть файл, нужно вручную открыть его, нажав ОТКРЫТЬ С ПОМОЩЬЮ -> БЛОКНОТ" << "\n";
	std::cout << "Выполнил курсовую работу студент группы AT-182 Курпол Владислав. Преподователь: Сперанский В.А." << "\n";

	std::cout << "Вы хотите начать работу с программой?" << "\n";
	std::cout << "1. Да" << "\n";
	std::cout << "2. Нет" << "\n";
	int choice = Check_Number();
	if (choice == 1)
	{
		std::cout << "Продолжение работы..." << "\n";
	}
	else if (choice == 2)
	{
		std::cout << "Конец работы..." << "\n";
		system("pause");
		return 0;
	}
	
	std::cout << "Введите колличество пациентов:" << "\n";
	
	int number = Check_Number();
	vector<Doctor> pacient(number);

	srand(time(0)); // автоматическая рандомизация

	int password = rand();
	cout << "Код для изменения данных: " << password << endl;

	
	menu(pacient, number, password);
}