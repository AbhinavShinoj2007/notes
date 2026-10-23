#include<stdio.h>
#include<stdlib.h>
#define N 3
int cq[N],front=-1,rear=-1;
void insert(int x){
if(front==(rear+1)%N){
printf("The queue is Full");
return;
}
if(front==-1)front=0;
rear=(rear+1)%N;
cq[rear]=x;
}
void delete(){
int y;
if(front==-1&&rear==-1){printf("the queue is empty\n");
return;
}
y=cq[front];
printf("The deleted element is :%d",y);
if(front==rear)
{front=-1;rear=-1;}
else{
front=(front+1)%N;}}

void display(){
int i;
if(front==-1){printf("Queue is empty");
return;
}
i = front;
while(1){
printf("%d\t",cq[i]);

if(i==rear)break;
i=(i+1)%N;}
printf("\n");
}

void insert(int x);
void display();
void delete();
int main(){
int ch,x;
while(1){
printf("\nSelect the choice :\n");
printf("\n1. Insert");
printf("\n2.delete");
printf("\n3.Display");
printf("\n4.Exit");
printf("\nEnter the choice:");
scanf("%d",&ch);
switch(ch){
case 1:
printf("Enter the element to add:\n");
scanf("%d",&x);
insert(x);break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
printf("Program ended\n");
return 0;
default:
printf("Invalid choice");
}
}
return 0;
}
