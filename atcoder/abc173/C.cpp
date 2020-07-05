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
vector<string> tmp;

void gen(int n, int arr[], int i) { 
    if (i == n) { 
        string s;
        for(ll i=0;i<n;i++)
            s.push_back('0'+arr[i]);
        tmp.push_back(s);
        return; 
    } 
 
    arr[i] = 0; 
    gen(n, arr, i + 1); 
  
    arr[i] = 1; 
    gen(n, arr, i + 1); 
} 

int main(){
    fast;

    ll h,w,k;
    cin>>h>>w>>k;
    
    int arr[h];
    gen(h, arr, 0);
    
    vector<string> crr(tmp);
    tmp.clear();
    
    int brr[w];
    gen(w, brr, 0);
    
    vector<string> drr(tmp);
    
    ll black = 0;
    
    vector<string> in(h);
    for(ll i=0;i<h;i++)
        cin>>in[i];
    
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            if(in[i][j]=='#')
                black++;
        }
    }
    
    ll cnt = 0;
    
    ll vis[h][w];
    
    for(auto u: crr){
        for(auto v: drr){
            
            for(ll i=0;i<h;i++)
                for(ll j=0;j<w;j++)
                    vis[i][j] = 0;
                    
            ll res = 0;        
                    
            for(ll i=0;i<h;i++){
                if(u[i]=='1'){
                    for(ll j=0;j<w;j++){
                        if(in[i][j]=='#'){
                            vis[i][j] = 1;
                            res++;
                        }
                    }
                }
            }
            
            for(ll i=0;i<w;i++){
                if(v[i]=='1'){
                    for(ll j=0;j<h;j++){
                        if(!vis[j][i] && in[j][i]=='#'){
                            res++;
                            vis[j][i] = 1;
                        }
                    }
                }
            }
            
            if((black-res)==k)
                cnt++;
        }
    }
    
    cout<<cnt<<endl;
    

    return 0;
}
