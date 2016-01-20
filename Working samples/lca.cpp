#include<bits/stdc++.h>
using namespace std;
vector<int>g[111111];
int n,tin[111111],tout[111111],t,p[111111][20];
void dfs(int v,int pr){
    tin[v]=++t;
    p[v][0]=pr;
    for(int i=1;i<=18;i++)
        p[v][i]=p[p[v][i-1]][i-1];
    for(int i=0;i<g[v].size();i++){
        int to=g[v][i];
        if(to!=pr) dfs(to,v);
    }
    tout[v]=++t;
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
    for(;;){
        int u,v,lca;
        scanf("%d%d",&u,&v);
        if(tin[u]<=tin[v]) swap(u,v);
        lca=u;
        for(int i=18;i>=0;i--)
            if(!(tin[p[lca][i]]<=tin[v]&&tout[p[lca][i]]>=tout[v]))
                lca=p[lca][i];
        lca=p[lca][0];
        if(u==v) lca=u;
        printf("%d\n",lca);
    }
}
