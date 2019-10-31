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
	string A = "2+e(e(1)/e(1)-1)";
	bool a = ExpressionCheck(A);
	cout  << a << endl;
	string B = ExpressionParse(A);
	cout << B;
	x = ExpressionSolveV2(B);
	cout << endl << x;
	cin >> x;
	return 0;
}
//---------------------------------------------------------------------------
