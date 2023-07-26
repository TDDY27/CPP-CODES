#include <bits/stdc++.h>

using namespace std;

int n;
queue <pair<int,int>> cow;
stack <pair<int,int>> rec;

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>> tmp;
        cow.push({tmp,i});
    }

    int ans[n+5];
    memset(ans,0,sizeof(ans));

    rec.push(cow.front()), cow.pop();
    while(!cow.empty()){
        if(cow.front().first<rec.top().first) rec.push(cow.front()), cow.pop();
        else{
            while(!rec.empty() && cow.front().first>=rec.top().first){
                ans[rec.top().second]=cow.front().second-rec.top().second;
                rec.pop();
            }
            rec.push(cow.front()), cow.pop();
        }
    }

    while(!rec.empty()){
        ans[rec.top().second]=n-rec.top().second;
        rec.pop();
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<endl;

}
