#include "core.h"
#include<exception>
#include<iostream>
#include "error.h"

/*#define error_room      0
#define error_head      1
#define error_tail      2
#define error_wordslen  4
#define error_fp        5
#define error_words_n   6
#define error_path      7
#define error_n         3*/


/*void core::throwException(int kind){
    switch(kind){
        case error_room:
            cout << "There is no memory to be allotted!" << endl;
            break;
        case error_head:
            cout << "The parameter head is wrong!" << endl;
            break;
        case error_tail:
            cout << "The parameter tail is wrong!" << endl;
            break;
        case error_n:
            cout << "The parameter n is wrong!" << endl;
            break;
        case error_wordslen:
            cout << "The parameter len is wrong!" << endl;
            break;
        case error_fp:
            cout << "Wrong file pointer!solution.txt will be opened." << endl;
            break;
        case error_words_n:
            cout << "There vector words haves too few words to meet the requirements!" << endl;
            break;
        case error_path:
            cout << "cannot open the file!" << endl;
            break;
    }
}*/

void
core::init() throw(error_room){//初始化类
        int num = 26 * 26;
        head = new Head[num];
        if(head == NULL){
            throw error_room();
            return;
        }
        for(int i = 0; i < num; i ++){

            head[i].first = NULL;
            head[i].totalnum = 0;
        }
}

void
core::insert_bucket(int place, string str, wnode * f, wnode * p){//单词有序插到指定编号的桶中
    wnode * q = new wnode;
    q->word = str;
    q->length = str.length();
    q->visit = -1;
    q->next = p;
    f->next = q;
    head[place].totalnum ++;
}


int
core::insert(string str){//将单词插入数据结构中
    char start = str.at(0);//首字母
    char end = str.at(str.length() - 1);//尾字母
    int place = (start - 'a') * 26 + (end - 'a');//对应的桶号
    wnode * p = head[place].first;
    if(p == NULL){
        wnode * q = new wnode;
        q->word = str;
        q->length = str.length();
        q->next = NULL;
        q->visit = -1;
        head[place].totalnum ++;
        head[place].first = q;
        return 1;
    }
	else{
		if(p->length < str.length()){//将最长的单词放在最前面
			wnode * q = new wnode;
			q->word = str;
			q->length = str.length();
			q->visit = -1;
			q->next = p;
			head[place].first = q;
			head[place].totalnum ++;
			return 1;
		}
		else{
			wnode * f = p;
			if(p-> word != str){
				p = f->next;
				while(p != NULL){
					if(str.length() > p->length)
					{
						insert_bucket(place, str, f, p);
						return 1;
					}
					else if(p->word == str){//重复单词，直接丢弃
						return 0;
					}
					else if(str.length() <= p->length){//单词长度一样，继续向后看
						f = p;
						p = f->next;
					}
				}
				if(p == NULL)
				{
					insert_bucket(place, str, f, p);
					return 1;
				}
			}
			return 0;
		}
	}
}
bool
core::findnext(string &sequence, int &length, int now, int next, int &max, string &longest, int mode,int request,int end){
    seconds2 = time(NULL);
    if(seconds2 - seconds1>60){
        if(rand() % 10 < 5)
            return true;
    }
    if(seconds2 - seconds1 > 300){
        if((request != 3 ||  end == (sequence.at(sequence.length() - 2) - 'a'))&&sequence.find('\n') != (sequence.length() - 1)){
            if(length > max){
                max = length;
                longest = sequence;
            }
        }
        return false;
    }
	wnode * p = NULL;
	int record;
    for(int i = 0;i < 26; i ++){
        if(request == 2 && head[i*26+next].totalnum != 0){//从尾单词逆向查单词链
            p = head[i*26+next].first;
            record = i*26 + next;
        }
        else if(request != 2 && head[i+next*26].totalnum != 0){
            p = head[i+next*26].first;
            record = i + next*26;
        }
        else {
                if((request != 3 ||  end == (sequence.at(sequence.length() - 2) - 'a'))&&sequence.find('\n') != (sequence.length() - 1)){//是否符合单词链要求
                    if(length > max){
                        max = length;
                        longest = sequence;
                    }
                }
                continue;
        }
        while(p != NULL && p->visit == now){//是否已被使用
            p = p->next;
        }
        if(p != NULL){
            int templ = length;
            string temps = sequence;
            int visit = p->visit;
			//以上为了记录原状态，回溯将要恢复此状态
            if((record % 27) == 0){//若首尾字母一致，所有单词连接（可看作一个单词）
                wnode * q = p;
                while(q != NULL){
                    if(mode == 1)//字母数最多
                        length += q->length;
                    else
                        length ++;
                    if(request == 2){
                        sequence = q->word + "\n" + sequence;
                    }
                    else{
                        sequence += q->word;
                        sequence += '\n';
                    }
                    q->visit = now;
                    q = q->next;
                }
            }
            else{
                if(mode == 1)
                    length += p->length;
                else
                    length ++;
                if(request == 2){//倒置字符串
                    sequence = p->word + "\n" + sequence;
                }
                else{
                    sequence += p->word;
                    sequence += "\n";
                }
                p->visit = now;
            }
            if(!findnext(sequence, length, now, i, max, longest,mode,request,end)){
                return false;
            }
					//以下为恢复状态（回溯）
            sequence = temps;
            length = templ;
            p->visit = visit;
        }
        else if((request != 3 ||  end == (sequence.at(sequence.length() - 2) - 'a'))&&sequence.find('\n') != (sequence.length() - 1)){//到达叶子节点
            if(length > max){
                max = length;
                longest = sequence;
            }
        }
    }
	return true;
}

