#include <cmath>
#include <string>

using namespace std;

#include "values.h"
#include "listing.h"

double evaluateReduction(Operators operator_, double head, double tail)
{
	// Return the sum if operator is ADD, otherwise return product
    return (operator_ == ADD) ? head + tail : head * tail;
}

double evaluateRelational(double left, Operators operator_, double right)
{
	int result;
	switch (operator_)
	{
		case LESS:
			result = left < right;
			break;
		case GREATER:
			result = left > right;
			break;
		case LESS_EQUAL:
			result = left <= right;
			break;
		case GREATER_EQUAL:
			result = left >= right;
			break;
		case EQUAL:
			result = left == right;
			break;
		case NOT_EQUAL:
			result = left != right;
			break;
        default:
            break;
	}
	return result;
}

double evaluateArithmetic(double left, Operators operator_, double right)
{
	double result;
	switch (operator_)
	{
		case ADD:
			result = left + right;
			break;
		case SUBTRACT:
			result = left - right;
			break;
		case MULTIPLY:
			result = left * right;
			break;
		case DIVIDE:
			result = left / right;
			break;
		case REM:
			result = fmod(left, right);
			break;
		case EXP:
			result = pow(left * 1.0, right * 1.0);
			break;
		case ARROW:
			left = right;
			result = left;
			break;
        default:
            break;
	}
	return result;
}

double evaluateIfElse(double expression, double ifStatement, double elseStatement)
{
    return (expression == 1) ? ifStatement : elseStatement;
}
