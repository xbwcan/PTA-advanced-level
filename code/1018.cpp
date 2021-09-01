#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> Q;
const int maxn=505;

struct Edge
{
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d){}
};

vector<Edge> edges;
vector<int>G[maxn];
int n,m,c,s;
int d[maxn],vis[maxn],num[maxn],cnt[maxn];
vector<int>p[maxn];
double avg[maxn];

int main()
{
    fill(d,d+n+5,INT32_MAX);
    cin>>c>>n>>s>>m;
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    int u,v,cost;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&cost);
        edges.push_back(Edge(u,v,cost));
        G[u].push_back(i);
        G[v].push_back(i);
    }
    d[0]=0;
    Q.push(make_pair(0,0));
    while(!Q.empty())
    {
        int x=Q.top().second;
        Q.pop();
        if(vis[x]) 
            continue;
        vis[x]=true;
        for(auto i:G[x])
        {
            Edge& e = edges[i];
            if(d[e.to]>d[x]+e.dist)
            {
                d[e.to] = d[u]+e.dist;
                p[e.to].clear();
                p[e.to].push_back(x);
                Q.push(make_pair(d[e.to],e.to));
            }
            else if(d[e.to]==d[x]+e.dist)
            {
                p[e.to].push_back(x);
            }
        }
    }
}