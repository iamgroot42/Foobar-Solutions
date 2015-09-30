#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data
{
    int *a;
    int top;
};

struct data stack;
int m;

int push(int k)
{
    if(stack.top<m-1)
    {
    stack.top++;
    stack.a[stack.top]=k;
    return 1;
    }
    if(stack.top==m-1)
    {
        int *b;
        int i;
        if((b=(int*)malloc(sizeof(int)*m*2))==NULL) return -1;
        else
        {
            for(i=0;i<m;i++) b[i]=stack.a[i];
            stack.a=b;
            stack.top++;
            stack.a[stack.top]=k;
            //for(i=0;i<=stack.top;i++) printf("%d,",stack.a[i]);
            m*=2;
            return 0;
        }
    }

}

int pop()
{
    if(stack.top==-1) {return -1;}
    int lol;
    lol=stack.top;
    stack.top--;
    return stack.a[lol];
}

int isempty()
{
    if(stack.top==-1) return 1;
    return 0;
}

int top()
{
    if(stack.top==-1) return -1;
    return stack.a[stack.top];
}

int main()
{
    int t,k;
stack.top=-1;
    char s[10];
    scanf("%d",&m);
    scanf("%d",&t);
    stack.a=(int *)malloc(sizeof(int)*m);
    while(t--)
    {
        scanf("%s",s);
        if(!strcmp(s,"pop")) { printf("%d\n",pop()); }
        else if(!strcmp(s,"isempty")) { printf("%d\n",isempty()); }
        else if(!strcmp(s,"top")) { printf("%d\n",top());}
        else { scanf("%d",&k); printf("%d\n",push(k)); }
    }
    return 0;
}
