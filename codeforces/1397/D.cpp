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
            
        if(n==1){
            cout<<"T"<<endl;
            continue;
        }    
        
        multiset<ll, greater<ll>> s;
        for(auto u: arr)
            s.insert(u);
        
        ll a = 0, b = 0, cur = 1;
        ll movea = 0, moveb = 0;
        
        while(!s.empty()){
            ll x = *s.begin();
            
            if(cur==1){
                if(x>a){
                    s.erase(s.begin());
                    if(a!=0)
                        s.insert(a);
                    a = x-1;
                } else {
                    if(a==0)
                        break;
                    a--;
                }
                movea++;
            } else {
                if(x>b){
                    s.erase(s.begin());
                    if(b!=0)
                        s.insert(b);
                    b = x-1;
                } else {
                    if(b==0)
                        break;
                    b--;
                }
                moveb++;
            }
            cur = !cur;
        }
        
        
        cout<<( movea>moveb || a>b ? "T" : "HL" )<<endl;
    }
    
    return 0;
}