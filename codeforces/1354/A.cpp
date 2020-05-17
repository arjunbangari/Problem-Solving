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
        ll a,b,c,d;
        
        cin>>a>>b>>c>>d;
        
        ll ans = 0;
        
        if(b>=a){
            ans = b;
        } else {
            ll dif = a-b;
            if((c-d)<=0){
                ans = -1;
            } else {
                ans = b + ceil(((float)(a-b)/(float)(c-d)))*c;
            }
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}