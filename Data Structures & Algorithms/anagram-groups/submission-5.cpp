class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        for(string ch:strs){
            vector<int>freq(26,0);
            for(char c:ch){
                freq[c-'a']++;
            }
            string key=to_string(freq[0]);
            for(int k=1;k<26;k++){
                key+=","+to_string(freq[k]);
            }
            m[key].push_back(ch);
        }
        vector<vector<string>>ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};
