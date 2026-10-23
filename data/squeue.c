#include <stdio.h>
#define max 5
int deque[max];
int front=-1,rear=-1;
void insertrear(){
int item;
if(rear==max-1){
printf("Insertion at rear not possible\n");
return;}
printf("Enter element:");
scanf("%d",&item);
if(front==-1){
front=rear=0;}
else{
rear++;}
deque[rear]=item;}
void deletefront(){
if(front==-1){
printf("Dequeue is empty\n");
return;}
printf("Delete element:%d\t",deque[front]);
if(front==rear){
front=rear=-1;}
else{
front++;}}
void display(){
int i;
if(front ==-1){
printf("Deque is empty\n");
return;}
printf("Deque elements:");
for(i=front;i<=rear;i++){
printf("%d\t",deque[i]);}}
int main(){
int choice;
while(1){
printf("\n deque\n");
printf("1.insertion at rear\n");
printf("2.delete from front\n");
printf("3.display\n");
printf("4.exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice){
case 1:
insertrear();
break;
case 2:
deletefront();
break;
case 3:
display();
break;
case 4:
return 0;
deafult:
printf("Invalid choice\n");}}
return 0;}

