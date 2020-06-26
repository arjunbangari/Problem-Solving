#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;
 
// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> cnt(26);
    
    for(ll i=0;i<n;i++){
        string s;
        cin>>s;
        cnt[s[0]-'a']++;
    }
    
    ll ans = 0;
    
    for(ll i=0;i<26;i++){
        ll x = cnt[i]/2;
        ll y = cnt[i] - x;
        ans += x*(x-1)/2 + y*(y-1)/2;
    }
    
    cout<<ans<<endl;
    
    return 0;
}