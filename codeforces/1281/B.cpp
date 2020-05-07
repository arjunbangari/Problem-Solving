#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

string s,c;

void solve(){
    ll n = s.length();
    ll m = c.length();
    
    map<char,ll> mp;
    
    for(ll i=0;i<n;i++)
        mp[s[i]] = i;
    
    for(ll i=0;i<n;i++){
        for(char u='A'; u<s[i]; u++ ){
            if(mp.find(u)!=mp.end()){
                if(mp[u]>i){
                    swap(s[i], s[mp[u]]);
                    return;
                }
            }
        }
    }
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        cin>>s>>c;
        solve();
        
        cout<<( s<c ? s : "---" )<<endl;
    }
    
    return 0;
}