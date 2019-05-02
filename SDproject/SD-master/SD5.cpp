#include<iostream>
using namespace std;
typedef struct emp
{
	long int id,no;
	char name[50],dept[50],des[50];
	struct emp *next;
	struct emp *pre;
}node;
node *first=NULL;
node *accept()
{
	node *a;
	a=new node;
	cout<<"Enter id: ";
	cin>>a->id;
	cout<<"Enter name: ";
	cin>>a->name;
	cout<<"Enter the department: ";
	cin>>a->dept;
	cout<<"Enter designation: ";
	cin>>a->des;
	cout<<"Enter contact number: ";
	cin>>a->no;
	a->next=NULL;
	a->pre==NULL;
	return(a);
}
node *create(node *first)
{
	char p;
	do
	{
		node *a,*b,*newnode;
		newnode=accept();
		if(first==NULL)
		{
			first=newnode;
		}
		else
		{
			a=first;
			while(a->next!=NULL)
                a=a->next;
            a->next=newnode;
            newnode->pre=a;
		}
		cout<<"Do you wish to create another one?\n";
		cin>>p;
	}while(p=='y'||p=='Y');
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
		cout<<"_______________________________________________________________________\n";
		cout<<"ID\tName\tDepartment\tDesignation\tContact\n";
		while(a!=NULL)
		{
			cout<<a->id<<"\t"<<a->name<<"\t\t"<<a->dept<<"\t\t"<<a->des<<"\t"<<a->no<<"\n";
			a=a->next;
		}
	}
}
node *del_beg(node *first)
{
	node *temp=first;
	first=first->next;
	temp->next=NULL;
	first->pre=NULL;
	delete temp;
	return first;
}
void del_end(node *first)
{
	node *a=first;
	while(a->next!=NULL)
	{
		a=a->next;
	}
	node *b;
	b=a->pre;
	b->next=NULL;
	a->pre=NULL;
	delete a;
}
void del_pos(node *first)
{
	node *temp=first;
	temp=temp->next;
	node *a=first;
	int eid;
	cout<<"Enter the employee id you wish to delete\n";
	cin>>eid;
	while(temp->id!=eid)
	{
		temp=temp->next;
		a=a->next;
	}
	a->next=temp->next;
	(temp->next)->pre=a;
	delete temp;
}
int main()
{
	char op;
	do
	{
		long int c;
		node *a;
		cout<<"What do you wish to do?\n1] Create\n2] Display\n ";
		cout<<"3] Delete from start\n4] Delete from end\n5] Delelte from position\n";
		cin>>c;
		switch(c)
		{
			case 1: first=create(first);
				break;
			case 2: display(first);
				break;
			case 3: first=del_beg(first);
				break;
			case 4: del_end(first);
				break;
			case 5: del_pos(first);
				break;
			default:cout<<"Invalid\n";
		}
		cout<<"Do you wish to continue?\n";
		cin>>op;
	}while(op=='y'||op=='Y');
	return 0;
}
