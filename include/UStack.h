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



int Priority(char s)
{
	switch (s)
	{
	case '+': return 2;
	case '-': return 3;
	case '*': return 4;
	case '/': return 5;
	case '(': return 0;
	case ')': return 1;
	case '^': return 7;
	case 's': return 8;
	case 'e': return 10;
	default:
		return -1;
	}
}
bool ExpressionCheck(std::string _A)
{
	int Status = 0;
	int BracketCounter = 0;
	int PointCounter = 0;
	bool Check = 0;
	for (int i = 0; i <= _A.size(); i++)
	{
		if (Status == 4)
			return 1;
		if (Status == 3)
			return 0;
		if (Status == 2)
		{
			if ((BracketCounter == 0)&&(PointCounter == 0))
				return 1;
			else 
				return 0;
		}
		if (Status == 1)
		{
			if (PointCounter > 1)
			{
				Status = 3;
			}
			else if (_A[i] == 0)
			{
					Status = 2;
					PointCounter = 0;
			}
			else if (_A[i] == 41)
			{
				BracketCounter--;
				if (BracketCounter >= 0)
					Status = 1;
				else Status = 3;
				PointCounter = 0;
			}
			else if ((_A[i] >= 48 && _A[i] <= 59))
			{
				Status = 1;
				PointCounter = 0;
			}
			else if (_A[i] == 44)
			{
				PointCounter++;
				Status = 1;
				if (_A[i + 1] == 0)
					Status = 3;
			}
			else if (_A[i] == '+' || _A[i] == '-' || _A[i] == '^' || _A[i] == '/' || _A[i] == '*')
			{
				Status = 0;
				PointCounter = 0;
			}
			else Status = 3;
		}
		else if (Status == 0)
		{
			if (_A[i] == 10)
			{
				Status = 2;
			}
			else if (_A[i] == 40)
			{
				BracketCounter++;
				Status = 0;

			}
			else if ((_A[i] >= 48) && (_A[i] <= 57))
			{
				Status = 1;
			}
			else if (_A[i] == 'e' || _A[i] == 's' || _A[i] == 'c' )
			{
				if (_A[i + 1] == 0)
					Status = 4;
				else Status = 0;
			}
			else Status = 3;
		}
	}
	if (Status != 3)
		Check = 1;
	return Check;
}
std::string ExpressionParse(std::string _A)
{
	TStack<char> Polska;
	char tmp;
	std::string Result;
	for (int i = 0; i < _A.size(); i++)
	{
		if (_A[i] == '(')
		{
			Polska.Push(_A[i]);
		}
		if (_A[i] == ')')
		{
			while (Polska.Top() != '(')
			{
				tmp = Polska.Pop();
				Result = Result + tmp;
			}
			Polska.Pop();
		}
		if (((_A[i] >= 48 && _A[i] <= 59))||(_A[i]== 44 ))
		{
			Result = Result + _A[i];
			if ((_A[i + 1] < 48 || _A[i + 1] > 59) && (_A[i+1]!= 44))
			{
				Result = Result + '|';
			}

		}
		if (_A[i] == '+' || _A[i] == '-' || _A[i] == 'e' || _A[i] == '^' || _A[i] == '/' || _A[i] == '*')
		{
			if (Polska.IsEmpty())
			{
				Polska.Push(_A[i]);
			}
			else
			{
					while (!Polska.IsEmpty()  && (Priority(_A[i])) < Priority(Polska.Top()))	
					{
						Result = Result + Polska.Pop();
					}
					Polska.Push(_A[i]);
			}
		}
	}
	while (!Polska.IsEmpty())
	{
		Result = Result + Polska.Pop();
	}
	return Result;
}
double ExpressionSolveV2(std::string _A)
{
	double tmp;
	TStack<double> NumbersStack;
	int count = 0;
	int IntegerPart = 1;
	double mult = 0.1;
	for (int i = 0; i < _A.size(); i++)
	{
		//std::cout << "TOP " << NumbersStack.Top() << std::endl;
		switch (_A[i])
		{
		case '+':
			NumbersStack.Push((NumbersStack.Pop()) + (NumbersStack.Pop()));

			break;
		case '-':
			tmp = NumbersStack.Pop();
			NumbersStack.Push((NumbersStack.Pop()) - tmp);
			break;
		case '*':
			NumbersStack.Push((NumbersStack.Pop())*(NumbersStack.Pop()));
			break;
		case '/':
			tmp = NumbersStack.Pop();
			NumbersStack.Push((NumbersStack.Pop()) / tmp);
			break;
		case 'e':
			NumbersStack.Push(exp(NumbersStack.Pop()));
			break;
		case 's':
			NumbersStack.Push(sin(NumbersStack.Pop()));
			break;
		case 'c':
			NumbersStack.Push(cos(NumbersStack.Pop()));
			break;
		case '^':
			NumbersStack.Push(pow(NumbersStack.Pop(), NumbersStack.Pop()));
			break;
		case '|':
			break;
		case ',':
			IntegerPart = 0;
			break;
		default:
			if (count == 0)
				tmp = _A[i]-48;
			else
			{
				if (IntegerPart)
				{
					tmp = tmp * 10 + _A[i] - 48;
				}
				else
				{
					tmp = tmp + mult * (_A[i] - 48);
					mult = mult / 10;
				}
			}
			if ((_A[i + 1] < 48 || _A[i + 1] > 59)&&(_A[i+1]!=44))
			{
				NumbersStack.Push(tmp);
				count = -1;
				tmp = 0;
				mult = 0.1;
			}
			count++;
		}
	}
	return NumbersStack.Top();
}

#endif
