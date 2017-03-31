#include<iostream>
using namespace std;

int swap(int& a,int& b)
{
   int t;
   t=a;
   a=b;
   b=t;
   return 1;
}
int main()
{
   int n,*a,c=0;
   cin>>n;
   a=new int[n];
   
   for(int i=0;i<n;i++)
   cin>>a[i];
   
   for(int i=n-1;i>=1;i--)
   for(int j=0;j<n-1;j++)
   if(a[j]>a[j+1])
   c+=swap(a[j],a[j+1]);
   
   cout<<c;
}