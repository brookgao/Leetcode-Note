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








