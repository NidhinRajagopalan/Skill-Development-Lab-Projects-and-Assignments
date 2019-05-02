#include <iostream>
using namespace std;
const int siz=100;
struct stack
{
    char s[siz];
    int top;
}st;
int stempty()
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}
int stfull()
{
    if(st.top==siz-1)
        return 1;
    else
        return 0;
}
void push(char item)
{
    if(stfull())
    {
        cout<<"Overflow in push\n";
    }
    else
    {
        st.top++;
        st.s[st.top]=item;
    }
}
char pop()
{
    if(stempty())
    {
        cout<<"Underflow in pop\n";
        return 0;
    }
    else
    {
        char item;
        item=st.s[st.top];
        st.top--;
        return(item);
    }
}
void display()
{
   int i;
   if(stempty())
		cout<<"stack is empty\n";
   else
    {
        for(i=st.top;i>=0;i--)
            cout<<st.s[i];
   }
}
char readtop()
{
    if(stempty())
        return 0;
    else
    {
        char item;
        item=st.s[st.top];
        return(item);
    }
}

int strlen(char *str)
{
    int len=0;
    for(int i=0;*(str+i)!='\0';i++)
        len++;
    return (len);
}
int operand(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
}
int pref(char p)
{
    if(p=='+' || p=='-')
        return 1;
    else if(p=='*' || p=='/')
        return 2;
    else if(p=='(' || p==')' || p=='^')
        return 3;
    else if(p=='\0')
        return -1;
    else
        return 0;
}
void intopo(char *str)
{
    int i=0;
    for(i=0;i<=strlen(str);i++)
    {
        int pc=pref(str[i]);
        char s=readtop();
        int pp=pref(s);
        if(pref(str[i])==0)
            cout<<str[i];
        else if(pc==-1)
        {
            while(st.top!=-1)
            {
                char ele=pop();
                if(ele!='(' && ele!=')')
                cout<<ele;
            }
        }
        else if(str[i]==')')
        {
             while (!stempty() && readtop() != '(')
             {
                char ele=pop();
                if(ele!='(' && ele!=')')
                    cout<<ele;
             }
        }
        else if(readtop()=='(')
                    push(str[i]);
        else
        {
            while (!stempty() && pref(str[i]) <= pref(readtop()))
            {
                char ele=pop();
                if(ele!='(' && ele!=')')
                    cout<<ele;
            }
            push(str[i]);
        }
    }
}
int main()
{
    st.top=-1;
    char op;
    do
    {
        char str[50];
        cout<<"Enter the infix expression\n";
        cin>>str;
        intopo(str);
        cout<<"\nDo you wish to go again? ";
        cin>>op;
    }while(op=='y' || op=='Y');
    return 0;
}
