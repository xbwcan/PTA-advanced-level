#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int f[1050][1050];
int vis[1050][1050];
string str;
int dp(int i,int j)
{
    if(vis[i][j])
        return f[i][j];
    else if(i+1==j){
        vis[i][j]=1;
        if(str[i]==str[j]){
            f[i][j]=1;
            return 1;
        }
        else{
            f[i][j]=0;
            return 0;
        }
    }
    else if(i==j){
        vis[i][j]=1;
        f[i][j]=1;
        return 1;
    }
    else{
        vis[i][j]=1;
        if(str[i]==str[j])
        {
            f[i][j]=dp(i+1,j-1);
            return f[i][j];
        }
        else{
            f[i][j]=0;
            return 0;
        }
    }
}
int main(){
    int ans=0;
    getline(cin,str);
    int len=str.length();
    for(int j=0;j<len;j++)
    {
        //cout<<j<<endl;
        for(int i=0;i<=j;i++)
        {
            if(dp(i,j))
            {
                ans=max(ans,j-i+1);
                //cout<<i<<" "<<j<<":"<<dp(i,j)<<"    "<<ans<<endl;
            }
                
        }
    }
    cout<<ans<<endl;
    return 0;
}
