#include<iostream>
using namespace std;
typedef struct emp
{
    int id;
    long int no;
    char name[20],dept[20],des[20];
    struct emp *next;
    struct emp *prev;
}node;

node *first=NULL;

node* add()
{
    node *a=new node;
    cout<<"Enter id: ";
    cin>>a->id;
    cout<<"Enter name: ";
    cin>>a->name;
    cout<<"Enter department: ";
    cin>>a->dept;
    cout<<"Enter designation: ";
    cin>>a->des;
    cout<<"Enter contact number: ";
    cin>>a->no;
    a->next=NULL;
    a->prev=NULL;
    return(a);
	
}

node* create(node *first)
{
	
    char p;
    do
    {		
        node *a,*newnode;
        newnode=add();
        if(first==NULL)
        {				
            first=newnode;
        }

        else
        {
            a=first;
            while(a->next!=NULL)
                {a=a->next;}
            a->next=newnode;
            newnode->prev=a;
        }

        cout<<"Do you wish to add one more? (Enter y/n)";
        cin>>p;
    }
    while(p=='y'||p=='Y');
    return(first);		
}

void display(node *first)
{
    if(first==NULL)
    {
        cout<<"No list exists\n";
    }
    else
    {
        node *a;
        a=first;
        cout<<"***********************************************************************\n";
        cout<<"ID\tName\tDepartment\tDesignation\tContact\n";
        while(a!=NULL)
        {
            cout<<a->id<<"\t"<<a->name<<"\t\t"<<a->dept<<"\t\t"<<a->des<<"\t"<<a->no<<"\n";
            a=a->next;
        }
        cout<<"***********************************************************************\n";
    }
}
node *insert_beg(node *first)
{
    node *newnode;
    newnode=add();
    newnode->next=first;
    newnode->prev=NULL;
    first->prev=newnode;
    return newnode;
}
node *insert_end(node *first)
{
    node *newnode;
    node *a=first;
    newnode=add();
    while(a->next!=NULL)
    {
        a=a->next;
    }
    a->next=newnode;
    newnode->prev=a;
    return a;
}
node *insert_pos(node *first)
{
    node *newnode;
    node *a=first;
    newnode=add();
    int eid;
    cout<<"Enter empid after which you wish to add?\n";
    cin>>eid;
    while(a->id!=eid && a->next!=	NULL)
    {
        a=a->next;
    }
    if(a->next==NULL)
    {
        cout<<"Underflow\n";
    }
    else
    {
        newnode->next=a->next;
        newnode->prev=a;
        (a->next)->prev=newnode;
        a->next=newnode;
    }
    return a;
}
int main()
{
    char op;
    do
    {
        long int c;
        node *a;
        cout<<"What do you wish to do? \n1] Create \n2] Display \n3] Insert at start \n";
        cout<<"4] Insert at end \n5] Insert at position\n";
        cin>>c;
        switch(c)
        {
            case 1: first=create(first);
                    break;
            case 2: display(first);
                    break;
            case 3: first=insert_beg(first);
                    break;
            case 4: a=insert_end(first);
                    break;
            case 5: a=insert_pos(first);
                    break;
            default:cout<<"Invalid\n";
        }
        cout<<"Do you wish to continue? (Enter y/n)\n";
        cin>>op;
    }while(op=='y'||op=='Y');
    return 0;
}



	



