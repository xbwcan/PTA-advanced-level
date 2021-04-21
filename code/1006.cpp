#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include <utility>
#include "vector"
#include "queue"
using namespace std;
typedef pair<string, string> p;
int main()
{
    int n;
    cin>>n;
    priority_queue<p, vector<p>, greater<p>> sign_in;
    priority_queue<p> sign_out;
    string u,v,w;
    for(int i=1;i<=n;i++)
    {
        cin>>u>>v>>w;
        sign_in.push(make_pair(v, u));
        sign_out.push(make_pair(w, u));
    }
    cout<<sign_in.top().second<<" "<<sign_out.top().second;
    return 0;
}