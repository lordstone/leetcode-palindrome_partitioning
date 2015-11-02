class Solution {
public:

    string addbars(string str){
        string tmp = "";
        for(int i = 0; i < str.length(); i ++){
            tmp += "#";
            tmp += str[i];
        }
        tmp += "#";
        return tmp;
    }
    
    string removePonds(string str){
        string tmp = "";
        int ptr = 0;
        while(ptr < str.length()){
            if(str[ptr] != '#'){
                tmp += str[ptr];
            }
            ptr++;
        }
        return tmp;
    }
    
    vector<vector<string>> myPartition(string s){
        vector<vector<string>> arr;
        if(s.length() == 0) return arr;
        int ptr = s.length() - 1;
        while(ptr >= 0){
            int left = ptr;
            int right = ptr;
            if(s[ptr] == '#'){
                left -= 1;
                right += 1;
            }
            while(left >= 0 && right < s.length()){
                if(s[left] != '#' && s[left] == s[right]){
                    vector<vector<string>> tmparr = myPartition(s.substr(right + 1));
                    for(vector<string> elem : tmparr){
                        elem.insert(elem.begin(), removePonds(s.substr(left, right-left)));
                    }
                }
                left -= 2;
                right += 2;
            }//end while
            ptr--;
        }//end while
        return arr;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> arr;
        if(s.length() == 0) return arr;
        string str = addbars(s);
        arr = myPartition(str);
        return arr;
    }
};
