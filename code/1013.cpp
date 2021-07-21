#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int edge[2010][2010],vis[2010];
int n,m,k;
int dfs(int node)
{
    vis[node]=1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&edge[i][node]==1)
            dfs(i);
    }
    return 0;
}
int main()
{
    cin>>n>>m>>k;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        edge[u][v]=edge[v][u]=1;
    }
    int w;
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&w);
        int cnt=0;
        fill(vis,vis+2000,0);
        vis[w]=1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j])
            {
                dfs(j);
                cnt++;
            } 
        }
        printf("%d\n",cnt-1);
    }
    return 0;
}