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
        
    set<ll> s;
    multiset<ll, greater<ll> > ms;
    
    vector<ll> sum(n+1);
    sum[0] = 0;
    for(ll i=1;i<=n;i++)
        sum[i] = arr[i] + sum[i-1];
    
    map<ll,ll> mp;
    
    mp[1] = n;
    s.insert(1);
    ms.insert(sum[n]);
    
    vector<ll> order(n);
    for(auto &u: order)
        cin>>u;
        
    for(ll i=0;i<n;i++){
        auto it = s.upper_bound(order[i]);
        it--;
        
        ll val = *it;
        
        ll sum1 = sum[mp[val]] - sum[order[i]];
        ll sum2 = sum[order[i]-1] - sum[val-1];
        ll original_sum = sum[mp[val]] - sum[val-1];
        ms.erase(ms.lower_bound(original_sum));
        
        mp[order[i]+1] = mp[val];
        mp[val] = order[i]-1;
        
        ms.insert(sum1);
        ms.insert(sum2);
        
        s.insert(order[i]+1);
        
        cout<<*ms.begin()<<endl;
    }
    
    
    return 0;
}