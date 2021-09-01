#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int maxn = 500;
typedef pair<int,int> pii;
struct Edge{
    int from, to, distance, cost;
    Edge(int u, int v, int d, int c):from(u),to(v),distance(d),cost(c){}
};
vector<Edge> edges;
vector<int> G[maxn];
bool done[maxn];
int p[maxn];
int cost[maxn];
int dis[maxn];
int n,m,s,d;

int main()
{
    priority_queue<pii,vector<pii>,greater<pii>> q;
    scanf("%d%d%d%d",&n,&m,&s,&d);
    for(int i=0;i<n;i++)
        dis[i]=INT32_MAX;
    
    for(int i=0;i<m;i++)
    {
        int u,v,d,c;
        scanf("%d%d%d%d",&u,&v,&d,&c);
        edges.push_back(Edge(u,v,d,c));
        G[u].push_back(i);
        G[v].push_back(i);
    }
    dis[s]=0;
    q.push(make_pair(dis[s],s));
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if(done[u])continue;
        done[u]=true;
        for(int i=0;i<G[u].size();i++)
        {
            Edge &e = edges[G[u][i]];
            int v;
            if(u==e.to)
                v=e.from;
            else 
                v=e.to;
            if(dis[v]>dis[u]+e.distance)
            {
                dis[v]=dis[u]+e.distance;
                p[v]=G[u][i];
                cost[v]=cost[u]+e.cost;
                q.push(make_pair(dis[v],v));
            }
            else if(dis[v]==dis[u]+e.distance)
            {
                if(cost[v]>cost[u]+e.cost)
                {
                    p[v]=G[u][i];
                    cost[v]=cost[u]+e.cost;
                    q.push(make_pair(dis[v],v));
                }
            }
        }
    }
    int cur = d;
    int total_cost=0,total_dist=0;
    stack<int> ans;
    while(cur!=s)
    {
        Edge &e = edges[p[cur]];
        total_cost+=e.cost;
        total_dist+=e.distance;
        ans.push(cur);
        if(cur==e.from)
            cur=e.to;
        else 
            cur=e.from;
    }
    ans.push(s);
    while(!ans.empty())
    {
        printf("%d ",ans.top());
        ans.pop();
    }
    printf("%d %d\n",dis[d],cost[d]);
    return 0;
}