class Solution {
public:
    
    bool isPalindrome(string str){
        int start = 0, end = str.length() - 1;
        while(start <= end){
            if(str[start] != str[end]) return false;
            start ++;
            end --;
        }
        return true;
    }
    
    void myPartition(string &s, int start, vector<string> &temp, vector<vector<string>> &solution){
        if(start == s.length() ){
            solution.push_back(temp);
            return;
        }

        for(int i = start; i < s.length(); i ++){
            if(isPalindrome(s.substr(start, i - start + 1))){
                temp.push_back(s.substr(start, i - start + 1));
                myPartition(s, i + 1, temp, solution);
                temp.pop_back();
            }            
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> arr;
        if(s.length() == 0) return arr;
        vector<string> output;
        myPartition(s, 0,output, arr);
        return arr;
    }
};
