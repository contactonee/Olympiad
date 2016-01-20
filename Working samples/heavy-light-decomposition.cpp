#include <bits/stdc++.h>
using namespace std;
const int N=111111,INF=2e9;
int n,t[N],z[N],tin[N],tout[N],ttime,p[N][20],id[N],head[N],pos[N],sz[N],curchain,curvertex;
bool used[N];
vector<int>g[N];
void dfs(int v,int pr){
    sz[v]=1;
    tin[v]=++ttime;
    p[v][0]=pr;
    for(int i=1;i<18;i++)
        p[v][i]=p[p[v][i-1]][i-1];
    for(int i=0;i<g[v].size();i++){
        int to=g[v][i];
        if(to!=pr){
            dfs(to,v);
            sz[v]+=sz[to];
        }
    }
    tout[v]=++ttime;
}
void heavylight(int v){
    used[v]=1;
    id[v]=curchain;
    if(!head[curchain]) head[curchain]=v;
    pos[v]=++curvertex;
    if(g[v].size()==1&&v!=1) return;
    int maxsz=-1,maxson;
    for(int i=0;i<g[v].size();i++){
        int to=g[v][i];
        if(!used[to]&&sz[to]>maxsz) maxsz=sz[to],maxson=to;
    }
    heavylight(maxson);
    for(int i=0;i<g[v].size();i++){
        int to=g[v][i];
        if(!used[to]) curchain++,heavylight(to);
    }
}
int getmax(int v,int l,int r,int tl,int tr){
    if(tl>tr) return -INF;
    if(tl==l&&tr==r) return t[v];
    int mid=(l+r)/2;
    t[v*2]+=z[v],t[v*2+1]+=z[v];
    z[v*2]+=z[v],z[v*2+1]+=z[v],z[v]=0;
    return max(getmax(v*2,l,mid,tl,min(tr,mid)),getmax(v*2+1,mid+1,r,max(tl,mid+1),tr));
}
void upd(int v,int l,int r,int tl,int tr,int x){
    if(tl>tr) return;
    if(tl==l&&tr==r) t[v]+=x,z[v]+=x;
    else{
        int mid=(l+r)/2;
        t[v*2]+=z[v],t[v*2+1]+=z[v];
        z[v*2]+=z[v],z[v*2+1]+=z[v],z[v]=0;
        upd(v*2,l,mid,tl,min(tr,mid),x);
        upd(v*2+1,mid+1,r,max(tl,mid+1),tr,x);
        t[v]=max(t[v*2],t[v*2+1]);
    }
}
int maxvalue(int u,int v){
    int ans=0;
    while(id[u]!=id[v]){
        int Head=head[id[u]];
        ans=max(ans,getmax(1,1,n,pos[Head],pos[u]));
        u=p[Head][0];
    }
    return max(ans,getmax(1,1,n,pos[v],pos[u]));
}
void addvalue(int u,int v,int x){
    while(id[u]!=id[v]){
        int Head=head[id[u]];
        upd(1,1,n,pos[Head],pos[u],x);
        u=p[Head][0];
    }
    upd(1,1,n,pos[v],pos[u],x);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,1);
    heavylight(1);
    for(;;){
        int u,v,c,lca;
        scanf("%d%d%d",&u,&v,&c);
        if(tin[u]<tin[v]) swap(u,v);
        lca=u;
        for(int i=17;i>=0;i--)
            if(!(tin[p[lca][i]]<tin[v]&&tout[p[lca][i]]>tout[v]))
                lca=p[lca][i];
        lca=p[lca][0];
        if(u==v) lca=u;
        if(!c)
            printf("%d\n",max(maxvalue(u,lca),maxvalue(v,lca)));
        else
            addvalue(u,lca,c),
            addvalue(v,lca,c),
            addvalue(lca,lca,-c);
    }
}
