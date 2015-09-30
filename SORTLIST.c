#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct dll
{
    long long x;
    struct dll *right;
    struct dll *left;
};

struct dll* top=NULL;
struct dll* bottom=NULL;

void insert_right(int a)
{
    struct dll *temp;
    temp=(struct dll*)malloc(sizeof(struct dll));
    if(bottom==NULL)
    {
        temp->x=a;
        top=temp;
        bottom=temp;
        top->left=NULL;
        bottom->right=NULL;
    }
    else
    {
        temp->x=a;
        bottom->right=temp;
        temp->left=bottom;
        temp->right=NULL;
        bottom=temp;
    }
}

void insert_left(int a)
{
    struct dll *temp;
    temp=(struct dll*)malloc(sizeof(struct dll));
    if(top==NULL)
    {
        temp->x=a;
        top=temp;
        bottom=temp;
        top->left=NULL;
        bottom->right=NULL;
    }
    else
    {
        temp->x=a;
        top->left=temp;
        temp->right=top;
        temp->left=NULL;
        top=temp;
    }
}

void display_left()
{
    struct dll *temp;
    temp=(struct dll*)malloc(sizeof(struct dll));
    temp=top;
    while(temp!=NULL)
    {
        printf("%d\n",temp->x);
        temp=temp->right;
    }
    printf("\n");
}

void display_right()
{
    struct dll *temp;
    temp=(struct dll*)malloc(sizeof(struct dll));
    temp=bottom;
    while(temp!=NULL)
    {
        printf("%d\n",temp->x);
        temp=temp->left;
    }
    printf("\n");
}

void del_top()
{
    struct dll *temp;
    temp=(struct dll*)malloc(sizeof(struct dll));
    temp=top;
    if(top==bottom) {top=NULL; bottom=NULL; free(temp);}
    else
    {
        (top->right)->left=NULL;
        top=top->right;
        free(temp);
    }
}

void del_bot()
{
    struct dll *temp;
    temp=(struct dll*)malloc(sizeof(struct dll));
    temp=bottom;
    if(top==bottom) {top=NULL; bottom=NULL; free(temp);}
    else
    {
        (bottom->left)->right=NULL;
        bottom=bottom->left;
        free(temp);
    }
}

struct dll* pivot(struct dll* a,struct dll*b)
{
    if(a==b) return a;
    struct dll *p,*q;
    long long t;
    p=(struct dll*)malloc(sizeof(struct dll));
    q=(struct dll*)malloc(sizeof(struct dll));
    p=a;
    q=a;

   // 8 9 12 5

    while(p!=NULL && p!=b)
    {
        if(p->x < b->x)
        {
            t=q->x;
            q->x=p->x;
            p->x=t;
            q=q->right;
        }
        p=p->right;
    }
    t=b->x;
    b->x=q->x;
    q->x=t;
    return q;
}

void qdls(struct dll* a,struct dll *b)
{
    struct dll *temp;
    temp=(struct dll*)malloc(sizeof(struct dll));
    if(a!=b && a!=b->right && b!=NULL && a!=NULL)
    {
        temp=pivot(a,b);
        if(temp->left!=a && temp->left!=NULL) qdls(a,temp->left);
        if(temp->right!=b && temp->right!=NULL)qdls(temp->right,b);
    }
}

int main()
{
    char a[50];
    int p,q;
    do
    {
    scanf("%s",a);
    if(!strcmp(a,"insertbeg")) {scanf("%d",&p); insert_left(p); }
    else if(!strcmp(a,"insertend")) {scanf("%d",&p); insert_right(p); }
    else if(!strcmp(a,"deletebeg")) {if(top!=NULL) {del_top(); }}
    else if(!strcmp(a,"deletelast")) {if(bottom!=NULL) {del_bot(); }}
    else if(!strcmp(a,"stop")) {scanf("%d",&p); if(top!=NULL) { qdls(top,bottom); if(!p) display_left(); else display_right();}}
    }while(strcmp(a,"stop"));
    return 0;
}
