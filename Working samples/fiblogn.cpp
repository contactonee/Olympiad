#include<iostream>
using namespace std;
typedef long long ll;
ll n,a[2][2],b[2][2],c[2][2];
int main()
{
    cin>>n;
    a[0][1]=a[1][0]=a[1][1]=1;
    b[0][0]=b[1][1]=1;
    n--;
    while(n)
    {
        if(n&1)
        {
            for(ll i=0;i<2;i++)
                for(ll j=0;j<2;j++)
                    for(ll q=0;q<2;q++)
                        c[i][j]+=a[i][q]*b[q][j];
            for(ll i=0;i<2;i++)
                for(ll j=0;j<2;j++)
                    b[i][j]=c[i][j],c[i][j]=0;
            n--;
        }
        for(ll i=0;i<2;i++)
            for(ll j=0;j<2;j++)
                for(ll q=0;q<2;q++)
                    c[i][j]+=a[i][q]*a[q][j];
        for(ll i=0;i<2;i++)
            for(ll j=0;j<2;j++)
                a[i][j]=c[i][j],c[i][j]=0;
        n>>=1;
    }
    cout<<b[0][0]+b[0][1];
    return 0;
}
