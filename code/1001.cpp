#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    a=a+b;
    stack<int> s;
    int flag=0;
    if(a<0)
    {
        a=-a;
        flag=1;
    }
    else if(a==0)
    {
        cout<<"0";
        return 0;
    }
    int n=0;
    while(a>0)
    {
        s.push(a%10);
        a/=10;
        n++;
    }
    if(flag)
        cout<<"-";
    for(int i=1;i<=n;i++)
    {
        
        cout<<s.top();
        s.pop();
        if((n-i)%3==0&&n!=i)
            cout<<",";
    }
    //cout<<endl<<n;
    return 0;
}