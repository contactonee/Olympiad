#include <bits/stdc++.h>
using namespace std;
const int N =  1111111;
int t[N], a[N], z[N];
void build(int v, int l, int r){
    if(l == r) t[v] = a[l];
    else{
        int mid = (l + r) / 2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
int get(int v, int l, int r, int tl, int tr){
    if(tl > tr) return 0;
    if(tl == l && tr == r) return t[v];
    int mid = (l + r) / 2;
    t[v * 2] += ((mid - l + 1) * z[v]), t[v * 2 + 1] += ((r - mid) * z[v]);
    z[v * 2] += z[v], z[v * 2 + 1] += z[v], z[v]=0;
    return get(v * 2, l, mid, tl, min(tr, mid)) + get(v * 2 + 1, mid + 1, r, max(tl, mid + 1), tr);
}
void upd(int v, int l, int r, int tl, int tr, int x){
    if(tl > tr) return;
    if(tl ==  l && tr ==  r) z[v] += x, t[v] += (r - l + 1) * x;
    else{
        int mid = (l + r) / 2;
        t[v * 2] += ((mid - l + 1)*z[v]), t[v * 2 + 1] += ((r - mid)*z[v]);
        z[v * 2] += z[v], z[v * 2 + 1] += z[v], z[v]=0;
        upd(v * 2, l, mid, tl, min(tr, mid), x);
        upd(v * 2 + 1, mid + 1, r, max(tl, mid + 1), tr, x);
        t[v]=t[v * 2]+t[v * 2 + 1];
    }
}
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
        cin>>a[i];
    build(1, 1, n);
    int m;
    cin>>m;
    while(m--){
        int c, l, r;
        cin>>c>>l>>r;
        if(c<2)
            cout<<get(1, 1, n, l, r)<<"\n";
        else{
            int x;
            cin>>x;
            upd(1, 1, n, l, r, x);
        }
    }
    return 0;
}
