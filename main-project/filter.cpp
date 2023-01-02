#include "filter.h"
#include "bank_subscription.h"
#include <cstring>
#include <fstream>
bank_subscription** filter(bank_subscription* array[], int size, bool (*check)(bank_subscription* element), int& result_size)
{
	bank_subscription** result = new bank_subscription * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}
bool check_by_bank(bank_subscription* element)
{
	return strcmp(element->bank, "Беларусбанк") == 0;

}
bool check_by_sell(bank_subscription* element)
{
	return element->costrates.sell < 2.5;
}