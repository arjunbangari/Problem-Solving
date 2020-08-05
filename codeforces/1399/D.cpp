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
        
        string s;
        cin>>s;
        
        set<ll> st[2];
        for(ll i=0;i<n;i++){
            if(s[i]=='0')
                st[0].insert(i);
            else
                st[1].insert(i);
        }
        
        vector<ll> ans(n);
        ll cnt = 0;
        
        while(!st[0].empty() && !st[1].empty()){
            ll last = -1, cur = 0;
            
            if((*st[1].begin())<(*st[0].begin()))
                cur = 1;
                
            while(1){
                auto it = st[cur].upper_bound(last);
                if(it==st[cur].end())
                    break;
                ans[*it] = cnt;
                last = *it;
                st[cur].erase(it);
                cur = !cur;
            }
            cnt++;
        }
        
        ll cur = 0;
        if(!st[0].empty())
            cur = 0;
        else
            cur = 1;
            
        while(!st[cur].empty()){
            ll val = *st[cur].begin();
            st[cur].erase(st[cur].begin());
            ans[val] = cnt;
            cnt++;
        }
        
        cout<<cnt<<endl;
        for(ll i=0;i<n;i++)
            cout<<ans[i]+1<<" ";
        cout<<endl;
        
    }
    
    return 0;
}