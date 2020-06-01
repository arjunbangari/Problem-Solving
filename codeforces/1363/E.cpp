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
struct info{
  ll cost, initial, final, type1, type2; 
  
  void init(){
        type1 = ( !initial && final ? 1 : 0 );
        type2 = ( initial && !final ? 1 : 0 );
  }
};

vector<ll> v[maxn];
vector<info> arr(maxn);

ll ans = 0;

// type1 -> 0, 1     type2 -> 1, 0

void dfs(ll i, ll p=1){
    arr[i].cost = min(arr[i].cost, arr[p].cost);
    arr[i].init();
    
    for(auto u: v[i]){
        if(u==p)
            continue;
        dfs(u, i);
        
        arr[i].type1 += arr[u].type1;
        arr[i].type2 += arr[u].type2;
    }
    
    ll tmp = min(arr[i].type1, arr[i].type2);
    ans += tmp*arr[i].cost;
    arr[i].type1 -= tmp;
    arr[i].type2 -= tmp;
    
}

int main(){
    fast;
    
    ll n,x,y,a = 0,b = 0;
    cin>>n;
    
    for(ll i=1;i<=n;i++)
        cin>>arr[i].cost>>arr[i].initial>>arr[i].final;
    
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for(ll i=1;i<=n;i++){
        a = ( arr[i].initial && !arr[i].final ? a+1 : a );
        b = ( !arr[i].initial && arr[i].final ? b+1 : b );
    }
    
    if(a!=b){
        cout<<-1<<endl;
        return 0;
    }
    
    dfs(1);
    
    cout<<2*ans<<endl;
    
    return 0;
}