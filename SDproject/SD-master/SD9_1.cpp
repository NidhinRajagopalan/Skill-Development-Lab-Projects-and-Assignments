#include<iostream>
#include<stdlib.h>

using namespace std;

struct friends
{
    char name[20];
    long long int ph;
    int roll;
};

int main()
{
    int num;
    cout<<"\n enter the number of friends : ";
    cin>>num;

    friends obj[num];
    cout<<"\n enter the name, phone number and roll number of "<<num<<" friends : \n";
    for(int i=0;i<num;i++)
    {
        cout<<i+1<<" name : "; cin>>obj[i].name;
        cout<<i+1<<" phone number : "; cin>>obj[i].ph;
        cout<<i+1<<" roll number : "; cin>>obj[i].roll;
    }


    int r;
    cout<<"\n\n enter the roll number you want to search : ";
    cin>>r;

    int front=0,rear=num-1,mid;
    mid=(front+rear)/2;

    while(front<=rear)
    {

        if(obj[mid].roll<r)
        {
            front=mid+1;
        }
        else if(obj[mid].roll==r)
        {
            cout<<"\n"<<r<<" found at "<<mid+1<<" position"<<endl;
            cout<<"\n\t  details of searched friend are as follows : ";
            cout<<"\n\t  name : "<<obj[mid].name;
            cout<<"\n\t  phone number : "<<obj[mid].ph;
            cout<<"\n\t  roll number : "<<obj[mid].roll<<endl;
            exit(0);
        }
        else if(obj[mid].roll>r)
        {
            rear=mid-1;
        }

        mid=(front+rear)/2;
    }
    cout<<"\n data not found ";

return 0;
}
