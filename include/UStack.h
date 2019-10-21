#ifndef __TSTACK_H__
#define __TSTACK_H__
#include <string>
#include <vector>
#include <math.h>
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
int Prioritet(char s)
{
	switch (s)
	{
	case '+': return 2;
	case '-': return 2;
	case '*': return 3;
	case '/': return 3;
	case '(': return 0;
	case ')': return 1;
	default:
		return -1;
	}
}

std::string OPZPerevod(std::string _A) // пока что только цифры давайте напишем (3+2)
{
	TStack<char> OPZ;
	int SK = 0;
	char tmp;
	std::string OPZ2;
	for (int i = 0; i < _A.size(); i++)
	{
		//std::cout << "TOP " << OPZ.Top() << std::endl;
	//	std::cout << "STRING " << OPZ2 << std::endl;
		if (_A[i] == '(')
		{
			OPZ.Push(_A[i]);
			std::cout << "WHILE V SKOBKE " << OPZ.Top() << std::endl;
		}
		if (_A[i] == ')')
		{
			while (OPZ.Top() != '(')
			{
				tmp = OPZ.Pop();
				std::cout << "WHILE V SKOBKE " << OPZ.Top() << std::endl; //(2+2)
				OPZ2 = OPZ2 + tmp;
			}
			OPZ.Pop();
		}
		if (_A[i] >= 48 && _A[i] <= 59)
		{
			OPZ2 = OPZ2 + _A[i];
			if (_A[i+1] < 48 || _A[i+1] > 59)
			{
				OPZ2 = OPZ2 + '|';
			}

		}
		if (_A[i] == '+' || _A[i] == '-' || _A[i] == 'e' || _A[i] == '^' || _A[i] == '/' || _A[i] == '*')
		{
			if (OPZ.IsEmpty())
			{
				OPZ.Push(_A[i]);
			}
			else
			{
				if (Prioritet(_A[i]) > Prioritet(OPZ.Top()))
				{
					OPZ.Push(_A[i]);
				}
				else 
				{
					while (!OPZ.IsEmpty() && (Prioritet(_A[i])) <= Prioritet(OPZ.Top()))
					{
						OPZ2 = OPZ2 + OPZ.Pop();
					}
					OPZ.Push(_A[i]);
				}
			}
		}
	}
	while (!OPZ.IsEmpty())
	{
		OPZ2 = OPZ2 + OPZ.Pop();
	}
	return OPZ2;
}
double OPZSolvev2(std::string _A) 
{
	double tmp;
	TStack<double> OPZ;
	int count = 0;
	for (int i = 0; i < _A.size(); i++)
	{
		std::cout << "TOP " << OPZ.Top() << std::endl;
		switch (_A[i])
		{
		case '+':
			OPZ.Push((OPZ.Pop()) + (OPZ.Pop()));

			break;
		case '-':
			tmp = OPZ.Pop();
			OPZ.Push((OPZ.Pop()) - tmp);
			break;
		case '*':
			OPZ.Push((OPZ.Pop())*(OPZ.Pop()));
			break;
		case '/':
			tmp = OPZ.Pop();
			OPZ.Push((OPZ.Pop()) / tmp);
			break;
		case 'e':
			OPZ.Push(exp(OPZ.Pop()));
			break;
		case 's':
			OPZ.Push(sin(OPZ.Pop()));
			break;
		case 'c':
			OPZ.Push(cos(OPZ.Pop()));
			break;
		case '^':
			OPZ.Push(pow(OPZ.Pop(), OPZ.Pop()));
			break;
		case '|':
			break;
		default:
			std::cout << "COUNT - cifri f 4isle " << count << std::endl;
			if (count == 0)
				tmp = _A[i]-48;
			else tmp = tmp * 10 + _A[i]-48;
			if (_A[i + 1] < 48 || _A[i + 1] > 59)
			{
				OPZ.Push(tmp);
				count = -1;
				tmp = 0;
			}
			count++;
		}
	}
	return OPZ.Top();
}

#endif
