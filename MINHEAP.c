#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int hsize;
//1-indexing

struct node
{
	char first[100];
	char last[100];
};

struct node a[1000001];

int comp(struct node a,struct node b)
{
	if(strcmp(a.first,b.first)>0) return 1;
	else if(strcmp(a.first,b.first)<0) return -1;
	else
	{
		if(strcmp(a.last,b.last)>0) return 1;
		else return -1;
	}
}

void perc_down(int i)
{
	int small,l,r;
	struct node temp;
	small=i;
	l=2*i;
	r=2*i+1;
	if(l<=hsize)
	{
		if(comp(a[l],a[i])==-1) small=l;
	}
	if(r<=hsize)
	{
		if(comp(a[r],a[small])==-1) small=r;
	}
	if(small!=i)
	{
		temp=a[i];
		a[i]=a[small];
		a[small]=temp;
		perc_down(small);
	}
}

int perc_up(int i)
{
	struct node temp;
	while(i>1)
	{
		if(comp(a[i],a[i/2])==-1)
		{
			temp=a[i];
			a[i]=a[i/2];
			a[i/2]=temp;
		}
		else break;
		i/=2;
	}
	return i;
}

void init(char p[100],char q[100])
{
	strcpy(a[1].first,p);
	strcpy(a[1].last,q);
	hsize=1;
}

int insert(char p[100],char q[100])
{
	hsize++;
	strcpy(a[hsize].first,p);
	strcpy(a[hsize].last,q);
	return perc_up(hsize);
}

void min_heap()
{
	printf("%s %s\n",a[1].first,a[1].last);
}

void delete_min()
{
	min_heap();
	a[1]=a[hsize];
	hsize--;
	perc_down(1);
}

void delete(int i)
{
	printf("%s %s\n",a[i].first,a[i].last);
	a[i]=a[hsize];
	hsize--;
	perc_down(i);
}

int main()
{
	char x[101],y[101],z[101];
	int t,d;
	scanf("%d",&t);
	hsize=0;
	while(t--)
	{
		scanf("%s",x);
		if(!strcmp(x,"InitHeap"))
		{
			scanf("%s %s",y,z);
			init(y,z);
		}
		else if(!strcmp(x,"Insert"))
		{
			scanf("%s %s",y,z);
			printf("%d\n",insert(y,z));
		}
		else if(!strcmp(x,"FindMin"))
		{
			if(hsize<=0) printf("-1\n");
			else min_heap();
		}
		else if(!strcmp(x,"DeleteMin"))
		{
			if(hsize<=0) printf("-1\n");
			else delete_min();
		}
		else if(!strcmp(x,"Delete"))
		{
			scanf("%d",&d);
			if(d>hsize || d<=0) printf("-1\n");
			else delete(d);
		}
		//printf("%d\n",hsize);
	}
	return 0;
}