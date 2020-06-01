#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e3;
ll const mod = 1e18+7;

// code begins here

string s, t;
ll n;
vector<ll> pre(maxn);

void preprocess(){
    pre[0] = 1;
    for(ll i=1;i<maxn;i++)
        pre[i] = (pre[i-1]*53)%mod;
}

int main(){
    fast;
    
    cin>>s>>t;
    n = s.length();

    preprocess();
    
    set<ll> st;
    ll k;
    cin>>k;
    
    for(ll i=0;i<n;i++){
        ll bad = 0, hash=0;
        for(ll j=i;j<n;j++){
            if(t[s[j]-'a']=='0')
                bad++;
            if(bad>k)
                break;
            hash += ((s[j]-'a'+1)*pre[j-i])%mod;
            hash %= mod;
            st.insert(hash);
        }
    }
    
    ll sz = st.size();
    
    cout<<sz<<endl;
    
    return 0;
}