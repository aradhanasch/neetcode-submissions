class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        for(string s:strs){
            vector<int>freq(26,0);
            for(char ch:s){
                freq[ch-'a']++;
            }
            string key=to_string(freq[0]);
            for(int i=1;i<26;i++){
                key+=","+to_string(freq[i]);
            }
            m[key].push_back(s);
        }
        vector<vector<string>>res;
        for(auto i:m){
            res.push_back(i.second);
        }
        return res;
    }
};
