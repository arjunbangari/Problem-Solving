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
    
    ll n,m,k;
    cin>>n>>m>>k;
    
    vector<ll> arr(n), brr(m);
    for(auto &u: arr)
        cin>>u;
    for(auto &u: brr)
        cin>>u;
    
    for(ll i=1;i<n;i++)
        arr[i]+=arr[i-1];
    for(ll j=1;j<m;j++)
        brr[j] += brr[j-1];
    
    ll ans =0;
    
    for(ll i=0;i<n;i++){
        if(arr[i]>k)
            break;
        
        ll ans1 = i+1;
        auto it = upper_bound(brr.begin(), brr.end(), k - arr[i]) - brr.begin();
        ans1 += it;
        ans = max(ans, ans1);
    }
    
    for(ll i=0;i<m;i++){
        if(brr[i]>k)
            break;
        ans = max(ans, i+1);
    }
    
    cout<<ans<<endl;
    
    return 0;
}