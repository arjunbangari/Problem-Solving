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
int const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(auto &u: arr)
        cin>>u;
        
    set<int> s;
    vector<int> v[maxn];
    
    for(ll i=0;i<n;i++){
        v[arr[i]].push_back(i);
        s.insert(arr[i]);
    }
    
    int ans = 1;
    
    for(auto i: s){
        for(auto j: s){
            int cnt = 1, ind = v[i][0];
            
            while(1){
                auto it = upper_bound(all(v[j]), ind);
                if(it==v[j].end())
                    break;
                cnt++;
                ind = *it;
                
                it = upper_bound(all(v[i]), ind);
                if(it==v[i].end())
                    break;
                cnt++;
                ind = *it;
            }
            
            ans = max(ans, cnt);
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}