class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis(deadends.begin(),deadends.end());
        
        queue<pair<string,int>> q;
        string s="0000";
        if(vis.count(s)) return -1;
        q.push({s,0});
        vis.insert(s);
        vector<int> change={-1,1};

        while(!q.empty()){
            auto curr=q.front();
            string s=curr.first;
            int steps=curr.second;
            q.pop();

            if(s==target){
                return steps;
            }

            for(int i=0;i<4;i++){
                for(auto d:change){
                    string temp=s;
                    temp[i]=((temp[i]-'0'+d+10)%10)+'0';
                    if(!vis.count(temp)){
                        vis.insert(temp);
                        q.push({temp,steps+1});
                    }
                }
            }
        }
        return -1;
    }
};