int
core::longestLetter(int mode,int request,string& longest,char str[]){
	wnode * p;
	string sequence="\n";//存放当前得到的单词链
	int start = 0;//记录单词的开头，用于hash
	int end = 0;//记录单词的结尾，用于hash
	int length;//记录当前得到的单词链长度
	int max = 0;//记录当前最长单词链长度
	//string longest="no" ;//存放目标单词链，单词以'\n'隔开
	int amount = 26*26;
    if(request == 1 || request == 3)
        start = str[0] - 'a';//start理解为词头为arg[0]的桶起始编号，共有26个，以后按顺序取每个桶
    if(request == 2 || request == 3)
        end = str[1] - 'a';//start理解为词头为arg[0]的桶起始编号，共有26个，以后按顺序取每个桶
    for(int i = 0; i < amount; i ++){
        seconds2 = time(NULL);
        if(seconds2 - seconds1 > 60){
            if(rand() % 100 < 90)
                continue;
        }
        if((request == 1 || request == 3) && i/26 != start){//首不合要求
            continue;
        }
        if(request == 2 && i%26 != end){//尾不合要求。
            continue;
        }
        if(head[i].totalnum != 0){
            p = head[i].first;
            if(mode == 1){
                length = p->length;
            }
            else
                length = 1;
            sequence = p->word;
            sequence += '\n';//用于隔开单词,不能被记录到单词链长度中
            p->visit = i;
            if(i % 27 == 0){//出现首尾字母一样的情况，可以先将他们全部连接
                while(p->next != NULL){
                    p = p->next;
                    if(mode == 1){
                        length += p->length;
                    }
                    else
                        length ++;
                    sequence += p->word;
                    sequence += "\n";
                    p->visit = i;
                }
            }
            if(request == 2){
                char c = p->word.at(0);
                if(!findnext(sequence, length, i, (c-'a'), max, longest, mode,request,start)){//尾要求逆向寻找
                    return max;
                }
            }
            else {
                char c = p->word.at(p->length - 1);
                if(!findnext(sequence, length, i, (c-'a'), max, longest,mode,request,end)){
                    return max;
                }
            }
            if((request != 3 || sequence.at(sequence.length() - 2) == str[1]) &&sequence.find('\n') != (sequence.length() - 1)){
                if(length > max){
                    max = length;
                    longest = sequence;
                }
            }
        }
    }
    return max;
}

