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
        
        if(n>=4){
        
            deque<ll> dq;
            dq.push_back(1);
            dq.push_back(4);
            dq.push_back(2);
            
            for(ll i=3;i<=n;i+=2)
                dq.push_front(i);
            
            for(ll i=6;i<=n;i+=2)
                dq.push_back(i);
            
            for(auto u: dq)
                cout<<u<<" ";
            cout<<endl;
            
        } else {
            cout<<-1<<endl;
        }
        
        
    }
    
    return 0;
}