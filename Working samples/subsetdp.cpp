#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[20],dp[1<<20][20];
int main()
{
    cin>>n>>k;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        dp[1<<i][i]=1;
    }
    for(ll mask=1;mask<(1<<n);mask++)
        for(ll i=0;i<n;i++)
            if((mask>>i)&1)
                for(ll j=0;j<n;j++)
                    if((mask>>j)&1&&i!=j&&abs(a[i]-a[j])<=k)
                        dp[mask][i]+=dp[mask^(1<<i)][j];
    ll ans=0;
    for(ll i=0;i<n;i++)
        ans+=dp[(1<<n)-1][i];
    cout<<ans;
    return 0;
}
