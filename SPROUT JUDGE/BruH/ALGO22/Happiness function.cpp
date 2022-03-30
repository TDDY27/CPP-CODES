#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back

using namespace std;

int t,n;
float f[20][3];

float func(int num,int ind){
    return f[num][0]*(ind-f[num][1])*(ind-f[num][1])+f[num][2];
}

float ter(int a){
    float fa,fb,fc,fd;
    fa=0,fb=100,fc=200,fd=300;
    while(fd-fa>1e-7){
        cout<<func(a,fb)<<" "<<func(a,fc)<<endl;
        if( func(a,fb)>func(a,fc) ){
            fa=fb;
            fc=fa+(fd-fa)*2/3;
            fb=fa+(fd-fa)*1/3;
        }else if( func(a,fb)<func(a,fc) ){
            fd=fc;
            fc=fa+(fd-fa)*2/3;
            fb=fa+(fd-fa)*1/3;
        }else if( func(a,fb)==func(a,fc)){
            return func(a,(fb+fc)/2);
        }
    }
    return func(a,(fb+fc)/2);
}

signed main(){
    cin>>t;
    while(t>0){
        memset(f,0,sizeof(f));

        cin>>n;
        for(int i=1;i<=n;i++) cin>>f[i][0]>>f[i][1]>>f[i][2];
        float maxn=-1;

        for(int i=1;i<=n;i++) mmax=min(mmin,ter(i));
        cout<<mmin<<endl;

        t--;
    }
}
