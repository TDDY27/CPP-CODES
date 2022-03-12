#include <bits/stdc++.h>
#define int long long
#define PB push_back
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

vector <int> v;
int t,n,a,ans;

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        cin>>n;
        v.clear();
        ans=0;

        for(int i=0;i<n;i++){
            cin>>a;
            int near=1;
            while(v.size()>0){
                if(a>v.back()){
                    ans++;
                    v.pop_back();
                    near++;
                }else if(a==v.back()){
                    for(int j=v.size()-1;v[j]==a;j--) ans++;
                    if(v.size()>1)ans++;
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
