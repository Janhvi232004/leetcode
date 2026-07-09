struct stock{
    int price;
    int span;
};

class StockSpanner {
    stack <stock> st;

public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span =1;
        while(!st.empty() && st.top().price<=price){
            span+=st.top().span;
            st.pop();
        }
        st.push({price,span});
        return span;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */