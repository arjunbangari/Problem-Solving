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
    
    ll n;
    cin>>n;
    
    vector<ld> p(n+1);
    for(ll i=1;i<=n;i++)
        cin>>p[i];
    
    ld dp[n+1][n+1] = {0};
    
    dp[1][0] = (1-p[1]);
    dp[1][1] = p[1];
    
    for(ll i=2;i<=n;i++){
        for(ll j=0;j<=n;j++){
            if(j>i)
                break;
            
            if(j!=0)
                dp[i][j] = dp[i-1][j-1] * p[i];
            dp[i][j] += dp[i-1][j] * ( 1-p[i] );
        }
    }
    
    
    
    ld ans = 0;
    for(ll i=0;i<=n;i++)
        if( i>(n-i) )
            ans += dp[n][i];
    
    cout<<fixed<<setprecision(10)<<ans<<endl;
    
    return 0;
}