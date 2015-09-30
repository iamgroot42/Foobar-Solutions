#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct dll
{
    int x,y;
    struct dll *right;
    struct dll *left;
};

struct dll* top=NULL;
struct dll* bottom=NULL;
struct dll* top3=NULL;
struct dll* bottom3=NULL;

int compare(struct dll* a,struct dll* b)
{
    if(a->x > b->x) return 1;
    else if(a->x < b->x) return -1;
    else
    {
        if(a->y > b->y) return 1;
        else return -1;
    }
}

void insert_right(struct dll** p,struct dll** q,int a,int b)//p is top,q is bottom
{
    struct dll *temp;
    temp=(struct dll*)malloc(sizeof(struct dll));
    if((*q)==NULL)
    {
        temp->x=a;
        temp->y=b;
        (*p)=temp;
        (*q)=temp;
        (*p)->left=NULL;
        (*q)->right=NULL;
    }
    else
    {
        temp->x=a;
        temp->y=b;
        (*q)->right=temp;
        temp->left=(*q);
        temp->right=NULL;
        (*q)=temp;
    }
}

void insert_left(struct dll** p,struct dll** q,int a,int b)//p is top,q is bottom
{
    struct dll *temp;
    temp=(struct dll*)malloc(sizeof(struct dll));
    if((*p)==NULL)
    {
        temp->x=a;
        temp->y=b;
        (*p)=temp;
        (*q)=temp;
        (*p)->left=NULL;
        (*q)->right=NULL;
    }
    else
    {
        temp->x=a;
        temp->y=b;
        (*p)->left=temp;
        temp->right=(*p);
        temp->left=NULL;
        (*p)=temp;
    }
}

void display_left(struct dll *a)//a is top
{
    struct dll *temp;
    temp=(struct dll*)malloc(sizeof(struct dll));
    temp=a;
    while(temp!=NULL)
    {
        printf("%d %d\n",temp->x,temp->y);
        temp=temp->right;
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
    while(p!=NULL && p!=b)
    {
        if(compare(p,b)==-1)
        {
            t=q->x;
            q->x=p->x;
            p->x=t;
            t=q->y;
            q->y=p->y;
            p->y=t;
            q=q->right;
        }
        p=p->right;
    }
    t=b->x;
    b->x=q->x;
    q->x=t;
    t=b->y;
    b->y=q->y;
    q->y=t;
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
    int t,x,y;
    do
    {
        scanf("%d",&t);
        if(t==1) {scanf("%d %d",&x,&y); insert_left(&top,&bottom,x,y);}
        if(t==2) {scanf("%d %d",&x,&y); insert_right(&top,&bottom,x,y);}
    }while(t);
    do
    {
        scanf("%d",&t);
        if(t==1) {scanf("%d %d",&x,&y); insert_left(&top,&bottom,x,y);}
        if(t==2) {scanf("%d %d",&x,&y); insert_right(&top,&bottom,x,y);}
    }while(t);
    qdls(top,bottom);
    struct dll *temp1;
    temp1=(struct dll*)malloc(sizeof(struct dll));
    temp1=top;
    while(temp1!=NULL)
    {
        if(temp1->right!=NULL) { while( (((temp1->right)->x) == (temp1->x)) && (((temp1->right)->y) == (temp1->y)) ) {temp1=temp1->right; if(temp1==NULL) break; }}
        insert_right(&top3,&bottom3,temp1->x,temp1->y);
        temp1=temp1->right;
    }
    display_left(top3);
    return 0;
}
