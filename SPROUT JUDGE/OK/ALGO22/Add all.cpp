#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int t,n;

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        priority_queue<int,vector<int>,greater<int> >prio;
        cin>>n;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            prio.push(temp);
        }
        int ans=0;
        int add=0;
        while(prio.size()>1){
            add=0;
            add+=prio.top();
            prio.pop();
            add+=prio.top();
            prio.pop();
            ans+=add;
            prio.push(add);
        }
        cout<<ans<<endl;

        t--;
    }
}
