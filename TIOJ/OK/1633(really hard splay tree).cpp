#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define lc ch[p][0]
#define rc ch[p][1]

using namespace std;

int n,m,l1,r1,l2,r2;
string com;//command
int const maxn=2e5;
int fa[maxn], ch[maxn][2], rev[maxn],sz[maxn];

void pull(int p){
    sz[p]=sz[lc]+sz[rc]+1;
}

// Don't forget to push down or update the lazy tag
void push(int p){
    if(rev[p]) swap(lc,rc);
    rev[lc]^=rev[p], rev[rc]^=rev[p];
    rev[p]=0;
}

void update(int p){
    if(fa[p]) update(fa[p]);
    push(p);
}

int get(int p){
    return ch[fa[p]][1]==p;
}

void turn(int p){
    // t stand for temporary+something
    int g=get(p), f=fa[p], c=ch[p][!g];
    if(fa[f]) ch[fa[f]][get(f)]=p;
    fa[p]=fa[f], fa[f]=p, ch[f][g]=c, ch[p][!g]=f;
    if(c) fa[c]=f;
    pull(f), pull(p);// care!!! pull(f) first pull(p) later
}

void splay(int p){
    update(p);
    /*for(int f=fa[p]; f; f=fa[p]){
        if(get(p)==get(f)) turn(f),turn(p);
        else turn(p),turn(p);
    }*/
    for(int f=fa[p]; f; turn(p), f=fa[p])
        if(fa[f]) turn( get(p)==get(f)? f:p );
}

/*int Rank(int p){
    splay(p);
    return sz[lc]+1;
}*/

// Don't forget to push down or update the lazy tag
int Find(int p,int k){
    splay(p);// only update/push the element above p but no element beneath
    while(k){
        push(p);// very important  don't forget
        if(k>sz[lc]+1) k-=sz[lc]+1, p=rc;
        else if(k<=sz[lc]) p=lc;
        else return p;
    }
    return 0;
}

void split(int p,int k){
    if(!k || !sz[p]) return;
    p=Find(p,k), splay(p);
    fa[rc]=0, rc=0;
    pull(p);
}

void Merge(int u,int v){
    if(!sz[u] || !sz[v] || Find(u,1)==Find(v,1) ) return;
    u=Find(u,sz[u]), v=Find(v,1), splay(u), splay(v);
    ch[u][1]=v, fa[v]=u;
    pull(u);
}

void build(int f,int l,int r){
    if(l>r) return;
    int p=(l+r)>>1;
    fa[p]=f, ch[f][p>f]=p;
    build(p,l,p-1); build(p,p+1,r);
    pull(p);
}

void print(int p){
    if(!p) return;
    push(p);
    print(lc), cout<<p<<" ", print(rc);
}

signed main(){
    TDDY

    cin>>n>>m;
    build(0,1,n);
    ch[0][1]=0; //Because build(0,1,n) make ch[0][1]=(1+n)/2
    while(m>0){
        cin>>com;
        cin>>l1>>r1;
        int a,b,c,d,e;
        if(com=="REV"){
            a=Find(1,l1-1), b=Find(1,r1), c=Find(1,r1+1);
            split(b,r1), split(b,l1-1);
            splay(b), rev[b]^=1;
            Merge(a,b), Merge(b,c);
        }else{
            cin>>l2>>r2;
            a=Find(1,l1-1), b=Find(1,r1), c=Find(1,r1+1), d=Find(1,r2), e=Find(1,r2+1);
            //Because 1<=l1<=r1<=l2<=r2<=N so only five intervals
            split(b,r2), split(b,l2-1), split(b,r1), split(b,l1-1);
            Merge(a,d), Merge(d,c), Merge(c,b), Merge(b,e);
        }
        m--;
    }
    splay(1), print(1), cout<<endl;
    return 0;
}
