#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=10005;
int fa[10005];
map<int,int> vis;
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int Union(int x,int b)
{
    int fx=find(x);
    int fb=find(b);
    if(fx!=fb)
        fa[fx]=fb;
}
int main()
{
    int n,maxnum=-1,cnt=0;
    cin>>n;
    for(int i=1;i<=maxn;i++)
        fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        int t,x,y;
        cin>>t;
        scanf("%d",&x);
        maxnum=max(maxnum,x);
        for(int i=1;i<t;i++)
        {
            scanf("%d",&y);
            maxnum=max(maxnum,y);
            Union(x,y);
        }
    }
    for(int i=1;i<=maxnum;i++)
    {
        fa[i]=find(i);
        if(vis.find(fa[i])==vis.end())
        {
            vis[fa[i]]=1;
            cnt++;
            //cout<<fa[i]<<"  "<<i<<endl;
        }
    }
    cout<<cnt<<" "<<maxnum<<endl;
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int fu=find(u);
        int fv=find(v);
        if(fu==fv)
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }
    return 0;
}