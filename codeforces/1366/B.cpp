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

    ll t;
    cin>>t;
    
    while(t--){
        ll n,x,m;
        cin>>n>>x>>m;
        
        vector<pll> arr;
        arr.push_back({x,x});
        
        ll ans= 0;
        
        while(m--){
            ll l,r;
            cin>>l>>r;
            
            for(auto u: arr){
                if(r<u.first || l>u.second)
                    continue;
                arr.push_back({l,r});
                break;
            }
        }
        
        sort(arr.begin(), arr.end());
        
        ll sz = arr.size();
        ans += arr[0].second - arr[0].first +1;
        
        for(ll i=1;i<sz;i++){
            arr[i].first = max(arr[i].first, arr[i-1].second+1);
            if(arr[i].second>=arr[i].first)
                ans += arr[i].second - arr[i].first + 1;
            else
                arr[i].second = arr[i].first-1;
        }
        
        cout<<ans<<endl;
    }

    return 0;
}
