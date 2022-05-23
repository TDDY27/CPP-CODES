#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n;
int f[10500][5];
int mul=1e6;

float func(float pos){
    float mmin=1e8;
    for(int i=1;i<=n;i++){
        float tmp=f[i][1]*(pos*pos)+f[i][2]*pos+f[i][3];
        mmin=min(mmin,tmp);
    }
    return mmin;
}

float ter(){ // ternary search
    int t=1e4;
    float f4,f3,f2,f1;
    f4=60*24*90; f1=0; f3=(f4+f1)*2/3; f2=(f4+f1)/31;
    for(int i=1;i<=t;i++){
        if(func(f2)>func(f3)) f4=f3;
        else f1=f2;
        f3=(f1+f4)*2/3; f2=(f1+f4)/3;
        f1*=mul; f2*=mul; f3*=mul; f4*=mul;
        f1=trunc(f1); f2=trunc(f2); f3=trunc(f3); f4=trunc(f4);
        f1/=mul; f2/=mul; f3/=mul; f4/=mul;
    }
    float res=(f2+f3)/2;
    res*=mul; res=trunc(res); res/=mul;
    return res;
}

signed main(){
    TDDY
    cin>>n;
    for(int i=1;i<=n;i++) cin>>f[i][1]>>f[i][2]>>f[i][3];
    float ans=ter();
    cout<<setprecision(6)<<fixed<<ans<<endl;
}
