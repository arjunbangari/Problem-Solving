#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll a,b,x,y, n;
        cin>>a>>b>>x>>y>>n;
        
        ll tmp1 = max(a-n, x);
        ll a1 = tmp1;
        ll n1 = n - ( a -  tmp1);
        
        tmp1 = max(b-n1, y);
        ll b1 = tmp1;
        
        ll ans1 = a1*b1;
        
        ll tmp2 = max(b-n, y);
        ll b2 = tmp2;
        ll n2 = n - ( b - tmp2);
        
        tmp2 = max(a - n2, x);
        ll a2 = tmp2;
        
        ll ans2 = b2*a2;
        
        cout<<min(ans1, ans2)<<endl;
    }
    
    return 0;
}