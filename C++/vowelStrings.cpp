#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        // int vowelStrings(vector<string>& words, int left, int right) {
        //     int count = 0;
        //     for (int i = 0; i < words.size(); i++) {
        //         string word = words[i];
        //         int vowels = 0;
        //         for (int j = 0; j < word.size(); j++) {
        //             if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u') {
        //                 vowels++;
        //             }
        //         }
        //         if (vowels >= left && vowels <= right) {
        //             count++;
        //         }
        //     }
        //     return count;
        // }

        // int vowelStrings(vector<string>& words, int left, int right) {
        //     unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'}; // 定义元音字母集合
        //     int count = 0; // 计数器
        //     for (int i = 0; i < words.size(); i++) { // 遍历每个单词
        //     string word = words[i]; // 获取当前单词
        //     int vowelCount = 0; // 当前单词中的元音字母计数器
        //     for (int j = 0; j < word.size(); j++) { // 遍历单词中的每个字符
        //         if (vowels.count(word[j])) { // 如果字符是元音字母
        //         vowelCount++; // 增加元音字母计数
        //         }
        //     }
        //     if (vowelCount >= left && vowelCount <= right) { // 如果元音字母数量在指定范围内
        //         count++; // 增加符合条件的单词计数
        //     }
        //     }
        //     return count; // 返回符合条件的单词数量
        // }

        int vowelStrings(vector<string>& words, int left, int right) {
            unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'}; // 定义元音字母集合
            int count = 0; // 计数器
            for(int i=left;i<=right;i++){
                string word = words[i]; // 获取当前单词
                if( !word.empty() && vowels.find(tolower(word[0]))  !=  vowels.end() && vowels.find(tolower(word.back())) != vowels.end()  ){ // 如果字符是元音字母
                    count++; // 增加元音字母计数

                }
            }
            return count; // 返回符合条件的单词数量
        }
    };

int main(){
    Solution solution;
    vector<string> words = {"are","amy","u"};
    int left = 0;
    int right = 2;
    cout << solution.vowelStrings(words, left, right) << endl;

    return 0;

}
