#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,a[5555],d[5555][5555],s[5555];

int main()
{
    for(;;)
    {
        scanf("%I64d",&n);
        if(!n) return 0;
        for(ll i=1;i<=n;i++)
        {
            scanf("%I64d",&a[i]);
            d[i][i]=a[i];
            s[i]=s[i-1]+a[i];
        }
        for(ll len=2;len<=n;len++)
            for(ll l=1,r=l+len-1;r<=n;l++,r++)
                d[l][r]=max(a[l]+s[r]-s[l]-d[l+1][r],a[r]+s[r-1]-s[l-1]-d[l][r-1]);
        printf("%I64d %I64d",d[1][n],s[n]-d[1][n]);
    }
}
