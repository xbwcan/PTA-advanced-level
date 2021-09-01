#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> num;
vector<int> ans;
int n;
void print(int cur,int heigh)
{
    ans[heigh]=num[cur];
    if(cur*2+1<=n)
    {
        print(cur*2+1,heigh+1);
    }
    if(cur*2<=n)
    {
        print(cur*2,heigh+1);
    }
    if(cur*2>n)
    {
        for(int i=1;i<=heigh;i++)
        {
            if(i!=1)
                printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }

}
int main()
{
    scanf("%d",&n);
    num.reserve(n+10);
    ans.reserve(n+10);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    int flag1=1,flag2=1;// big small
    for(int i=1;i*2<=n;i++)
    {
        if(num[i]>=num[2*i]||(2*i+1<=n)&&(num[i]>=num[2*i+1]))
            flag2=0;
        if(num[i]<=num[2*i]||(2*i+1<=n)&&(num[i]<=num[2*i+1]))
            flag1=0;
    }
    print(1,1);
    if(flag1)
    {
        cout<<"Max Heap"<<endl;
        return 0;
    }
    if(flag2)
    {
        cout<<"Min Heap"<<endl;
        return 0;
    }
    cout<<"Not Heap"<<endl;
    return 0;
}