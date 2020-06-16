#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;

    ll n,m;
    cin>>n>>m;
    
    vector<ll> arr(n);
    for(auto &u: arr)  
        cin>>u;
    
    vector<ll> brr(n), crr(n);
    for(ll i=0;i<n;i++){
        if(i==0){
            brr[i] = crr[i] = 0;
            continue;
        }
        brr[i] = ( arr[i]>=arr[i-1] ? brr[i-1] : i );
        crr[i] = ( arr[i]<=arr[i-1] ? crr[i-1] : i );
    }
    
    while(m--){
        ll l, r;
        cin>>l>>r;
        l--; r--;
        
        ll tmp = crr[r];
        tmp = brr[tmp];
        
        cout<< (tmp<=l ? "Yes" : "No") <<endl;
    }
    
    return 0;
}
