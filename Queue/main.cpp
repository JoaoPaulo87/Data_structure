#pragma once
#include <iostream>

#define TYPE int

class Queue
{
private:
	int size;
	TYPE indexLast;
	TYPE* queue;
	void PrintResult() const;

public:
	bool IsEmpty() const;
	unsigned int Size() const;
	TYPE FirstElement() const; 
	Queue();
	Queue(const Queue& other);
	~Queue();
	friend std::ostream& operator<<(std::ostream& os, const Queue& sourceObject);
	Queue& operator=(const Queue& other);
	void Push(const TYPE& value);
	TYPE Pop();
};

int main()
{
	// The functions FirstElement(), Size() and IsEmpty() are public just for testing.

	Queue q;

	q.Push(5);
	q.Push(9);
	q.Push(11);
	printf("The first element is %d\n", q.FirstElement()); 
	printf("\n");

	q.Pop();
	q.Pop();
	q.Pop();
	q.Pop();
	printf("The size is : %d\n", q.Size());
	printf("The is empty? %d\n", q.IsEmpty());
	printf("\n");

	return 0;
}

void Queue::Push(const TYPE& value)
{
	printf("The size before add is : %d\n", Size());
	this->size++;
	printf("The size after add is : %d\n", Size());

	TYPE* newQueue = new TYPE[this->size];

	for (int index = 0; index < this->size; index++)
	{
		newQueue[index] = this->queue[index];
	}

	delete[] this->queue;

	this->queue = newQueue;

	this->queue[indexLast] = value;
	printf("Value inserted : %d\n", this->queue[indexLast]);

	this->indexLast++;

	printf("\n");
}

Queue::Queue()
{
	this->size = 0;
	this->queue = new int[size];
	this->indexLast = 0;
}

Queue::Queue(const Queue& sourceObject)
{
	this->indexLast = sourceObject.indexLast;
	this->size = sourceObject.size;
	this->queue = new int[sourceObject.size];

	for (int index = 0; index < this->size; index++)
	{
		this->queue[index] = sourceObject.queue[index];
	}
}

Queue::~Queue()
{
	delete[] this->queue;
	this->queue = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Queue& sourceObject)
{
	os << sourceObject.indexLast << " | " << sourceObject.size << " | ";
	for (int index = 0; index < sourceObject.size; index++)
	{
		os << sourceObject.queue[index] << " | ";
	}

	return os;
}

Queue& Queue::operator=(const Queue& sourceObject)
{
	if (this == &sourceObject) // In case obj1 == obj1
	{
		return *this;
	}
	else
	{
		this->indexLast = sourceObject.indexLast;
		this->size = sourceObject.size;
		this->queue = sourceObject.queue;

		return *this;
	}
}

bool Queue::IsEmpty() const
{
	return this->size == 0;
}

unsigned int Queue::Size() const
{
	return this->size;
}

TYPE Queue::FirstElement() const
{
	return this->queue[0];
}

TYPE Queue::Pop()
{
	if (!IsEmpty())
	{
		for (int index = 0; index < this->size; index++)
		{
			printf("Current value before pop : %d at index [%d]\n", this->queue[index], index);
		}

		printf("The value : %d was poped out\n", this->FirstElement());
		printf("The value : %d of indexLast \n", this->indexLast);
		printf("The value : %d of size\n", this->Size());

		if (this->indexLast <= this->Size())
		{
			for (int index = 0; index < this->size; index++)
			{
				this->queue[index] = this->queue[index + 1];
			}

			printf("The size before add is : %d\n", Size());
			this->size--;
			printf("The size after add is : %d\n", Size());

			TYPE* newQueue = new TYPE[this->size];

			for (int index = 0; index < this->size; index++)
			{
				newQueue[index] = this->queue[index];
			}

			delete[] this->queue;

			this->queue = newQueue;

			PrintResult();

			this->indexLast--;
		}
	}
	else
	{
		printf("Couldn't pop out. Queue is empty!\n");
	}

	printf("\n");

	return this->queue[0];
}

void Queue::PrintResult() const
{

	for (int index = 0; index < this->size; index++)
	{
		printf("Current value after pop : %d at index [%d]\n", this->queue[index], index);
	}

}