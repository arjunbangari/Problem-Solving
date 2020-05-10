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
        ll n,k;
        cin>>n>>k;
        
        ll rem = k%(n-1);
        ll di = k/(n-1);
        
        ll ans = di*n + rem - (rem==0);
        
        cout<<ans<<endl;
    }
    
    return 0;
}