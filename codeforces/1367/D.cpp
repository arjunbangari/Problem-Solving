#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll q;
    cin>>q;
    
    while(q--){
        string s;
        cin>>s;
        
        ll m, n = s.length();
        cin>>m;
        
        vector<ll> brr(m);
        for(auto &u: brr)
            cin>>u;
        
        char t[m];
        for(ll i=0;i<m;i++)
            t[i] = '#';
        
        map<char, ll> mp;
        
        set<char, greater<char>> st;
        for(ll i=0;i<n;i++){
            mp[s[i]]++;
            st.insert(s[i]);
        }
        
        ll sz = st.size();
        
        vector<ll> arr;
        ll cur = 0;
        
        while(cur<m && !st.empty()){
            
            vector<ll> tmp;
            
            for(ll j=0;j<m;j++){
                if(t[j]=='#'){
                    ll cnt = 0;
                    for(auto it: arr)
                        cnt += abs(it-j);
                    
                    if(cnt==brr[j]){
                        cur++;
                        tmp.push_back(j);
                    }
                }
            }
            
            char u;
            while(1){
                u = *st.begin(); 
                st.erase(st.begin());
                if(mp[u]>=(ll)(tmp.size())) 
                    break;
            }
            
            for(auto x: tmp){
                t[x] = u;
                arr.push_back(x);
            }
            
        }
        
        for(auto u: t)
            cout<<u;
        cout<<endl;
    }
    
    return 0;
}