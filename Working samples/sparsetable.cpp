#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll p,n,k[100001],c[100001][21],m,l,r;
int main()
{
	scanf("%I64d",&n);
	for(int i=2;i<=n;i++)
		k[i]=k[i/2]+1;
	for(ll i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
		c[i][0]=a;
	}
   	for(ll len=1;len<=k[n];len++)
		for(ll i=1;i<=n;i++)
			c[i][len]=min(c[i][len-1],c[i+(1<<len-1)][len-1]);
  	cin>>m;
  	for(ll i=1;i<=m;i++)
  	{
  		scanf("%I64d%I64d",&l,&r);
  		p=k[r-l+1];
  		printf("%I64d",min(c[l][p],c[r-(1<<p)+1][p]));
  	}	
  	return 0;
}