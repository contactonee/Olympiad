#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,comp,color[1111111];
vector < ll > e[1111111],re[1111111],order;
bool b[1111111];

void dfs1(ll v)
{
    b[v]=1;
    for(ll i=0;i<e[v].size();i++)
    {
        ll to=e[v][i];
        if(!b[to])
            dfs1(to);
    }
    order.push_back(v);
}

void dfs2(ll v)
{
    b[v]=1;
    color[v]=comp;
    for(ll i=0;i<re[v].size();i++)
    {
        ll to=re[v][i];
        if(!b[to])
            dfs2(to);
    }
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%I64d%I64d",&n,&m);
    for(ll i=1;i<=m;i++)
    {
        ll x,y;
        scanf("%I64d%I64d",&x,&y);
        e[x].push_back(y);
        re[y].push_back(x);
    }
    for(ll i=1;i<=n;i++)
        if(!b[i])
            dfs1(i);
    for(ll i=1;i<=n;i++)
        b[i]=0;
    for(ll i=order.size()-1;i>=0;i--)
    {
        ll curr=order[i];
        if(!b[curr])
        {
            comp++;
            dfs2(curr);
        }
    }
    printf("%I64d\n",comp);
    for(ll i=1;i<=n;i++)
        printf("%I64d ",color[i]);
    return 0;
}
