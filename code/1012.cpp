#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
struct student
{
    string id;
    int c;
    int math;
    int english;
    int avg;
    int bestRank;
    char flag;
};
student students[3000];
bool cmp1(student a, student b)
{
    return a.c>b.c;
}
bool cmp2(student a, student b)
{
    return a.math>b.math;
}
bool cmp3(student a, student b)
{   
    return a.english>b.english;
}
bool cmp4(student a, student b)
{
    return a.avg>b.avg;
}
int main()
{
    int n,m;

    cin>>n>>m;
    //cout<<n<<m<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>students[i].id;
        scanf("%d%d%d",&students[i].c,&students[i].math,&students[i].english);
        students[i].bestRank=n+1;
        students[i].avg=(students[i].c+students[i].math+students[i].english)/3;
    }
    for(int i=1;i<=4;i++)
    {
        if(i==1)
        {
            sort(students+1,students+n+1,cmp4);
            for(int j=1;j<=n;j++)
            {
                //cout<<j<<"  "<<students[j].bestRank<<endl;
                if(j<students[j].bestRank)
                {
                    students[j].bestRank=j;
                    students[j].flag='A';
                }
            }
        }
        else if(i==2)
        {
            sort(students+1,students+n+1,cmp1);
            for(int j=1;j<=n;j++)
            {
                if(j<students[j].bestRank)
                {
                    students[j].bestRank=j;
                    students[j].flag='C';
                }
            }
        }
        else if(i==3)
        {
            sort(students+1,students+n+1,cmp2);
            for(int j=1;j<=n;j++)
            {
               if(j<students[j].bestRank)
                {
                    students[j].bestRank=j;
                    students[j].flag='M';
                }
            }
        }
        else if(i==4)
        {
            sort(students+1,students+n+1,cmp3);
            for(int j=1;j<=n;j++)
            {
               if(j<students[j].bestRank)
                {
                    students[j].bestRank=j;
                    students[j].flag='E';
                }
            }
        }
    }
    string target;
    for(int i=1;i<=m;i++)
    {
        cin>>target;
        int ok=0;
        for(int j=1;j<=n;j++)
        {
            //cout<<target<<"   "<<students[j].id<<endl;
            if(students[j].id.compare(target)==0)
            {
                printf("%d %c\n",students[j].bestRank,students[j].flag);
                ok=1;
            }
        }
        if(!ok)
            printf("N/A\n");
    }
    return 0;
}