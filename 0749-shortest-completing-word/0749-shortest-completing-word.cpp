class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        transform(licensePlate.begin(), licensePlate.end(), licensePlate.begin(), ::tolower);
        map<char,int> m;
        for(int i=0;i<licensePlate.size();i++){
            if(licensePlate[i]<123 && licensePlate[i]>96){
                m[licensePlate[i]]++;
            }
        }
        vector<string> v;
        // for(auto i:m){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        for(int i=0;i<words.size();i++){
            map<char,int> m1;
            m1=m;
            // for(auto j:m1){
            //     cout<<i<<" "<<j.first<<" "<<j.second<<endl;
            // }
            for(int j=0;j<words[i].length();j++){
                if(m[words[i][j]]!=0 && m1[words[i][j]]!=0){
                    m1[words[i][j]]--;
                }
            }
            // for(auto j:m1){
            //     cout<<i<<" "<<j.first<<" "<<j.second<<endl;
            // }
            bool allnull=true;
            for(auto j:m1){
                if(j.second!=0){
                    allnull=false;
                }
            }
            if(allnull){
                // cout<<words[i]<<endl;
                v.push_back(words[i]);
            }
        }
        // for(auto i:v){
        //     cout<<i<<endl;
        // }
        string ans="";
        int mini=1e9;
        for(int i=0;i<v.size();i++){
            if(v[i].length()<mini){
                ans=v[i];
                mini=v[i].length();
            }
        }
        return ans;
    }
};