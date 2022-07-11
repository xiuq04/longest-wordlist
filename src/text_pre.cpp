#include "core.cpp"
#include <iostream>

using namespace std;
int main(){
    char filename[] = "testfile.txt";
    vector <string> words;
    int num = core::text_preprocess(filename, words);
    cout << num << endl;
    for(int i = 0; i < num; i ++){
        cout << words[i] << endl;
    }
    gen_n_chain(woeds,num,5,)
}
