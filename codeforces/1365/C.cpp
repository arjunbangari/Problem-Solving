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
    
    vector<ll> arr(n), brr(n);
    
    for(auto &u: arr)
        cin>>u;
    for(auto &u: brr)
        cin>>u;
    
    map<ll,ll> mp;
    vector<ll> cnt(maxn, 0);
    
    for(ll i=0;i<n;i++)
        mp[arr[i]] = i;
    
    for(ll i=0;i<n;i++){
        ll tmp = i - mp[brr[i]];
        if(tmp<0)
            tmp += n;
        cnt[tmp]++;
    }
    
    ll ans = *max_element(cnt.begin(), cnt.end());
    
    cout<<ans<<endl;
    
    return 0;
}