class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int res=0,n=prices.size();
        int price=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(price>prices[i]){
                res+=price-prices[i];
                price=prices[i];
            }
            else if(prices[i]>price)price=prices[i];
        }
        return res; 
    }
};