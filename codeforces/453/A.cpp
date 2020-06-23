#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ld m,n;
    cin>>m>>n;
    
    ld ans = 0;
    
    for(ld i=1;i<=m;i++)
        ans += i*(pow(i/m, n) - pow((i-1.0)/m, n));
    
    cout<<fixed<<setprecision(10)<<ans<<endl;
    
    return 0;
}