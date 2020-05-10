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
        ll a,b,c;
        cin>>c>>b>>a;
        
        deque<ll> dq;
        
        if(b>0){
            dq.push_back(1);
            dq.push_back(0);
            
            for(ll i=0;i<(b-1)/2;i++){
                dq.push_back(1);
                dq.push_back(0);
            }
        }
        
        if(a>0){
            if(b>0){
                for(ll i=0;i<a;i++)
                    dq.push_front(1);
            } else {
                for(ll i=0;i<=a;i++)
                    dq.push_front(1);
            }
        }
        
        if(b%2==0 && b>0)
            dq.push_front(0);
        
        if(c>0){
            if(b>0){
                for(ll i=0;i<c;i++)
                    dq.push_back(0);
            } else {
                for(ll i=0;i<=c;i++)
                    dq.push_back(0);
            }
        }
        
        for(auto u: dq)
            cout<<u;
        cout<<endl;
    
    }
    
    return 0;
}