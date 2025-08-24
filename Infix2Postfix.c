#include <stdio.h>

short prec(char c){ //assigns precedence
    switch(c){
        case '^': return 3; break;
        case '/':
        case '*': return 2; break;
        case '+': case '-': return 1; break;
        default: return -1;
    }
} 
short associativity(char c) { //Move right or left
    if (c=='^') return 0;
    return 1;
}

void infixToPostfix(char exp[]) {
    char result[100];
    int resultIndex=0;
    int len=0;for(;exp[len]!='\0';len++);//calculates length of string
    char stack[100]; //stack declared
    int stackIndex=-1;

    for (int i=0;i<len;i++) {
        char c=exp[i];

        if ((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))
            result[resultIndex++]=c;
        else if (c=='(')
            stack[++stackIndex]=c;
        else if (c == ')') {
            while (stackIndex >= 0 && stack[stackIndex] != '(')
                result[resultIndex++] = stack[stackIndex--];
            stackIndex--; 
        }
        else {
            while (stackIndex >= 0 && (prec(exp[i]) < prec(stack[stackIndex])||prec(exp[i])==prec(stack[stackIndex])&&associativity(exp[i])))
                result[resultIndex++]=stack[stackIndex--];
            stack[++stackIndex]=c;
        }
    }

    while (stackIndex>=0)
        result[resultIndex++]=stack[stackIndex--];
    result[resultIndex]='\0';
    printf("%s", result);
}

void main(){
    char exp[100];
    scanf("%s",exp);
    infixToPostfix(exp);
}
