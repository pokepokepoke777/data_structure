#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;
vector<int>a;
vector<int> Compress(vector<int> &tmp){
    sort(tmp.begin(),tmp.end());
    /*
        重複した成分を除去
        異なった種類の数字がtmpに含まれる
    */
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    vector<int>ans;
    /*
        sortしているので二分探索可能
        そのindexを取得すればよい
    */
    for(int i=0;i<a.size();i++){
        int id = lower_bound(tmp.begin(),tmp.end(),a[i])-tmp.begin();
        ans.push_back(id);
    }
    return ans;
}

int main(void){
    int n;
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int>tmp = a;
    vector<int>val = Compress(tmp);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)cout<<val[i]<<" ";
    cout<<endl;
}
