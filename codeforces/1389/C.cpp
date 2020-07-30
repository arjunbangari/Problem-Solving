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
        string s;
        cin>>s;
        
        ll n = s.length();
        
        map<char, vector<ll>> mp;
        for(ll i=0;i<n;i++)
            mp[s[i]].push_back(i);
        
        ll mx = 0;
        
        for(char i='0';i<='9';i++){
            for(char j='0';j<='9';j++){
                if(i==j){
                    ll sz = mp[i].size();
                    mx = max(mx, sz);
                    continue;
                }
                
                ll cnt = 0, last = -1, cur = i;
                if(!mp[j].empty() && !mp[i].empty() && mp[j][0]<mp[i][0])
                    cur = j;
                
                while(1){
                    auto it = upper_bound(mp[cur].begin(), mp[cur].end(), last);
                    if(it==mp[cur].end())
                        break;
                    
                    cnt++;
                    last = *it;
                    
                    if(cur==i)
                        cur = j;
                    else
                        cur = i;
                }
                
                if(cnt&1)
                    cnt--;
                
                mx = max(mx, cnt);
            }
        }
        
        cout<<n-mx<<endl;
    }
    
    return 0;
}