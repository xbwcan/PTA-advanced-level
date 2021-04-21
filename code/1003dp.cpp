#include "iostream"
#include <cstdio>
#include <cstring>
#include <iterator>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    freopen("PTA\\data.txt","w",stdout);
    srand(time(NULL));
    
        int t =100;
        //cout<<t<<endl;
        while(t--)
        {
            int n,m,src,dst;
            
            n = 100+rand()%400;
            m=n*(n-1)/2;
            src = 1+rand()%n;
            dst = 1+rand()%n;
            cout<<n<<" "<<m<<" "<<src<<" "<<dst<<endl;
            if(src==dst)
                dst = (src*src)%n;
            int peo[505]={0};
            for(int i=0;i<n;i++)
                cout<<0+rand()%10<<" ";
            cout<<endl;

            int d[505][505];
            memset(d,0,sizeof(d));
            for(int i=0;i<n-1;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    cout<<i<<" "<<j<<" "<<rand()%10<<endl;
                }
            }
        }
    
}