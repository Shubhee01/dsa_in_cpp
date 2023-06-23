class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n=ast.size();
        stack<int> s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push(ast[i]);
            }else{
                int x=ast[i];
                // cout<<s.top()<<endl;
                while(!s.empty() && s.top()>=0 && x<0){
                    if(s.top()==x*(-1)){
                        x=0;
                    }else if(s.top()>abs(x)){
                        x=s.top();
                    }
                    s.pop();
                }
                s.push(x);
            }
        }
        vector<int> v;
        while(!s.empty()){
            if(s.top()!=0){
                v.push_back(s.top());
            }
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};