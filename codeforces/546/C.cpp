#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    ll n,k1,k2,temp,flag=0,ans=0;
    cin>>n;
    deque<ll> d1;
    deque<ll> d2;
    
    cin>>k1;
    for(ll i=0;i<k1;i++){
        cin>>temp;
        d1.push_front(temp);
    }
    
    cin>>k2;
    for(ll i=0;i<k2;i++){
        cin>>temp;
        d2.push_front(temp);
    }
    
    unordered_set <string> mp;
    
    while(!d1.empty() && !d2.empty()){
        string s;
        s = ' ';
        deque <ll> :: iterator it;
        for(it = d1.begin(); it != d1.end(); ++it) 
            s += to_string(*it);
        for(it = d2.begin(); it != d2.end(); ++it) 
            s += to_string(*it);
        
        if(mp.find(s)!=mp.end()){
            flag = 1;
            break;
        }
        mp.insert(s);
        
        ll a = d1.back();
        ll b = d2.back();
        d1.pop_back();
        d2.pop_back();
        
        if(a>b){
            d1.push_front(b);
            d1.push_front(a);
        } else {
            d2.push_front(a);
            d2.push_front(b);
        }
        ans++;
    }
    
    if(flag)
        cout<<-1<<"\n";
    else{
        ll win=1;
        if(d1.empty())
            win=2;
        cout<<ans<<" "<<win<<"\n";
    }
    
    return 0;
}
