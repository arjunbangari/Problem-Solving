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
        ll a,b;
        cin>>a>>b;
        
        ll cnt1 = 0, cnt2 = 0;
        
        while(a%2==0){
            cnt1++;
            a /= 2;
        }
        
        while(b%2==0){
            cnt2++;
            b /= 2;
        }
        
        if(a!=b){
            cout<<-1<<endl;
            continue;
        }
        
        ll dif = abs(cnt1-cnt2);
        
        ll ans = dif/3;
        dif = dif%3;
        
        ans += dif/2 + dif%2;
        
        
        cout<<ans<<endl;
    }
    
    return 0;
}