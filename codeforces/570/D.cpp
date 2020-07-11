#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 5e5+5;
ll const mod = 1e9+7;

// code begins here

int n,m;
vector<int> v[maxn], sz(maxn), depth(maxn), tmp[maxn];
vector<pll> queries;
string s;
vector<int> *vec[maxn];
int cnt[maxn][26] = {0};

void dfs1(int i, int d = 1){
    sz[i] = 1;
    depth[i] = d;
    for(auto u: v[i]){
        dfs1(u, d+1);
        sz[i] += sz[u];
    }
}

void dfs2(int i, int keep){
    int mx = -1, bigchild = -1;
    for(auto u: v[i]){
        if(sz[u]>mx){
            mx = sz[u];
            bigchild = u;
        }
    }
    
    for(auto u: v[i]){
        if(u!=bigchild)
            dfs2(u, 0);
    }
    
    if(bigchild!=-1){
        dfs2(bigchild, 1);
        vec[i] = vec[bigchild];
    } else 
        vec[i] = new vector<int> ();
    
    vec[i]->push_back(i);
    cnt[depth[i]][s[i-1]-'a']++;
    
    for(auto u: v[i]){
        if(u!=bigchild){
            for(auto x: *vec[u]){
                cnt[depth[x]][s[x-1]-'a']++;
                vec[i]->push_back(x);
            }
        }
    }
    
    for(auto u: tmp[i]){
        int flag = 0, d = queries[u].second;
        
        for(ll i=0;i<26;i++){
            if(cnt[d][i]&1)
                flag++;
        }
        queries[u] = ( flag>1 ? make_pair(0,0) : make_pair(1,1) ) ;
    }
    
    if(keep==0)
        for(auto u: *vec[i])
            cnt[depth[u]][s[u-1]-'a']++;
}

int main(){
    fast;
    
    cin>>n>>m;
    
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        v[p].push_back(i);
    }
    
    cin>>s;
        
    for(int i=0;i<m;i++){
        int ver, dep;
        cin>>ver>>dep;
        queries.push_back({ver, dep});
        tmp[ver].push_back(i);
    }
    
    dfs1(1);
    dfs2(1, 0);
    
    for(ll i=0;i<m;i++)
        cout<<(queries[i].first ? "Yes" : "No")<<endl;
    
    return 0;
}