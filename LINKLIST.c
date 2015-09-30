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

void insert_right(int a,int b)
{
    struct dll *temp;
    temp=(struct dll*)malloc(sizeof(struct dll));
    if(bottom==NULL)
    {
        temp->x=a;
        temp->y=b;
        top=temp;
        bottom=temp;
        top->left=NULL;
        bottom->right=NULL;
    }
    else
    {
        temp->x=a;
        temp->y=b;
        bottom->right=temp;
        temp->left=bottom;
        temp->right=NULL;
        bottom=temp;
    }
}

void insert_left(int a,int b)
{
    struct dll *temp;
    temp=(struct dll*)malloc(sizeof(struct dll));
    if(top==NULL)
    {
        temp->x=a;
        temp->y=b;
        top=temp;
        bottom=temp;
        top->left=NULL;
        bottom->right=NULL;
    }
    else
    {
        temp->x=a;
        temp->y=b;
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
        printf("%d %d\n",temp->x,temp->y);
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
        printf("%d %d\n",temp->x,temp->y);
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

void del_all()
{
    struct dll *temp;
    temp=(struct dll*)malloc(sizeof(struct dll));
    while(top!=NULL)
    {
        temp=top;
        top=top->right;
        free(temp);
    }

}

int main()
{
    char a[50];
    int p,q;
    do
    {
    scanf("%s",a);
    if(!strcmp(a,"createlist")){ top=NULL; bottom=NULL;}
    else if(!strcmp(a,"insertbeg")) {scanf("%d %d",&p,&q); insert_left(p,q);}
    else if(!strcmp(a,"insertend")) {scanf("%d %d",&p,&q); insert_right(p,q);}
    else if(!strcmp(a,"deletebeg")) {if(top!=NULL) del_top();}
    else if(!strcmp(a,"deletelast")) {if(bottom!=NULL) del_bot();}
    else if(!strcmp(a,"deletelist")) {if(top!=NULL) del_all(); }
    else if(!strcmp(a,"printlist")) {scanf("%d",&p); if(top!=NULL) {if(!p) display_left(); else display_right();} else printf("NULL\n\n");}
    }while(strcmp(a,"0"));
    return 0;
}
