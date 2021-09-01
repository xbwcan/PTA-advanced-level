#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int maxnum[100005],minnum[100005],nums[100005];
int n;
vector<int> ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);
    }
    for(int i=2;i<=n;i++)
    {
        maxnum[i]=max(nums[i],maxnum[i-1]);
    }
    minnum[n]=nums[n];
    for(int i=n-1;i>=1;i--)
        minnum[i]=min(nums[i],minnum[i+1]);
    int cnt=0;
    if(nums[1]<minnum[2])
    {
        cnt++;
        ans.push_back(nums[1]);
    }
    for(int i=2;i<n;i++)
    {
        if(nums[i]>maxnum[i-1]&&nums[i]<minnum[i+1])
        {
            cnt++;
            ans.push_back(nums[i]);
        }
    }
    if(nums[n]>maxnum[n-1])
    {
        cnt++;
        ans.push_back(nums[n]);
    }
    cout<<cnt<<endl;
    for(int i=0;i<ans.size();i++)
    {
        if(i!=0)
            printf(" ");
        printf("%d",ans[i]);
    }
    cout<<endl;
    return 0;
}