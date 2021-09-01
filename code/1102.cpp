#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int l[15],r[15],vis[15];
int cnt ;
queue<int>q;
void in_order(int root)
{
    if(l[root]!=-1)
        in_order(l[root]);
    printf("%d",root);
    if(cnt>1)
    {
        cnt--;
        printf(" ");
    }
    if(r[root]!=-1)
        in_order(r[root]);
    return ;
}
int main()
{
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    int n;
    scanf("%d",&n);
    char x,y;
    for(int i=0;i<n;i++)
    {
        scanf("%c",&x);
        scanf("%c",&x);
        scanf("%c",&y);
        scanf("%c",&y);
        if(x!='-')
        {
            r[i]=x-'0';
            vis[r[i]]=1;
        }
        if(y!='-')
        {
            l[i]=y-'0';
            vis[l[i]]=1;
        }    
    }
    int root=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            root=i;
    }
    q.push(root);
    cnt=n;
    while (!q.empty())
    {
        int cur=q.front();
        q.pop();
        printf("%d",cur);
        if(cnt>1)
        {
            cnt--;
            printf(" ");
        }
        if(l[cur]!=-1)
            q.push(l[cur]);
        if(r[cur]!=-1)
            q.push(r[cur]);
    }
    printf("\n");
    cnt=n;
    in_order(root);
    printf("\n");
    return 0;
}