#include<iostream>
#include<string>
using namespace std;

void main(){
    string str = "2 1 4 _ 3 1 20 _ @ # 4 5 9";

    for(int i=0;i<str.size();i++){
        char ch = str[i];
        if(str[i]<='0' && str[i]>='9'){
            if(str[i+1]<='0' && str[i+1]>='9'){
                char ch='A'+ (int)(str[i] + str[i+1]);
                cout<<ch<<" ";
            }
        }
    }
}
