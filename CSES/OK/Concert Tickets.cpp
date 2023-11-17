#include <bits/stdc++.h>

using namespace std;

multiset <int> st;

signed main(){
    int n,m,h,t;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        st.insert(tmp);
    }

    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        if(st.upper_bound(tmp)==st.begin()) cout<<-1<<endl;
        else{
            //thanksone is to dian to pretend weak
            cout<<*--st.upper_bound(tmp)<<endl;
            st.erase(--st.upper_bound(tmp));
        }
    }
}
