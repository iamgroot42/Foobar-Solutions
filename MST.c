#include <stdio.h>
#include <stdlib.h>
 
 #define maxx 1000000

struct AdjListNode
{
    int dest,weight;
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
            printf("-> %c(%d)", (pCrawl->dest)+'A',pCrawl->weight);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

 //Un-Directed 

struct heeep
{
    int v,z;
};

struct potato
{
    int ans;
    int p,q;
};

struct heeep* heep;
int *pos;
int hsize; //0-indexing

int cmpf(const void * a, const void * b)
{
   struct potato* x=(struct potato*)a;
   struct potato* y=(struct potato*)b;
   return  x->ans > y->ans ;
}

void perc_down(int i)
{
    int smallest=i;
    if(2*i+1<hsize)
    {
        if(heep[2*i+1].z<heep[i].z)
        {
            smallest=2*i+1;
        }
    }
    if(2*i+2<hsize)
    {
        if(heep[2*i+2].z<heep[smallest].z)
        {
            smallest=2*i+2;
        }
    }
    if(smallest!=i)
    {
       struct heeep temp;

       pos[heep[i].v]=smallest;
       pos[heep[smallest].v]=i;

       temp=heep[i];
       heep[i]=heep[smallest];
       heep[smallest]=temp;
       perc_down(smallest); 
    }
}

void perc_up(int i)
{
    struct heeep temp;
    while(i>0)
    {
        if(heep[i].z<heep[(i-1)/2].z)
        {
            pos[heep[i].v]=(i-1)/2;
            pos[heep[(i-1)/2].v]=i;

            temp=heep[i];
            heep[i]=heep[(i-1)/2];
            heep[(i-1)/2]=temp;
            i=(i-1)/2;
        }
        else break;
    }
}

struct heeep extract_min()
{
    hsize--;    
    pos[heep[0].v]=hsize;
    pos[heep[hsize].v]=0;
    struct heeep p=heep[0];
    heep[0]=heep[hsize];
    perc_down(0);
    return p;
}

void decrease_key(int i,int p)
{
    heep[i].z=p;
    perc_up(i);
}

int inHeap(int p)
{
    if(pos[p]<hsize) return 1;
    else return 0;
}

struct AdjListNode* newAdjListNode(int data,int w) //OK
{
    struct AdjListNode* newNode =(struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = data;
    newNode->next = NULL;
    newNode->weight = w;
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

void addEdge(struct Graph* graph, int src, int dest,int w) //OK
{
    struct AdjListNode* newNode = newAdjListNode(dest,w); 
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode; //Assuming source exists

    newNode = newAdjListNode(src,w);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void Prim(struct Graph* g)
{
    struct AdjListNode *temp;
    struct heeep tempo;
    temp=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    int n,i;
    n=g->V;
    int parent[n];
    struct potato key[n];
    for(i=0;i<n;i++)
    {
        parent[i]=-1;
        key[i].ans=maxx;
        heep[i].v=i;
        heep[i].z=maxx;
        pos[i]=i;
    }
    hsize=n;
    key[0].ans=0;
    heep[0].z=0;
    heep[0].v=0;
    pos[0]=0;
    parent[0]=-1;
    while(hsize)
    {   
        tempo=extract_min();
        // printf("Min was : %d\n",tempo.z);
        temp=g->array[tempo.v].head;
        while(temp!=NULL)
        {
            if(inHeap(temp->dest))
            {
                if(temp->weight < key[temp->dest].ans)
                {
                    key[temp->dest].ans=temp->weight;
                    key[temp->dest].p=tempo.v;
                    key[temp->dest].q=temp->dest;
                    parent[temp->dest]=tempo.z;
                    decrease_key(pos[temp->dest],temp->weight);
                    // printf("%d is stored at heap's index %d\n",temp->dest,pos[temp->dest]);
                }
            }
            temp=temp->next;
            // for(i=0;i<hsize;i++)
            // {
            //     printf("Heap[%d] : (%d,%d) ; ",i,heep[i].v,heep[i].z);
            // }
            // printf("\n");
        }
    }
    qsort(key,n,sizeof(struct potato),cmpf);
    int rofl,lfor;
    for(i=1;i<n;i++)
    {
        if(key[i].p<key[i].q)
        {
            rofl=key[i].p;
            lfor=key[i].q;
        }
        else
        {
            rofl=key[i].q;
            lfor=key[i].p;
        }
        printf("%d %d %d\n",rofl+1,lfor+1,key[i].ans);
    }
}

int main()
{
    int V,E,t,x,y,w,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&V);
        scanf("%d",&E);
        struct Graph* graph = createGraph(V);
        heep=(struct heeep*)malloc(sizeof(struct heeep)*V);
        pos=(int*)malloc(sizeof(int)*V);
        for(i=0;i<E;i++)
        {
            scanf("%d",&x);
            scanf("%d",&y);
            scanf("%d",&w);
            addEdge(graph,x-1,y-1,w);
        }
        Prim(graph);
        // printGraph(graph);
    }
    return 0;
}