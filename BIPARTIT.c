#include <stdio.h>
#include <stdlib.h>
 
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

void addEdge(struct Graph* graph, int src, int dest) //OK
{
    struct AdjListNode* newNode = newAdjListNode(dest); 
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode; //Assuming source exists

   	newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void BiPartite(struct Graph* g,int j)
{
	int color[g->V];
	int flag=0;
	struct AdjListNode *temp;
	temp=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	int n,y,i;
	n=g->V;
	for(i=0;i<n;i++) color[i]=-1;
	color[j]=1;
	enqueue(j);
	while(!isEmpty())
	{	
		y=dequeue();
		temp=g->array[y].head;
		while(temp!=NULL)
		{
			if(color[temp->dest]==-1)
			{
				color[temp->dest]=(1+color[y])%2;
				enqueue(temp->dest);
			}
			else if(color[temp->dest]==color[y])
			{
				flag=1;
				break;
			}
			temp=temp->next;
		}
	}
	if(flag) printf("NO\n");
	else printf("YES\n");
}

int main()
{
    int t;
	int V,E,i,x,y;
    scanf("%d",&t);
    while(t--)
    {
		scanf("%d",&V);
		scanf("%d",&E);
		struct Graph* graph = createGraph(V);
		for(i=0;i<E;i++)
		{
			scanf("%d",&x);
			scanf("%d",&y);
			addEdge(graph,x-1,y-1);
		}
		BiPartite(graph,1);
	}
    return 0;
}