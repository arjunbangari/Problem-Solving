#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

ll const inf = 1e18;
ll const maxn = 1e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    ordered_set s;
    
    ll cnt =  0;
    
    for(ll i=0;i<n;i++){
        auto tmp =  s.order_of_key(arr[i]);
        cnt += (i-tmp);
        s.insert(arr[i]);
    }
    
    cout<< ( (cnt&1)==((3*n)&1) ? "Petr" : "Um_nik" ) <<endl;
    
    return 0;
}