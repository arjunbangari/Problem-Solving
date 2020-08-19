#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> arr(maxn);
map<ll, ll> cnt;

ll check(ll m, ll n){
    multiset<ll, greater<ll>> available;
    set<pll> used;
    
    for(auto u: cnt)
        available.insert(u.second);
    
    ll t = 0;
    
    for(ll i=0;i<=m;i++){
        if(available.empty())
            return false;
        
        ll val = *available.begin();
        available.erase(available.begin());
        used.insert({t++, val-1});
    }
    
    for(ll i=m+1;i<n;i++){
        pll x = *used.begin();
        used.erase(used.begin());
        
        available.insert(x.second);
        
        ll val = *available.begin();
        available.erase(available.begin());
        
        if(val==0)
            return false;
        
        used.insert({t++, val-1});
    }
    
    return true;
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        cnt.clear();
        
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        for(ll i=0;i<n;i++)
            cnt[arr[i]]++;
        
        ll l =0, r = n-1, ans=0;
        
        while(l<=r){
            ll mid = (l+r)/2;
            if(check(mid, n)){
                ans = mid;
                l = mid+1;
            } else 
                r = mid-1;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}