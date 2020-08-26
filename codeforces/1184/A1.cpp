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

void solve(ll r){
    for(ll i=1;i<=sqrtl(r);i++){
        if( (r-1)%i==0 ){
            ll a = (r-1)/i - i - 1;
            if(a>0 && a%2==0){
                cout<<i<<" "<<a/2<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    fast;
    
    ll r;
    cin>>r;
    
    solve(r);
    
    return 0;
}