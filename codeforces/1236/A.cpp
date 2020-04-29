#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
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
        ll a,b,c;
        cin>>a>>b>>c;
        
        ll ans = 0;
        
        while(b>0 && c>1){
            b--;
            c-=2;
            ans += 3;
        }
        while(a>0 && b>1){
            a--;
            b-=2;
            ans += 3;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}