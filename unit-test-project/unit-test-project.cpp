#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/bank_subscription.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	bank_subscription* build_subscription(double buy, double sell)
	{
		bank_subscription* subscription = new bank_subscription;
		subscription->costrates.buy = buy;
		subscription->costrates.sell = sell;
		return subscription;
	}
	void delete_subscription(bank_subscription* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}



	TEST_CLASS(unittestproject)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			bank_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(2, 3.2); // 1.2
			subscriptions[1] = build_subscription(3, 4.1); // 1.1
			subscriptions[2] = build_subscription(2, 4.5); // 2.5
			Assert::AreEqual(2.5, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);



		}
	};
}