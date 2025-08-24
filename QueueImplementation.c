//Implement a Queue (FIFO) Data Structure in C 
//Write a program in C to represent a Queue (FIFO) Data Structure

#include <stdio.h>
int Q[10],front=-1,rear=-1,n=10;
void enqueue(){
    if (rear<n-1){
        int value;
        printf("Enter the value to enqueue : ");
        scanf("%i",&value);
        if(front==-1&&rear==-1){
            Q[++rear]=value;
            front++;
        }else Q[++rear]=value;
        printf("\n%i enqueued to the queue.\n",value);
    } else printf("The queue is full\n");
}
void dequeue(){
    if((front==-1&&rear==-1)||(front>rear)) printf("Queue is empty, cannot dequeue.\n");
    else printf("%i dequeued from the queue.\n",Q[front++]);
}

void display(){
    if((front==-1&&rear==-1)||(front>rear)) printf("Queue is empty.\n");
    else{
        printf("Queue elements : ");
        for (int i=front;i<=rear;i++) printf("%i ",Q[i]);
        printf("\n");
    }
}

void main(){
    int c;
    for(;;){
        printf("\n----- Menu -----\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your Choice : ");
        scanf("%i",&c); printf("\n");
        switch(c){
            case 1:enqueue();break;
            case 2:dequeue();break;
            case 3: display();break;
            case 4: return;
            default: printf("INVALID INPUT");
        }
    }
}