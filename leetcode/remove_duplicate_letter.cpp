#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>



class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        std::map<char, int> last_occ;
        // Making last_occurrence map
        for(int i=0; i< s.length(); i++){
            auto iterator = last_occ.find(s[i]);
            if (last_occ.find(s[i]) != last_occ.end()){
                iterator->second = i;
            }
            else
                last_occ.insert(std::make_pair(s[i], i));
        }
        std::vector<char> result;
        std::vector<char> visited;
        for(int i=0; i< s.length(); i++){
            char c = s[i];
            if (find(visited.begin(), visited.end(), s[i]) != visited.end())
                continue;

            while (result.size() > 0 && s[i] < result.back() && last_occ[result.back()] > i){
                char last = result.back();
                result.pop_back();
                auto pos = find(visited.begin(), visited.end(), last);
                visited.erase(pos);
            }

            visited.push_back(s[i]);
            result.push_back(s[i]);
        }
        std::string answer = "";
        for(auto iter=result.begin(); iter != result.end(); iter++){
            answer += *iter;
        }
        return answer;
    }
};

int main(int argc,char** argv){
    Solution sol;
    sol.removeDuplicateLetters(argv[1]);
    return 0;
}