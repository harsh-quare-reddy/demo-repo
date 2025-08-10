#include <iostream>     // for cin, cout
#include <vector>       // for vector
#include <algorithm>    // for max
using namespace std;

void buildSegTree(vector<int>& bs, vector<int>& segTree, int low, int hi, int i){
    if(low == hi){
        segTree[i] = bs[low];
        return ;
    }

    int mid = (low + hi) / 2;

    buildSegTree(bs, segTree, low, mid-1, 2*i+1);
    buildSegTree(bs, segTree, mid, hi, 2*i + 2);

    segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
}

void solve(vector<int>& fs, vector<int>& bs){
    int n = fs.size();

    // create an array for building segtree
    vector<int> segTree(4*n, 0);
    buildSegTree(bs, segTree, 0, n-1, 0);

    for(int i = 0; i < 4*n; i++){
        cout << segTree[i] << ", ";
    }

    return ;

}

int main(){
    int n;
    cin>> n;
    vector<int> arr1(n), arr2(n);
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }

    solve(arr1, arr2);

    return 0;
}