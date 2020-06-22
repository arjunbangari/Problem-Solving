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

int main(){
    fast;
    
    ll n,k,m;
    cin>>n>>k>>m;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
        
    sort(arr.rbegin(), arr.rend());
    
    ld ans = -inf;
    
    for(ll i=1;i<n;i++)
        arr[i] += arr[i-1];
    
    for(ll i=0;i<n;i++){
        ll nm = m - (n - i - 1);
        if(nm<0)
            continue;
        ll ext = min(nm, k*(i+1));
        ld sum = arr[i] + ext;
        ld val = (ld)sum/(ld)(i+1);
        ans = max(ans, val);
    }
    
    cout<<fixed<<setprecision(10)<<ans<<endl;
    
    return 0;
}