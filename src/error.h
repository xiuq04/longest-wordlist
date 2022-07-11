#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED
#include<exception>
#include<iostream>
using namespace std;

class error_room:public exception
{
public:
   const char* what()const throw()
   {
        return "There is no memory to be allotted!\n";
   }
};

class error_head:public exception
{
public:
   const char* what()const throw()
   {
        return "The parameter head is wrong!\n";
   }
};

class error_tail:public exception
{
public:
   const char* what()const throw()
   {
        return "The parameter tail is wrong!\n";
   }
};

class error_n:public exception
{
public:
   const char* what()const throw()
   {
        return "The parameter n is wrong!\n";
   }
};

class error_wordslen:public exception
{
public:
   const char* what()const throw()
   {
        return "The parameter len is wrong!\n";
   }
};

class error_fp:public exception
{
public:
   const char* what()const throw()
   {
        return "Wrong file pointer!solution.txt will be opened.\n";
   }
};

class error_words_n:public exception
{
public:
   const char* what()const throw()
   {
        return "There vector words haves too few words to meet the requirements!\n";
   }
};

class error_path:public exception
{
public:
   const char* what()const throw()
   {
        return "cannot open the file!\n";
   }
};



#endif // ERROR_H_INCLUDED
