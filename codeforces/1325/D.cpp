#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll u,v;
    cin>>u>>v;
    
    if(u>v || (v-u)%2)
        cout<<-1<<endl;
    else if(u==0 && v==0)
        cout<<0<<endl;
    else if(u==v){
        cout<<1<<endl<<u<<endl;;
    }
    else{
        ll x = (v-u)/2;
        if(x&u){
            cout<<3<<endl;
            cout<<u<<" "<<x<<" "<<x<<endl;
        } else {
            cout<<2<<endl;
            cout<<x<<" "<<u+x<<endl;
        }
    }
    
    return 0;
}