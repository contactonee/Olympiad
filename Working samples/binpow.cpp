#include <cstdio>
#include <fstream>
using namespace std;
typedef long long ll;
int main()
{
	ll a,n;
	scanf("%I64d%I64d",&a,&n);
	ll ans=1;
	while(n)
	{
		if(n&1)
		{
			ans*=a;
            n--;
		}
	 	a*=a;
	 	n>>=1;
	}
	printf("%I64d\n",ans);
}
