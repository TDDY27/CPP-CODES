#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back
using namespace std;

int const maxn=2500;
int n,k;

struct node{
    int ind;
    node *lc,*rc,*pr;
};

signed main(){
    TDDY
    cin>>n;

    node now;
    now.pr=NULL; now.lc=NULL; now.rc=NULL; now.ind=-1;
    node root;

    cin>>k;
    root.ind=k; root.pr=NULL; root.lc=NULL; root.rc=NULL;
    now=root;

    for(int i=0;i<n;i++){
        cin>>k;
        node *temp=new node;
        temp->ind=k;
        temp->lc=NULL;
        temp->rc=NULL;

        if(k<now.ind){
            temp->pr=&now;
            now.lc=temp;
            now->lc; // 不知道出了甚麼bug
        }else{
        }
    }
}
