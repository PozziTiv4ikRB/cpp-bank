#include <iostream>
#include "bank_subscription.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
//#include "processing.h"
using namespace std;
void output(bank_subscription* subscriptions)
{



	cout << subscriptions->bank << endl;
	cout << subscriptions->costrates.buy << " ";
	cout << subscriptions->costrates.sell << endl;
	cout << subscriptions->address << endl;
	cout << '\n';
}


int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Laboratory work #8. GIT\n";
	cout << "Variant #4. Exchange rates\n";
	cout << "Author: Michael Dyakonov\n";
	cout << "Group: 12\n";
	const char* s = "12,32";
	cout << atof(s) << endl << endl;
	bank_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
	int size;
	try
	{
		read("data.txt", subscriptions, size);
		for (int i = 0; i < size; i++)
		{
			subscriptions[i]->length = subscriptions[i]->costrates.sell - subscriptions[i]->costrates.buy;

		}
		for (int i = 0; i < size; i++)
		{
			cout << subscriptions[i]->bank << endl;
			cout << subscriptions[i]->costrates.buy << ' ';
			cout << subscriptions[i]->costrates.sell << endl;
			cout << subscriptions[i]->length << '\n';
			cout << subscriptions[i]->address << '\n';
			cout << '\n';
		}
		bool (*check_function)(bank_subscription*) = NULL;
		cout << "1)Вывести курсы валюты во всех отделениях банка «Беларусбанк»\n";
		cout << "2)Вывести курсы валюты и адреса отделений банков, в которых продажа меньше 2,5\n";
		int item;
		cin >> item;
		cout << '\n';
		switch (item)
		{
		case 1:
			check_function = check_by_bank; //
			cout << "***** Курсы валюты во всех отделениях банка «Беларусбанк» *****\n\n";
			break;
		case 2:
			check_function = check_by_sell; //
			cout << "***** Продажа меньше 2,5 *****\n\n";
			break;
		default:
			throw " ";
		}
		if (check_function)
		{
			int new_size;
			bank_subscription** filtered = filter(subscriptions, size, check_function, new_size);
			cout << "1)Пирамидальная сортировка по убыванию разницы между стоимостью продажи и покупки\n";
			cout << "2)Сортировка слияниием по убыванию разницы между стоимостью продажи и покупки \n";
			cout << "3)Пирамидальная сортировка по возрастанию названию банка\n";
			cout << "4)Сортировка слияниием по возрастанию названию банка\n";
			int sort;
			cin >> sort;
			switch (sort)
			{
			case 1:
				InsertionSort(filtered, new_size);
				break;
			case 2:
				Quick(filtered, new_size);
				break;
			case 3:
				InsertionSort_str(filtered, new_size);
				mess_sort(filtered, new_size);
				break;
			case 4:
				Quick_str(filtered, new_size);
				mess_sort(filtered, new_size);
				break;
			default:
				throw " ";
			}
			for (int i = 0; i < new_size; i++)
			{
				output(filtered[i]);
			}
			delete[] filtered;
		}
		for (int i = 0; i < size; i++)
		{
			delete subscriptions[i];
		}

	}
	catch (const char* error)
	{
		cout << error << '\n';
	}



	return 0;
}