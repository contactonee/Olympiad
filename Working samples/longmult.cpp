#include<bits/stdc++.h>
using namespace std;
#define MAX 111111111
int a[MAX],b[MAX],c[MAX];
int main()
{
    c[0]=1;
    string s;
    cin>>s;
    a[0]=s.size();
    for(int i=0;i<a[0];i++)
        a[a[0]-i]=s[i]-48;
    cin>>s;
    b[0]=s.size();
    for(int i=0;i<b[0];i++)
        b[b[0]-i]=s[i]-48;
    for(int i=1;i<=a[0];i++)
        for(int j=1;j<=b[0];j++)
        {
            c[i+j-1]+=(a[i]*b[j]);
            c[0]=max(c[0],(i+j)*(c[i+j-1]>9));
            c[i+j]+=c[i+j-1]/10;
            c[i+j-1]%=10;
        }
    for(int i=c[0];i>0;i--)
        cout<<c[i];
    return 0;
}
