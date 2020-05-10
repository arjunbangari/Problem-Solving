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
        ll n,k;
        cin>>n>>k;
        
        ll x = n - k + 1;
        ll y = n - 2*(k-1);
        
        if(x>0 && x%2){
            cout<<"YES"<<endl;
            for(ll i=1;i<k;i++)
                cout<<1<<" ";
            cout<<x<<endl;
        }
        else if(y>0 && y%2==0){
            cout<<"YES"<<endl;
            for(ll i=1;i<k;i++)
                cout<<2<<" ";
            cout<<y<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}