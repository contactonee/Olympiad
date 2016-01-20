#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz size()
typedef long long ll;

ll n,m,t,p[111111],r[111111],tw;
vector < pair < pair < ll,ll > ,pair < ll,ll > > > e;
vector < ll > ans;

ll get(ll x)
{
    return x==p[x]?x:p[x]=get(p[x]);
}

void unite(ll a,ll b)
{
    a=get(a);
    b=get(b);
    if(a!=b)
    {
        if(r[a]>r[b])
            swap(a,b);
        p[a]=p[b];
        r[b]+=r[a];
    }
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%I64d %I64d",&n,&m);
    for(ll i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=1;
    }
    e.resize(m+1);
    for(ll i=1;i<=m;i++)
    {
        scanf("%I64d %I64d %I64d",&e[i].se.fi,&e[i].se.se,&e[i].fi.fi);
        e[i].fi.se=i;
    }
    sort(e.begin(),e.end());
    for(ll i=1;i<=m;i++)
    {
        ll a=e[i].se.fi,b=e[i].se.se,ed=e[i].fi.fi;
        if(get(a)!=get(b))
        {
            tw+=ed;
            ans.pb(e[i].fi.se);
            unite(a,b);
        }
    }
    if(ans.size()<n-1)
    {
        cout<<"-1";
        return 0;
    }
    printf("%I64d\n",(ll)tw);
    for(ll i=0;i<ans.size();i++)
        printf("%I64d\n",ans[i]);
    return 0;
}
