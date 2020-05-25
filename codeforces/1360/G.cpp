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
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,m,a,b;
        cin>>n>>m>>a>>b;
        
        if(a*n!=b*m){
            cout<<"NO"<<endl;
            continue;
        }
        
        ll ans[n][m];
        for(ll i=0;i<n;i++)
            for(ll j=0;j<m;j++)
                ans[i][j] = 0;
        
        ll last = 0;
        for(ll i=0;i<n;i++){
            for(ll j=last, k=0;k<a;j++, k++){
                ans[i][j%m] = 1;
                last = j%m;
            }
            last++;
        }
        
        cout<<"YES"<<endl;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++)
                cout<<ans[i][j];
            cout<<endl;
        }
        
    }
    
    return 0;
}