class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;
        int score =0;
        for(string op:ops){
            if(op=="+"){
                int top1=st.top();
                st.pop();
                int top2=st.top();
                st.push(top1);
                st.push(top1+top2);
            }else if(op=="D"){
                int top=st.top();
                st.push(top*2);
            }else if(op=="C"){
                st.pop();
            }else{
                int num=stoi(op);
                st.push(num);
            }
        }
        while(!st.empty()){
            score+=st.top();
            st.pop();
        }
        return score;
    }
};