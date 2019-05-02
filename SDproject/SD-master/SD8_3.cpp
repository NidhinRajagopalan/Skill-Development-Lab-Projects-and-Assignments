#include<iostream>
using namespace std;

void search(int arr[],int n,int key,int f,int b,int a);
int fib(int n);
int main()
{
  int arr[20];
  int n,key,f;
  cout<<"Enter the total number of element"<<endl;
  cin>>n;
  cout<<"Enter the number";
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  cout<<"Enter the Element to be search"<<endl;
  cin>>key;
  search(arr,n,key,n,fib(n),fib(fib(n)));
  return 0;

}

void search(int arr[],int n,int key,int f,int b,int a)
{

 if(f<1||f>n)
    cout<<"The number is not Present";
 else if(key<arr[f])
    {
       if(a<=0)
        cout<<"The Element is not Present"<<endl;
        else
        search(arr,n,key,f-a,a,b-a);
    }
 else if(key>arr[f])
    {
        if(b<=1)
        cout<<"The Element is not Present";
        else
        search(arr,n,key,f+a,b-a,a-b);
    }
 else
    cout<<"The element is present at"<<f<<endl;
}

int fib(int n)
{
    int a,b,f;
    if(n<1)
       return n;
    a=0;
    b=1;
    while(b<n)
    {
       f=a+b;
       a=b;
       b=f;
    }
      return a;
}
