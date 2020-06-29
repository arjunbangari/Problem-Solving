#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll q;
    cin>>q;
    
    while(q--){
        ll n;
        cin>>n;
        
        map<ll, pll> mp;
        
        vector<ll> arr(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]] = {inf, -1};
        }
        
        for(ll i=0;i<n;i++){
            mp[arr[i]].first = min(mp[arr[i]].first, i);
            mp[arr[i]].second = max(mp[arr[i]].second, i);
        }
        
        ll last = -1, cnt = 0, total = 0, mx = 0;
        
        for(auto u: mp){
            total++;
            if(u.second.first>last)
                cnt++;
            else 
                cnt = 1;
            
            last = u.second.second;
            mx = max(mx, cnt);
        }
        
        cout<<total-mx<<endl;
    }
    
    return 0;
}