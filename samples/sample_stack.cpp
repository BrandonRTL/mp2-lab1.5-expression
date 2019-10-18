#include <iostream>
#include "UStack.h"
//---------------------------------------------------------------------------
using namespace std;
int main()
{
	TMinStack<int> A;
	A.Push(2);
	A.Push(10);
	A.Push(1);
	A.Push(-10);
	int x = A.FindMin();
	cout << x;
	cin >> x;
	return 0;
}
//---------------------------------------------------------------------------
