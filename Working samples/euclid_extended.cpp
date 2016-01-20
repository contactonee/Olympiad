#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll a,b,x,y;
int gcd(ll a,ll b,ll &x,ll &y)
{
	if(!a)
    {
		x=0;
        y=1;
		return b;
	}
	ll x1,y1;
	ll d=gcd(b%a,a,x1,y1);
	x=y1-(b/a)*x1;
	y=x1;
	return d;
}
int main()
{
    ll c;
    scanf("%I64d%I64d%I64d",&a,&b,&c);
    c=-c;
    ll g=gcd(a,b,x,y);
    if(c%g)
    {
        cout<<"-1";
        return 0;
    }
    printf("%I64d %I64d",x*c/g,y*c/g);
    return 0;
}
