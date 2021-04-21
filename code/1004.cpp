#include <array>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> child[110];
array<int,110> ans;
int h=0;
void dfs(int root, int height)
{
    h=max(h,height);
    if(child[root].size()==0)
        ans[height]+=1;
    else
    {
        for(int i=0;i<child[root].size();i++)
        {
            dfs(child[root][i],height+1);
        }
    }
    return ;
}
int main()
{
    int n,m;
    scanf("%d",&n);
        scanf("%d",&m);
        
        for(int i=1;i<=n;i++)
        {
            child[i].clear();
            ans[i]=0;
        }
        h=0;
        for(int i=1;i<=m;i++)
        {
            int u=0,v=0,k;            
            scanf("%d%d",&u,&k);
            for(int j=1;j<=k;j++)
            {
                scanf("%d",&v);
                child[u].push_back(v);
            }
        }
        dfs(1,1);
        for(int i=1;i<=h;i++)
        {
            cout<<ans[i];
            if(i!=h)
                printf(" ");
        }
    
}