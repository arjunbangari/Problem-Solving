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

void call_dfs(){
    while(!unvisited.empty()){
        int v = *unvisited.begin();
        unvisited.erase(unvisited.begin());
        dfs(v);
        cur++;
    }
}

int main(){
    fast;
    
    int n, m, k, deg = 0;
    cin>>n>>m>>k;
    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(x==1 || y==1)
            deg++;
        v.push_back(fx(x,y));
    }
    
    sort(v.begin(), v.end());
    
    for(int i=1;i<=n;i++)
        unvisited.insert(i);
    call_dfs();
    
    if(cur!=1){
        cout<<"impossible"<<endl;
        return 0;
    }
    
    cur = 0;
    for(int i=2;i<=n;i++)
        unvisited.insert(i);
    call_dfs();

    if(cur<=k && (n-1-deg)>=k){
        cout<<"possible"<<endl;
    } else
        cout<<"impossible"<<endl;
        
    return 0;
}