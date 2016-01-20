#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
typedef long long ll;
ll n,m,s,e[100001],h[100001],g[100001];
bool b[100001];
vector < ll > sorted;
void dfs(ll v)
{
	b[v]=true;
	ll i=h[v];
	while(i>0)
	{
		if(!b[e[i]])
			dfs(e[i]);
		i=g[i];
	}
	sorted.push_back(v);
}
int main()
{
	freopen("dfs.in","r",stdin);
	cin >> n >> m >> s;
	for(ll i=1;i<=m;i++)
	{
		ll x;
		cin >> x >> e[i];
		g[i]=h[x];
		h[x]=i;
	}
	dfs(s);
	for(ll i=sorted.size()-1;i>=0;i--)
		cout << sorted[i] << " ";
   	return 0;
}