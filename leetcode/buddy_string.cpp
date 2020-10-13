#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    set<char> makeSet(string s){
        set<char> result;
        for(size_t i=0; i < s.length(); i++){
            result.insert(s[i]);
        }
        return result;
    }

    vector<int> counting(string s){
        vector<int> result(26, 0);
        for(size_t i=0; i < s.length(); i++){
            result[s[i]-'a']++;
        }
        return result;
    }

    bool buddyStrings(string A, string B) {
        int sizeA = A.length();
        int sizeB = B.length();
        set<char> sa = makeSet(A);
        set<char> sb = makeSet(B);
        vector<int> counter = counting(A);
        if ((sa != sb) || (sizeA != sizeB)){
            cout << "False\n";
            return false;
        }

        vector<int> diff;
        for(size_t i=0; i < sizeA; i++){
            if (A[i] != B[i])
                diff.emplace_back(i);
        }
        int diffSize = diff.size();
        if (diffSize == 0){
            if (find_if(counter.begin(), counter.end(), [](int x) -> bool{
                return x >= 2;
            }) != counter.end()) {
                return true;
            }
            return false;
        }else if(diffSize == 2){
            char tmp = A[diff[0]];
            A[diff[0]] = A[diff[1]];
            A[diff[1]] = tmp;
            if (A.compare(B) == 0)
                return true;
            else
                return false;
        }
        return false;
    }
};

int main(int argc, char** argv){
    Solution s;
    if (s.buddyStrings(argv[1], argv[2]))
        cout << "True";
    else
    {
        cout << "False";
    }
    
    return 0;
}