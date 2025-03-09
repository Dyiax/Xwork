#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <array>
#include <numeric>
using namespace std;

class Solution {
    public:
        // 方法1：排序     将字符串数组按照字母异位词分组
        // vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //     unordered_map<string, vector<string>> mp; // 用于存储分组结果的哈希表
        //     for(string& str: strs){
        //         string key = str;
        //         sort(key.begin(), key.end()); // 对字符串排序，作为哈希表的键
        //         mp[key].push_back(str); // 将原字符串加入对应的分组
        //     }
        //     vector<vector<string>> res; // 存储最终结果
        //     for(auto it = mp.begin(); it != mp.end(); it++){
        //         res.emplace_back(it->second); // 将每个分组加入结果
        //     }
        //     return res;
        // }
        // 方法2：计数     将字符串数组按照字母异位词分组

        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string,vector<string>> map; // 用于存储分组结果的哈希表
            for(string str:strs) {
            int counts[26] = {0}; // 计数数组，用于记录每个字母出现的次数
                for(char c:str) {
                    counts[c-'a']++; // 统计每个字母出现的次数
                }
            string key = ""; // 用于生成哈希表的键
                for(int i = 0;i<26;++i) {//遍历数组counts
                    if(counts[i]!=0) {
                    key.push_back(i+'a'); // 将字母加入键
                    key.push_back(counts[i]); // 将字母出现的次数加入键
                    }
                }
            map[key].push_back(str); // 将原字符串加入对应的分组
            }
            vector<vector<string>> res; // 存储最终结果
            for(auto& p:map) {
            res.push_back(p.second); // 将每个分组加入结果
            }
            return res;
        }
    

};

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"}; // 输入字符串数组
    Solution s;
    vector<vector<string>> res = s.groupAnagrams(strs); // 调用函数进行分组
    for(auto& v: res){
        for(auto& str: v){
            cout << str << " "; // 输出每个分组的字符串
        }
        cout << endl;
    }
    return 0;
}