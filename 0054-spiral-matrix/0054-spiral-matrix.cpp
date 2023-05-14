class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> v;
        int left=0;
        int right=m-1;
        int top=0;
        int down=n-1;
        while(true){
            if(left>right){
                break;
            }
            for(int i=left;i<=right;i++){
                v.push_back(matrix[top][i]);
            }
            top++;
            if(down<top){
                break;
            }
            for(int i=top;i<=down;i++){
                v.push_back(matrix[i][right]);
            }
            right--;
            if(left>right){
                break;
            }
            for(int i=right;i>=left;i--){
                v.push_back(matrix[down][i]);
            }
            down--;
            if(down<top){
                break;
            }
            for(int i=down;i>=top;i--){
                v.push_back(matrix[i][left]);
            }
            left++;
        }
        return v;
    }
};