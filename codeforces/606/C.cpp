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
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n), brr(n+1);
    for(auto &u: arr)
        cin>>u;
    
    for(ll i=0;i<n;i++)
        brr[arr[i]] = i;
    
    ll i = 1, ans = 0;
    while(i<=n){
        ll j = i+1;
        while(j<=n && brr[j]>brr[j-1])
            j++;
        
        ans = max(ans, j-i);
        i = j;
    }
    
    cout<<n-ans<<endl;
    
    return 0;
}