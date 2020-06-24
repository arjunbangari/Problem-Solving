#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll const inf = 1e18;
ll const maxn = 2e6+5;
ll const mod = 1e9+7;
 
// code begins here
 
int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    if(n<=m){
        cout<<n<<endl;
        return 0;
    }
    
    ll x = ceil((sqrtl(1+8*(n-m)) - 1.0)/2.0);
    
    // ll val = x*(x+1)/2;

    // if( val && (n-m)%val)
    //     x++;
    
    cout<<m+x<<endl;
    
    
    return 0;
}