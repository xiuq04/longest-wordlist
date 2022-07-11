#include "core.cpp"
#include <iostream>
using namespace std;
int main(){
    core test;
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
    test.testforinsert(words, 16);
    return 0;
}