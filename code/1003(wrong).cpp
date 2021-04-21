#include<cstdio>
#include<cstring>
#include<functional>
#include<stdint.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<long long,long long> pii;
struct Edge{
    long long from,to,dist;
    Edge(long long u, long long v, long long d):from(u),to(v),dist(d){}
};
const long long inf = INT64_MAX;
const long long maxn = 100010;
long long peo[maxn], total[maxn], ans[maxn], vis[maxn], dis[maxn];
vector<Edge> edges;
vector<long long> G[maxn];
int main()
{
    long long src, dst, n , m;
    cin>>n>>m>>src>>dst;
    //cin>>n>>m>>src;
    for(long long i=0;i<n;i++)
        scanf("%lld",&peo[i]);
    for(long long i=1;i<=m;i++)
    {       
        long long u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        edges.push_back(Edge(u,v,w));
        G[u].push_back(i-1);
        G[v].push_back(i-1);
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for(long long i=0;i<=n;i++)    
        dis[i]=inf;
    dis[src]=0;
    ans[src]=1;
    total[src]=peo[src];
    q.push(pii(0,src));
    while(!q.empty())
    {
        pii x = q.top();
        q.pop();
        long long u = x.second;
        if(vis[u]) continue;
        vis[u]=1;
        for(long long i=0;i<G[u].size();i++)
        {
            Edge& e = edges[G[u][i]];
            long long& v = e.to;
            
            if(dis[v]>dis[u]+e.dist)
            {
                dis[v]=dis[u]+e.dist;
                ans[v]=ans[u];
                total[v]=total[u]+peo[v];
                if(!vis[v])q.push(pii(dis[v],v));
            }
            
            else if(dis[v]==dis[u]+e.dist)
            {
                    ans[v]+=ans[u];
                    total[v]=max(total[v],total[u]+peo[v]);
                    if(!vis[v])q.push(pii(dis[v],v));
            }
            
        }
    }
    cout<<ans[dst]<<" "<<total[dst];
    return 0;
}