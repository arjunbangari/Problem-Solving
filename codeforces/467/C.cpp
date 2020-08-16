#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,m,k;
    cin>>n>>m>>k;
    
    vector<ll> arr(n+1);
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    
    for(ll i=2;i<=n;i++)
        arr[i] += arr[i-1];
    
    ll dp[n+1][k+1];
    for(ll i=0;i<=n;i++)    
        for(ll j=0;j<=k;j++)
            dp[i][j] = 0;
        
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=k;j++){
            if(j*m>i)
                break;
            
            dp[i][j] = max(dp[i-1][j], dp[i-m][j-1] + arr[i] - arr[i-m]);
        }
    }
    
    // for(ll i=0;i<=n;i++){
    //     for(ll j=0;j<=k;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    
    cout<<dp[n][k]<<endl;
    
    
    return 0;
}