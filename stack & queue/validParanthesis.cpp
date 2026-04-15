#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){
    stack<char> st;

    for(auto i : s){
        if(i == '(' || i == '{' || i == '[') st.push(i);
        else{
            if(st.empty()) return false;
            char ch = st.top();
            if((ch == '(' && i == ')') || (ch == '{' && i == '}') || (ch == '[' && i == ']')) st.pop();
            else return false;
        }
    }
    return st.empty();
}


int main(){
    isValid("{([])}")? cout << 1: cout << 0;
    return 0;
}