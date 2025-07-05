class Solution {
public:
    bool isNumber(string s) {
        bool digit= false ; 
        bool e = false ; 
        bool decimal = false;
        bool intBefore_e =0 ; 
        bool intAfter_e = 0 ;
        bool intAfterDec = 0 ; 
        bool intSingle = 0 ; 
        bool sign = false ; 
        // bool 
        for(int i=0;i<s.size();i++){
            if(s[i]=='-'||s[i]=='+'){

                if(i==0||s[i-1]=='e'||s[i-1]=='E'){sign = true ;}
                else return 0 ; 
            }
            // if(!isdigit(s[i])&&(s[i]!='.'||s[i]!='e'||s[i]!='E')) return false; 
            if (!isdigit(s[i]) && s[i] != '.' && s[i] != 'e' && s[i] != 'E' && s[i] != '+' && s[i] != '-') return false;

            if(isdigit(s[i])){
                if(e==0) intBefore_e = true; 
                if(e) intAfter_e=true ; 
                // if(decimal)intAfterDec =true ; 
                intSingle =true ; 
            }

            if(s[i]=='e'||s[i]=='E'){
                if(e==true)return false ; 
                if(!intBefore_e)return false ; 
                e=true;
            }
            if(s[i]=='.'){
                if(e==true)return false ;
                if(decimal) return false ; 
                decimal = true ;
            }

        }

        if(decimal||sign){

            if(intSingle==0)return false ;
        }
        if(e){
            if(intBefore_e==0||intAfter_e==0) return false ;
        }
        
        return 1 ;
    }
};