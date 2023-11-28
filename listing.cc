// This file contains the bodies of the functions that produces the compilation
// listing

#include <cstdio>
#include <string>

using namespace std;

#include "listing.h"

static int lineNumber;
static string multipleError = "";
static string error = "";
static int errorLine = 0;
static int totalErrors = 0;
static int lexicalErrors = 0;
static int syntaxErrors = 0;
static int semanticErrors = 0;

static void displayErrors();

void firstLine() {
	lineNumber = 1;
	printf("\n%4d  ",lineNumber);
}

void nextLine() {
	displayErrors();
	lineNumber++;
	printf("%4d  ",lineNumber);
}

int lastLine() {
    printf("\r");
    displayErrors();
    printf("     \n");

	// Check if there are any errors to display
    if (totalErrors > 0) {
        printf("\nLexical Errors:   %11d", lexicalErrors);
        printf("\nSyntax Errors:    %11d", syntaxErrors);
        printf("\nSemantic Errors:  %11d", semanticErrors);
        printf("\nTotal Number of Errors: %5d\n", totalErrors);
    } else {
        printf("Compiled Successfully\n");
    }
    
    return totalErrors;
}

void appendError(ErrorCategories errorCategory, string message)
{
	// Static message array to avoid recreating it on every function call
    static string messages[] = {
        "Lexical Error, Invalid Character ",
        "",
        "Semantic Error, ",
        "Semantic Error, Duplicate Identifier: ",
        "Semantic Error, Undeclared "
    };

    error = messages[errorCategory] + message;
    multipleError += error + "\n";
    totalErrors++;

	// Increment specific error counters based on error category
    switch (errorCategory)
    {
        case 0:
            lexicalErrors++;
            break;
        case 1:
            syntaxErrors++;
            break;
        default:
            if (errorCategory >= 2)
                semanticErrors++;
            break;
    }
}

void displayErrors() {
    // If there are errors stored, display them
    if (!multipleError.empty()) {
        printf("%s", multipleError.c_str());
    }

    // Clear the error and multipleError strings
    error = "";
    multipleError = "";
}
