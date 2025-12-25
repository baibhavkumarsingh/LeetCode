class Solution {
public:
int facto(int x){
    switch(x){
        case 0: return 1;
        case 1: return 1;
        case 2: return 2;
        case 3: return 6;
        case 4: return 24;
        case 5: return 120;
        case 6: return 720;
        case 7: return 5040;
        case 8: return 40320;
        case 9: return 362880;
        default: return -1;
    }
}

    string getPermutation(int n, int k) {
        vector<int>vec(n);
        for(int i=0;i<n;i++) vec[i]=i+1;
        k=k-1;
        int size=vec.size();
        string s="";

        while(vec.size()!=1){
            int factorial=facto(--size);
            int index=k/factorial;
            s=s+char('0'+vec[index]);
            k=k%factorial;
            vec.erase(vec.begin()+index);

        }
        s=s+char('0' + vec[0]); // for last element
        return s;
    }
};