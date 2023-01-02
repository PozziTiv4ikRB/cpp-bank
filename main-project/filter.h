#ifndef FILTER_H
#define FILTER_H
#include "bank_subscription.h"
bank_subscription** filter(bank_subscription* array[], int size, bool (*check)(bank_subscription* element), int& result_size);
bool check_by_bank(bank_subscription* element);
bool check_by_sell(bank_subscription* element);
void siftDown(bank_subscription** report, int root, int bottom);
void InsertionSort(bank_subscription** report, int size);
void Quick(bank_subscription** report, int size);
void siftDown_str(bank_subscription** report, int root, int bottom);
void InsertionSort_str(bank_subscription** report, int size);
void Quick_str(bank_subscription** report, int size);
void mess_sort(bank_subscription** report, int size);
#endif