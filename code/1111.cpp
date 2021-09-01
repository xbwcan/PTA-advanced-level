#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int maxn = 500+5;
struct Edge
{
    int from, to, dist, time;
    Edge(int u, int v, int d, int t):from(u),to(v),dist(d),time(t){}
};
vector<Edge> edges;
typedef pair<int,int> pii;
vector<int> G[maxn];
int dis[maxn],pre[maxn],time[maxn],cnt[maxn];
bool done[maxn];

priority_queue<pii,vector<pii>,greater<pii>> q;
int main()
{
    int n,m,s,d;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        dis[i]=INT32_MAX;
    for(int i=0;i<m;i++)
    {
        int u,v,flag,dis,time;
        scanf("%d%d%d%d%d",&u,&v,&flag,&dis,&time);
        edges.push_back(Edge(u,v,dis,time));
        G[u].push_back(i);
        if(!i)
            G[v].push_back(i);
    }
    dis[s]=0;
    q.push(make_pair(dis[s],s));
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if(done[u]) continue;
        done[u]=true;
        for(int i=0;i<G[u].size();i++)
        {
            Edge &e = edges[G[u][i]];
            int v;
            if(u==e.from)
                v=e.to;
            else 
                v=e.from;
            if(dis[v]>dis[u]+e.dist)
            {
                dis[v]=dis[u]+e.dist;
                pre[v]=G[u][i];
                time[v]=time[u]+e.time;
                cnt[v]=cnt[u]+1;
                q.push(make_pair(dis[v],v));
            }
            else if(dis[v]==dis[u]+e.dist)
            {
                if(time[v]>time[u]+e.time)
                {
                    time[v]=time[u]+e.time;
                    pre[v]=G[u][i];
                    cnt[v]=cnt[u]+1;
                    q.push(make_pair(dis[v],v));
                }
            }
        }
    }
    int cur = d;
    stack<int> ans1;
    while(cur!=s)
    {
        Edge &e = edges[pre[cur]];
        ans1.push(cur);
        if(cur==e.from)
            cur=e.to;
        else 
            cur=e.from;
    }
    int tmp_time=time[d], tmp_cnt=cnt[d];
    for(int i=0;i<n;i++)
    {
        time[i]=INT32_MAX;
        done[i]=false;
        cnt[i]=0;
        pre[i]=0;
    }
    time[s]=0;
    q.push(make_pair(time[s],s));
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if(done[u]) continue;
        done[u]=true;
        for(int i=0;i<G[u].size();i++)
        {
            Edge &e = edges[G[u][i]];
            int v;
            if(u==e.from)
                v=e.to;
            else 
                v=e.from;
            if(time[v]>time[u]+e.time)
            {
                time[v]=time[u]+e.time;
                pre[v]=G[u][i];
                cnt[v]=cnt[u]+1;
                q.push(make_pair(dis[v],v));
            }
            else if(time[v]=time[u]+e.time)
            {
                if(cnt[v]>cnt[u]+1)
                {
                    cnt[v]=cnt[u]+1;
                    pre[v]=G[u][i];
                    time[v]=time[u]+e.time;
                    q.push(make_pair(dis[v],v));
                }
            }
        }
    }
}