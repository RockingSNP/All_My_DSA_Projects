#include<stdio.h>
#include<stdlib.h>

int front = (-1), rear = (-1);
int *queue,choice,x,N;

void enqueue(){
	if(((rear+1)%N) == front){
		printf("Queue Overflow!\n");}
	else if(front == -1 && rear == -1){
		printf("Enter The First element you want to Enqueue: ");
		scanf("%d",&x);
		front = rear =0;
		queue[rear] = x;}
	else{printf("The element you want to Enqueue:  ");
		scanf("%d",&x);
		rear = (++rear)%N;
		queue[rear] = x;
	}
}

void dequeue(){
	if(front == -1 && rear == -1){
		printf("Queue Underflow\n");
	}else if(front==rear){
		front = rear = (-1);
	}else{
		printf("The dequeued Element is: %d\n",queue[front]);	
			front ++;
		
	}
}

void display(){
	printf("\nYour Queue is : {");
	for(int i=0;i<=N-1;i++){
		printf("%d  ",queue[i]);
	}printf("}\n");
}
void main(){
	printf("What Size of Queue to You Want? : \t");
	scanf("%d",&N);
	queue = (int*)malloc(N*sizeof(int));
	select:
    printf("What Operation do you want to perform?\n");
    printf("For Enqueue   Press 1\nDequeue        Press 2\nDisplay   Press 3:\t");
    scanf("%d", &choice);
    
    switch (choice)    {
    case 1:
		enqueue();
        goto select;
        break;
    case 2:
        dequeue();
        goto select;
        break;
    case 3:
        display();
        goto select;
        break;

    default:
        printf("Unknown Input.Try again!\n");
        goto select;
        break;
    }}