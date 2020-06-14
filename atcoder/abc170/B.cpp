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

int main(){
    fast;
    
    ll x,y;
    cin>>x>>y;
    
    if((y-2*x)%2==0){
        ll tmpx = (y-2*x)/2;
        ll tmpy = x - tmpx;
        if(tmpx>=0 && tmpy>=0){
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
        
    } else {
        cout<<"No"<<endl;
    }
    
    return 0;
}
