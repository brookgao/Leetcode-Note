//
//  string.cpp
//  Leetcode
//
//  Created by GaoBrook on 15/3/15.
//  Copyright (c) 2015年 gao. All rights reserved.
//

#include "string.h"


//20.Valid Parentheses
bool isValid(string s) {
    int len = int(s.size());
    std::stack<char> par;
    std::map<char,char> map_par ={{'}','{'},{']','['},{')','('}};
    bool valid = false;
    
    for(auto i =0;i<len;i++){
        if(!map_par.count(s[i])){
            par.push(s[i]);
        } else{
            if(!par.empty()&&map_par[s[i]] == par.top())
                par.pop();
            else
                par.push(s[i]);
        }
    }
    
    if(par.empty())
        valid = true;
    
    return valid;
}

//22.Generate Parentheses

//vector<string> generateParenthesis(int n) {
//    std::string shorterStr =
//    shorterStr.append(<#const std::basic_string<char> &__str#>)
//    
//}

//58.Length of Last Word
int lengthOfLastWord(string s) {
    auto iter = s.begin();
    int lastLen = 0;
    bool hasSpace = false;
    while (iter != s.end()) {
        if (*iter != ' '){
            lastLen = hasSpace == true? 0:lastLen+1;
        }else{
            hasSpace = true;
        }
        
        iter++;
    }
    return lastLen;
    
}


//71.Simplify Path
string simplifyPath(string path) {
    auto len = path.size();
    stack<char> store;
    int line_flag = 0;
    int dot_flag = 0;
    
    for (int i=0; i<=len; i++) {
        char c;
        
        if(i == len){
            c = '/';
        }
        else{
            c = path[i];
        }
        
        switch (c) {
            case '.':
                dot_flag++;
                store.push(c);
                break;
            case '/':
                if (line_flag&& dot_flag == 1) {
                    store.pop();
                    store.pop();
                }else if(line_flag&&dot_flag ==2){
                    while (dot_flag != 0&&!store.empty()) {
                        if (store.top() == '/') {
                            dot_flag--;
                        }
                        store.pop();
                    }
                }else if(line_flag&&!dot_flag){
                    store.pop();
                    line_flag =0;
                }
                
                store.push(c);
                line_flag = 1;
                dot_flag = 0;
                break;
                
            default:
                store.push(c);
                line_flag = 0;
                dot_flag = 0;
                break;
        }
    }
    
    while(store.size() > 1&&store.top()=='/')
        store.pop();
    
    string re;
    for (auto i=store.size(); i!=0; i--) {
        re = store.top()+re;
        store.pop();
    }
    
    return re;
}

//14.Longest Common Prefix
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty())
        return "";
    
    std::string result = strs[0];
    
    for (int i = 1; i < strs.size(); i ++) {
        
        while (strs[i].find(result) != 0 && result.length() > 0) {

            result = result.substr(0, result.length()-1);
        }
        
        if (result.length() == 0) {
            return NULL;
        }
        
    }

    return result;
}

//67.Add Binary
string addBinary(string a, string b) {
    int indexA = static_cast<int>(a.size())-1;
    int indexB = static_cast<int>(b.size())-1;
    stack<int> numStack;
    string result;
    
    int preSum = 0;
    int pa;
    int pb;
    while (indexA >=0 || indexB >=0) {
        pa = 0;
        pb = 0;
        if (indexA >= 0) pa = a[indexA] - '0';
        if (indexB >= 0) pb = b[indexB] - '0'; //从末尾开始相加
        
        cout<<"pa:"<<pa<<",pb:"<<pb<<",preSum:"<<preSum<<endl;
        int currentSum = pa+pb+preSum;
        int judge = currentSum%2;  //前一位和当前和相加
        cout<<"push:"<<judge<<endl;
        numStack.push(judge);

        preSum = 0;
        if (currentSum > 1) preSum = 1;
        
        indexA--;
        indexB--;
    }
    
    if (preSum) numStack.push(1); //如果到头还有1，就进一位
    
    while (!numStack.empty()) {
        result += std::to_string(numStack.top());
        numStack.pop();
    }
    cout<<result<<endl;
    return result;
}





