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

    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
            
        ll even=0, odd=0;
        for(ll i=0;i<n;i++){
            if(arr[i]%2!=i%2){
                if(arr[i]%2)
                    odd++;
                else
                    even++;
            }
        }
        
        if(even!=odd){
            cout<<-1<<endl;
        } else {
            cout<<even<<endl;
        }
    }
    
    return 0;
}
