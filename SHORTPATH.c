#include <stdio.h>
#include <stdlib.h>

#define maxx 1000000000

int graph[1050][1050];
int V,E;

void PrintGraph(int v)
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++) printf("%d ",graph[i][j]);
		printf("\n");
	}
}

int md(int d[], int s[])
{
	// Initialize min value
	int min,mi;
	min=maxx;
	int v;
	for (v = 0; v < V; v++)
	{
		if (s[v] == 0 && d[v] <= min)
		{
			min = d[v];
			mi = v;
		}
	}
	return mi;
}

int  DJ(int src,int dest)
{
	int count,i,u,v,ans[V],set[V];  
	for (i=0;i<V;i++)
	{
		ans[i]=maxx;
		set[i]=0;
 	}
	ans[src]=0;
	for(count=0;count<V-1;count++)
	{
		u=md(ans, set);
		set[u] = 1;
		for(v=0;v<V;v++)
		{
			if ((!set[v]) && (graph[u][v]!=-1) && (ans[u]!=maxx) && (ans[u]+graph[u][v]<ans[v]))
			{
				ans[v] = ans[u] + graph[u][v];
			}
		}
	}
	return ans[dest];
}


int main()
{
    int x,y,t,i,j,w,path;
    scanf("%d",&t);
	scanf("%d",&V);
	scanf("%d",&E);
	int answer[V][V];
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++) { answer[i][j]=maxx; graph[i][j]=-1;} //-1 corresponds to +Inf
	}
	for(i=0;i<E;i++)
	{
		scanf("%d",&x);
		scanf("%d",&y);
		scanf("%d",&w);
		graph[x-1][y-1]=w; //Edge from X to Y
	}
	while(t--)
	{
		scanf("%d",&x);
		scanf("%d",&y);
		path=DJ(x-1,y-1);
		if(path==maxx) path=-1;
		printf("%d\n",path);
	}
    return 0;
}