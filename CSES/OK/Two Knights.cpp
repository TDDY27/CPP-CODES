#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;

int k;

signed main(){
    cin>>k;

    for(int i=1;i<=k;i++){
        // by drawing and you can find the answer
        // i got some inspirations from thanksone
        // and also get some hints from https://www.codespeedy.com/the-two-knights-problem-implemented-in-c/
        cout<< i*i*(i*i-1)/2 - 4*(i-1)*(i-2) << endl;
    }
}
