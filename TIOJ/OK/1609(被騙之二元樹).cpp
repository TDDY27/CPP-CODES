#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back

using namespace std;

struct node{
    int ind;
    node *lc, *rc, *pr;
};

int n;
node *root= new node;

void Insert(int a){
    node *now=root;
    while(true){
        if(a> now->ind && now->rc!=NULL) now=now->rc;
        else if(a< now->ind && now->lc!=NULL) now=now->lc;
        else  break;
    }
    // remember to open a new memory space
    node *tmp= new node; tmp->ind=a, tmp->pr=now, tmp->lc=NULL, tmp->rc=NULL;
    if(a> now->ind) now->rc=tmp;
    else now->lc=tmp;
}

void dfs(node *a){
    if(a->lc !=NULL) dfs(a->lc);
    cout<< a->ind <<" ";
    if(a->rc !=NULL) dfs(a->rc);
}

signed main(){
    TDDY

    cin>>n;
    int vi; cin>>vi;
    root->ind=vi, root->pr=NULL, root->lc=NULL, root->rc=NULL;

    for(int i=0;i<n-1;i++){ int tmp; cin>>tmp, Insert(tmp); }
    dfs(root);
}
