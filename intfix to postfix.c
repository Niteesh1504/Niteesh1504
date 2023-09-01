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
#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}
INFIX TO POSTFIX .c
Displaying INFIX TO POSTFIX .c.
