#include <bits/stdc++.h>
using namespace std;
int n, m;
struct item{
    int x, y, sz;
    item *l, *r;
};
typedef item* pitem;
pitem tree, tmp, tmp1;
void upd (pitem &t){
    if (t){
        t -> sz =  1;
        if (t -> l)
            t -> sz += t -> l -> sz;
        if (t -> r)
            t -> sz += t -> r -> sz;
    }
}
void split (pitem t, int x, pitem &l, pitem &r){
    if(!t){
        l =  r =  0;
        return;
    }
    if (t -> x<=x)
        split (t -> r, x, t -> r, r),l =  t;
    else
        split (t -> l, x, l, t -> l),r =  t;
    upd (l);
    upd (r);
}
void merge (pitem &t, pitem l, pitem r){
    if(!l||!r){
        t =  l?l:r;
        return;
    }
    if (l -> y>r -> y)
        merge (l -> r, l -> r, r),t =  l;
    else
        merge (r -> l, l, r -> l),t =  r;
    upd (t);
}
void insert (pitem &t, pitem it){
    if(!t||it -> y>t -> y)
        split (t, it -> x, it -> l, it -> r),t =  it;
    else
        insert (t -> x >= it -> x ? t -> l : t -> r, it);
    upd (t);
}
void erase (pitem &t, int x){
    if (t -> x  ==  x)
        merge (t, t -> l, t -> r);
    else
        erase (t -> x<=x?t -> r:t -> l, x);
}
int get (pitem t, int k){
    if(!t)
        return -1;
    int cnt =  1;
    if (t -> l)
        cnt += t -> l -> sz;
    if (cnt  ==  k)
        return t -> x;
    if (cnt>k)
        return get (t -> l, k);
    else
        return get (t -> r, k - cnt);
}
main(){
    cin >> n;
    for (int i =  1;i<=n;i++){
        int x;
        cin >> x;
        tmp = new item();
        tmp -> x =  x;
        tmp -> y =  rand();
        tmp -> sz =  1;
        insert (tree, tmp);
    }
    cin >> m;
    while (m--){
        string s;
        int x;
        cin >> s >> x;
        if (s.size() == 2){
            split (tree, x - 1, tree, tmp);
            split (tmp, x, tmp1, tmp);
            merge (tree, tree, tmp);
        }
        else{
            if (s[0] == '+'){
                tmp =  new item();
                tmp -> x =  x;
                tmp -> y =  rand();
                tmp -> sz =  1;
                insert (tree, tmp);
            }
            if (s[0] == '-')
                erase (tree, x);
            if (s[0] == '?')
                cout << get (tree, x) << "\n";
        }
    }
    return 0;
}
