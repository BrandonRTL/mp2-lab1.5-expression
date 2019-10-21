#ifndef __TSTACK_H__
#define __TSTACK_H__

const int MAX_STACK_SIZE = 100000000;

template <class ValType>
class TStack
{
protected:
	ValType * pVector;
	int Size;
	int Count;
public:
	TStack(int _Size = 13)
	{
		Size = _Size;
		pVector = new ValType[Size];
		Count = 0;
	}
	~TStack()
	{
		delete[] pVector;
	}
	TStack(const TStack<ValType> &v)
	{
		Size = v.Size;
		Count = v.Count;
		pVector = new ValType[v.Size];
		for (int i = 0; i < Size; i++)
		{
			pVector[i] = v.pVector[i];
		}
	}
	bool IsEmpty()
	{
		return (Count == 0);
	}
	bool IsFool()
	{
		return (Count == Size);
	}
	void Push(const ValType &v)
	{
		if (IsFool())
		{
			ValType* _pVector;
			_pVector = new ValType(4 / 3 * Size);
			for (int i = 0; i < Size; i++)
				_pVector[i] = pVector[i];
			pVector = _pVector;
		}
		pVector[Count + 1] = v;
		Count++;
	}
	ValType Top()
	{
		return pVector[Count];
	}
	ValType Pop()
	{
		if (IsEmpty())
		{
			return 0;
		}
		Count--;
		return pVector[Count + 1];
	}
};
template <class ValType>
class TMinStack
{
private:
	TStack<ValType> JustStack;
	TStack<ValType> MinStack;
public:
	TMinStack(int _Size = 13)
	{
		TStack<ValType> A(_Size);
		JustStack = A;
		MinStack = A;
	}
	bool IsEmpty()
	{
		return (JustStack.IsEmpty());
	}
	bool IsFool()
	{
		return (JustStack.IsFool());
	}
	void Push(const ValType &v)
	{
		JustStack.Push(v);
		if ((MinStack.IsEmpty()) || (v <= MinStack.Top()))
			MinStack.Push(v);
	}
	ValType Pop()
	{
		if (JustStack.Top() == MinStack.Top())
			MinStack.Pop();
		return JustStack.Pop();
	}
	ValType FindMin()
	{
		return MinStack.Top();
	}
};
#endif
