#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
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
        ll n;
        cin>>n;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
        
        ll i=0, j=n-1, alice_total=0, bob_total=0, moves=0, prev=0, cur=1;
        
        while(i<=j){
            moves++;
            ll sweets = 0;
            if(cur){
                while(i<=j && prev>=0){
                    sweets += arr[i];
                    prev -= arr[i];
                    i++;
                }
                
                alice_total += sweets;
            } else {
                while(j>=i && prev>=0){
                    sweets += arr[j];
                    prev -= arr[j];
                    j--;
                }
                
                bob_total += sweets;
            }
            
            prev = sweets;
            cur = !cur;
        }
        
        cout<<moves<<" "<<alice_total<<" "<<bob_total<<endl;
        
    }
    
    return 0;
}