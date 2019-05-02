#include <iostream>
using namespace std;
#define size 5
class pizza
{
  int porder[size];
  int front,rear;
public:
    pizza()
    {
        front=rear=-1;
    }
    int qfull()
    {
        if((front==0)&&(rear==(size-1))||(front==(rear+1)%size))
        return 1;
        else
        return 0;
     }
    int qempty()
    {
        if(front==-1) 
        return 1; 
        else 
        return 0;
    }
      void accept_order(int);
      void make_payment(int);
      void order_in_queue();
};

void pizza::accept_order(int item)
{
  if(qfull())
    cout<<"No more orders."<<endl;
  else
    {
        if(front==-1)
            {
                front=rear=0;
            }
        else
          {
            rear=(rear+1)%size; 
          }
          porder[rear]=item; 
    }
}
 
void pizza::make_payment(int n)
{
    int item; 
    char ans; 
    if(qempty()) 
      cout<<"Order is not there"<<endl;
    else 
      {
        cout<<"Deliverd orders as follows: "<<endl;
        for(int i=0;i<n;i++)
            {
               item=porder[front];
               if(front==rear)
                    {
                    front=rear=-1;
                    }
                else
                    {
                    front=(front+1)%size;
                    }
                cout<<"\t"<<item;
              }
        cout<<"Total amount to pay : "<<n*100<<endl;
        cout<<"Thank you "<<endl;
      }
}
 
void pizza::order_in_queue()
{
  int temp;
  if(qempty())
    {
        cout<<"There is no pending order."<<endl;
    }
  else
    {
        temp=front;
        cout<<"Pending Order as follows."<<endl;
        while(temp!=rear)
        {
            cout<<"\t"<<porder[temp];
            temp=(temp+1)%size;
        }
        cout<<"\t"<<porder[temp];
    }
}
int main()
{
  pizza p1;
  int ch,k,n;
  do
  {
    cout<<"Welcome To Pizza Parlor"<<endl;
    cout << "1.Accept order, 2.Make payment, 3.Pending Orders \n Enter your choice: "<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1: cout<<"Which Pizza do u like most: "<<endl;
                cout<<"1.Veg Soya Pizza, 2.Veg butter Pizza, 3.Egg_Pizza"<<endl;
                cout<<"Please enter your order: ";
                cin>>k;
               p1.accept_order(k);
        break; 
        
        case 2: cout<<"How many Pizza ?";
                cin>>n;
                p1.make_payment(n);
        break;
        
        case 3: cout<<"\n Following orders are in queue to deliver....as follows..\n";
                p1.order_in_queue();
                break;
    } 
  }while(ch!=4);
 
  return 0;
}
