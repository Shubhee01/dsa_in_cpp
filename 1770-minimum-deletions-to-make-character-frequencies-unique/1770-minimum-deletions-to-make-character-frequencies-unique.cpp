class Solution {
public:
    int minDeletions(string s) {
        map<char,int> m;
        int count=0;
        for(auto i:s){
            m[i]++;
        }
        vector<int> v;
        for(auto i:m){
            while(find(v.begin(),v.end(),i.second)!=v.end() && i.second!=0){
                count++;
                i.second--;
            }
            v.push_back(i.second);
        }
        return count;
    }
};