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
    
    vector<ll> cnt(n+1);
    
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j+=i){
            cnt[j]++;
        }
    }
    
    ll ans = 0;
    
    for(ll i=1;i<=n;i++)
        ans += i*(cnt[i]);
    
    cout<<ans<<endl;
        
    
    return 0;
}