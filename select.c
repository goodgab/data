#include<stdio.h>
int counter;
int partition(int array[],int first,int last)
{   
    int x=array[last];
    int i=first-1,temp;
    for(int j=first;j<=last-1;j++)
    {
        if(array[j]<=x){
        temp=array[++i];
        array[i]=array[j];
        array[j]=temp;
        counter++;
        }
    }
    temp=array[i+1];
    array[i+1]=array[last];
    array[last]=temp;
    counter++;
    return (i+1);
}
int select(int array[], int first, int last, int i)
{
    int middle,k;
   if(first == last) return array[first];
   middle = partition( array, first, last);
     k = middle - first + 1;
   if(i < k) return select(array, first, middle - 1, i);
   else if(i > k) return select(array, middle + 1, last, i - k);
   else return array[middle];
}
int main()
{
    int a, i;
    scanf("%d%d", &a, &i);
    int x[a];
    for(int i=0;i<a;i++)
    scanf("%d", &x[i]);
    select( x, 0, a-1, i);
    printf("%d ", counter);
}
