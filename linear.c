#include<stdio.h>

#include <math.h>

void swap(int *a,int *b);

int partitionbymedian(int A[],int p,int r,int M);

int select(int *A,int p,int r,int i);

int partition(int A[],int p,int r);

int linearselect(int A[],int p,int r,int i);

int main()

{

int A[10000];

int m,i;scanf("%d%d", &m, &i);

int x;

for(x = 0 ; x < m ; x++)scanf("%d", &A[x]);

linearselect(A,0,m-1,i);

}

int partitionbymedian(int A[],int p,int r,int M){

int i;

for(int k=p;k<=r;k++)

{

if(A[k]==M)

{

i=k;

break;

}

}

swap(&A[i], &A[r]);

return partition(A, p, r);

}

int select(int A[],int p,int r,int i)

{

int q,k;

if(p==r)return A[p];

q = partition( A, p, r);

k = q - p + 1;

if(i < k)return select(A, p, q - 1, i);

else if(i>k)return select(A, q + 1, r, i - k);

else return A[q];

}

int partition(int A[],int p,int r)

{

int x=A[r];

int i=p-1;

for(int j=p;j<=r;j++)

{

if(A[j]<x){

swap(&A[++i], &A[j]);

}

}

swap(&A[i+1], &A[r] );

return (i+1);

}

int linearselect(int A[],int p,int r,int i)

{



int t=r-p+1, M, q, k;

k =ceil(t/5.0);



if(t<=5)

{

return select(A, p, r, i);

}

int B[10000];



for(int c=0;c<k;c++)

{

int first=p+5*c;

int last = first+4;

if(c==k-1)

{

int a = t%5;

if(a>=1&&a<=2) B[c] = select(A, first, r , 1 );

else if(a<=4&&a>=3) B[c] = select(A, first, r, 2);

else B[c] = select(A, first, r, 3);

}

else

B[c]=select( A, first, last, 3);

}

M=linearselect( B, 0, k-1,ceil(k/2.0));

printf("%d\n", M);

q=partitionbymedian(A, p, r, M);



k=q-p+1;



if(i<k)

return linearselect(A, p, q-1, i);

else if(i>k)

return linearselect(A, q+1, r, i-k);

else

return A[q];

}

void swap(int *a,int *b)

{

int temp = *a;

*a = *b ;

*b = temp;

}