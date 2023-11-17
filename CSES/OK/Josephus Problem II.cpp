#include <bits/stdc++.h>
#define int long long

using namespace std;

int const maxn=2e5+500;
int bit[maxn];

void update(int pos,int val){
    for(int i=pos;i<maxn;i+=i&(-i) ) bit[i]+=val;
}

int query(int pos){
    int sum=0;
    for(int i=pos;i>=1;i-=i&(-i) ) sum+=bit[i];
    return sum;
}

int who(int num){
    int sum=0, per=0;
    for(int i=1<<17; i>=1; i>>=1 ){
        if(per+i<maxn && sum+bit[per+i]<num){ sum+=bit[per+i], per+=i; }
    }
    return per+1;
}


signed main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) update(i,1);

    int now=0;
    for(int i=1;i<=n;i++){
        now=who( (query(now)+k)%query(n)+1 );
        cout<<now<<" ";
        update(now,-1);
    }
}
