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
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        ll cnt3 = 0, cnt2 = 0;
        
        while(n%3==0){
            n /= 3;
            cnt3++;
        }
        
        while(n%2==0){
            n /= 2;
            cnt2++;
        }
        
        if(n==1 && cnt2<=cnt3){
            cout<<cnt3 + (cnt3-cnt2)<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
    
    return 0;
}