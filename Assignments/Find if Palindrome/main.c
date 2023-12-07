#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    char data[MAX_STACK_SIZE];
} stack;

void initialize(stack* s) {
    s->top = -1;
}

int push(stack* s, char value) {
    if (s->top >= MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        return 0;
    }
    
    s->data[++(s->top)] = value;
    return 1;
}

int isEmpty(stack* s) {
    return (s->top == -1);
}

char pop(stack* s) {
    if (isEmpty(s)) {
        return 'I';
    }
    
    return s->data[(s->top)--];
}

char peek(stack* s) {
    if (isEmpty(s)) {
        return 'I';
    }
    
    return s->data[s->top];
}

int isPalindrome(char* str) {
    stack s;
    initialize(&s);
    int len = strlen(str);
    int i;
    
    for (i = 0; i < len / 2; i++) {
        push(&s, str[i]);
    }
    
    if (len % 2 != 0) {
        i++;
    }
    
    while (str[i] != '\0') {
        char c = pop(&s);
        
        if (c == 'I' || c != str[i]) {
            return 0;
        }
        
        i++;
    }
    
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    
    return 0;
}
