#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int t,x,len;
    double y;
    map<int,double> num;
    num.clear();
    cin>>t;
    len=t;
    for(int i=1;i<=t;i++)
    {
        cin>>x>>y;
        num[x]=y;
    }
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>x>>y;
        if(num[x]==0.0)
            {
                num[x]=y;
                len++;
            }
        else
            num[x]+=y;
    }
    cout<<len<<" ";
    for(int i=1000;i>=0;i--)
    {
        if(num[i]!=0.0)
        {
            cout<<i<<" "<<num[i];
            len--;
            if(len)
                cout<<" ";
        }
    }
    cout<<endl;
    return 0;
}