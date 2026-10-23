#include <stdio.h>
void transpose(int a[][3],int m,int b[][3]){
int i,j,k=1;
int row=a[0][0],cols=a[0][1],terms=a[0][2];
b[0][0]=cols;
b[0][1]=row;
b[0][2]=terms;
for(i=0;i<cols;i++){
for(j=1;j<=terms;j++){
if(a[j][1]==i){
b[k][0]=a[j][1];
b[k][1]=a[j][0];
b[k][2]=a[j][2];
k++;}
}}}
int main(){
int A[4][3];
print("Enter elements for 4 rows and 3 columns:\n");
for(int i=0;i<4;i++){
for(int j=0;j<3;j++){
scanf("%d",&A[i][j]);}}
int B[][3];
transpose(A,4,B);
printf("Orginal sprase matrix:\n");
for(int i=0;i<A[0][2];i++){
printf("%d %d %d \n",A[i][0],A[i][1],A[i][2]);}
printf("Transposed Matrix:\n");
for(int i=0;i<B[0][2];i++){
printf("%d %d %d \n",B[i][0],B[i][1],B[i][2]);}
return 0;}
