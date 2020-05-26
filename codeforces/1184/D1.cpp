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
ll n,q;


int main(){
    fast;

    ll n,k,m,t;
    cin>>n>>k>>m>>t;
    
    ll r = n;
    
    while(t--){
        ll type, pos;
        cin>>type>>pos;
        
        if(type){
            if(pos<=k)
                k++;
            r++;
        } else {
            if(pos>=k)
                r = pos;
            else{
                k -= pos;
                r -= pos;
            }
        }

        cout<<r<<" "<<k<<endl;
    }
    
    return 0;
}