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
        ll x,y,n;
        cin>>x>>y>>n;
        
        while(1){
            if(n%x>=y){
                n -= (n%x - y);
                break;
            } else {
                n -= (n%x);
                n--;
            }
        }
        cout<<n<<endl;
    }
    
    return 0;
}