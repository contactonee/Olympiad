#include<bits/stdc++.h>
using namespace std;
struct item{
    int x,y,cost,sum;
    bool rev;
    item *l,*r;
};
typedef item* pitem;
pitem g,tree,h;
void upd(pitem &t){
    if(!t) return;
    t->sum=t->cost;
    t->x=1;
    if(t->l)
        t->x+=t->l->x,
        t->sum+=t->l->sum;
    if(t->r)
        t->x+=t->r->x,
        t->sum+=t->r->sum;
}
void push(pitem &t){
    if(!t->rev) return;
    if(t->l) t->l->rev^=1;
    if(t->r) t->r->rev^=1;
    t->rev=0;
    swap(t->l,t->r);
}
void split(pitem t,int x,pitem &l,pitem &r){
    if(!t){
        l=r=0;
        return;
    }
    push(t);
    int k=1;
    if(t->l) k+=t->l->x;
    if(x<k)
        split(t->l,x,l,t->l),r=t;
    else
        split(t->r,x-k,t->r,r),l=t;
    upd(l);
    upd(r);
}
void merge(pitem &t,pitem l,pitem r){
    if(!l||!r){
        t=l?l:r;
        return;
    }
    push(l);
    push(r);
    if(l->y>r->y)
        merge(l->r,l->r,r),t=l;
    else
        merge(r->l,l,r->l),t=r;
    upd(t);
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        g=new item();
        g->sum=g->cost=x;
        g->y=rand();
        g->x=1;
        merge(tree,tree,g);
    }
    cin>>n;
    while(n--){
        int c,l,r;
        cin>>c>>l>>r;
        if(c==1){
            split(tree,r,tree,h);
            split(tree,l-1,g,tree);
            cout<<tree->sum<<"\n";
            merge(tree,g,tree);
            merge(tree,tree,h);
        }
        else{
            split(tree,r,tree,h);
            split(tree,l-1,g,tree);
            tree->rev^=1;
            merge(tree,g,tree);
            merge(tree,tree,h);
        }
    }
    return 0;
}
