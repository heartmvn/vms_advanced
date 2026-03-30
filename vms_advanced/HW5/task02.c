#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 1000

int stack[STACK_SIZE];
int top = -1;

void push(int val) {
    if (top < STACK_SIZE - 1) {
        stack[++top] = val;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return 0;
}

int main() {
    char ch;
    int num = 0;
    int reading_number = 0;

    while ((ch = getchar()) != EOF) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
            reading_number = 1;
        } else {
            if (reading_number) {
                push(num);
                num = 0;
                reading_number = 0;
            }

            if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                int b = pop();
                int a = pop();
                int res = 0;

                switch (ch) {
                    case '+': res = a + b; break;
                    case '-': res = a - b; break;
                    case '*': res = a * b; break;
                    case '/': res = b != 0 ? a / b : 0; break;
                }

                push(res);
            } else if (ch == '.') {
                break;
            }
        }
    }

    printf("%d\n", pop());
    return 0;
}

