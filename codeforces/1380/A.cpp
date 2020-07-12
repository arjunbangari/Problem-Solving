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

void solve(){
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
        for(auto &u: arr)   
            cin>>u;
        
        for(ll i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                cout<<"YES"<<endl;
                cout<<i<<" "<<i+1<<" "<<i+2<<endl;
                return;
            }
        }
    
    cout<<"NO"<<endl;
    return;
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        solve();
    }
    
    return 0;
}