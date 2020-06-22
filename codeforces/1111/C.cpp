#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e5+5;
ll const mod = 1e9+7;

// code begins here

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

ll n,k,a,b;
vector<ll> arr(maxn);

ll solve(ll l , ll r){
    auto it1 = lower_bound(arr.begin(), arr.end(), l);
    auto it2 = upper_bound(arr.begin(), arr.end(), r);
    
    ll num = (it2 - it1);
    ll sz = r-l+1;
    ll cost;
    
    if(num)
        cost = b*num*sz;
    else
        cost = a;
    
    if(sz==1 || num==0)
        return cost;
    
    ll mid = (l+r)/2;
    ll ans = min(cost, solve(l, mid) + solve(mid+1, r));
    
    return ans;
}

int main(){
    fast;
    
    cin>>n>>k>>a>>b;
    arr.resize(k);
    
    for(auto &u: arr)
        cin>>u;
    
    sort(arr.begin(), arr.end());
    
    ll ans = solve(1, binpow(2, n));
    
    cout<<ans<<endl;
    
    return 0;
}