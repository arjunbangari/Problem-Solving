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
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    ll mn = *min_element(arr.begin(), arr.end());
    ll mx = *max_element(arr.begin(), arr.end());
    
    ll ans = mx - mn + 1 - n;
    
    cout<<max(ans, 0LL)<<endl;
    
    return 0;
}