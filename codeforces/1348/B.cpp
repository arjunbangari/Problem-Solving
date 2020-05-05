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
        ll n,k,x;
        cin>>n>>k;
        
        set<ll> s;
        for(ll i=0;i<n;i++){
            cin>>x;
            s.insert(x);
        }
        
        ll sz = s.size();
        
        if(sz>k)    
            cout<<-1;
        else{
            ll temp = k - sz;
            cout<<n*k<<endl;
            
            for(ll i=0;i<n;i++){
                for(auto u: s)
                    cout<<u<<" ";
                for(ll j=0;j<temp;j++)
                    cout<<1<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}