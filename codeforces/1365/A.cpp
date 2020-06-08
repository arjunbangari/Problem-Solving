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

void solve(){
    ll n,m;
    cin>>n>>m;
    
    ll arr[n][m];
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            cin>>arr[i][j];
        
    ll rows = 0, cols = 0;        
        
    for(ll i=0;i<n;i++){
        ll flag = 1;
        for(ll j=0;j<m;j++){
            if(arr[i][j])
                flag = 0;
        }
        if(flag)
            rows++;
    }
    
    for(ll i=0;i<m;i++){
        ll flag = 1;
        for(ll j=0;j<n;j++){
            if(arr[j][i])
                flag = 0;
        }
        if(flag)
            cols++;
    }
    
    ll tmp = min(rows, cols);
    
    cout<< ( tmp%2 ? "Ashish" : "Vivek") <<endl;
    
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        solve();
    }
    
    return 0;
}