#include <bits/stdc++.h>
#define int long long
#define PB push_back
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int t,n,a,ans,same1,same2,frnt;
vector <int> v;

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        cin>>n;
        v.clear();
        ans=0;
        same1=0;
        same2=-1;

        for(int i=0;i<n;i++){
            cin>>a;
            while(v.size()>0){
                if(a>v.back()){
                    ans++;
                    v.pop_back();
                    if(a>same2)same1=0;
                }else if(a==v.back()){
                    if(a<same)
                    same2=a;
                    if(same1==0) frnt=v.size();
                    same1++;
                    ans+=same1;
                    if(v.size()>1 && frnt!=1) ans++;
                    //cout<<same1<<endl;
                    break;
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
// 遇到相等的case會bug 尤其是相等夾相等的case  ex 2 2 2 1 1 1 、2 2 1 1 2 2 、 2 2 2 1 1 1 2 2 2
