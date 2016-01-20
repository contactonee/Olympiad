# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,len,l,r,calc,j,x,a[1111111],b[1111111],z[1111111];
char t;
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%I64d",&n);
    len=(ll)sqrt(n);
    len+=(len*len!=n);
    for(ll i=1;i<=n;i++)
        scanf("%I64d",&a[i]),
        b[i/len+1-!(i%len)]+=a[i];
    scanf("%I64d",&m);
    while(m--){
        cin>>t;
        scanf("%I64d%I64d",&l,&r);
        j=l;
        if(t=='U'){
            scanf("%I64d",&x);
            for(;j<=r&&j%len!=1;j++)
                a[j]+=x,b[j/len+1-!(j%len)]+=x;
            for(;j+len-1<=r;j+=len)
                z[j/len+1]+=x;
            for(;j<=r;j++)
                a[j]+=x,b[j/len+1-!(j%len)]+=x;
        }
        else{
            calc=0;
            for(;j<=r&&j%len!=1;j++)
                calc+=a[j]+z[j/len+1-!(j%len)];
            for(;j+len-1<=r;j+=len)
                calc+=b[j/len+1]+(z[j/len+1]*len);
            for(;j<=r;j++)
                calc+=a[j]+z[j/len+1-!(j%len)];
            printf("%I64d\n",calc);
        }
    }
    return 0;
}
