#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool check(string str)
{
    if(str.length()==1)
        return true;
    else {
        int i=0,j=str.length()-1;
        while(i<=j)
        {
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
}
void add(string &str1)
{
    string str2=str1;
    cout<<str1<<" + ";
    for(int i=0;i<str1.length();i++){
        str2[i]=str1[str1.length()-1-i];
        printf("%c",str2[i]);
    }
    //cout<<endl;
    for(int i=str1.length()-1;i>=0;i--)
    {
        if(str1[i]+str2[i]-'0'-'0'>=10)
        {
            str1[i]='0'+(str1[i]+str2[i]-'0'-'0'-10);
            //cout<<str1[i]<<"  ";
            if(i==0)
            {
                str1=("1"+str1);
                //cout<<str1[0]<<endl;
            }
                
            else{ 
                str1[i-1]='0'+(str1[i-1]-'0'+1);
                //cout<<str1[i-1]<<endl;
            }
        }
        else 
            str1[i]='0'+(str1[i]+str2[i]-'0'-'0');
    }
    cout<<" = "<<str1<<endl;

}
int main()
{
    string str;

    cin>>str;
    int i=1;
    while(!check(str))
    {
        if(i==11){
            printf("Not found in 10 iterations.\n");
            break;
        }
        add(str);
        i++;
    }
    if(i!=11)
    {
        cout<<str<<" is a palindromic number.\n";
    }
    return 0;
}