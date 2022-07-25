#include <bits/stdc++.h>
#define int long long
#define INF 1e17
#define _INF -1e17

using namespace std;

int const maxn=2e5+500;
int srt[maxn];
int num[maxn];

int solve(int a,int b,int ans){
    int af,ab,bf,bb; // a front a back b front b back
    af=srt[a-1], ab=srt[a+1], bf=srt[b-1], bb=srt[b+1];
    int A=srt[a], B=srt[b];

    if(B<af && A>af) ans++;
    if(B>ab && A<ab && b-a>1) ans++;
    if(A<bf && B>bf && b-a>1) ans++;
    if(A>bb && B<bb) ans++;
    if(B>af && A<af) ans--;
    if(B<ab && A>ab && b-a>1) ans--;
    if(A>bf && B<bf && b-a>1) ans--;
    if(A<bb && B>bb) ans--;

    if(b-a==1 && B>A) ans++;
    else if(b-a==1 && B<A) ans--;

    swap(srt[a],srt[b]);
    /*for(int i=1;i<=5;i++) cout<<srt[i]<<" ";
    cout<<endl;*/
    return ans;
}

signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        srt[tmp]=i;
        num[i]=tmp;
    }

    int ans=1;
    for(int i=1;i<=n-1;i++)
        if(srt[i+1]<srt[i]) ans++;

    srt[0]=_INF, srt[n+1]=INF;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(num[a]>num[b]) swap(a,b);
        ans=solve(num[a],num[b],ans);
        cout<<ans<<endl;
        swap(num[a],num[b]);
    }
}
