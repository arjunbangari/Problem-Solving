#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){   
    string s;
    cin>>s;
    map<char, int> mp;
    int l = s.length();
    for(int i=0;i<l;i++){
        if(mp.find(s[i])!=mp.end())
            mp[s[i]]++;
        else
            mp[s[i]] = 1;
    }
    int odd = 0;
    map<char, int>::iterator itr; 
    for(itr=mp.begin();itr!=mp.end();itr++){
        if((itr->second)%2!=0)
            odd++;
    }
    
    if(odd<=1)
        cout<<"First"<<"\n";
    else{
        if(odd%2==0)
            cout<<"Second"<<"\n";
        else
            cout<<"First"<<"\n";
    }
        
    return 0;
}
