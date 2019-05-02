#include<iostream>
using namespace std;
void copy(char *);
void reverse(char *);
int length(char *);
void sub(char *);

int main()
{
    char str1[100];
    int choice;
    
    do
    {
     
        cout<<"\n\nEnter the string on which you want to perform an operation\n";
        cin>>str1;
    
        cout<<"Enter the operation you want to perform - \n1 to copy\n2 to reverse\n3 to obtain a substring\n4 to exit\n";
        cin>>choice;
    
        switch(choice)
        {
            case 1:
            {
                copy(str1);
                break;
            }
        
            case 2:
            {
                reverse(str1);
                break;
            }
        
            case 3:
            {
                sub(str1);
                break;
            }
            
           case 4:
            {
                break;
            }
        
            default:
            cout<<"Enter valid option";
            break;
                  
        }
    }
    while(choice!=4);
            
}

void copy(char *p)
{
    char cop[100],*q;
    q=cop;
    for(p;*p!='\0';p++)
    {
        *q=*p;
        q++;
    }
    *q='\0';
    cout<<"Copied string is - "<<cop;
}

void reverse(char *p)
{
    int n=length(p);
    int i;
    char *inc,*dec,temp;
    inc=p;
    dec=p;
    for(i=0;i<(n-1);i++)
    {
        dec++;
    }
    for(i=0;i<(n/2);i++)
    {
        temp=*inc;
        *inc=*dec;
        *dec=temp;
        inc++;
        dec--;
    }
    cout<<p;
    
}

int length(char *p)
{
    int n=0;
    while(*p!='\0')
    {
        p++;
        n++;
    }
    return(n);
}

void sub(char *p)
{
    int i,pos,len;
    char substring[100],*q;
    q=substring;
    cout<<"Enter the position from which you create a substring - ";
    cin>>pos;
    cout<<"Enter the length of the substring - ";
    cin>>len;
    for(i=0;i<len;i++)
    {
        *q=*(p+(pos-1));
        q++;
        pos++;
    }
    *q='\0';
    
    cout<<substring;
            
}