#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct que
{
    int poptime;
    int endtime;
    queue<int> waitQueue;
};

int cost[1010];
int ans[1010];
que qu[25];
int main()
{
    int n,m,k,q,cur=1;;
    cin>>n>>m>>k>>q;
    //cout<<n<<m<<k<<q<<endl;


    for(int i=1;i<=k;i++){
        scanf("%d",&cost[i]);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i==1)
            {
                qu[j].poptime=cost[j];
            }
            qu[j].waitQueue.push(cost[cur]);
            qu[j].endtime+=cost[cur];
            ans[cur] = qu[j].endtime;
            cur++;
        }
    }

    while(cur<=k)
    {
        int tmp=INT32_MAX,tgt;

        for(int i=1;i<=n;i++)
        {
            if(qu[i].poptime<tmp)
            {
                tgt=i;
                tmp=qu[i].poptime;
            }
        }
        qu[tgt].waitQueue.pop();
        qu[tgt].waitQueue.push(cur);
        qu[tgt].poptime+=qu[tgt].waitQueue.front();
        qu[tgt].endtime+=cost[cur];
        ans[cur]=qu[tgt].endtime;
        cur++;
    }
    //for(int i=1;i<=k;i++)
        //cout<<ans[i]<<" ";
    //cout<<endl;
    int tgt;

    for(int i=1;i<=q;i++)
    {
        scanf("%d",&tgt);
        if(ans[tgt]-cost[tgt]>=540)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n",ans[tgt]/60+8,ans[tgt]%60);
    }
    return 0;
}