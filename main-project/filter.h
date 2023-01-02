#ifndef FILTER_H
#define FILTER_H
#include "bank_subscription.h"
bank_subscription** filter(bank_subscription* array[], int size, bool (*check)(bank_subscription* element), int& result_size);
bool check_by_bank(bank_subscription* element);
bool check_by_sell(bank_subscription* element);
#endif
