Google Classroom
Classroom
DATA STRUCTURE -II - CSE 203
Sem III : CSE : D
Home
Calendar
Enrolled
To-do
D
DATA STRUCTURE -II - CSE 203
Sem III : CSE : D
O
OOPS WITH C++ - CSE 202
Sem III : CSE : D
C
Chemistry for Engineers (CHE 103)
Sem II : CSE D
C
CSE_2022-25
SECTION-D
E
Environmental Science (ENV 111)
Sem II: CSE D
D
Discrete Mathematics (MAT 141)
Sem II : CSE D, E and F
L
Linear Algebra (MAT 211)
Sem II : CSE D
E
Exploratory Learning and Discovery (ENTR 100)
Sem : I CSE ( A to O)
E
Engineering Physics Lab (PHY 101L)
Sem I : CSE D
E
Engineering Physics (PHY 101)
Sem I : CSE D
O
Orientation on Internationalization (IRH 101)
Sem I : CSE D
O
Orientation on Internationalization (IRH 101)
Sem I : CSE D
C
Communicative English (EGL 101)
Sem I : CSE D
C
CSE 108: Introduction to Computer Science and Programming Using C
Sem I : Section - D [CSE]
C
CSE 108L Lab: Introduction to Computer Science and Programming Using C Lab
Sem I : Section - D [CSE]
I
Introductory Biology for Engineers (BIO 103)
Sem I : CSE D
Archived classes
Settings
Assignment details
Assignment 3
Chinmaya Kumar Swain
•
Aug 25
100 points
Due Yesterday, 11:59 PM
1. 

Write a program to  convert the Infix notation to postfix notation using stack.

2. Write a program to evaluate the postfix notation using stack.
Class comments
Your work
Turned in

evaluate value .c
C

INFIX TO POSTFIX .c
C
Work cannot be turned in after the due date
Private comments
// C program to evaluate value of a postfix expression
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Stack type
struct Stack {
int top;
unsigned capacity;
int* array;
};

// Stack Operations
struct Stack* createStack(unsigned capacity)
{
struct Stack* stack
= (struct Stack*)malloc(sizeof(struct Stack));

if (!stack)
return NULL;

stack->top = -1;
stack->capacity = capacity;
stack->array
= (int*)malloc(stack->capacity * sizeof(int));

if (!stack->array)
return NULL;

return stack;
}

int isEmpty(struct Stack* stack)
{
return stack->top == -1;
}

char peek(struct Stack* stack)
{
return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
if (!isEmpty(stack))
return stack->array[stack->top--];
return '$';
}

void push(struct Stack* stack, char op)
{
stack->array[++stack->top] = op;
}

// The main function that returns value
// of a given postfix expression
int evaluatePostfix(char* exp)
{
// Create a stack of capacity equal to expression size
struct Stack* stack = createStack(strlen(exp));
int i;

// See if stack was created successfully
if (!stack)
return -1;

// Scan all characters one by one
for (i = 0; exp[i]; ++i) {

// If the scanned character is an operand
// (number here), push it to the stack.
if (isdigit(exp[i]))
push(stack, exp[i] - '0');

// If the scanned character is an operator,
// pop two elements from stack apply the operator
else {
int val1 = pop(stack);
int val2 = pop(stack);
switch (exp[i]) {
case '+':
push(stack, val2 + val1);
break;
case '-':
push(stack, val2 - val1);
break;
case '*':
push(stack, val2 * val1);
break;
case '/':
push(stack, val2 / val1);
break;
}
}
}
return pop(stack);
}

// Driver code
int main()
{
char exp[20];
printf("Enter the expression : ");
scanf("%s",exp);

// Function call
printf("postfix evaluation: %d", evaluatePostfix(exp));
return 0;
}

evaluate value .c
Displaying evaluate value .c.
