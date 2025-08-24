#include <stdio.h>
int top1=-1,top2=-1,n,stack[100],queue[100];

void enqueue(){
    if(top1!=n-1){
        int value;
        printf("Enter the value to enqueue : ");
        scanf("%i",&value);
        stack[++top1]=value;
        printf("\n%i enqueued to the queue\n",value  );
    } else printf("Overflow");
}
void dequeue(){
    if(top1==-1) printf("Queue is Empty, Cannot dequeue");
    else{
        int pop=stack[0];
        for(int i=top1;i>=1;i--)
            queue[++top2]=stack[top1--];
        top1--;
        for(int i=top2;i>=0;i--)
            stack[++top1]=queue[top2--];
        printf("%i dequeued from the queue\n",pop);
    }
}
void display(){
    if(top1==-1) printf("Queue is empty.\n");
    else{
        printf("Queue Elements : ");
        for(int i=0;i<=top1;i++) printf("%i ",stack[i]);
        printf("\n");
    }
}
void main(){
    printf("Enter size of queue : ");
    scanf("%i",&n);
    int c;
    while(1){
        printf("\n----- Menu -----\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice : ");
        scanf("%i",&c);printf("\n");
        switch(c){
            case 1:enqueue();break;
            case 2:dequeue();break;
            case 3: display();break;
            case 4: return;
            default: printf("INVALID INPUT");
        }
    }
}