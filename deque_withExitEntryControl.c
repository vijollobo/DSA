#include <stdio.h>
int DEQ[5],n=5,front=-1,rear=-1;
int isFull(){return ((front==0&&rear==-1)||(front==rear+1)||(rear==n-1));}
int isEmpty(){return front==-1;}

void insertFront(){
    if(isFull()) printf("Queue Overflow");
    else{
        if(front==-1) {front=0;rear=0;}
        else if(front==0)front=n-1;
        else --front;
        int element;
        printf("Input the element for adding in queue : ");
        scanf("%i",&element);
        DEQ[front]=element;
    }
}

void insertRear(){
    if(isFull()) printf("Queue Overflow");
    else if(rear==n-1) rear=0;
    else ++rear;
    int element;
    printf("Input the element for adding in queue : ");
    scanf("%i",&element);
    DEQ[rear]=element;
}

void deleteFront(){
    if(isEmpty()) printf("Queue Underflow");
    else{ int removed=DEQ[front];
    if(front==rear){front=-1;rear=-1;}
    else if(front==n-1) front=0;
    else ++front;
    printf("Element deleted from queue is %i",removed);
    }
}

void deleteRear(){
    if(isEmpty()) printf("Queue Underflow");
    else{int removed=DEQ[rear];
    if(front==rear){front=-1;rear=-1;}
    else if(rear==0) rear=n-1;
    else --rear;
    printf("Element deleted from queue is %i",removed);
    }
}

void display(){
    if(isEmpty()) printf("Queue is empty");
    else{printf("Queue elements :\n");int i=front;
    for(;i!=rear;i++)printf("%i ",DEQ[i]);
    printf("%i",DEQ[i]);}
}
int main(){
    int mch;
    printf("1. Input restricted dequeue\n2. Output restricted dequeue\nEnter your choice : ");
    scanf("%d",&mch);
    if(mch==1){
        while(1){int c;
            printf("\n----Dequeue Menu----\n1. Insert at rear\n2. Delete from front\n3. Delete from rear\n4. Display\n5. Quit\nEnter your choice : ");
            scanf("%i",&c);
            switch(c){
                case 1: insertRear();break;
                case 2: deleteFront();break;
                case 3: deleteRear();break;
                case 4: display(); break;
                case 5: return 0;
                default: printf("Wrong Choice");
            }
        }
    }
    else if(mch==2){
        for(;;){int c;
            printf("\n----Dequeue Menu----\n1. Insert at rear\n2. Insert at front\n3. Delete from front\n4. Display\n5. Quit\nEnter your choice : ");
            scanf("%i",&c);
            switch(c){
                case 1: insertRear();break;
                case 2: insertFront();break;
                case 3: deleteFront();break;
                case 4: display(); break;
                case 5: return 0;
                default: printf("Wrong Choice");
            }
        }
    }
    else printf("\nWrong Choice");
}