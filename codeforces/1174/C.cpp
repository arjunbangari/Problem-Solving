#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ll cur = 1;
    vector<ll> ans(n+1), prime(n+1, 1);
    
    for(ll i=2;i<=n;i++){
        if(prime[i]){
            for(ll j=i;j<=n;j+=i){
                prime[j] = 0;
                ans[j] = cur;
            }
            cur++;
        }
    }
    
    for(ll i=2;i<=n;i++)
        cout<<ans[i]<<" ";
    
    return 0;
}