bool
core::N_findnext(string &sequence, int &length, int now, int next, int &max, string &longest,int request,int n,int end,int& count,fstream& fout){
    wnode * p = NULL;
	int record;
	if(length == n){//单词链是否符合要求
        if(request != 3 ||  end == (sequence.at(sequence.length() - 2) - 'a')){
                longest = sequence+"\n";
                fout << longest;
                count ++;
        }
        return true;
	}
	seconds2 = time(NULL);
    if(seconds2 - seconds1 > 300){
        return false;
    }
    for(int i = 0;i < 26; i ++){
        if(request ==2 && head[i*26+next].totalnum != 0){//尾逆向
            p = head[i*26+next].first;
            record = i*26 + next;
        }
        else if(request != 2 && head[i+next*26].totalnum != 0){
            p = head[i+next*26].first;
            record = i + next*26;
        }
        else {
                continue;
        }
        while(p != NULL){
            if(p->visit == now){
                p = p->next;
                continue;
            }
            int templ = length;
            string temps = sequence;
            int visit = p->visit;
            //以上为了记录原状态，回溯将要恢复此状态
            length ++;
            if(request == 2){
                sequence = p->word + "\n" + sequence;
            }
            else{
                sequence += p->word;
            	sequence += '\n';
            }
            p->visit = now;
            if(!N_findnext(sequence, length, now, i, max, longest,request,n,end,count,fout)){
                return false;
            }
            //以下为恢复状态（回溯）
            sequence = temps;
            length = templ;
            p->visit = visit;
            p=p->next;
        }
    }
	return true;
}

int
core::N_longestLetter(int request,int n,char str[],fstream& fout){
	wnode * p;
	string sequence="\n";//存放当前得到的单词链
	int start = 0;//记录单词的开头，用于hash
	int end = 0;//记录单词的结尾，用于hash
	int length;//记录当前得到的单词链长度
	int max = 0;//记录当前最长单词链长度
	string longest ;//存放目标单词链，单词以'\n'隔开
	int amount = 26*26;
	int count=0;
    if(request == 1 || request == 3)
        start = str[0] - 'a';//start理解为词头为arg[0]的桶起始编号，共有26个，以后按顺序取每个桶
    if(request == 2 || request == 3)
        end = str[1] - 'a';//start理解为词头为arg[0]的桶起始编号，共有26个，以后按顺序取每个桶
    for(int i = 0; i < amount; i ++){
        if((request == 1 || request == 3) && i/26 != start){//首不合要求
            continue;
        }
        if(request == 2 && i%26 != end){//尾不合要求
            continue;
        }
        if(head[i].totalnum != 0){
            p = head[i].first;
            while(p != NULL){
                length = 1;
                sequence = p->word;
                sequence += "\n";//用于隔开单词,不能被记录到单词链长度中
                p->visit = i;
                if(request == 2){
                    char c = p->word.at(0);
                    if(!N_findnext(sequence, length, i, (c-'a'), max, longest, request,n,end,count,fout)){
                        return count;
                    }
                }
                else {
                    char c = p->word.at(p->length - 1);
                    if(!N_findnext(sequence, length, i, (c-'a'), max, longest,request,n,end,count,fout)){
                        return count;
                    }
                }
                p->visit = -1;
                p = p->next;
            }
        }

    }
    return count;
}

int
core::check_head_and_tail(char head, int tail, char str[]) throw(error_head,error_tail){
    int request;
    if(head == 0 && tail == 0){
        request = 0;
    }
    else if(head != 0 && tail == 0){
        if(head >= 'a' && head <= 'z'){
            request = 1;
            str[0] = head;
        }
        else{
            throw error_head();
            request = -1;
        }
    }
    else if(head == 0 && tail != 0){
        if(tail >= 'a' && tail <= 'z'){
            request = 2;
            str[1] = tail;
        }
        else{
            throw error_tail();
            request = -1;
        }
    }
    else if(head != 0 && tail != 0){
        if(head >= 'a' && head <= 'z' && tail >= 'a' && tail <= 'z'){
            request = 3;
            str[0] = head;
            str[1] = tail;
        }
        else {
            if(head < 'a' || head > 'z'){
                throw error_head();
            }
            if(tail < 'a' || tail > 'z'){
                throw error_tail();
            }
            request = -1;
        }
    }
    return request;
}


