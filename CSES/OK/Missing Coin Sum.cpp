#include <bits/stdc++.h>
#define int long long

using namespace std;

int const maxn=2e5+500;
int num[maxn];

signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>num[i];
    sort(num,num+n);

    int now=0;
    for(int i=0;i<n;i++){
        if(num[i]>now+1){
            cout<<now+1<<endl;
            return 0;
        }
        now+=num[i];
    }
    cout<<now+1<<endl;
}
