#include <iostream>
#include "Expression.h"
//---------------------------------------------------------------------------
using namespace std;
int main()
{
	double x;
	string A = "2+e(e(1)/e(1)-1)";
	string D = "(x^2+2*x+2)/(x^2+1)";
	vector<string> C;
	bool a = ExpressionCheck(A);
	cout  << a << endl;
	string B = ExpressionParse(A);
	cout << B;
	x = ExpressionSolveV2(B);
	cout << endl << x <<endl;
	C = StringToVector(D);
	C = ExpressionParsev2(C);
	x = ExpressiongSolve(C);
	cout << x;
	cin >> x;
	return 0;
}
//---------------------------------------------------------------------------
