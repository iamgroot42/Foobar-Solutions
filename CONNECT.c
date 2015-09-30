#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Code taken from BFS ; Seg fault? :-?
 
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

struct AdjList
{
    struct AdjListNode *head;  
};
 
struct Graph
{
    int V;
    struct AdjList* array;
};

struct queue
{
	int Data;
	struct queue* next;
};

struct queue *rear,*front;

int dequeue()
{
      struct queue *temp, *var=front;
      if(front==NULL) return -1;
      else
      {				
		int j=front->Data;      	
        front = front->next;
        free(var);
        return j;
      }
}

int isEmpty()
{
	if(front==NULL) return 1;
	else return 0;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void enqueue(int value)
{
     struct queue *temp;
     temp=(struct queue *)malloc(sizeof(struct queue));
     temp->Data=value;
     if (front == NULL)
     {
           front=temp;
           front->next=NULL;
           rear=front;
     }
     else
     {
           temp->next=NULL;
           rear->next=temp;
           rear=temp;
     }
}
 //Un-Directed 

struct AdjListNode* newAdjListNode(int data) //OK
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = data;
    newNode->next = NULL;
    return newNode;
}
 
struct Graph* createGraph(int V) //OK
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}
	
void addVertices(struct Graph* g,int n) //Unexpected behaviour
{
	int p,i;
	p=g->V;
	p+=n;
	struct AdjList* temp;
	temp=(struct AdjList*)realloc(g->array,sizeof(p*sizeof(struct AdjList)));
	if(!temp)
	{
		printf("Could not increase size\n");
	}
	else
	{
		g->array=temp;
	}
	for(i=g->V;i<p;i++)
		g->array[i].head=NULL;
	g->V=p;
}

void addEdge(struct Graph* graph, int src, int dest) //OK
{
    struct AdjListNode* newNode = newAdjListNode(dest); 
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode; //Assuming source exists

   	newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void deleteEdge(struct Graph* g,int i,int j) //OK
{
	struct AdjListNode* co;
	int flag;
	flag=0;
	if(i>=g->V) { return;}
	co=g->array[i].head;
	if(co==NULL) { return;}
	if(co->next==NULL && co->dest==j)
	{
		g->array[i].head=NULL;
		return;
	}
	while(co->next!=NULL)
	{
		if((co->next)->dest==j)
		{
			co->next=(co->next)->next;
			flag=1;
			break;
		}
		co=co->next;
	}
}

void deleteNode(struct Graph* g,int i) //OK
{
	int j; 
	for(j=0;j<g->V;j++)
	{
		deleteEdge(g,j,i);
	}
	while(g->array[i].head!=NULL)
	{
		g->array[i].head=(g->array[i].head)->next;
	}
}

void printGraph(struct Graph* graph) //OK
{
    int v;
    if(graph==NULL) {printf("Empty Graph\n"); return;}
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("%d = ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

void deleteGraph(struct Graph* g)
{
	int i;
	for(i=0;i<g->V;i++)
	{
		while(g->array[i].head!=NULL)
		{
			g->array[i].head=(g->array[i].head)->next;
		}
	}
	free(g);
}

int *visit,*parent,*level,*label;

void BFS(struct Graph* g,int j,int z)
{
	struct AdjListNode *temp;
	temp=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	int n,y,i;
	n=g->V;
	enqueue(j);
	visit[j]=1;
	label[j]=z;
	parent[j]=-1; // No parent
	while(!isEmpty())
	{	
		y=dequeue();
		temp=g->array[y].head;
		while(temp!=NULL)
		{
			if(visit[temp->dest]==0 && label[temp->dest]==0)
			{
				visit[temp->dest]=1;
				label[temp->dest]=z;
				parent[temp->dest]=y;
				level[temp->dest]=level[y]+1;
				enqueue(temp->dest);
			}
			temp=temp->next;
		}
	}
}

int labelComponent(struct Graph* g)
{
	int i,v,j;
	v=g->V;
	j=1;
	for(i=0;i<v;i++)
	{
		struct AdjListNode* pCrawl = g->array[i].head;
		if(pCrawl==NULL)
		{
			label[i]=j;
			j++;
		}
		else
		{
			while(pCrawl!=NULL)
			{
				if(visit[pCrawl->dest]==0)
				{
					// printf("CALLING\n");
					BFS(g,pCrawl->dest,j);
					j++;
				}
				pCrawl=pCrawl->next;
			}
		}
	}
	return j-1;
}

int main()
{
    int V,E,i,x,y;
    scanf("%d",&V);
    scanf("%d",&E);
	struct Graph* graph = createGraph(V);
    visit=(int*)malloc(sizeof(int)*V);
    parent=(int*)malloc(sizeof(int)*V);
    level=(int*)malloc(sizeof(int)*V);
    label=(int*)malloc(sizeof(int)*V);
    for(i=0;i<V;i++)
    {
    	visit[i]=parent[i]=level[i]=label[i]=0;
    }
    for(i=0;i<E;i++)
    {
    	scanf("%d",&x);
    	scanf("%d",&y);
    	addEdge(graph,x-1,y-1);
    }
	// printGraph(graph);
	int zz;
	zz=labelComponent(graph);
	printf("%d\n",zz);
	int* lel;
	lel=(int*)malloc(sizeof(int)*zz);
	for(i=0;i<zz;i++) lel[i]=0;
	for(i=0;i<V;i++)
	{
		lel[label[i]-1]++;
	}
	qsort(lel,zz,sizeof(int),cmpfunc);
	for(i=zz-1;i>=0;i--)
	{
		printf("%d\n",lel[i]);
	}
    return 0;
}