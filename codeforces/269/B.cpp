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
    
    ll n,m,s;
    ld x;
    cin>>n>>m;
    
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>s>>x;
        arr[i] = s;
    }
    
    vector<ll> dp(n, 1);
    
    for(ll i=1;i<n;i++){
        for(ll j=0;j<i;j++){
            if(arr[j]<=arr[i])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
    }
    
    ll mx = *max_element(all(dp));
    
    cout<<n-mx<<endl;
    
    return 0;
}