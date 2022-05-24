#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back

using namespace std;

int const maxn=5e5+500;
array<int,maxn> lps;
string s,t;
vector <int> rec;

void KMP(){

    int i,j;
    i=0; j=0;
    while(i<t.size()){
        if(s[j]==t[i] && j!=s.size()-1){
            i++; j++;
        }else if(s[j]==t[i] && j==s.size()-1){
            rec.PB(i-j);
            i++; j=lps[j];
        }else if(s[j]!=t[i] && j!=0){
            j=lps[j-1];
        }else if(s[j]!=t[i] && j==0){
            i++;
        }
    }
}

array <int,maxn> LPS(){
    array <int,maxn> tmp;

    tmp[0]=0;
    int i,len;
    i=1; len=0;

    while(i<s.size()){
        if(s[i]==s[len]){
            len++;
            tmp[i]=len;
            i++;
        }else{
            if(len!=0) len=tmp[len-1];
            else{ tmp[i]=0; i++; }
        }
    }

    return tmp;
}

signed main(){
    cin>>s>>t;
    lps=LPS();
    KMP();
    if(rec.size()>0){
        cout<<rec[0];
        for(int i=1;i<rec.size();i++) cout<<" "<<rec[i];
    }
    cout<<"\n";
}
