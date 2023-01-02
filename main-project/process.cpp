#include "processing.h"
#include <iostream>
#include "bank_subscription.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
using namespace std;

double process(bank_subscription* protocol[], double size)
{
	double max;
	for (int i = 0; i < size; i++)
	{
		protocol[i]->length = protocol[i]->costrates.sell - protocol[i]->costrates.buy;

	}
	max = protocol[0]->length;
	for (int i = 0; i < size; i++)
	{
		if (max < protocol[i]->length)
		{
			max = protocol[i]->length;
		}
	}
	return max;
}