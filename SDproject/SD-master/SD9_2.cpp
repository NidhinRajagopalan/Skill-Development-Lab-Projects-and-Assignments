#include<iostream>
#include<stdlib.h>

using namespace std;

struct friends
{
    char name[10][20];
    long long int ph[10];
    int roll[10];
}obj;


void search(char name[][20],long long int ph[],int roll[],int r,int front,int rear)
{
    int mid;
    while(rear>=1)
    {
        mid=(front+rear)/2;

        if(roll[mid]<r)
        {
            search(name,ph,roll,r,mid+1,rear);
        }
        else if(roll[mid]==r)
        {
            cout<<"\n"<<r<<" found at "<<mid+1<<" position"<<endl;
            cout<<"\n\t  details of searched friend are as follows : ";
            cout<<"\n\t  name : "<<name[mid];
            cout<<"\n\t  phone number : "<<ph[mid];
            cout<<"\n\t  roll number : "<<roll[mid]<<endl;
            exit(0);
        }
        else if(roll[mid]>r)
        {
            search(name,ph,roll,r,front,mid-1);
        }
    }
    cout<<"\n data not found ";
}

int main()
{
    int num;
    cout<<"\n enter the number of friends : ";
    cin>>num;


    cout<<"\n enter the name, phone number and roll number of "<<num<<" friends : \n";
    for(int i=0;i<num;i++)
    {
        cout<<i+1<<" name : ";
        cin>>obj.name[i];
        cout<<i+1<<" phone number : ";
        cin>>obj.ph[i];
        cout<<i+1<<" roll number : ";
        cin>>obj.roll[i];
    }


    int r;
    cout<<"\n\n enter the roll number you want to search : ";
    cin>>r;

    search(obj.name,obj.ph,obj.roll,r,0,num-1);

return 0;
}
