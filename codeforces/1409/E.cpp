#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,k;
        cin>>n>>k;
        
        vector<ll> arr(n), ycord(n);
        for(auto &u: arr)
            cin>>u;
        for(auto &u: ycord)
            cin>>u;
        
        sort(all(arr));
        
        vector<pll> klen;
        
        for(ll i=0;i<n;i++){
            if(i && arr[i]==arr[i-1])
                continue;
            auto it = upper_bound(all(arr), arr[i]+k);
            ll l1 = it - arr.begin();
            
            ll num = l1 - i;
            klen.push_back({arr[i], num});
        }
        
        // for(auto u: klen)
        //     cout<<u.first<<" "<<u.second<<endl;
        
        ll sz = klen.size();
        
        vector<ll> mx(sz);
        mx[sz-1] = klen[sz-1].second;
        for(ll i=sz-2;i>=0;i--)
            mx[i] = max(klen[i].second, mx[i+1]);
        
        // for(auto u: mx)
        //     cout<<u<<" ";
        // cout<<endl;
        
        ll ans = 0;
        
        for(auto u: klen){
            ll sum = u.second;
        
            auto it = lower_bound(all(klen), make_pair(u.first+k+1, 0LL));
            auto ln = it - klen.begin();
            
            // cout<<u.first<<" "<<u.second<<" "<<ln<<endl;
            
            if(it!=klen.end())
                sum += mx[ln];
            
            // cout<<    
            
            ans = max(sum, ans);
        }
        
        cout<<ans<<endl;
        
    }
    
    return 0;
}