#include <stdio.h>
#include <stdlib.h>

char stk[100];
int top = -1;

char infix[100];
char postfix[100];

void push(char ch) {
    stk[++top] = ch;
    return;
}

char pop() {
    return stk[top--];
}

int prec(char ch) {
    switch(ch) {
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/':
        case '%': return 3;
        case '^': return 4;
    }

    return -1;
}

void main()
{
    printf("Enter the infix expression: \n");
    scanf("%s", infix);

    char ch, temp;
    int i, j = 0;

    push('#');

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (stk[top] != '(') {
                postfix[j++] = pop();
            }
            temp = pop();
        }
        else {
            while (prec(stk[top]) >= prec(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (stk[top] != '#') {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("\nThe post fix expression is:\n-> %s", postfix);

    return;
}
