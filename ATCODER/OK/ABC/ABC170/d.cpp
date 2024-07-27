#include <bits/stdc++.h>

using namespace std;

int const maxn=1e6+10;

struct info{
    int val;
    int index;
};

bool cmp(info a,info b){
    if(a.val<b.val) return 1;
    else return 0;
}

signed main(){
    int n;
    cin>>n;
    info* A;
    A=new info [maxn];
    for(int i=0;i<n;i++){
        A[i].index=i;
        cin>>A[i].val;
    }
    sort(A,A+n,cmp);
    int check[maxn];
    fill(check,check+maxn,0);

    int ans=0;
    for(int i=0;i<n;i++){
        // cout<<"hi"<<endl;
        if(check[A[i].val]==0 && ( i==n-1 || A[i+1].val!=A[i].val )){
            ans++;
            // cout<<A[i].index<<endl;
            // return 0;
        }
        if(check[A[i].val]==1) continue;
        int now=A[i].val;
        while(now<maxn){
            check[now]=1;
            now+=A[i].val;
        }
    }
    cout<<ans<<endl;
}