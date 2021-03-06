#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef tree<
    ll,
    null_type,
    less_equal<ll>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    vector<ll> pre(n), suf(n);
    map<ll,ll> mp;
    
    for(ll i=0;i<n;i++){
        mp[arr[i]]++;
        pre[i] = mp[arr[i]];
    }
    
    mp.clear();
    
    for(ll i=n-1;i>=0;i--){
        mp[arr[i]]++;
        suf[i] = mp[arr[i]];
    }
    
    ordered_set os;
    
    ll ans = 0;
    
    for(ll i=n-1;i>=0;i--){
        ans += os.order_of_key(pre[i]);
        os.insert(suf[i]);
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}