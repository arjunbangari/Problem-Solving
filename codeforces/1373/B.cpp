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
        string s;
        cin>>s;
        
        ll n = s.length(), cnt=0;
        
        while(1){
            ll flag = 0;
            for(ll i=1;i<n;i++){
                if(s[i]!=s[i-1]){
                    s.erase(i-1,2);
                    n-=2;
                    cnt++;
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                break;
        }
        
        cout<< (cnt&1 ? "DA" : "NET")<<endl;
    }
    
    return 0;
}