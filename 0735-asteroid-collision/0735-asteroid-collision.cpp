class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int a:asteroids){
            bool destruction=false;
            while(!st.empty() && a<0 &&  st.top()>0){
                if(st.top()<-a){
                   st.pop();
                   continue; 
                }
                
                else if (st.top()==-a){
                st.pop();
                }
                destruction=true;
                break;

            }
            



            
            if (!destruction) st.push(a);

        }
        vector<int>res (st.size());
        for(int i=st.size()-1;i>=0;i--){
            res[i]=st.top();
            st.pop();
        }
        return res;
        
    }
};