#include "StackTest.h"
#include "IStack.h"
#include <stdio.h>

bool StackIntegerTest::RunTest()
{
	return this->RunPushTest() 
		&& this->RunPopTest() 
		&& this->RunTopTest()
		&& this->RunIsEmptyTest()
		&& this->RunItemsAmountTest();
}

bool StackIntegerTest::RunPushTest()
{
	bool result = true;

	if (this->stackToTest != nullptr)
	{
		this->stackToTest->Clear();
		this->stackToTest->Push(13);

		if (this->stackToTest->Top() == 13)
		{
			printf("Item pushed is 13, stack top is 13\n");

			this->stackToTest->Push(25);

			if (this->stackToTest->Top() == 25)
			{
				printf("Item pushed is 25, stack top is 25\n");
			}
			else
			{
				printf("Item pushed was 25. Stack top is not 25\n");
				result = false;
			}
		}
		else
		{
			printf("Item pushed was 13. Stack top is not 13\n");
			result = false;
		}
	}
	else
	{
		printf("Null stack to test pointer on stack integer push test\n");
	}

	return false;
}

bool StackIntegerTest::RunPopTest()
{
	bool result = true;

	if (this->stackToTest != nullptr)
	{
		this->stackToTest->Clear();

		this->stackToTest->Push(13);
		this->stackToTest->Push(54);
		this->stackToTest->Push(25);

		if (this->stackToTest->Pop() == 25)
		{
			printf("Last item pushed in stack was 25. Item obtained in pop was too\n");

			if (this->stackToTest->ItemsAmount() == 2)
			{
				if (this->stackToTest->Pop() == 54)
				{
					printf("Next item should be 54. Item obtained in pop was too\n");
				}
				else
				{
					printf("Next item should be 54, but item obtained in pop wasn't\n");
					result = false;
				}
			}
			else
			{
				printf("Items amount in stack is not 2\n");
				result = false;
			}
		}
		else
		{
			printf("Last item pushed in stack was 25 but item obtained in pop wasn't\n");
			result = false;
		}
	}
	else
	{
		printf("Null stack to test pointer on stack integer pop test\n");
	}

	return false;
}

bool StackIntegerTest::RunTopTest()
{
	bool result = true;

	if (this->stackToTest != nullptr)
	{
		if (this->stackToTest != nullptr)
		{
			this->stackToTest->Clear();

			this->stackToTest->Push(13);
			this->stackToTest->Push(54);
			this->stackToTest->Push(25);

			if (this->stackToTest->Top() == 25)
			{
				printf("Last item pushed in stack was 25. Item obtained in top was too\n");

				if (this->stackToTest->ItemsAmount() == 3)
				{
					printf("Items amount in stack remains constant after top\n");
				}
				else
				{
					printf("Items amount in stack is not 3 after top call\n");
					result = false;
				}
			}
			else
			{
				printf("Last item pushed in stack was 25 but item obtained in pop wasn't\n");
				result = false;
			}
		}
		else
		{
			printf("Null stack to test pointer on stack integer pop test\n");
		}
	}
	else
	{
		printf("Null stack to test pointer on stack integer top test\n");
	}

	return false;
}

bool StackIntegerTest::RunIsEmptyTest()
{
	bool result = true;

	if (this->stackToTest != nullptr)
	{
		// Clear the stack, so then it will be empty
		this->stackToTest->Clear();

		if (!stackToTest->IsEmpty())
		{
			result = false;
			printf("After Clear() the stack is not empty\n");
		}
		else
		{
			printf("After Clear() the stack is empty\n");

			// Inserting one item and checking again
			this->stackToTest->Push(55);

			if (stackToTest->IsEmpty())
			{
				result = false;
				printf("After inserting one item, the stack is still empty\n");
			}
			else
			{
				printf("After inserting one item, the stack is not empty\n");
			}
		}
	}
	else
	{
		printf("Null stack to test pointer on stack integer is empty test\n");
	}

	return false;
}

bool StackIntegerTest::RunItemsAmountTest()
{
	bool result = true;

	if (this->stackToTest != nullptr)
	{
		// Clear the stack, so then it will be empty
		this->stackToTest->Clear();

		if (stackToTest->ItemsAmount() != 0)
		{
			result = false;
			printf("After Clear() the stack contains some items. Test failed\n");
		}
		else
		{
			printf("After Clear() the stack contains zero items\n");

			// Inserting one item and checking again
			this->stackToTest->Push(55);

			if (stackToTest->ItemsAmount() != 1)
			{
				result = false;
				printf("After inserting one item, the stack items amount is different from 1\n");
			}
			else
			{
				printf("After inserting one item, the stack items amount is one\n");
			}
		}
	}
	else
	{
		printf("Null stack to test pointer on stack integer items amount test\n");
	}

	return false;
}

StackIntegerTest::StackIntegerTest(IStack<int>* stack)
{
	this->stackToTest = stack;
}

StackIntegerTest::~StackIntegerTest()
{
	if (this->stackToTest != nullptr)
		delete this->stackToTest;
}

void StackIntegerTest::Run()
{
	if (this->RunTest())
	{
		printf("Stack integer test succeed\n");
	}
	else
	{
		printf("Stack integer test failed\n");
	}
}
