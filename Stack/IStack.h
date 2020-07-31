#pragma once

template <typename ItemType>
class IStack
{
public:
	virtual ~IStack() { }

	/// <summary>
	/// Add an item to the stack, as the new top
	/// </summary>
	/// <param name="item"></param>
	virtual void Push(const ItemType& item) = 0;

	/// <summary>
	/// Takes an item from the stack's top
	/// </summary>
	/// <param name="defaultValue">Return value in case the stack is empty</param>
	/// <returns>If not empty, returns the poped item, else, returns defaultValue</returns>
	virtual ItemType Pop(const ItemType& defaultValue = ItemType()) = 0;

	/// <summary>
	/// Just peek's the top item. If empty, returns defaultValue
	/// </summary>
	/// <param name="defaultValue">Value to return if stack is empty</param>
	/// <returns>The top item</returns>
	virtual ItemType Top(const ItemType& defaultValue = ItemType()) const = 0;

	/// <summary>
	/// Check if the stack is empty
	/// </summary>
	/// <returns>True if the stack is empty</returns>
	virtual bool IsEmpty() const = 0;

	/// <summary>
	/// Returns the items amount from the stack
	/// </summary>
	/// <returns>Items amount if any</returns>
	virtual unsigned int ItemsAmount() const = 0;

	/// <summary>
	/// Clears all the stack
	/// </summary>
	virtual void Clear() = 0;
};
