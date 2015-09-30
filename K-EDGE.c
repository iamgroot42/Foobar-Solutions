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

int min(int a,int b)
{
	if(a>b) return b;
	else return a;
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

void printGraph(struct Graph* graph) //OK
{
    int v;
    if(graph==NULL) {printf("Empty Graph\n"); return;}
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("%c = ", v+'A');
        while (pCrawl)
        {
            printf("-> %c", (pCrawl->dest)+'A');
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int tim;
int flag;
int *arrive,*parent,*mbe,*visit;

void edge2(struct Graph* g,int v)
{
	if(flag==1) return;
	visit[v]=1;
	int p;
	arrive[v]=mbe[v]=tim;
	tim++;
	struct AdjListNode* temp;
	temp=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	temp=g->array[v].head;
	while(temp!=NULL)
	{
		p=temp->dest;
		if(visit[p]==0)
		{
			parent[p]=v;
			edge2(g,p);
			mbe[v]=min(mbe[v],mbe[p]);
		}
		else if(parent[v]!=p)
		{
			mbe[v]=min(mbe[v],arrive[p]);
		}
		if((mbe[p]>arrive[v]) && (!flag)) {flag=1; return;} // && parent[v]!=-1 ?
		temp=temp->next;
	}
}

int main()
{
    int V,E,x,y,t,i;
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
		tim=1;
		flag=0;
		arrive=(int*)malloc(sizeof(int)*V);
		mbe=(int*)malloc(sizeof(int)*V);
		visit=(int*)malloc(sizeof(int)*V);
		parent=(int*)malloc(sizeof(int)*V);
		for(i=0;i<V;i++)
		{
			arrive[i]=0;
			parent[i]=-1;
			visit[i]=0;
			mbe[i]=0;;
		}
		edge2(graph,0);
		// printGraph(graph);
		// for(i=0;i<V;i++)
		// {
		// 	printf("%c : D:%d , L:%d\n",'A'+i,arrive[i],mbe[i]);
		// }
		for(i=0;i<V;i++)
		{
			if(!visit[i]) flag=3;
		}
		if(E<2) flag=2;
		//  
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
    return 0;
}