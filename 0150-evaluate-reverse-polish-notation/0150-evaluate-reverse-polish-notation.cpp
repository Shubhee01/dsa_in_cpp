class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<string> s;
        for(int i=0;i<t.size();i++){
            if(t[i]=="+"){
                int x=stoi(s.top());
                s.pop();
                int y=stoi(s.top());
                s.pop();
                int z=x+y;
                s.push(to_string(z));
            }else if(t[i]=="-"){
                int x=stoi(s.top());
                s.pop();
                int y=stoi(s.top());
                s.pop();
                int z=y-x;
                s.push(to_string(z));
            }else if(t[i]=="*"){
                int x=stoi(s.top());
                s.pop();
                int y=stoi(s.top());
                s.pop();
                int z=x*y;
                s.push(to_string(z));
            }else if(t[i]=="/"){
                int x=stoi(s.top());
                s.pop();
                int y=stoi(s.top());
                s.pop();
                int z=y/x;
                s.push(to_string(z));
            }else{
                s.push(t[i]);
            }
        }
        int ans=stoi(s.top());
        return ans;
    }
};