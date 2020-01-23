#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll q,x,y,v,last=0;
    cin>>q>>x;
    unordered_set<ll> us;
    ll cnt[x+1] = {0};
    us.max_load_factor(0.25);us.reserve(512);
    while(q--){
        cin>>y;
        v = y%x;
        cnt[v]++;
        us.insert(v + (cnt[v]-1)*x);
        
        if(us.find(last)==us.end())
            cout<<last<<endl;
        else{
            while(1){
                last++;
                if(us.find(last)==us.end()){
                    cout<<last<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}