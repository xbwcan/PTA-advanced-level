#include "iostream"
#include "cstdio"
#include <algorithm>
#include <cstring>
#include <stdint.h>
using namespace std;
int n, num[10015];
long long  sum,tmp;
int main()
{
    cin>>n;
    int l=1,r=n;
    sum=-1;
    tmp=0;
    int tmpindex=0;
    memset(num,0,sizeof(num));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        tmp+=num[i];
        if(tmp<0)
        {
            tmp=0;
            tmpindex=i+1;
        }
        else if(tmp>sum)
        {
            sum=tmp;
            l=tmpindex;
            r=i;
        }
    }
    if(sum<0)sum=0;
    printf("%d %d %d\n",sum,num[l],num[r]);
    return 0;
}