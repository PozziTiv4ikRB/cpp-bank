#ifndef BOOK_SUBSCRIPTION_H
#define BOOK_SUBSCRIPTION_H

#include "constants.h"


struct cost
{
    double buy;
    double sell;
};

struct bank_subscription
{
    char bank[MAX_STRING_SIZE];
    cost costrates;
    char address[MAX_STRING_SIZE];
    double length;
};

#endif#pragma once