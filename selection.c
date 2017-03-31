#include<iostream>
using namespace std;

void swap(int& a,int& b)
{
   int t;
   t=a;
   a=b;
   b=t;
}
int main()
{
   int n,a[100001],m,c=0;
   cin>>n;
   for(int i=1;i<n+1;i++)
   cin>>a[i];
   
   for(int i=0;i<n-1;i++)
   {
      m=1;
      for(int j=2;j<=n-i;j++)
      if(a[m]<a[j])
      {
      m=j;
      c++;
      }
      
      swap(a[m],a[n-i]);
   }
   
   cout<<c;
   
}