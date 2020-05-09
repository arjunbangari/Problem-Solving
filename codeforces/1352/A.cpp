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
        
        vector<ll> arr;
        
        ll k = 1;
        
        while(n>0){
            ll rem = n%10;
            if(rem!=0)
                arr.push_back(rem*k);
            k *= 10;
            n /= 10;
        }
        
        cout<<(ll)arr.size()<<endl;
        for(auto u: arr)
            cout<<u<<" ";
        cout<<endl;
    }
    
    return 0;
}