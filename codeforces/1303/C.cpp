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
ll cycle = 0;
vector<ll> vis(26, 0);
map<char, set<char>> mp;
string alpha("abcdefghijklmnopqrstuvwxyz");

void dfs(char i, char p='_'){
    vis[i-'a'] = 1;
    for(auto u: mp[i]){
        if(u==p)
            continue;
        if(vis[u-'a'])
            cycle = 1;
        dfs(u, i);
    }
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        
        cycle = 0;
        mp.clear();
        for(ll i=0;i<26;i++)
            vis[i] = 0;
        
        ll n = s.length();
        
        if(n==1){
            cout<<"YES"<<endl;
            cout<<alpha<<endl;
            continue;
        }
        
        for(ll i=0;i<n;i++){
            if((i+1)<n)
                mp[s[i]].insert(s[i+1]);
            if((i-1)>=0)
                mp[s[i]].insert(s[i-1]);
        }
        
        ll flag = 0;
        char start='_';
        
        for(auto u: mp){
            ll sz = u.second.size();
            if(sz>2)
                flag = 1;
            if(sz==1)
                start = u.first;
        }
        
        if(flag || start=='_'){
            cout<<"NO"<<endl;
            continue;
        }
        
        dfs(start);
        
        if(cycle){
            cout<<"NO"<<endl;
            continue;
        }
        
        cout<<"YES"<<endl;
        
        map<char, ll> search;
        stack<char> st;
        st.push(start);
        char parent = '_';
        
        while(1){
            char val = st.top();
            cout<<val;
            search[val] = 1;
            ll end = 1;
            
            for(auto u: mp[val]){
                if(u!=parent){
                    st.push(u);
                    end = 0;
                }
            }
            
            parent = val;
            if(end)
                break;
        }
            
        for(char u='a';u<='z';u++){
            if(!search[u]){
                cout<<u;
            }
                
        }
        
        cout<<endl;
        
    }
    
    return 0;
}