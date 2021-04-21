#include "cstdio"
#include "iostream"
#include "algorithm"
using namespace std;
const int inf = 999999999;
long long edges[505][505], peo[505], vis[505], dis[505], ans[505] ,num[505];
long long n,m,src,dst;
int main()
{
    freopen("PTA\\data.txt","r",stdin);
    freopen("PTA\\out2.txt","w",stdout);
    int t;
    t=100;
    while(t--)
    {
    fill(edges[0],edges[0]+505*505,inf);
    fill(vis,vis+505,0);
    fill(ans,ans+505,0);
    fill(num,num+505,0);
    cin>>n>>m>>src>>dst;
    for(int i=0;i<n;i++)
        dis[i]=inf;
    for(int i=0;i<n;i++)
        scanf("%lld",&peo[i]);
    //fill(edges[0],edges[0]+505*505,inf);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        //cout<<u<<" "<<v<<" "<<w<<endl;
        edges[u][v]=edges[v][u]=w;
    }
    dis[src]=0;
    ans[src]=1;
    num[src]=peo[src];
    for(int i=0;i<n;i++)
    {
        int u =-1, minn=inf;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&dis[j]<minn)
            {
                u=j;
                minn=dis[j];
            }
        }
        if(u==-1)break;
        vis[u]=1;
        for(int v=0;v<n;v++)
        {
            if(!vis[v]&&edges[u][v]!=inf)
            {
                if(dis[u]+edges[u][v]<dis[v])
                {
                    dis[v]=dis[u]+edges[u][v];
                    ans[v]=ans[u];
                    num[v]=num[u]+peo[v];
                }
                else if(dis[v]==dis[u]+edges[u][v])
                {
                    ans[v]+=ans[u];
                    num[v]=max(num[v],num[u]+peo[v]);
                }
            }
        }
    }
    cout<<ans[dst]<<" "<<num[dst]<<endl;
    }
    return 0;
}

