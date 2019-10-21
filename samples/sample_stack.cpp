#include <iostream>
#include "UStack.h"
//---------------------------------------------------------------------------
using namespace std;
int main()
{
	/*TMinStack<int> A;
	A.Push(2);
	A.Push(10);
	A.Push(1);
	A.Push(-10);
	int x = A.FindMin();
	cout << x; */
	double x;
	string A = "((2*(2+2)*(2+4))/(1+2/3))";
	string B = OPZPerevod(A);
	cout << B;
	x = OPZSolvev2(B);
	cout << x;
	cin >> x;
	return 0;
}
//---------------------------------------------------------------------------
