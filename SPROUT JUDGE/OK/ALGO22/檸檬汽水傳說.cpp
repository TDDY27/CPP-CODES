#include <bits/stdc++.h>
#define int long long
#define PB push_back
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int t,n,ans;

struct rec{
    int val;
    int same;
};

rec a;
vector <rec> v;

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        cin>>n;
        v.clear();
        ans=0;

        for(int i=0;i<n;i++){
            cin>>a.val;
            a.same=0;
            while(v.size()>0){
                if(a.val>v.back().val){
                    ans++;
                    ans+=v.back().same;
                    v.pop_back();
                }else if(a.val==v.back().val){
                    ans++;
                    ans+=v.back().same;
                    a.same=v.back().same+1;
                    v.pop_back();
                }else{
                    ans++;
                    break;
                }
            }
            v.PB(a);
        }

        cout<<ans<<endl;
        t--;
    }

}
