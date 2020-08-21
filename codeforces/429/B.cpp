#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    ll arr[n+2][m+2];
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
            cin>>arr[i][j];
    
    ll d1[n+2][m+2], d2[n+2][m+2], d3[n+2][m+2], d4[n+2][m+2];
    for(ll i=0;i<n+2;i++){
        for(ll j=0;j<m+2;j++){
            d1[i][j] = d2[i][j] = d3[i][j] = d4[i][j] = 0;
        }
    }
    
    // d1 : (1, 1) -> (n, m)
    // d2 : (n, m) -> (1, 1)
    // d3 : (n, 1) -> (1, m)
    // d4 : (1, m) -> (n, 1)
    
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
            d1[i][j] = arr[i][j] + max(d1[i-1][j], d1[i][j-1]);
        
    for(ll i=n;i>=1;i--)
        for(ll j=m;j>=1;j--)
            d2[i][j] = arr[i][j] + max(d2[i][j+1], d2[i+1][j]);
            
    for(ll i=n;i>=1;i--)
        for(ll j=1;j<=m;j++)
            d3[i][j] = arr[i][j] + max(d3[i][j-1], d3[i+1][j]);
            
    for(ll i=1;i<=n;i++)
        for(ll j=m;j>=1;j--)
            d4[i][j] = arr[i][j] + max(d4[i][j+1], d4[i-1][j]);
        
    ll ans = 0;
    
    for(ll i=2;i<n;i++){
        for(ll j=2;j<m;j++){
            // l->r , d->u
            ans = max(ans, d1[i][j-1] + d2[i][j+1] + d3[i+1][j] + d4[i-1][j]);
            // u->d , l->r
            ans = max(ans, d1[i-1][j] + d2[i+1][j] + d3[i][j-1] + d4[i][j+1]);
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}