#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll const inf = 1e18;
ll const maxn = 2e6+5;
ll const mod = 1e9+7;
 
// code begins here
 
int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<vector<ll> > arr(n+2, vector<ll> (n+2, 0));
    vector<vector<ll>> lr(n+2, vector<ll> (n+2, 0));
    vector<vector<ll>> rl(n+2, vector<ll> (n+2, 0));
    
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            cin>>arr[i][j];
    
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            lr[i][j] = arr[i][j] + lr[i-1][j-1];
            rl[i][j] = arr[i][j] + rl[i-1][j+1];
        }
    }
    
    ll mxw = -inf, mxb = -inf, x1, y1, x2, y2;
    
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            ll x = min(n-i, n-j);
            ll y = min(n-i, j-1);
            ll val = lr[i+x][j+x] + rl[i+y][j-y] - arr[i][j];
            // cout<<i<<" "<<j<<" "<<val<<endl;
            
            if((i+j)&1){
                if(val>mxb){
                    x1 = i;
                    y1 = j;
                }
                mxb = max(mxb, val);
            } else {
                if(val>mxw){
                    x2 = i;
                    y2 = j;
                }
                mxw = max(mxw, val);
            }
        }
    }
    
    cout<<mxw+mxb<<endl;
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    
    return 0;
}