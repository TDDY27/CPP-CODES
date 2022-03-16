#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int const maxn=2500;
int n,k;

struct node{
    int ind;
    node *lc,*rc,*pr;

    void printnode(node a){
        cout<<a.ind<<endl;
    }
};

signed main(){
    TDDY
    cin>>n;

    node root,rec;
    cin>>k;
    root.ind=k;
    root.pr=NULL;
    rec.ind=k;

    for(int i=0;i<n-1;i++){
        cin>>k;
        node temp;
        if(k>temp)

    }


}

