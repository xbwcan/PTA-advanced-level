#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct node{
    string username;
    string password;
    bool isChanged;
};
node users[1010];
int main()
{
    int n,m;
    cin>>n;
    m=0;
    for(int i=1;i<=n;i++)
    {
        cin>>users[i].username>>users[i].password;
        int flag=0;
        for(int j=0;j<=users[i].password.length();j++)
        {
            if(users[i].password[j]=='1')
            {
                users[i].password[j]='@';
                users[i].isChanged=true;
                flag=1;
            }
            else if(users[i].password[j]=='0')
            {
                users[i].password[j]='%';
                users[i].isChanged=true;
                flag=1;
            }
            else if(users[i].password[j]=='O')
            {
                users[i].password[j]='o';
                users[i].isChanged=true;
                flag=1;
            }
            else if(users[i].password[j]=='l')
            {
                users[i].password[j]='L';
                users[i].isChanged=true;
                flag=1;
            }
        }
        if(flag)
            m++;
    }
    if(m==0)
    {
        if(n==1)
        {
            cout<<"There is 1 account and no account is modified\n";
        }
        else 
            printf("There are %d accounts and no account is modified\n",n);
        return 0;
    }
    cout<<m<<endl;
    for(int i=1;i<=n;i++)
    {
        if(users[i].isChanged)
        {
            cout<<users[i].username<<" "<<users[i].password<<endl;
        }
    }
}