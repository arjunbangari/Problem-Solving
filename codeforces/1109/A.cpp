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
    
    vector<ll> arr(n+1);
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    
    ll ans = 0;
    map<ll, pll> mp;
    mp[0].second++;
    
    for(ll i=1;i<=n;i++){
        arr[i] ^= arr[i-1];
        
        if(i&1){
            ans += mp[arr[i]].first;
            mp[arr[i]].first++;
        }
        else{
            ans += mp[arr[i]].second;
            mp[arr[i]].second++;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}