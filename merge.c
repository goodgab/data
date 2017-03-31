#include<iostream>
using namespace std;
 
int counter=0;
void Merge(int array[], int first, int middle,int last) 
{ 
    int i,j,t,*temp; 
    i=first;
    j=middle+1;
    t=0;
    temp=new int[last];
    while(i<=middle&&j<=last) 
    { 
        if(array[i]<array[j]){ 
        temp[t++]=array[i++];
        } 
        else{ 
        temp[t++]=array[j++];
        }
        counter++;
    } 
    while(i<=middle){ 
        temp[t++]=array[i++];} 
    while(j<=last){ 
        temp[t++]=array[j++];
        }
    i=first;t=0; 
    while(i<=last){
        array[i++]=temp[t++];}
}
void MergeSort(int array[], int first,int last) 
{ 
    int middle; 
    if(first<last) 
    { 
        middle=(first+last)/2;
        MergeSort(array, first,middle); 
        MergeSort(array, middle+1, last);
        Merge(array, first, middle, last);
    } 
}
int main() 
{ 
    int i,a,*x;
    cin>>a;
    x=new int[a];
    for(i=0;i<a;i++) 
    cin>>x[i];
    MergeSort(x, 0, a-1); 
    cout<<counter;
}