#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;

struct info{
    int x;
    int y;
};

int const maxn=1e6+500;
int n;

int operator ^ ( info const &a, info const &b){
    return a.x*b.y-a.y*b.x;
}

info operator - (info const &a, info const &b){
    info tmp; tmp.x=a.x-b.x, tmp.y=a.y-b.y;
    return tmp;
}

int operator * (info const &a, info const &b){
    return a.x*b.x+a.y*b.y;
}

signed main(){
    TDDY
    cin>>n;

    int r=0,l=0,b=0;
    info vec1,vec2,now,then; //vector
    cin>>then.x>>then.y>>now.x>>now.y;
    vec1=now-then, then=now;

    for(int i=0;i<n-2;i++){
        cin>>now.x>>now.y;
        vec2=now-then;

        int tmp=vec1^vec2;
        if(tmp>0) l++;
        else if(tmp==0 && vec1*vec2<0) b++;
        else if(tmp<0) r++;
        then=now, vec1=vec2;
    }

    cout<<l<<" "<<r<<" "<<b<<endl;
}
