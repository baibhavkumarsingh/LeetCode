
struct Node{
    Node*links[26];
    bool flag=0;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node*temp){
        links[ch-'a']=temp;
    }
    Node*get(char ch){
        return links[ch-'a'];
    }
    bool isend(){
        return flag;
    }
    void setend(){
        flag=1;
    }
};


class Trie{
    unordered_map<string, bool> memo;
    public: 
    Node*root;

    Trie(){
        root=new Node();
    }

    void insert(string word){
        Node*temp=root;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i])){
                temp->put(word[i],new Node());
            }
            temp=temp->get(word[i]);
        }
        temp->setend();
    }

    bool findword(string word){
        Node*temp=root;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i])){
                return false;
            }
            temp=temp->get(word[i]);
        }
        if(temp->isend())return true;
        return false;
    }

     bool solve(string word){
        if(word.size()==0) return true; 
        if(memo.find(word) != memo.end()) return memo[word];
        for(int i=1;i<=word.size();i++){
            if(findword(word.substr(0,i))){
                bool ans =solve(word.substr(i));
                if(ans==true)return true;
            }
        }
        memo[word] = false;
        return false;
    }


};


class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        for(int i=0;i<wordDict.size();i++){
            t.insert(wordDict[i]);
        }
        return t.solve(s);
    }
};