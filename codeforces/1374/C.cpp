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
        
        string s;
        cin>>s;
        
        stack<ll> st;
        ll cnt = 0;
        
        for(ll i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
            } else {
                if(st.empty()){
                    cnt++;
                } else {
                    st.pop();
                }
            }
        }
        ll sz = st.size();
        cnt += sz;
        
        cout<<cnt/2<<endl;
    }
    
    return 0;
}