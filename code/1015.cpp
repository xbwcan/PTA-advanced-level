#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
bool isPrime(int n){
    if(n==1)
        return false;
    else if(n==2)
        return true;
    else    
    {
        int len = sqrt(n)+0.5;
        for(int i=2;i<=len;i++)
            if(n%i==0)
                return false;
        return true;
    }
}
int transform(int n,int radix){
    string tmp;
    int cur=0;
    while(n>0)
    {
        cur++;
        tmp[cur]='0'+n%radix;
        n=n/radix;
    }
    int ans=0;
    int len=cur;
    int base=1;
    while(cur>0)
    {
        ans+=(tmp[cur]-'0')*base;
        base*=radix;
        cur--;
    }
    return ans;
}
int main()
{
    int n,radix;
    while(scanf("%d",&n))
    {
        if(n<0)
            break;
        scanf("%d",&radix);
        if(!isPrime(n)){
            printf("No\n");
            continue;
        }
        else{
            int m = transform(n,radix);
            //cout<<n<<"  "<<m<<endl;
            if(!isPrime(m)){
                printf("No\n");
                continue;
            }
            printf("Yes\n");
        }
    }
    return 0;
}