#include <iostream>
using namespace std;
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
	bool IsFool() // я знаю, что надо full, но так веселее
	{
		return (Count == Size);
	}
	void Push(const ValType &v) // добавляет элемент в стек
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
	ValType Pop() // вынимает верхний элемент из стека
	{
		if (IsEmpty())
		{
			return 0; // или исключение?
		}
		Count--;
		return pVector[Count+1];
	}

};

int main()
{
	TStack<int> A(3);
	A.Push(1);
	A.Push(2);
	A.Push(3);
	A.Push(4);
	A.Push(5);
	A.Push(6);
	int x = A.Pop();
	cout << x;
	cin >> x;
	return 0;
}