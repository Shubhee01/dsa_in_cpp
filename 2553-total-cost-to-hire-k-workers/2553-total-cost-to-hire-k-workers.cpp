class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        priority_queue <int, vector<int>, greater<int>> q1;
        priority_queue <int, vector<int>, greater<int>> q2;
        int j1=0;
        int j2=n-1;
        long long sum=0;
        for(int i=0;i<k;i++){
            while(j1<=j2 && q1.size()<candidates){
                // cout<<i<<" j1 "<<costs[j1]<<endl;
                q1.push(costs[j1]);
                j1++;
            }
            while(j2>=j1 && q2.size()<candidates){
                // cout<<i<<" j2 "<<costs[j2]<<endl;
                q2.push(costs[j2]);
                j2--;
            }
            if(!q1.empty() && !q2.empty() && q1.top()<=q2.top()){
                // cout<<"q1 "<<q1.top()<<endl;
                // cout<<"q2 "<<q2.top()<<endl;
                sum+=q1.top();
                q1.pop();
            }else if(!q1.empty() && !q2.empty() && q1.top()>q2.top()){
                // cout<<"q1 "<<q1.top()<<endl;
                // cout<<"q2 "<<q2.top()<<endl;
                sum+=q2.top();
                q2.pop();
            }else{
                if(q1.empty() && !q2.empty()){
                    sum+=q2.top();
                    q2.pop();
                }else if(q2.empty() && !q1.empty()){
                    sum+=q1.top();
                    q1.pop();
                }
            }
        }
        return sum;
    }
};