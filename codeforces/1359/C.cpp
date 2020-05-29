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
    
    ll tst;
    cin>>tst;
    
    while(tst--){
        ld h,c,t;
        cin>>h>>c>>t;
        
        if((ll)h==(ll)t){
            cout<<1<<endl;
            continue;
        }
        
        ld tmp = h + c - 2*t;
        
        if((ll)tmp>=0){
            cout<<2<<endl;
            continue;
        }
        
        ld x = (c-t)/tmp;
        
        ld x1 = ceil(x), x2 = floor(x);
        
        ll ans;
        ld mn = inf;
        
        ld err1 = abs(t - (x1*(h+c) - c)/(2.0*x1 - 1));
        ld err2 = abs(t - (x2*(h+c) - c)/(2.0*x2 - 1));
        
        if(err1<err2){
            ans = 2*((ll)x1) - 1;
            mn = err1;
        } else {
            ans = 2*((ll)x2) - 1;
            mn = err2;
        }
        
        
        ld err = abs(t - (h+c)/2.0);
        
        if(err<mn)
            ans = 2;
        
        cout<<ans<<endl;
        
    }
    
    return 0;
}