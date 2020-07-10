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

set<int> unvisited;
vector<pair<int, int>> v;
int cur = 0;

pair<int, int> fx(int x, int y){
    return make_pair(min(x,y), max(x,y));
}

void dfs(int i){
    for(auto it=unvisited.begin();it!=unvisited.end();){
        if(!binary_search(v.begin(), v.end(), fx(i, *it))){
            int val = *it;
            unvisited.erase(it);
            dfs(val);
            it = unvisited.upper_bound(val);
        } else
            it++;
    }
}

int main(){
    fast;
    
    int n, m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v.push_back(fx(x,y));
    }
    
    sort(v.begin(), v.end());
    
    for(int i=1;i<=n;i++)
        unvisited.insert(i);
    
    while(!unvisited.empty()){
        int v = *unvisited.begin();
        unvisited.erase(unvisited.begin());
        dfs(v);
        cur++;
    }
    
    cout<<cur-1<<endl;
        
    return 0;
}