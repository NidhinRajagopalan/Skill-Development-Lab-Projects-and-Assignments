#include<iostream>
using namespace std;
int length(char *);
void pal(char *);
int comp(char *,char *);
int main()
{
    char str1[100],str2[100];
    int choice,len,check;
    
    do
    {
        cout<<"\n\nEnter string\n";
        cin>>str1;
    
        cout<<"Enter -\n1 to find the length of a string\n2 to check whether string is a palindrome\n3 to compare two strings\n4 to exit\n";
        cin>>choice;
    
        switch(choice)
        {
            case 1:
            {
                len=length(str1);
                cout<<"The length is - "<<len;
                break;
            }
         
            case 2:
            {
                pal(str1);
                break;
            }
        
            case 3:
            {
                cout<<"Enter string 2";
                cin>>str2;
                check=comp(str1,str2);
                if(check==0)
                {
                    cout<<"The strings are same";
                }
                else cout<<"Strings are different";
            }
        
            case 4:
            {break;}
        
            default:
            {
                cout<<"Enter a valid option";
                break;
            }
         
        }
    }
    while(choice!=4);
}

int length(char *p)
{
    int j=0;
    while(*p!=0)
    {
        p++;
        j++;
    }
    return(j);
}

void pal(char *p)
{
    int i,n,check;
    char rev[100],*q;
    q=rev;
    n=length(p);
    for(i=n-1;i>=0;i--)
    {
        *q=*(p+i);
        q++;
    }
    *q='\0';
    check=comp(p,rev);
    if(check==0)
        {
            cout<<"The string is a palindrome";
        }
    else cout<<"String isn't a palindrome";
}
 
int comp(char *p,char *q)
{
    int flag=0;
    while(*p!='\0'&&*q!='\0')
    {
        if(*p!=*q)
            flag=1;
        p++;
        q++;
    }
    return(flag);
}