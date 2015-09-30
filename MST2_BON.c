#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

struct edge
{
	int src,dest,weight;
};

struct set
{
	int parent,size;
};

struct set* subs;
struct edge* grape;
struct queue *rear,*front;
struct Graph* graph;
int **answer;
int **GAP;
int **inMST;

int higher(int a,int b)
{
	if(a>b) return a;
	return b;
}

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

struct AdjListNode* newAdjListNode(int data)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = data;
    newNode->next = NULL;
    return newNode;
}
 
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) 
{
    struct AdjListNode* newNode = newAdjListNode(dest); 
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode; //Assuming source exists

   	newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void BFS(struct Graph* g,int j)
{
	int *visit;
	struct AdjListNode *temp;
	temp=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	int n,y,i;
	n=g->V;
	visit=(int*)calloc(n,sizeof(int));
	enqueue(j);
	visit[j]=1;
	while(!isEmpty())
	{	
		y=dequeue();
		temp=g->array[y].head;
		while(temp!=NULL)
		{
			if(visit[temp->dest]==0)
			{
				visit[temp->dest]=1;
				enqueue(temp->dest);
				answer[j][temp->dest]=answer[temp->dest][j]=higher(answer[j][y],GAP[y][temp->dest]);
			}
			temp=temp->next;
		}
	}

}

int Find(int x)
{
	if(x!=subs[x].parent)
	{
		subs[x].parent=Find(subs[x].parent);
	}
	return subs[x].parent;
}

int Union(int x,int y)
{
	int xx,yy;
	xx=Find(x);
	yy=Find(y);
	if(subs[xx].size>subs[yy].size)
	{
		subs[yy].parent=xx;
		subs[xx].size+=subs[yy].size;
	}
	else if(subs[xx].size<subs[yy].size)
	{
		subs[xx].parent=yy;
		subs[yy].size+=subs[xx].size;
	}
	else
	{
		subs[xx].parent=yy;
		subs[yy].size+=subs[xx].size;
	}
}

int comp(const void* a,const void* b)
{
	struct edge* x=(struct edge*)a;
	struct edge* y=(struct edge*)b;
	return x->weight > y->weight;
}

int Kruskal(int v,int e)
{
	qsort(grape,e,sizeof(struct edge),comp);
	struct edge popoye[v-1];
	int t,i;
	for(i=0;i<v;i++)
	{
		subs[i].size=1;
		subs[i].parent=i;
	}
	i=0;
	t=0;
	int xx,yy;
	while(t<v-1)
	{
		xx=Find(grape[i].src);
		yy=Find(grape[i].dest);
		if(xx!=yy)
		{
			popoye[t]=grape[i];
			Union(xx,yy);
			t++;
		}
		i++;
	}
	int sum=0;
	for(i=0;i<v-1;i++)
	{
		sum+=popoye[i].weight;
		inMST[popoye[i].src][popoye[i].dest]=inMST[popoye[i].dest][popoye[i].src]=1;
		addEdge(graph,popoye[i].src,popoye[i].dest);
	}
	return sum;
}

int secondMST(int v,struct Graph* star)
{
	int i,j;
	int temp=100000001;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++) answer[i][j]=0;
	}
	for(i=0;i<v;i++)
	{
		BFS(star,i); //Fills the matrix representing max[u,v]
	}

	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(!inMST[i][j] && (GAP[i][j]-answer[i][j])<temp && GAP[i][j]>answer[i][j]) //Edge that doesn't belong to MST
			{
				temp=GAP[i][j]-answer[i][j];
			}
		}
	}
	// for(i=0;i<v;i++)
	// {
	// 	for(j=0;j<v;j++)
	// 	{
	// 		printf("%d ",answer[i][j]);
	// 	}
	// 	printf("\n");
	// }
	return temp;		
}

int main()
{
	int t,x,y,w,V,E,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&V);
		scanf("%d",&E);
		front=rear=NULL;
		subs=(struct set*)malloc(sizeof(struct set)*V);
		grape=(struct edge*)malloc(sizeof(struct edge)*E);
		GAP=(int**)malloc(sizeof(int*)*V);
		inMST=(int**)malloc(sizeof(int*)*V);
		answer=(int**)malloc(sizeof(int*)*V);
		for(i=0;i<V;i++)
		{
			answer[i]=(int*)malloc(sizeof(int)*V);
			inMST[i]=(int*)malloc(sizeof(int)*V);
			GAP[i]=(int*)malloc(sizeof(int)*V);
			for(j=0;j<V;j++)
			{
				answer[i][j]=0;
				GAP[i][j]=0;
				inMST[i][j]=0;
			}
		}
		graph = createGraph(V);
		for(i=0;i<E;i++)
		{
			scanf("%d",&x);
			scanf("%d",&y);
			scanf("%d",&w);
			grape[i].src=x-1;
			grape[i].dest=y-1;
			grape[i].weight=w;
			GAP[x-1][y-1]=GAP[y-1][x-1]=w;
		}
		int mst2=0;
		int testing;
		mst2=Kruskal(V,E);
		testing=secondMST(V,graph);
		// printf("First MST is %d\n",mst2);
		// printf("Second MST returned %d\n",testing);
		if(testing!=100000001) mst2+=testing;
		else mst2=-1;
		free(GAP);
		free(inMST);
		free(answer);
		free(graph);
		free(grape);
		free(subs);
		printf("%d\n",mst2);
	}
	return 0;
}