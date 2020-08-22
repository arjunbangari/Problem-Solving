#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    string s;
    cin>>s;
    
    ll w = 0, b = 0;
    for(auto u: s){
        if(u=='W')
            w++;
        else
            b++;
    }
    
    if( w&1 && b&1 ){
        cout<<-1<<endl;
        return 0;
    }
    
    if(w==0 || b==0){
        cout<<0<<endl;
        return 0;
    }
    
    ll k=0;
    vector<ll> pos;
    
    char c;
    if(w%2==0)
        c = 'W';
    else
        c = 'B';
    
    
    while(1){
        for(ll i=0;i<n-1;i++){
            if(s[i]==c){
                s[i] = ( s[i]=='W' ? 'B' : 'W' );
                s[i+1] = ( s[i+1]=='W' ? 'B' : 'W');
                k++;
                pos.push_back(i);
            }
        }
        
        w =0, b = 0;
        for(auto u: s){
            if(u=='W')
                w++;
            else    
                b++;
        }
        
        if(w==0 || b==0)
            break;
    }
    
    
    cout<<k<<endl;
    for(auto u: pos)
        cout<<u+1<<" ";
    
    return 0;
}