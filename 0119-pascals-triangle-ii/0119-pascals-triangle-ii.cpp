class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n=rowIndex+1;
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            vector<int> a(i+1,1);
            for(int j=1;j<i;j++){
                a[j]=v[i-1][j-1]+v[i-1][j];
            }
            v.push_back(a);
        }
        return v[rowIndex];
    }
};