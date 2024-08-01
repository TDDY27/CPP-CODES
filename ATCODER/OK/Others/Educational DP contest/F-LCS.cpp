#include <bits/stdc++.h>

using namespace std;

int const maxn=3005;

// number in rec : 1 means nows==nowt and move to nows-1 nowt-1
// 2 means dp[nows-1][nowt]>dp[nows][nowt] therefore move upward
// 3 means otherwise and move left

int solve(string &s,string &t,int nows,int nowt,int **dp,int **rec){
    if(nows==0 || nowt==0 || dp[nows][nowt]!=-1 ) return dp[nows][nowt];
    if(s[nows-1]==t[nowt-1]){
        dp[nows][nowt]=solve(s,t,nows-1,nowt-1,dp,rec)+1;
        rec[nows][nowt]=1;;
    }else{
        int left,up;
        up=solve(s,t,nows-1,nowt,dp,rec);
        left=solve(s,t,nows,nowt-1,dp,rec);
        if(up>left){
            dp[nows][nowt]=up;
            rec[nows][nowt]=2;
        }else{
            dp[nows][nowt]=left;
            rec[nows][nowt]=3;
        }
    }
    return dp[nows][nowt];
}
// void solve(string s,string t,int **dp,int **rec){
//     int lens=s.length(), lent=t.length();
//     for(int i=1;i<=lens;i++){
//         for(int j=1;j<=lent;j++){
//             if(s[i-1]==t[j-1]){
//                 dp[i][j]=dp[i-1][j-1]+1;
//                 rec[i][j]=1;
//             }else{
//                 if(dp[i-1][j]>dp[i][j-1]){
//                     rec[i][j]=2;
//                     dp[i][j]=dp[i-1][j];
//                 }else{
//                     rec[i][j]=3;
//                     dp[i][j]=dp[i][j-1];
//                 }
//             } 
//         }
//     }
// }

signed main(){
    string s,t;
    cin>>s>>t;
    int lens=s.length(), lent=t.length();
    int **dp= new int* [maxn];
    int **rec=new int *[maxn];
    for(int i=0;i<maxn;i++){
        dp[i]=new int [maxn];
        rec[i]=new int [maxn];
    }
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++) dp[i][j]=-1, rec[i][j]=0;
    for(int i=0;i<maxn;i++) dp[i][0]=0, dp[0][i]=0;

    solve(s,t,lens,lent,dp,rec);
    int nows=lens, nowt=lent;
    string ans="";
    while(nows!=0 && nowt!=0){
        if(rec[nows][nowt]==1){
            ans=t[nowt-1]+ans;
            nows--, nowt--;
        }else if(rec[nows][nowt]==2) nows--;
        else nowt--;
    }
    cout<<ans<<endl;
//     for(int i=0;i<=lens;i++){
//         for(int j=0;j<=lent;j++)
//             cout<<dp[i][j]<<" ";
//         cout<<endl; 
//     }
}
// #include <bits/stdc++.h>

// using namespace std;

// int const maxn=3010;
// signed main(){
//     string a,b;
//     cin>>a>>b;
//     int lena=a.size(), lenb=b.size();
//     int rec[maxn];
//     for(int i=0;i<maxn;i++) rec[i]=0;
//     int ans=0, lst=0;
//     for(int i=0;i<lena;i++){
//         lst=0;
//         for(int j=0;j<lenb;j++){
//             if(b[j]==a[i] && rec[j]<lst+1){
//                 rec[j]=lst+1; 
//             }else lst=max(lst,rec[j]);
//             // ans=max(ans,rec[j]);
//         }
//     }
//     // cout<<ans<<endl;
//     int now=1;
//     int tmp=-1;
//     for(int i=0;i<lenb;i++){
//         if(rec[i]>now && tmp!=-1){
//             cout<<b[tmp]; 
//             now=rec[i];
//             tmp=i;
//         }else if(rec[i]>now && tmp==-1){
//             now=rec[i];
//             tmp=i;
//         }else if(rec[i]==now){
//             tmp=i;
//         }
//     }
//     cout<<b[tmp]<<endl;
// }