#include <bits/stdc++.h>

using namespace std;

#define PB push_back

int const maxn=3e5+100;

int binarysearchLIS(int rec[],int n){
    vector <int> lis;
    lis.PB(rec[1]);
    for(int i=2;i<=n;i++){
        if(rec[i]>lis.back()) lis.PB(rec[i]);
        else{
            int ind=lower_bound(lis.begin(),lis.end(),rec[i])-lis.begin();
            lis[ind]=rec[i];
        }
    }
    return lis.size();
}

signed main(){
    int n;
    cin>>n;
    int A[maxn], B[maxn];
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=n;i++) cin>>B[i];
    int rec[maxn];
    for(int i=1;i<=n;i++) rec[A[i]]=B[i];
    cout<<binarysearchLIS(rec,n)+n<<endl;
}