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

#define pi 3.14159265

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        double n;
        cin>>n;
        
        n *= 2.0;
        
        double ans = 1.0/tan(pi/n);
        
        cout<<fixed<<setprecision(7)<<ans<<endl;
    }
    
    return 0;
}