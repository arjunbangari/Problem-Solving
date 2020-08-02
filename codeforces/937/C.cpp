#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ld k,d,t;
    cin>>k>>d>>t;
    
    ld g = ( d<=k ? ceil(k/d)*d : d );
    ld dif = (g-k)/2.0;
    ld x = floor(t/(dif+k));
    ld ans = g*x;
    ld rem = t - x*(dif+k);
    if(rem<=k)
        ans += rem;
    else
        ans += k + (rem-k)*2;
    
    cout<<fixed<<setprecision(10)<<ans<<endl;    
    return 0;
}