#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef tuple<ll, ll, ll> tpl;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    string s;
    cin>>s;
    
    s = "#" + s;
    
    ll m;
    cin>>m;
    
    map< tpl, ll> vis, level;
    map< tpl, tpl> parent;
    
    queue<tpl> q;
    
    for(ll i=1;i<=10;i++){
        if(s[i]=='1'){
            tpl tmp(i, 0LL, i);
            q.push(tmp);
            vis[tmp] = 1;
            level[tmp] = 1;
            parent[tmp] = make_tuple(0LL, 0LL, 0LL);
        }
    }
    
    tpl ans;
    ll flag = 1;
    
    while(!q.empty()){
        tpl val = q.front();
        q.pop();
        
        if(level[val]==m){
            ans = val;
            flag = 0;
            break;
        }
        
        if( get<0>(val) > get<1>(val) ){
            for(ll i=1;i<=10;i++){
                if(s[i]=='1'){
                    tpl tmp( get<0>(val), get<1>(val)+i, i );
  
                    if(vis[tmp] || (get<1>(val)+i)<=get<0>(val) || i==get<2>(val))
                        continue;
                    q.push(tmp);
                    vis[tmp] = 1;
                    level[tmp] = level[val]+1;
                    parent[tmp] = val;
                }
            }
        } else {
            for(ll i=1;i<=10;i++){
                if(s[i]=='1'){
                    tpl tmp( get<0>(val)+i, get<1>(val), i );
  
                    if(vis[tmp] || (get<0>(val)+i)<=get<1>(val) || i==get<2>(val))
                        continue;
                    q.push(tmp);
                    vis[tmp] = 1;
                    level[tmp] = level[val]+1;
                    parent[tmp] = val;
                }
            }
        }
    }
    
    if(flag){
        cout<<"NO"<<endl;
        return 0;
    }
    
    vector<ll> arr;
    
    while(ans!=make_tuple(0LL, 0LL, 0LL)){
        tpl p = parent[ans];
        ll x = abs( get<0>(p) - get<0>(ans) + get<1>(p) - get<1>(ans) );
        arr.push_back(x);
        ans = p;
    }
    
    reverse(all(arr));
    
    cout<<"YES"<<endl;
    for(auto u: arr)
        cout<<u<<" ";
    cout<<endl;
    
    return 0;
}