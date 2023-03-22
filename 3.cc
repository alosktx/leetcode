/*
 * @Author: tangxiao
 * @Date: 2023-01-28 13:26:54
 * @LastEditTime: 2023-01-28 13:50:06
 * @LastEditors: tangxiao
 * @Copyright: 2022 FT. All right reserved.
 * @Description: Do not edit
 */
#include <iostream>
#include <string>

class Solution {
   public:
    int lengthOfLongestSubstring(std::string s) {
        int start = 0, end = 0, maxlen = 0;
        char map[256] = {0};
        map[s[start]] = 1;
        while(s[end]){
            maxlen = maxlen > (end - start + 1) ? maxlen : (end - start + 1);
            end++;
            while(map[s[end]]){
                map[s[start]] = 0;
                start++;
            }
            map[s[end]] = 1;
        }
        return maxlen;
    }
};

int main(int argc, char const *argv[])
{
    std::string s = "adasfdasf";
    // std::cout << (s[s.length()] == 0) << "\n";
    Solution sl;
    std::cout << sl.lengthOfLongestSubstring(s) << std::endl;
    ;
}
