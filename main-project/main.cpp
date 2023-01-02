#include <iostream>
#include "bank_subscription.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
//#include "processing.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #4. Exchange rates\n";
    cout << "Author: Michael Duakonov\n";
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