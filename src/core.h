#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED
#include<stdio.h>
//#include<string>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<iostream>
#include<ctime>
#include<sys/time.h>
#include<vector>
#include<exception>
#include "error.h"
using namespace std;

typedef struct Wnode{
	string word;
	int length;
	struct Wnode * next;
	int visit;
}wnode;

typedef struct{
	int totalnum;
	wnode * first;
}Head;

class core{
    static Head *head;
    static  time_t seconds1,seconds2;
    static void throwException(int kind);
    static void init() throw(error_room);
    static int insert(string str);
    static void insert_bucket(int place, string str, wnode * f, wnode * p);

    static bool findnext(string &sequence, int &length, int now, int next, int &max, string &longest, int mode,int request,int end);
    static int longestLetter(int mode,int request,string& longest,char str[]);
    static bool N_findnext(string &sequence, int &length, int now, int next, int &max, string &longest,int request,int n,int end,int& count,fstream& fout);
    static int N_longestLetter(int request,int n,char str[],fstream& fout);
    static int check_head_and_tail(char head, int tail, char str[]) throw(error_head,error_tail);
    public:
        static int text_preprocess(char* filename, vector <string> &words) throw(error_path);
        static int gen_chain_word(string words[], int len, string& result, char head, char tail) throw(error_room,error_wordslen,error_head,error_tail);
        static int gen_chain_char(string words[], int len, string& result, char head, char tail) throw(error_room,error_wordslen,error_head,error_tail);
        static int gen_n_chain(string words[], int len,int n,fstream& fout,char head, char tail)  throw(error_room,error_n,error_wordslen,error_fp,error_words_n,error_head,error_tail);
        int testforinsert(string words[], int len);
};

Head* core::head = NULL;
time_t core::seconds1 = 0;
time_t core::seconds2 = 0;
#endif // TEST_H_INCLUDED
