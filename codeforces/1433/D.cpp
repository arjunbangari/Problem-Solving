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
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
        
        set<ll> s;
        
        for(auto u: arr)
            s.insert(u);
        
        if(s.size()==1){
            cout<<"NO"<<endl;
            continue;
        }
        
        ll a = arr[0], b;
        for(ll i = 0;i<n;i++){
            if(arr[i]!=a)
                b = i;
        }    
        
        cout<<"YES"<<endl;
        for(ll i= 1;i<n;i++){
            if(arr[i]!=a){
                cout<<1<<" "<<i+1<<endl;
            } else {
                cout<<b+1<<" "<<i+1<<endl;
            }
        }
    
    }
    
    return 0;
}