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
        ll n,a,b;
        ll x = 0, y = 0;
        cin>>n>>a>>b;
        
        // a -> pipeline
        // b -> pillar
        
        string s;
        cin>>s;
        
        ll one = 0;
        for(auto u: s)
            if(u=='1')
                one++;
            
        if(one==0){
            cout<<n*a + (n+1)*b<<endl;
            continue;
        }
            

        ll i = 0;
        while(i<n && s[i]=='0')
            i++;
        
        x += i+1;
        y += i;
        
        while(i<n){
            ll j = i;
            while(j<n && s[j]==s[i])
                j++;
            
            ll ln = j-i;
            
            if(j==n){
                x += ln+1;
                y += ln;
            } else {
                if(s[i]=='1'){
                    x += ln;
                    y += 2*(ln+1);
                } else {
                    ll cost1 = (ln+2)*a + (ln-1)*b;
                    ll cost2 = ln*a + 2*(ln-1)*b;
                    if(cost1<cost2){
                        x += ln+2;
                        y += ln-1;
                    } else {
                        x += ln;
                        y += 2*(ln-1);
                    }
                }
            }
            i = j;
        }
        
        ll ans = x*a + y*b;
        cout<<ans<<endl;
    }
    
    return 0;
}