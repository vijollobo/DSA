#include <stdio.h>
int CQ[100],n,front=-1,rear=-1;
int isFull(){return ((front==(rear+1)%n)||(front==0&&rear==n-1));}
int isEmpty(){return (rear==-1&&front==-1);}

void enqueue(int element){ //inserts element at the end of the queue
    if(isFull())printf("\nQueue is full! Cannot enqueue.");
    else{
        if(front==-1)++front;
        rear=(rear+1)%n;
        CQ[rear]=element;
        printf("\nEnqueued %i to the queue.",element);
    }
}

void dequeue(){ //deletes element from the front of the queue
    int element;
    if(isEmpty()) printf("Queue is empty! Cannot dequeue.");
    else{
        element=CQ[front];
        if(front==rear){front=-1;rear=-1;}
        else front=(front+1)%n;
        printf("Dequeued value : %i",element);
    }
}

void display(){ //displays all element in the queue
    if(isEmpty()) printf("Queue is empty!");
    else{
        int i;
        printf("Queue elements are : ");
        for(i=front;i!=rear;i=(i+1)%n) printf("%i ",CQ[i]);
        printf("%i ",CQ[i]);
    }
}
int min(){ //returns element with least value in the queue
    int min=CQ[front],i;
    for(i=front;i!=rear;i=(i+1)%n){
        if (CQ[i]<min) min=CQ[i];
    }if (CQ[i]<min) min=CQ[i];
    return min;
}

int max(){ //return element with largest value in the queue
    int max=-99999,i;
    for(i=front;i!=rear;i=(i+1)%n){
        if (CQ[i]>max) max=CQ[i];
    }if (CQ[i]>max) max=CQ[i];
    return max;
}
int count(int a){int count=0,i; //returns the number of times 'a' is repeated in the queue
    for(i=front;i!=rear;i=(i+1)%n){
        if(CQ[i]==a)count++;
    }if(CQ[i]==a)count++;
    return count;
}
int inQ(int a){int i; //returns whether a is present in the queue or not
    for(i=front;i!=rear;i=(i+1)%n){
        if(CQ[i]==a){return 1; break;}
    }if(CQ[i]==a) return 1; 
    return 0;
}
void freq(){ //displays frequency of each and every element in the queue
     for(int i=min();i<=max();i++){
        if(inQ(i)){
            printf("%i - %i\n",i,count(i));
        }
    }
}

void main(){
    printf("Enter the maximum size of the queue: ");
    scanf("%i",&n);
    for(;;){
        int c;
        printf("\nCircular Queue Menu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Largest element\n5. Smallest element\n6. Frequency\n0. Exit\nEnter your choice : ");
        scanf("%i",&c);
        switch(c){
            case 1:{
                int val;
                printf("Enter the value to enqueue : ");
                scanf("%i",&val);
                enqueue(val);
                break;}
            case 2: dequeue();break;
            case 3: display();break;
            case 4: printf("The largest element in the circular queue is %i",max());break;
            case 5: printf("The smallest element in the circular queue is %i",min());break;
            case 6: printf("The frequency of each element in the Circular Queue is as follows\n");freq();break;
            case 0: return;
            default: printf("INVALID INPUT");
        }
    }
}