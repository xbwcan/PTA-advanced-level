#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
vector<int> inorder;
vector<int> preorder;
map<int,int> in,pre;
int n,m; 
int lca(int u, int v)
{
    int l = in[u];
    int r = in[v];
    if(l>r)
        swap(l,r);
    int mincur = n+1;
    int ans;
    for(int i=l;i<=r;i++)
    {
        if(pre[inorder[i]]<mincur)
        {
            mincur=pre[inorder[i]];
            ans=inorder[i];
        }
    }
    return ans;
}
int main()
{
    cin>>m>>n;
    inorder.reserve(n+10);
    inorder.clear();
    preorder.reserve(n+10);
    preorder.clear();
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&inorder[i]);
        in.insert(make_pair(inorder[i],i));
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&preorder[i]);
        pre.insert(make_pair(preorder[i],i));
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        map<int,int>::iterator it1, it2;
        it1=in.find(u);
        it2=in.find(v);
        if(it1==in.end()&&it2==in.end())
        {
            printf("ERROR: %d and %d are not found.\n",u,v);
        }
        else if(it1==in.end())
        {
            printf("ERROR: %d is not found.\n",u);
        }
        else if(it2==in.end())
        {
            printf("ERROR: %d is not found.\n",v);
        }
        else
        {
            int root = lca(u,v);
            if(root==u)
            {
                printf("%d is an ancestor of %d.\n",u,v);
            }
            else if(root==v)
                printf("%d is an ancestor of %d.\n",v,u);
            else    
                printf("LCA of %d and %d is %d.\n",u,v,root);
        }
    }
}