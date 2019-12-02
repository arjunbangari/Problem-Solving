#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    unordered_set <ll> p;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        p.insert(arr[i]);
    }
    
    ll first;
    for(ll i=0;i<n;i++){
        if(arr[i]%2==0){
            if(p.find(arr[i]*3)==p.end() && p.find(arr[i]/2)==p.end()){
                first = arr[i];
                break;
            }
        } else {
            if(p.find(arr[i]*3)==p.end()){
                first = arr[i];
                break;
            }
        }
        
    }
    //cout<<"\n"<<first<<"\n";
    
    deque<ll> dq;
    dq.push_front(first);
    p.erase(first);
    while(!p.empty()){
        if(first%3==0 && p.find(first/3)!=p.end()){
            dq.push_back(first/3);
            p.erase(first);
        } else if(p.find(first*2)!=p.end()){
            dq.push_back(first*2);
            p.erase(first);
        } else 
            break;
        first = dq.back();
    }
    
    std::deque<ll>::iterator it;
    for(it = dq.begin();it!=dq.end();it++)
        cout<<*it<<" ";
    
    return 0;
}