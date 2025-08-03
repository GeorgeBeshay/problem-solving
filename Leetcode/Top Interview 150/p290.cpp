/*
 * Created By George on 8/3/2025.
 */
 
 /*
  * Problem Link:       https://leetcode.com/problems/word-pattern/
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

class Solution {
public:

    void splitIntoTokens(const string& s, vector<string>& tokens) {
        string token;
        istringstream iss(s);

        while(iss >> token) {
            tokens.push_back(token);
        }
    }

    bool wordPattern(string pattern, string s) {

        vector<string> tokens;
        splitIntoTokens(s, tokens);
        map<char, string> mappings;
        map<string, char> reverse_mappings;

        if (pattern.size() != tokens.size()) {
            return false;
        }

        for (int i = 0; i < tokens.size(); i++) {

            if (
                mappings.count(pattern[i]) == 0 &&
                reverse_mappings.count(tokens[i]) == 0
                ) {
                mappings[pattern[i]] = tokens[i];
                reverse_mappings[tokens[i]] = pattern[i];
            }

            if (mappings[pattern[i]] == tokens[i]) {
                continue;
            }

            return false;
        }

        return true;
    }
};

int main(){
    
    
        
    return 0;
}