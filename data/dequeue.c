#include <stdio.h>
#define max 5
int deque[max];
int front=-1,rear=-1;
void insertfront(){
int item;
if((rear+1)%max==front){
printf("insertion at front not possible");
return;}
printf("Enter element:");
scanf("%d",&item);
if(front==-1){
front=rear=0;}
else{
front=(front-1+max)%max;}
deque[front]=item;}
void insertrear(){
int item;
if((rear+1)%max==front){
printf("Insertion at rear not possible\n");
return;}
printf("Enter element:");
scanf("%d",&item);
if(front==-1){
front=rear=0;}
else{
rear=(rear+1)%max;}
deque[rear]=item;}
void deletefront(){
if(front==-1){
printf("Dequeue is empty\n");
return;}
printf("Delete element:%d\t",deque[front]);
if(front==rear){
front=rear=-1;}
else{
front=(front+1)%max;}}
void deleterear(){
if(rear==-1){
printf("dequeue is empty\n");
return;}
printf("deleted element:%d\t",deque[rear]);
if(front==rear){
front=rear=-1;}
else{
rear=(rear-1+max)%max;}}
void display(){
int i;
if(front ==-1){
printf("Deque is empty\n");
return;}
printf("Deque elements:");
i=front;
while(1){
printf("%d ",deque[i]);
if(i==rear)
break;
i=(i+1)%max;}}
int main(){
int choice;
while(1){
printf("\n deque\n");
printf("1.insertion at front\n");
printf("2.insertion at rear\n");
printf("3.delete from front\n");
printf("4.delete from rear\n");
printf("5.display\n");
printf("6.exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice){
case 1:
insertfront();
break;
case 2:
insertrear();
break;
case 3:
deletefront();
break;
case 4:
deleterear();
break;
case 5:
display();
break;
case 6:
return 0;
deafult:
printf("Invalid choice\n");}}
return 0;}

