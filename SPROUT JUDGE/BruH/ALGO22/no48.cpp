#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back
using namespace std;

int n,k;

struct node{
    int ind;
    node *lc,*rc,*pr;
};

void dfs( node *nd){
    if(nd->lc!=NULL) dfs(nd->lc);
    cout<<nd->ind<<endl;
    if(nd->rc!=NULL) dfs(nd->rc);
    //cout<<nd->ind<<endl;
}

signed main(){
    TDDY
    cin>>n;

    node *now=new node;
    node *root=new node;
    node *Rroot=new node;

    cin>>k;
    root->ind=k; root->pr=NULL; root->lc=NULL; root->rc=NULL;
    now=root;
    Rroot=root;

    for(int i=0;i<n-1;i++){
        cin>>k;
        node *temp=new node;
        temp->ind=k;
        temp->lc=NULL;
        temp->rc=NULL;
	if(k<now->ind){
	    temp->pr=now;
	    now->lc=temp;
	    now=now->lc;
 	}else{
	    node *anc=new node;
	    if(now!=Rroot)anc=now->pr;
	        else anc=now;
		while( k> anc->ind && now!=Rroot){
		    if(anc==Rroot){
			now=now->pr;
			break;
   		    }
		    now=now->pr;
   	 	    anc=now->pr;
		}
		temp->pr=now;
		now->rc=temp;
		now=now->rc;
		if(k > Rroot->ind) Rroot=now;
        }
        cout<<now->ind<<" "<<now->lc<<" "<<now->rc<<" "<<now->pr<<endl;
    }
    dfs(root);
}
