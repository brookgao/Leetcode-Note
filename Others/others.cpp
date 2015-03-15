//
//  others.cpp
//  Leetcode
//
//  Created by GaoBrook on 15/3/15.
//  Copyright (c) 2015年 gao. All rights reserved.
//

#include "others.h"


//150.Evaluate Reverse Polish Notation
int evalRPN(vector<string> &tokens) {
    auto len = tokens.size();
    std::stack<string> store;
    
    for(auto i=0;i<len;i++){
        string tmp = tokens[i];
        if(tmp.size()<2&&!isdigit(tmp[0])){
            int snd= stoi(store.top());store.pop();
            int fst = stoi(store.top()); store.pop();
            int re = 0;
            switch (tmp[0]) {
                case '+':
                    re = fst+snd;
                    break;
                case '-':
                    re = fst-snd;
                    break;
                case '/':
                    re = fst/snd;
                    break;
                case '*':
                    re = fst*snd;
                    break;
            }
            store.push(std::to_string(re));
        }else{
            store.push(tmp);
        }
    }
    
    return stoi(store.top());
}

