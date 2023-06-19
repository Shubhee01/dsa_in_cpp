class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> alt;
        alt.push_back(0);
        int sum=0;
        for(int i=0;i<gain.size();i++){
            sum+=gain[i];
            alt.push_back(sum);
        }
        int ans=*max_element(alt.begin(),alt.end());
        return ans;
    }
};