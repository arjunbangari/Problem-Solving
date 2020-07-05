#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
// #define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;

    ll t;
    cin>>t;
    
    while(t--){
        ll n, m;
        cin>>n>>m;
        
        ll arr[n][m];
        for(ll i=0;i<n;i++)
            for(ll j=0;j<m;j++)
                cin>>arr[i][j];
        
        ll ans[n][m];
        ans[0][0] = 2;
        ans[0][m-1] = 2;
        ans[n-1][0] = 2;
        ans[n-1][m-1] = 2;
        
        for(ll i=1;i<m-1;i++){
            ans[0][i] = 3;
            ans[n-1][i] = 3;
        }
        for(ll i=1;i<n-1;i++){
            ans[i][0] = 3;
            ans[i][m-1] = 3;
        }
        
        for(ll i=1;i<n-1;i++)
            for(ll j=1;j<m-1;j++)
                ans[i][j] = 4;
        
        ll flag = 0;
        for(ll i=0;i<n;i++)
            for(ll j=0;j<m;j++)
                if(arr[i][j]>ans[i][j])
                    flag = 1;
        
        if(flag){
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
            for(ll i=0;i<n;i++){
                for(ll j=0;j<m;j++)
                    cout<<ans[i][j]<<" ";
                cout<<endl;
            }
        }
    }

    return 0;
}
