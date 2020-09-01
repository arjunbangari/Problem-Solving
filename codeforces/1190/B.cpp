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
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

map<ll, ll> mp;

bool check1(){
    return mp[0]>1;
}

bool check2(){
    for(auto u: mp)
        if(u.second>2)
            return true;
    return false;
}

bool check3(){
    for(auto u: mp){
        if(u.second>1 && mp[u.first-1]>0)
            return true;
    }
    return false;
}

bool check4(){
    ll cnt = 0;
    for(auto u: mp)
        if(u.second>1)
            cnt++;
    return cnt>1;
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    ll sum = 0;
    multiset<ll> ms;
    for(auto u: arr)
        ms.insert(u);
    
    for(ll i=0;i<n;i++){
        auto x = ms.lower_bound(i);
        if(x==ms.end())
            break;
        sum += ((*x)-i);
        ms.erase(x);
    }
    
    for(auto u: arr)
        mp[u]++;
    
    if(check1() || check2() || check3() || check4()){
        cout<<"cslnb"<<endl;
    } else {
        cout<< ( sum&1 ? "sjfnb" : "cslnb" ) <<endl;
    }
    
    return 0;
}