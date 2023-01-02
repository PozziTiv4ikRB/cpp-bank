#include "file_reader.h"
#include "constants.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;
cost convert(char* str)
{
	char tmp_buffer[MAX_STRING_SIZE];
	cost result;
	char* context = NULL;
	char* str_number = strtok_s(str, "_", &context);
	result.buy = atof(str_number);
	str_number = strtok_s(NULL, "_", &context);
	result.sell = atof(str_number);
	return result;
}


void read(const char* file_name, bank_subscription* array[], int& size)
{
	std::ifstream file(file_name);
	if (file.is_open())
	{
		size = 0;
		char tmp_buffer[MAX_STRING_SIZE];
		while (!file.eof())
		{
			bank_subscription* item = new bank_subscription;
			file >> item->bank;
			file >> tmp_buffer;
			item->costrates = convert(tmp_buffer);
			file.read(tmp_buffer, 1); // чтения лишнего символа пробела
			file.getline(item->address, MAX_STRING_SIZE);

			array[size++] = item;
		}
		file.close();
	}
	else
	{
		throw "Ошибка открытия файла";
	}
}