#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
ll n,m,sz,len,a[111111],b[111111],w[111111],c[111111],l,r,x,k,y;
pair<ll,ll>q[111111];
char ch;
vector<ll>t[444444];
void build(ll v, ll l, ll r)
{
    if(l==r)
    {
        t[v].pb(a[l]);
        return;
    }
    ll mid=(l+r)/2;
    build(v*2,l,mid);
    build(v*2+1,mid+1,r);
    t[v].resize(t[v*2].size()+t[v*2+1].size());
    merge(t[v*2].begin(),t[v*2].end(),t[v*2+1].begin(),t[v*2+1].end(),t[v].begin());
}
ll f(ll v, ll l, ll r, ll x, ll y, ll k)
{
    if(x>r||y<l)
        return 0;
    x=max(x,l),y=min(y,r);
    if(x==l&&y==r)
    {
        ll g=0,h=t[v].size()-1;
        while(g<h)
        {
            ll mi=(g+h+1)/2;
            if(t[v][mi]>k)
                h=mi-1;
            else
                g=mi;
        }
        if(t[v][g]>k)
            g--;
        return g+1;
    }
    ll mid=(l+r)/2;
    return f(v*2,l,mid,x,y,k)+f(v*2+1,mid+1,r,x,y,k);
}
int main()
{
    cin>>n>>m;
    len=sqrt(m);
    for(ll i=1;i<=n;i++)
        cin>>a[i],b[i]=a[i];
    sort(b+1,b+n+1);
    build(1,1,n);
    for(ll i=1;i<=m;i++)
    {
        cin>>ch>>l>>r;
        if(ch=='+')
            q[++sz]=mp(l,r);
        else
        {
            if(sz>len)
            {
                for(ll j=1;j<=sz;j++)
                    a[q[j].fi]+=q[j].se;
                sz=0;
                build(1,1,n);
            }
            cin>>k;
            x=1,y=n;
            while(x<y)
            {
                ll mid=(x+y)/2,ans=0;
                for(ll j=1;j<=sz;j++)
                    if(q[j].fi>=l&&q[j].fi<=r)
                    {
                        if(!w[q[j].fi])
                            c[q[j].fi]=a[q[j].fi];
                        if(a[q[j].fi]<=b[mid]&&a[q[j].fi]+q[j].se>b[mid])
                            ans--;
                        if(a[q[j].fi]>b[mid]&&a[q[j].fi]+q[j].se<=b[mid])
                            ans++;
                        w[q[j].fi]=1;
                        c[q[j].fi]+=q[j].se;
                    }
                for(ll j=1;j<=sz;j++)
                    w[q[j].fi]=0;
                if(f(1,1,n,l,r,b[mid])+ans<k)
                    x=mid+1;
                else
                    y=mid;
            }
            cout<<a[x]<<endl;
        }
    }
}
