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
        
        vector<ll> cnt(26);
        
        for(ll i=0;i<n;i++){
            string s;
            cin>>s;
            
            for(auto u: s){
                cnt[u-'a']++;
            }
        }
        
        ll flag = 0;
        for(ll i=0;i<26;i++){
            if(cnt[i]%n!=0)
                flag = 1;
        }
        
        cout<<( flag ? "NO" : "YES" ) <<endl;
    }
    
    return 0;
}