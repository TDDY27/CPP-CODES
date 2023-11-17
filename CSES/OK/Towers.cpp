#include <bits/stdc++.h>

using namespace std;

multiset <int> st;

signed main(){
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        if(st.upper_bound(k)!=st.end()) st.erase(st.upper_bound(k));
        st.insert(k);
    }
    cout<<st.size()<<endl;

}
