#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1111111,pr=17;
string s;
ll p[N]={1},h[N],n,m,l,r;
int main(){
    for(;;){
        cin>>s;
        n=s.size();
        for(ll i=0;i<n;i++){
            if(!p[i])p[i]=p[i-1]*pr;
            h[i+1]=h[i]+ll(s[i]-'a'+1)*p[i];
        }
        cout<<h[n]<<"\n";
        cin>>m;
        while(m--){
            cin>>l>>r;
            cout<<(h[r]-h[l-1])/p[l-1]<<"\n";
        }
    }
}
