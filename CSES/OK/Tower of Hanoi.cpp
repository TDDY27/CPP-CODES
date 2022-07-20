#include <bits/stdc++.h>

using namespace std;

void solve(int n,int sau,int aux,int tar){
    // sauce, auxiliary, target
    if(!n) return;
    solve(n-1,sau,tar,aux);
    cout<<sau<<" "<<tar<<endl;
    solve(n-1,aux,sau,tar);
}

signed main(){
    int n;
    cin>>n;
    cout<< (1<<n)-1 <<endl;
    solve(n,1,2,3);
}
