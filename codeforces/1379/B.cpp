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
        ll l,r,m;
        cin>>l>>r>>m;
        
        ll a=0,b=0,c=0;
        
        for(ll i=l;i<=r;i++){
            if(i<=m){
                ll x = m%i;
                if((l+x)<=r){
                    a = i;
                    b = l+x;
                    c = l;
                    break;
                }
                
                ll p = (m+i-1)/i;
                ll y = p*i - m;
                
                if((l+y)<=r){
                    a = i;
                    b = l;
                    c = l+y;
                    break;
                }
            }
            if(i>m){
                ll x = i - m;
                if((l+x)<=r){
                    a = i;
                    b = l;
                    c = l+x;
                    break;
                }
            }
        }
        
        cout<<a<<" "<<b<<" "<<c<<endl;
        
    }
    
    return 0;
}