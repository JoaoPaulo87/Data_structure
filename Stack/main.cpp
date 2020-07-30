#pragma once

#include <iostream>

void StackTest();
void IntegerStackTest();
void CharStackTest();

template<typename ItemType>
class Stack
{
private:
	ItemType* stack;
	int indexTop;
	int stackSize;

private:
	void InsertValue(const ItemType& value);
	void ShowValue();
	void IncreaseStackSize();
	void DecreaseStackSize();
	bool IsEmpty() const;
	ItemType& Top();
	int& Size();

public:
	void Push(const ItemType& value);
	ItemType Pop();
	Stack();
	Stack(const Stack& other);
	~Stack();
	Stack& operator= (const Stack& other);
};

int main()
{
	StackTest();

	return 0;
}

template<typename ItemType>
void Stack<ItemType>::IncreaseStackSize()
{
	printf("At the beggining this is the stackSize %d\n", this->Size());
	this->stackSize++;
	printf("After increasing the stackSize %d\n", this->Size());
}

template<typename ItemType>
int& Stack<ItemType>::Size()
{
	return this->stackSize;
}

template<typename ItemType>
Stack<ItemType>& Stack<ItemType>::operator= (const Stack& other)
{
	// Just in case I asign an object to itself like other = other
	if (this == &other)
	{
		return *this;
	}

	this->indexTop = other.indexTop;
	this->stackSize = other.stackSize;

	for (int index = 0; index < other.stackSize; index++)
	{
		this->stack[index] = other.stack[index];
	}

	return *this;
}

template<typename ItemType>
Stack<ItemType>::~Stack()
{
	if (this->stack != nullptr)
	{
		delete[] this->stack;
		this->stack = nullptr;
	}
}

template<typename ItemType>
Stack<ItemType>::Stack()
{
	this->indexTop = 0;
	this->stackSize = 0;
	this->stack = new ItemType[this->stackSize];
}

template<typename ItemType>
Stack<ItemType>::Stack(const Stack& other)
{
	this->indexTop = other.indexTop;
	this->stackSize = other.stackSize;

	for (int index = 0; index < other.stackSize; index++)
	{
		this->stack[index] = other.stack[index];
	}
}

template<typename ItemType>
void Stack<ItemType>::ShowValue()
{
	for (int index = 0; index < this->stackSize; index++)
	{
		std::cout << "The value of the stack is : " << this->stack[index] << std::endl;
	}

	printf("\n");
}

template<typename ItemType>
void Stack<ItemType>::InsertValue(const ItemType& value)
{
	ItemType* newStack = new ItemType[this->stackSize];

	for (int index = 0; index < this->stackSize; index++)
	{
		newStack[index] = this->stack[index];
	}

	delete[] this->stack;
	// With this, the pointer "stack" is pointing to the adress of "newStack".
	stack = newStack;

	this->stack[this->indexTop] = value;

	std::cout << "The value : " << Top() << " was inserted in the stack" << std::endl;
}

template<typename ItemType>
void Stack<ItemType>::Push(const ItemType& value)
{
	this->IncreaseStackSize();
	this->InsertValue(value);
	this->ShowValue();
	this->indexTop++;
}

template<typename ItemType>
ItemType& Stack<ItemType>::Top()
{
	return this->stack[this->indexTop];
}

template<typename ItemType>
bool Stack<ItemType>::IsEmpty() const
{
	return this->stackSize == 0;
}

template<typename ItemType>
ItemType Stack<ItemType>::Pop()
{
	printf("POP Function called\n");

	DecreaseStackSize();
	this->ShowValue();

	return Top();
}

template<typename ItemType>
void Stack<ItemType>::DecreaseStackSize()
{
	if (!IsEmpty() && this->stackSize > -1)
	{
		this->indexTop--;
		std::cout << "The last value was poped out: " << Top() << std::endl;

		printf("At the beggining this is the stackSize %d\n", this->Size());
		this->stackSize--;
		printf("After decreasing the stackSize %d\n", this->Size());

		ItemType* newStack = new ItemType[this->stackSize];

		for (int index = 0; index < this->stackSize; index++)
		{
			newStack[index] = this->stack[index];
		}

		delete[] this->stack;

		stack = newStack;
	}
	else
	{
		printf("There's no more values to pop out\n");
	}
}

void StackTest()
{
	IntegerStackTest();
	//CharStackTest();
}

void IntegerStackTest()
{
	Stack<int>* st = new Stack<int>();
	int num1 = 0;

	st->Push(5);
	st->Push(3);
	st->Push(9);
	st->Push(7);
	st->Pop();
	st->Push(4);
	st->Push(1);
	st->Pop();
	st->Pop();
	st->Pop();
	st->Pop();
	st->Pop();
	st->Pop();
	st->Pop();

	delete st;
}

void CharStackTest()
{
	Stack<char>* st = new Stack<char>();
	char ch = 'a';

	st->Push('a');
	st->Push('b');
	st->Push('c');
	st->Push('d');
	st->Pop();
	st->Push('e');
	st->Push('f');
	st->Pop();
	st->Pop();
	st->Pop();
	st->Pop();
	st->Pop();
	st->Pop();
	st->Pop();

	delete st;
}
