#include "UStack.h"
#include <gtest.h>

TEST(TExpression, can_calculate_some_easy_expression_1)
{
	std::string A = "2+3";
	std::string B = ExpressionParse(A);

	EXPECT_EQ(ExpressionCheck(A), 1);
	EXPECT_EQ(ExpressionSolveV2(B), 5);
}
TEST(TExpression, can_calculate_some_easy_expression_2)
{
	std::string A = "(2+3)*6/3+1";
	std::string B = ExpressionParse(A);

	EXPECT_EQ(ExpressionCheck(A), 1);
	EXPECT_EQ(ExpressionSolveV2(B), 11);
}
TEST(TExpression, can_calculate_some_easy_expression_3)
{
	std::string A = "(2^2+1)+3*((5+1)/2)";
	std::string B = ExpressionParse(A);

	EXPECT_EQ(ExpressionCheck(A), 1);
	EXPECT_EQ(ExpressionSolveV2(B), 14);
}
TEST(TExpression, can_calculate_some_easy_expression_4)
{
	std::string A = "3+4*2/(1-5)^2^3";
	std::string B = ExpressionParse(A);

	EXPECT_EQ(ExpressionCheck(A), 1);
	EXPECT_EQ(ExpressionSolveV2(B), 3.0001220703125);
}
TEST(TExpression, can_calculate_some_easy_expression_5)
{
	std::string A = "5^2^(2+2)";
	std::string B = ExpressionParse(A);

	EXPECT_EQ(ExpressionCheck(A), 1);
	EXPECT_EQ(ExpressionSolveV2(B), 152587890625);
}
TEST(TExpression, can_calculate_expression_with_unar_operators_1)
{
	std::string A = "e(0)";
	EXPECT_EQ(ExpressionCheck(A), 1);

	if (ExpressionCheck(A))
	{
		std::string B = ExpressionParse(A);

		EXPECT_EQ(ExpressionSolveV2(B), 1);
	}
}
TEST(TExpression, can_calculate_expression_with_unar_operators_2)
{
	std::string A = "e(e(0)-e(0))";
	EXPECT_EQ(ExpressionCheck(A), 1);

	if (ExpressionCheck(A))
	{
		std::string B = ExpressionParse(A);

		EXPECT_EQ(ExpressionSolveV2(B), 1);
	}
}
TEST(TExpression, returns_NULL_when_incorrect_expression_1)
{
	std::string A = "1,";

	EXPECT_EQ(ExpressionCheck(A), 0);
}
TEST(TExpression, returns_NULL_when_incorrect_expression_2)
{
	std::string A = "(1+2))";

	EXPECT_EQ(ExpressionCheck(A), 0);
}
TEST(TExpression, returns_NULL_when_incorrect_expression_3)
{
	std::string A = "(1,2*2,,1))";

	EXPECT_EQ(ExpressionCheck(A), 0);
}
TEST(TExpression, returns_NULL_when_incorrect_expression_4)
{
	std::string A = "(1,2*2,,1)),";

	EXPECT_EQ(ExpressionCheck(A), 0);
}
TEST(TExpression, returns_NULL_when_incorrect_expression_5)
{
	std::string A = "a";

	EXPECT_EQ(ExpressionCheck(A), 0);
}
TEST(TExpression, returns_NULL_when_incorrect_expression_6)
{
	std::string A = "a+b,23as";

	EXPECT_EQ(ExpressionCheck(A), 0);
}
TEST(TExpression, returns_1_when_correct_expression_1)
{
	std::string A = "1,1";

	EXPECT_EQ(ExpressionCheck(A), 1);
}
TEST(TExpression, returns_1_when_correct_expression_2)
{
	std::string A = "(1+2)";

	EXPECT_EQ(ExpressionCheck(A), 1);
}
TEST(TExpression, returns_1_when_correct_expression_3)
{
	std::string A = "(1,2*2,1)";

	EXPECT_EQ(ExpressionCheck(A), 1);
}
TEST(TExpressionV2, can_calculate_some_easy_expression_1)
{
	std::string A = "(2^2+1)+3*((5+1)/2)";
	std::vector<std::string> B = StringToVector(A);
	B = ExpressionParsev2(B);

	EXPECT_EQ(14, ExpressiongSolve(B));
}
TEST(TExpressionV2, can_calculate_some_easy_expression_2)
{
	std::string A = "5^2^(2+2)";
	std::vector<std::string> B = StringToVector(A);
	B = ExpressionParsev2(B);

	EXPECT_EQ(152587890625, ExpressiongSolve(B));
}
TEST(TExpressionV2, can_calculate_some_easy_expression_3)
{
	std::string A = "exp(exp(0)-exp(0))";
	std::vector<std::string> B = StringToVector(A);
	B = ExpressionParsev2(B);

	EXPECT_EQ(1, ExpressiongSolve(B));
}
TEST(TExpressionV2, throws_when_incorrect_expression_1)
{
	std::string A = "(1.2*2.1))";

	EXPECT_ANY_THROW(std::vector<std::string> B = StringToVector(A));
}
TEST(TExpressionV2, throws_when_incorrect_expression_2)
{
	std::string A = "(1.2*2..1)).";

	EXPECT_ANY_THROW(std::vector<std::string> B = StringToVector(A));
}
TEST(TExpressionV2, throws_when_incorrect_expression_3)
{
	std::string A = "1.";

	EXPECT_ANY_THROW(std::vector<std::string> B = StringToVector(A));
}
TEST(TExpressionV2, throws_when_incorrect_expression_4)
{
	std::string A = "1+sin";

	EXPECT_ANY_THROW(std::vector<std::string> B = StringToVector(A));
}

TEST(TExpressionV2, throws_when_incorrect_expression_5)
{
	std::string A = "sin()+1";

	EXPECT_ANY_THROW(std::vector<std::string> B = StringToVector(A));
}

TEST(TStack, can_create_stack)
{
	EXPECT_NO_THROW(TStack<int>(3));
}
TEST(TStack, cant_create_stack_with_negative_size)
{
	EXPECT_ANY_THROW(TStack<int>(-3));
}
TEST(TStack, cant_create_stack_with_too_big_size)
{
	EXPECT_ANY_THROW(TStack<int>(MAX_STACK_SIZE+3));
}
TEST(TStack, can_push_element)
{
	TStack<int> A;
	A.Push(3);

	EXPECT_EQ(3, A.Top());
}
TEST(TStack, can_pop_element)
{
	TStack<int> A;
	A.Push(3);
	A.Push(2);
	A.Pop();

	EXPECT_EQ(3, A.Top());
}
TEST(TStack, returns_Is_Empty_1)
{
	TStack<int> A;

	EXPECT_EQ(1, A.IsEmpty());
}
TEST(TStack, returns_Is_Empty_2)
{
	TStack<int> A;
	A.Push(13);
	A.Pop();

	EXPECT_EQ(1, A.IsEmpty());
}
TEST(TStack, cant_pop_from_empty_stack)
{
	TStack<int> A;

	EXPECT_ANY_THROW(A.Pop());
}








