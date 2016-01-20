#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

ll n,k,a[111111],d[111111];
const ll INF=2e9;

int main()
{
    cin>>n>>k;
    for(ll i=1;i<=k;i++)
        scanf("%I64d",&a[i]);
    for(ll f=1;f<=n;f++)
    {
        d[f]=INF;
        for(ll i=1;i<=k;i++)
            if(f>=a[i])
                d[f]=min(d[f],d[f-a[i]]+1);
    }
    cout<<d[n];
    return 0;
}
