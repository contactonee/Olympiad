#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    return a?gcd(b%a,a):b;
}
int main()
{
	ll a,b,g;
	cin>>a>>b;
	g=gcd(a,b);
	if(a>b)
        swap(a,b);
	printf("GCD(%I64d,%I64d)=%I64d\nLCM(%I64d,%I64d)=%I64d",a,b,g,a,b,a/g*b);
	return 0;
}
