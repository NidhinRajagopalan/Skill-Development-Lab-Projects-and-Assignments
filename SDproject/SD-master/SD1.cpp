#include<iostream>
using namespace std;
void create(int *,int,int);
void display(int *,int,int);
void sum(int *,int,int);
void del(int *,int,int);

int main()
{
    int arr[100],choice,n,i;
    
    do
    {      
        cout<<"\n\nEnter the no. elements of array\n";
        cin>>n;
    
        create(arr,n,i);
    
        cout<<"\nEnter -\n1 for displaying array\n2 for summing array elements\n3 for deleting\n4 for exiting\n\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                display(arr,n,i);
                break;
            }
            
            case 2:
            {
                sum(arr,n,i);
                break;
            }
            
            case 3:
            {
                del(arr,n,i);
                break;
            }
        
            case 4:
            {
                break;
            }
                
            default:
            {
               cout<<"Enter valid option";
               break;
            }
        }
    }
    
    while(choice!=4);
    
}

void create(int arr[],int n,int i)
{
    cout<<"Enter array elements\n";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

void display(int arr[],int n,int i)
{
    cout<<"The array elements are - \n";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"\n";
        
    }
                
}

void sum(int arr[],int n,int i)
{
    int temp=0;
    for(i=0;i<n;i++)
    {
        temp=temp+arr[i];        
    }
    cout<<"The sum is\n "<<temp;

}

void del(int arr[],int n,int i)
{
    int pos;
    cout<<"Enter position of the element you want to delete\n";
    cin>>pos;
    if(pos>n||pos<1)
    {
        printf("Enter valid position");
    }
    else
    {
        for(i=pos-1;i<n-1;i++)
        {
            arr[i]=arr[i+1];
        }
        cout<<"New array is - \n";
        for(i=0;i<n-1;i++)
        {
            cout<<arr[i]<<"\n";
        }
    }
}
