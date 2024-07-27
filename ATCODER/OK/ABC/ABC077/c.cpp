#include <bits/stdc++.h>

using namespace std;

#define ll long long

int const maxn=1e5+10;

signed main(){
    int n;
    cin>>n;
    ll A[maxn],B[maxn],C[maxn];
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n;i++) cin>>B[i];
    for(int i=0;i<n;i++) cin>>C[i];
    sort(A,A+n);
    sort(B,B+n);
    sort(C,C+n);

    ll recB[maxn];
    fill(recB,recB+maxn,0);
    int nowA=0, nowB=0;
    while(nowB<n){
        if(nowA>=n){
            recB[nowB+1]=recB[nowB];
            nowB++;
        }else if(B[nowB]>A[nowA]){
            recB[nowB]++;
            nowA++;
        }else{
            recB[nowB+1]+=recB[nowB];
            nowB++;
        }
    }
    ll recC[maxn];
    fill(recC,recC+maxn,0);
    int nowC=0;
    nowB=0;
    while(nowC<n){
        if(nowB>=n){
            recC[nowC+1]+=recC[nowC];
            nowC++;
        }else if(C[nowC]>B[nowB]){
            recC[nowC]+=recB[nowB];
            nowB++;
        }else{
            recC[nowC+1]+=recC[nowC];
            nowC++;
        }
    }
    // for(int i=0;i<n;i++) cout<<recB[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<n;i++) cout<<recC[i]<<" ";
    // cout<<endl;
    ll ans=0;
    for(int i=0;i<n;i++) ans+=recC[i];
    cout<<ans<<endl;
}