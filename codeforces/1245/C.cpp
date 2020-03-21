#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll m = 1e9+7;
    
    string s;
    cin>>s;
    
    ll n = s.length();
    
    for(ll i=0;i<n;i++){
        if(s[i]=='m' || s[i]=='w'){
            cout<<0<<endl;
            return 0;
        }
    }
    
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    
    ll dp[n];
    dp[0] = 1;
    
    if(s[1]==s[0] && (s[1]=='u' || s[1]=='n'))
        dp[1] = 2;
    else
        dp[1] = 1;
    
    for(ll i=2;i<n;i++){
        if((s[i]=='u' || s[i]=='n') && (s[i]==s[i-1]))
            dp[i] = (dp[i-1]+dp[i-2])%m;
        else
            dp[i] = dp[i-1];
    }
    
    cout<<dp[n-1]%m<<endl;
    
    return 0;
}