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
        ll n,m,x,y;
        cin>>n>>m>>x>>y;
        
        y = min(y, 2*x);
        
        string arr[n];
        
        for(ll i=0;i<n;i++)
            cin>>arr[i];
            
        ll ans =0;
            
        for(ll i=0;i<n;i++){
            ll l=0;

            while(l<m){
                if(arr[i][l]=='*'){
                    l++;
                    continue;
                }    
                
                
                ll r = l+1;
                while(r<m && arr[i][r]=='.')
                    r++;
                
                ll dif = r-l;
                
                ans += (dif/2)*y;
                
                if(dif%2)
                    ans += x;
                
                l = r;
            }
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}