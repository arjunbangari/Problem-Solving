#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    string s,t,ans;
    cin>>s;
    cin>>t;
    ll ss = s.length();
    ll st = t.length();
    
    ll dp[ss+1][st+1];
    for(ll i=0;i<=ss;i++)
        dp[i][0] = 0;
    for(ll i=0;i<=st;i++)
        dp[0][i] = 0;
        
    for(ll i=1;i<=ss;i++){
        for(ll j=1;j<=st;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    ll i=ss,j=st;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans = s[i-1]+ans;
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}