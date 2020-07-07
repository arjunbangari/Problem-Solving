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

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    vector<ll> arr[n], sz(n);
    for(ll i=0;i<n;i++){
        ll k,x;
        cin>>k;
        sz[i] = k;
        for(ll j=0;j<k;j++){
            cin>>x;
            arr[i].push_back(x);
        }
    }
    
    vector<vector<ll> > dp( n , vector<ll> (105, 0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<=sz[i];j++){
            for(ll k=0;k<=j;k++){
                ll sum = 0;
                for(ll l=0;l<k;l++)
                    sum += arr[i][l];
                for(ll l=sz[i]-j+k;l<sz[i];l++)
                    sum += arr[i][l];
                dp[i][j] = max(dp[i][j], sum);
            }
        }
    }
    
    vector<vector<ll> > dp2( n , vector<ll> (10005, 0));
    for(ll i=0;i<=sz[0];i++)
        dp2[0][i] = dp[0][i];
    ll sum = sz[0];
    
    for(ll i=1;i<n;i++){
        sum += sz[i];
        for(ll j=0;j<=m;j++){
            if(j>sum)
                break;
            for(ll k=0;k<=min(sz[i],j);k++)
                dp2[i][j] = max(dp2[i][j], dp[i][k] + dp2[i-1][j-k]);
        }
    }
    
    cout<<dp2[n-1][m]<<endl;
    
    return 0;
}