#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ld const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    ld tmp = inf;
    ll ans = 1;
    
    for(ll i=0;i<n;i++){
        if(arr[i]==0){
            cout<<0<<endl;
            return 0;
        }
        
        ans *= arr[i];
        tmp /= ((ld)arr[i]);
    }
    
    cout<< (tmp>=1.0 ? ans : -1)<<endl;
    
    return 0;
}