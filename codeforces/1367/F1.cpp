#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 998244353;
 
// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
        
        map<ll, ll> mp;
        
        for(ll i=0;i<n;i++)
            mp[arr[i]] = i;
        
        auto i = mp.begin();
        ll ans = 0;
        
        while(i!=mp.end()){
            auto j = i;
            ll last = i->second, cnt = 1;
            j++;
            while(j!=mp.end() && j->second>last){
                last = j->second;
                j++;
                cnt++;
            }
            
            ans = max(ans, cnt);
            i = j;
        }
        
        cout<<n-ans<<endl;
    }
    
    return 0;
}