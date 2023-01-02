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
void siftDown(bank_subscription** report, int root, int bottom)
{
	int maxChild;
	int done = 0;

	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)
			maxChild = root * 2;
		else if (report[root * 2]->length < report[root * 2 + 1]->length)
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;

		if (report[root]->length > report[maxChild]->length)
		{

			std::swap(report[root], report[maxChild]);
			root = maxChild;
		}
		else
			done = 1;
	}
}

void InsertionSort(bank_subscription** report, int size)
{

	for (int i = (size / 2); i >= 0; i--)
		siftDown(report, i, size - 1);
	for (int i = size - 1; i >= 1; i--)
	{
		std::swap(report[0], report[i]);
		siftDown(report, 0, i - 1);
	}
}
void Quick(bank_subscription** report, int size)
{
	int mid = size / 2;
	if (size % 2 == 1)
		mid++;
	int h = 1;

	bank_subscription** c = new bank_subscription * [size];
	int step;
	while (h < size)
	{
		step = h;
		int i = 0;
		int j = mid;
		int k = 0;
		while (step <= mid)
		{
			while ((i < step) && (j < size) && (j < (mid + step)))
			{
				if (report[i]->length > report[j]->length)
				{
					c[k] = report[i];
					i++; k++;
				}
				else {
					c[k] = report[j];
					j++; k++;
				}
			}
			while (i < step)
			{
				c[k] = report[i];
				i++; k++;
			}
			while ((j < (mid + step)) && (j < size))
			{
				c[k] = report[j];
				j++; k++;
			}
			step = step + h;
		}
		h = h * 2;

		for (i = 0; i < size; i++)
			report[i] = c[i];
	}
}

void siftDown_str(bank_subscription** report, int root, int bottom)
{
	int maxChild;
	int done = 0;

	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)
			maxChild = root * 2;

		else if (strlen(report[root * 2]->bank) > strlen(report[root * 2 + 1]->bank))
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		if (strlen(report[root]->bank) < strlen(report[maxChild]->bank))
		{

			std::swap(report[root], report[maxChild]);
			root = maxChild;
		}
		else
			done = 1;
	}
}

void InsertionSort_str(bank_subscription** report, int size)
{

	for (int i = (size / 2); i >= 0; i--)
		siftDown_str(report, i, size - 1);
	for (int i = size - 1; i >= 1; i--)
	{
		std::swap(report[0], report[i]);
		siftDown_str(report, 0, i - 1);
	}
}
void Quick_str(bank_subscription** report, int size)
{
	int mid = size / 2;
	if (size % 2 == 1)
		mid++;
	int h = 1;
	bank_subscription** c = new bank_subscription * [size];
	int step;
	while (h < size)
	{
		step = h;
		int i = 0;
		int j = mid;
		int k = 0;
		while (step <= mid)
		{
			while ((i < step) && (j < size) && (j < (mid + step)))
			{
				if (strlen(report[i]->bank) < strlen(report[j]->bank))
				{
					c[k] = report[i];
					i++; k++;
				}
				else {
					c[k] = report[j];
					j++; k++;
				}
			}
			while (i < step)
			{
				c[k] = report[i];
				i++; k++;
			}
			while ((j < (mid + step)) && (j < size))
			{
				c[k] = report[j];
				j++; k++;
			}
			step = step + h;
		}
		h = h * 2;

		for (i = 0; i < size; i++)
			report[i] = c[i];
	}
}
void mess_sort(bank_subscription** report, int size)
{
	int i = 0;
	int buf;
	while (i < size)
	{
		int count = 0;
		char* mess1 = report[i]->bank;
		for (int j = 0; j < size; j++)
		{
			if (strcmp(report[j]->bank, mess1) == 0)
				count++;
		}
		if (count == 1)
			i++;
		else
		{
			buf = i;
			bank_subscription** c = new bank_subscription * [count];
			for (int j = 0; j < count; j++)
			{
				c[j] = report[buf];
				buf++;

			}
			int min;
			for (int k = 0; k < count; k++)
			{
				min = k;
				for (int j = k + 1; j < count; j++)
					if (strlen(c[j]->address) < strlen(c[min]->address))
						min = j;
				std::swap(c[k], c[min]);
			}
			for (int l = 0; l < count; l++)
			{
				report[i] = c[l];
				i++;
			}
		}
	}
}