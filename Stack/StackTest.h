#pragma once

template <typename>
class IStack;

class StackIntegerTest
{
private:
	IStack<int>* stackToTest;

	/// <summary>
	/// Main run test private method
	/// </summary>
	/// <returns>True if the test was succeed</returns>
	bool RunTest();

	bool RunPushTest();
	bool RunPopTest();
	bool RunTopTest();

	bool RunIsEmptyTest();
	bool RunItemsAmountTest();

public:
	StackIntegerTest(IStack<int>* stack);
	virtual ~StackIntegerTest();

	void Run();
};

