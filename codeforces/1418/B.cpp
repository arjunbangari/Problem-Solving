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
        ll n;
        cin>>n;
        
        vector<ll> arr(n), locked(n);
        for(auto &u: arr)
            cin>>u;
        for(auto &u: locked)
            cin>>u;
        
        vector<ll> brr;
        for(ll i=0;i<n;i++){
            if(!locked[i])
                brr.push_back(arr[i]);
        }
        
        sort(rall(brr));
        
        ll j = 0;
        for(ll i=0;i<n;i++){
            if(!locked[i]){
                arr[i] = brr[j];
                j++;
            }
        }
        
        for(auto u: arr)
            cout<<u<<" ";
        cout<<endl;
    }
    
    return 0;
}