#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll dec(string n) 
{ 
    string num = n; 
    ll dec_value = 0; 
    ll base = 1; 
  
    ll len = num.length(); 
    for (ll i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
  
    return dec_value; 
} 

int main(){
    fast;
    ll n;
    cin>>n;
    ll arr[n];
    vector<string> bin;
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll count[32]={0};
    
    for(ll i=0;i<n;i++){
        string binary = std::bitset<32>(arr[i]).to_string();
        for(ll j=0;j<32;j++){
            if(binary[j]=='1')
                count[j]++;
        }
        bin.push_back(binary);
    }
    
    ll temp=0,mx=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<32;j++){
            if(count[j]>1)
                bin[i][j] = '0';
        }
        ll num = dec(bin[i]);
        if(num>mx){
            mx = num;
            temp = i;
        }
    }
    
    swap(arr[0],arr[temp]);
    
    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}