int
core::text_preprocess(char* filename, vector <string> &words) throw(error_path){
    FILE * fp = fopen(filename, "r");
	if(fp == NULL){
        throw error_path();
		return 0;
	}
	char ch = fgetc(fp);
    int flag = 0;
    int num = 0;
	string word;
	int length = 0;
	while(ch != EOF){
		if(ch >= 'a' && ch <= 'z'){
			if(length == 0)
				word = ch;
			else
				word += ch;
			length ++;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + 32;
			if(length == 0)
				word = ch;
			else
				word += ch;
			length ++;
		}
		else{
			if(length != 0){
                num = words.size();
                flag = 1;
				for(int i = 0; i < num; i ++){
                    if(word == words[i]){
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    words.push_back(word);
                    cout << words[num] << endl;
                }
				length = 0;
			}
		}
		ch = fgetc(fp);
	}
	if(length != 0){
		num = words.size();
        flag = 1;
		for(int i = 0; i < num; i ++){
            if(word == words[i]){
                flag = 0;
                break;
            }
        }
        if(flag){
            words.push_back(word);
            cout << words[num] << endl;
         }
		length = 0;
	}
	fclose(fp);
    num = words.size();
	return num;
}

int
core::gen_chain_word(string words[], int len, string& result, char head, char tail) throw(error_room,error_wordslen,error_head,error_tail){
    result = "\0";
    if(len < 1){
        throw error_wordslen();
        return 0;
    }
    try{
        init();
    }
    catch(error_room& e){
        throw e;
        return 0;
    }
    for(int i = 0; i < len; i++){
        if(insert(words[i]) == -1)
            return 0;
    }
    int request;
    char str[2];
    try {
        request = check_head_and_tail(head, tail, str);
    }
    catch(error_head& e){
        throw e;
    }
    catch(error_tail& e){
        throw e;
    }
    if(request == -1)
        return 0;
    seconds1 = time(NULL);
    int k = longestLetter(2,request,result,str);
    return k;
}

int
core::gen_chain_char(string words[], int len, string& result, char head, char tail) throw(error_room,error_wordslen,error_head,error_tail){
    result = "\0";
    if(len < 1){
        throw error_wordslen();
        return 0;
    }
    try{
        init();
    }
    catch(error_room& e){
        throw e;
        return 0;
    }
    for(int i = 0; i < len; i++){
        if(insert(words[i]) == -1)
            return 0;
    }
    int request;
    char str[2];
    try {
        request = check_head_and_tail(head, tail, str);
    }
    catch(error_head& e){
        throw e;
    }
    catch(error_tail& e){
        throw e;
    }
    if(request == -1)
        return 0;
    seconds1 = time(NULL);
    int k=longestLetter(1,request,result,str);
    return k;
}

int
core::gen_n_chain(string words[], int len, int n, fstream& fout, char head, char tail) throw(error_room,error_n,error_wordslen,error_fp,error_words_n,error_head,error_tail){
   // try {
        if(n > len || n <= 1){
            throw error_n();
            return 0;
        }
    //}
    //catch(error_n& e){
         //cout<<e.what();
        // throw error_n();
        // return 0;
   // }
        if(len < 1){
            throw error_wordslen();
            return 0;
        }
    if(!fout.is_open()){
        throw error_fp();
        //fout.open("solution.txt",ios::out);
        return 0;
    }

    fout<<"               \n";//为存放所得结果的个数预留空间
    try{
        init();
    }
    catch(error_room& e){
        throw e;
        return 0;
    }
    int num = 0;//记录有效单词的个数
    int m;
    for(int i = 0; i < len; i++){
        m = insert(words[i]);
        if(m == -1)
            return 0;
        else if(m == 1)
            num ++;
    }
    if(num < n){
        fout.seekp(0,ios::beg);
        throw error_words_n();
        return 0;
    }
    int request;
    char str[2];
    try {
        request = check_head_and_tail(head, tail, str);
    }
    catch(error_head& e){
        throw e;
    }
    catch(error_tail& e){
        throw e;
    }
    if(request == -1){
        fout.seekp(0,ios::beg);
        fout << 0;

        return 0;
    }
    seconds1 = time(NULL);
    int count = N_longestLetter(request,n,str,fout);
    fout.seekp(0,ios::beg);
    fout << count;
    return count;
}


int
core::testforinsert(string words[], int len){//测试插入函数
    init();
    for(int i = 0; i < len; i++){
        if(insert(words[i]) == -1)
            exit(0);
    }
    int num = 26 * 26;
    int flag;
    wnode * p;
    for(int i = 0; i < num; i ++){
        flag = 0;
        p = head[i].first;
        if(p != NULL)
            cout << "the bucket is:" << (char)('a'+i/26) << '-' << (char)('a'+i%26) << "  ";
        while(p != NULL){
            cout << p->word + "->";
            p = p->next;
            flag = 1;
        }
        if(flag)
            cout << "NULL" << endl;
    }
    return 0;
}
