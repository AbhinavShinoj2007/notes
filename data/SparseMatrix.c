#include <stdio.h>
void sparse_add(int a[][3],int b[][3],int m,int n,int c[][3]){
int i=1,j=1,k=1;
if(a[0][0]==b[0][0]&&a[0][1]==b[0][1]){
while(i<=m&&j<=n){
if(a[i][0]==b[j][0]&&a[i][1]==b[j][1]){
c[k][1]=a[i][0];
c[k][1]=a[i][1];
c[k][2]=a[i][2]+b[j][2];
i++;j++;k++;}
else if (a[i][0]==b[j][0]){
if(a[i][1]<b[j][1]){
c[k][0]=a[i][0];
c[k][1]=a[i][1];
c[k][2]=a[i][2];
i++;k++;}
else{
c[k][0]=b[j][0];
c[k][1]=b[j][1];
c[k][2]=b[j][2];
k++;j++;}}
else if(a[i][0]<b[j][0]){
c[k][0]=a[i][0];
c[k][1]=a[i][1];
c[k][2]=a[i][2];i++;k++;}
else{
c[k][0]=b[j][0];
c[k][1]=b[j][1];
c[k][2]=b[j][2];
k++;j++;}}
while(i<=m){
c[k][0]=a[i][0];
c[k][1]=a[i][1];
c[k][2]=a[i][2];i++;k++;}
while(j<=n){
c[k][0]=b[j][0];
c[k][1]=b[j][1];
c[k][2]=b[j][2];j++;k++;}
c[0][0]=a[0][0];
c[0][1]=a[0][1];
c[0][2]=k-1;
printf("\n Resultant sparse matrix:\n");
for(int x=0;x<k;x++){
printf("%d %d %d\n",c[x][0],c[x][1],c[x][2]);}}
else{
printf("Matrix dimension donot match\n");}}
int main(){
int A[5][3]={{3,3,4},{0,0,5},{0,2,8},{1,1,10},{2,0,12}};
int B[4][3]={{3,3,3},{0,0,6},{1,1,15},{2,2,20}};
int C[50][3];
sparse_add(A,B,4,3,C);
printf("Resultant sparse matrix:\n");
for(int i=0;i<=C[0][2];i++){
printf("%d %d %d\n",C[i][0],C[i][1],C[i][2]);}
return 0;}
