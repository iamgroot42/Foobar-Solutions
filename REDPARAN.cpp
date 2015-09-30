#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t,i,x,flag,temp;
	char c,y;
	scanf("%d\n",&t);
	while(t--)
	{
		scanf("\n");
		flag=0;
		vector<char> a;
		vector<int> b;
		while((c=getchar())!='\n')
		{
			scanf("%d",&x);
			if(c<='z' && c>='a')
			{
				a.push_back(c);
				b.push_back(x);
			}
			else
			{
				if(a.size())
				{
					temp=b.back();
					if(a.back()-'a'!=c-'A')
					{
						flag=1;
					}
					if(temp>x)
					{
						b.pop_back();
						b.push_back(temp-x);
					}
					else if(temp==x)
					{
						b.pop_back();
						a.pop_back();
					}
					else
					{
						flag=1;
					}
				}
				else flag=1;
			}
		}
		if(a.size()) flag=1;
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}