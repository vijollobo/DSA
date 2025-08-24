#include <stdio.h>
int stack[100],top=-1,n;
void push(){
    if(top>=n-1) printf("STACK is over flow");
    else {int value;
        printf("Enter a value to be pushed : ");
        scanf("%i",&value);
        stack[++top]=value;
    }
}

void pop(){
    if (top==-1) printf("Stack underflow");
    else printf("The popped element is %i",stack[top--]);
}
void display(){
    if (top==-1) printf("The STACK is empty");
    else{
        printf("The elements in STACK \n\n");
        for (int i=top;i>=0;i--) printf("%i\n",stack[i]);
        printf("Press Next Choice");
        
    }
}
int main(){
    int choice;
    printf("Enter size of stack : ");
    scanf("%d",&n);
    mp: printf("\nSTACK OPERATION USING ARRAY\n---------------------------------\n");
    printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n\n");
    scanf("%d",&choice);
    switch(choice){
        case 1: push();goto mp;break;
        case 2: pop();goto mp;break;
        case 3: display();goto mp;break;
        case 4: printf("EXIT POINT");break;
        default:
            printf("Please Enter a Valid Choice (1/2/3/4)");goto mp;
    }
}