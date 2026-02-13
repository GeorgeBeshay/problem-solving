/*
 * Created By George on 2/13/2026.
 */
 
 /*
  * Problem Link:       https://leetcode.com/problems/smallest-number-in-infinite-set/
  * Problem Status:     Accepted.
  */
  
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_INT numeric_limits<int>::max()

class SmallestInfiniteSet {
    int current_smallest = 1;
    map<int, bool> removed;
public:
    SmallestInfiniteSet() {

    }

    int popSmallest() {
        while (removed[current_smallest]) current_smallest++;
        removed[current_smallest] = true;
        return current_smallest++;
    }

    void addBack(int num) {
        removed[num] = false;
        current_smallest = min(num, current_smallest);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main(){
    
    
        
    return 0;
}