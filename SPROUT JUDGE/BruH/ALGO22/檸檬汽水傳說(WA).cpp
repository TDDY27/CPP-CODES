#include <bits/stdc++.h>
#define int long long
#define PB push_back
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int t,n,a,ans,same1,same2,frnt;

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        cin>>n;
        vector <int> v;
        ans=0;
        same1=0;
        same2=0;

        for(int i=0;i<n;i++){
            cin>>a;
            int near=1;
            while(v.size()>0){
                if(a>v.back()){
                    ans++;
                    v.pop_back();
                    near++;
                    if(a>same2)same1=0;
                }else if(a==v.back()){
                    same2=a;
                    if(same1==0) frnt=v.size();
                    same1++;
                    ans+=same1;
                    if(v.size()>1 && frnt!=1) ans++;
                    //cout<<same1<<endl;
                    break;
                }else{
                    if(near==1)ans++;
                    break;
                }
            }
            v.PB(a);
        }

        cout<<ans<<endl;
        t--;
    }

}
