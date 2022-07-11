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
        "fox",
        "dog",
        "leaf",
        "trick",
        "pseudopseudohypoparathyroidism",
        "aa",
        "aa",
        "aaaaaaaaaaaa",
        "algera",
        "aple",
        "zo",
        "elehant",
        "uner",
        "fx",
        "dg",
        "lef",
        "trck",
        "psudopseudohypoparathyroidism",
        "aa",
        "a",
        "aaaaaab"
    };

    int num, superlen = 50;
    string superwords[superlen];
    srand((unsigned)time(NULL));
    for(int i = 0; i < superlen; i ++){
        num = rand() % 12 + 1;
        superwords[i] = rand()%26 + 'a';
        for(int j = 1; j < num; j ++){
            superwords[i] += rand()%26 + 'a';
        }
        cout << superwords[i] << endl;
    }
    string result;
    fstream fout("solution.txt",ios::out);
    fstream debug("debug.txt", ios::out);
    fstream badname;
    for(int i = 0; i < 4; i ++){
        switch(i){
            case 0:
                test.testforinsert(words, 26);
                test.testforinsert(superwords, superlen);
                cout << endl << endl;
                break;
            case 1:
                debug << core::gen_chain_word(words, 26, result, 0, 0) << endl;
                debug << result << endl << endl;
                debug << core::gen_chain_word(words, 26, result, 'a', 0) << endl;
                debug << result << endl << endl;
                debug << core::gen_chain_word(words, 26, result, 0, 'a') << endl;
                debug << result << endl << endl;
                debug << core::gen_chain_word(words, 26, result, 'a', 'a') << endl;
                debug << result << endl << endl;
                break;
            case 2:
                debug << core::gen_chain_char(words, 26, result, 'a', 'a') << endl;
                debug << result << endl << endl;
                debug << core::gen_chain_char(words, 26, result, 0, 'a') << endl;
                debug << result << endl << endl;
                debug << core::gen_chain_char(words, 26, result, 'a', 0) << endl;
                debug << result << endl << endl;
                debug << core::gen_chain_char(words, 26, result, 0, 0) << endl;
                debug << result << endl << endl;
                debug << core::gen_chain_char(superwords, superlen, result, 0, 0) << endl;
                debug << result << endl << endl;
                break;
            case 3:
                debug << core::gen_n_chain(words, 26, 2, fout, 'a', 'a') << endl;
                debug << core::gen_n_chain(words, 26, 2, fout, 0, 'a') << endl;
                debug << core::gen_n_chain(words, 26, 2, fout, 'a', 0) << endl;
                debug << core::gen_n_chain(words, 26, 2, fout, 0, 0) << endl;
                //debug << core::gen_n_chain(words, 26, 27, fout, 0, 0) << endl;

                debug << core::gen_n_chain(superwords, superlen, 5, fout, '3', 'a') << endl;
                debug << core::gen_n_chain(words, 26, 2, badname, 0, 0) << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
