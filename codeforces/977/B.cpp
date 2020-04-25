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

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    string s;
    cin>>s;
    
    map<string, ll> mp;
    
    for(ll i=1;i<n;i++){
        string t;
        t.push_back(s[i-1]);
        t.push_back(s[i]);
        mp[t]++;
    }
    
    string ans;
    ll mx=-1;
    
    for(auto u: mp){
        if(u.second>mx)
            ans = u.first;
        mx = max(mx, u.second);
    }
    
    cout<<ans<<endl;
    
    return 0;
}