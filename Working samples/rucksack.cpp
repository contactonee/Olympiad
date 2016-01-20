#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
typedef long long ll;

vector < ll > f;
ll n,m,p[101],w[101],a[101][101];


void ans(ll k,ll s)
{
	if(a[k][s]==0)
		return;

	if(a[k][s]==a[k-1][s])
		ans(k-1,s);

 	else
 		ans(k-1,s-w[k]);

 	f.push_back(k);
}

int main()
{
	freopen("in.txt","r",stdin);
	cin >> n >> m;
	for(ll i=1;i<=n;i++)
	{
		cin >> p[i] >> w[i];
	}
	for(ll i=1;i<=max(n,m);i++)
	{
		a[i][0]=0;
		a[0][i]=0;		
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			if(w[i]<=j)
			{
				a[i][j]=max(a[i-1][j],a[i-1][j-w[i]]+p[i]);
			}
			else
			{
				a[i][j]=a[i-1][j];
			}		
		}
	}
	cout << a[n][m] << endl;
	ans(n,m);
	for(ll i=0;i<f.size();i++)
	{
		cout << f[i] << " ";
	}
	return 0;
}