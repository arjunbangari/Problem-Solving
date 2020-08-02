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
    
    string s;
    cin>>s;
    
    ll n = s.length();
    
    set<ll> st[2];
    for(ll i=0;i<n;i++){
        if(s[i]=='0')
            st[0].insert(i);
        else
            st[1].insert(i);
    }
    
    ll cnt = 0;
    
    vector<ll> ans[maxn];
    
    while(!st[0].empty()){
        ll last = -1, cur = 0;
        while(1){
            auto it = st[cur].upper_bound(last);
            if(it==st[cur].end())
                break;
            ans[cnt].push_back(*it);
            last = *it;
            st[cur].erase(it);
            cur = !cur;
        }
        cnt++;
    }
    
    if(!st[1].empty()){
        cout<<-1<<endl;
        return 0;
    }
    
    for(ll i=0;i<cnt;i++){
        ll x = ans[i].size();
        if(!ans[i].empty()){
            if(s[ans[i][x-1]]=='1'){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    
    cout<<cnt<<endl;
    for(ll i=0;i<cnt;i++){
        ll x = ans[i].size();
        cout<<x<<" ";
        for(auto u: ans[i])
            cout<<u+1<<" ";
        cout<<endl;
    }
    
    return 0;
}