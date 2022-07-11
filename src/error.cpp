#include "core.cpp"
#include <iostream>

using namespace std;
#define debugtype 2

int main(){
    core test;
    string result;
    fstream badname;
    string words[] = {
        "algebra", 
        "apple", 
        "zoo", 
        "elephant", 
        "under", 
        "trick",
        "pseudopseudohypoparathyroidism",
        "aa",   
        "aaaaaaaaaaaa",
        "algera", 
        "aple", 
        "zo", 
        "fox", 
        "dog", 
        "leaf",
         "aa"
    };
    if(debugtype == 2){
        cout << core::gen_chain_word(words, 16, result, 'a', 0) << endl;
        cout << core::gen_chain_char(words, 16, result, 'A', 'A') << endl;
        /*core::gen_n_chain(words, 16, 10, badname, 0, 0);
        core::gen_n_chain(words, 16, 17, badname, 0, 0);
        core::gen_n_chain(words, 16, 1, badname, 0, 0);
        test.testforinsert(words, 17);*/
    }
    return 0;
}