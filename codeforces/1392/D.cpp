#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
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
        
        string s, p;
        cin>>s;
        
        set<char> st;
        for(auto u: s)
            st.insert(u);
        
        ll sz = st.size();
        
        if(sz==1){
            cout<<(n+2)/3<<endl;
            continue;
        }
        
        ll ind;
        
        for(ll i=0;i<n;i++){
            if(s[i]=='R'){
                ind = i;
                break;
            }
        }
        
        if(ind==0){
            for(ll i=n-1;i>0;i--){
                if(s[i]=='L'){
                    ind = (i+1)%n;
                    break;
                }
            }
        }
        
        for(ll i=ind;i<n;i++)
            p.push_back(s[i]);
        
        for(ll i=0;i<ind;i++)
            p.push_back(s[i]);
        
        ll ans = 0;
        
        ll i = 0;
        while(i<n){
            ll j = i;
            ll r = 0, l = 0;
            while(j<n && p[j]==p[i])
                j++;
            
            r = j-i;
            ll x = j;
            while(j<n && p[j]==p[x])
                j++;
            
            l = j-x;
            
            ans += r/3 + l/3;
    
            i = j;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}