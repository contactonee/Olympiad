# include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(ll i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
