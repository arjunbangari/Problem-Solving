#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e7+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;

    ll t;
    cin>>t;
    
    while(t--){
        ll n,m;
        cin>>n>>m;
        
        ll arr[n+2][m+2];
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=m;j++)
                cin>>arr[i][j];
            
        ll dist[n+2][m+2];
        
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                dist[i][j] = i+j-1;
                // cout<<dist[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        ll ans = 0;
        
        for(ll i=1;i<=(n+m-1);i++){
            if(i>=(n+m-i))
                break;
            ll one = 0, zero = 0;
            for(ll j=1;j<=n;j++){
                for(ll k=1;k<=m;k++){
                    if(dist[j][k]==i || dist[j][k]==(n+m-i)){
                        if(arr[j][k]==1)
                            one++;
                        else
                            zero++;
                    }
                }
            }
            
            ans += min(one, zero);
        }
        
        cout<<ans<<endl;
        
    }

    return 0;
}
