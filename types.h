// This file contains type definitions and the function
// prototypes for the type checking functions

#include <vector>

typedef char* CharPtr;

enum Types {MISMATCH, INT_TYPE, REAL_TYPE, BOOL_TYPE, EMPTY};

void checkAssignment(Types lValue, Types rValue, string message);
Types checkArithmetic(Types left, Types right);
Types checkLogical(Types left, Types right);
Types checkRelational(Types left, Types right);
Types checkInteger(Types left, Types right);
Types checkIfThen(Types expression, Types left, Types right);
Types checkExpression(Types expression);
Types checkCases(Types state1, Types state2);