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

vector<ll> arr;
ll dp[maxn][2];

void recur( ll k, ll cur ){
    if(dp[k][cur]!=-1)
        return;
    
    if(k==0){
        dp[k][cur] = !cur;
        return;
    }
    
    ll ans = 0;
    for(auto u: arr){
        if( k >= u ){
            recur(k-u, !cur);
        }
    }
    
    dp[k][cur] = !cur;
    
    for(auto u: arr){
        if( k>=u && dp[k-u][!cur]==cur){
            dp[k][cur] = cur;
        }
    }
}

int main(){
    fast;
    
    ll n,k;
    cin>>n>>k;
    
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        arr.push_back(x);
    }
    
    for(ll i=0;i<maxn;i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    
    recur(k, 1);
    
    cout<< ( dp[k][1] ? "First" : "Second" ) <<endl;
    
    return 0;
}