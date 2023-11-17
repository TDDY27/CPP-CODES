#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back

using namespace std;

struct info{
    int tm;
    int go;
};

bool cmp(info a,info b){
    if(a.tm!=b.tm) return a.tm>b.tm;
    else return a.go<b.go;
}

int n;
vector<info> vec;

signed main(){
    TDDY
    
    cin>>n;
    for(int i=0;i<n;i++){
        info tmp;
        cin>>tmp.tm; tmp.go=1, vec.PB(tmp);
        cin>>tmp.tm; tmp.go=-1, vec.PB(tmp);
    }

    sort(vec.begin(),vec.end(),cmp);
    int ans=0,rec=0;
    info now;
    while(!vec.empty()){
        now=vec.back(), vec.pop_back();
        ans=max(ans,rec+now.go);
        rec+=now.go;
    }
    cout<<ans<<endl;
}
