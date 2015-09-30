#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,m,i,j,flag;
    int *a;
    scanf("%d %d",&n,&m);
    //printf("Nyancat\n");
    a=(int*)malloc(sizeof(int)*n);
    //printf("Nyancat\n");
    for(i=0;i<n;i++) scanf("%d",a+i);
    //printf("Nyancat\n");
    i=0;
    flag=0;
    j=n-1;
    while(i<j)
    {
        if(a[i]+a[j]==m)  { printf("%d %d %d %d\n",i,j,a[i],a[j]); flag=1; break;}
        else if(a[i]+a[j]<m)
        {
            if(a[i+1]+a[j]>a[i]+a[j-1]) i++;
            else j--;
        }
        else
        {
            if(a[i+1]+a[j]<a[i]+a[j-1]) j--;
            else i++;
        }
    }
    if(!flag) printf("NO\n");
    return 0;
}
