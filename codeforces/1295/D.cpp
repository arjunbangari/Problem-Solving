#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll a,m;
        cin>>a>>m;
        ll g = __gcd(a,m);
        ll md = m/g;
        cout<<phi(md)<<endl;
    }
    
    return 0;
}