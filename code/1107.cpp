#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1000*2+10;
int fa[maxn];
map<int,int>cnt;
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int Union(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
        fa[fx]=fy;
        return 0;
}
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<maxn;i++)
        fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        int t,x;
        char c;
        scanf("%d",&t);
        scanf("%c",&c);
        for(int j=1;j<=t;j++)
        {
            scanf("%d",&x);
            Union(i,x+n);
        }
    }
    for(int i=1;i<=n;i++)
    {
        fa[i]=find(i);
        cnt[fa[i]]++;
    }
    cout<<cnt.size()<<endl;
    vector<int> ans;
    for(map<int,int>::iterator it = cnt.begin();it!=cnt.end();it++)
    {
        ans.push_back(it->second);
    }
    sort(ans.begin(),ans.end(),cmp);
    for(vector<int>::iterator it = ans.begin();it!=ans.end();it++)
    {
        if(it!=ans.begin())
            printf(" ");
        cout<<*it;
    }
    cout<<endl;
    return 0;
}
