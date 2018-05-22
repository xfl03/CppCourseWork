/**
 * @file
 * 文档见util/StringUtil.h
 */
#include <string>
#include <iostream>
#include <sstream>
#include "StringUtil.h"

using namespace std;

string StringUtil::ReplaceAll(string source, string replacement, string replaceWith) {
    string t = source;
    unsigned long long begin = 0;//记录找到的位置
    while ((begin = t.find(replacement, begin)) != string::npos) {
        t.replace(begin, 1, replaceWith);//进行替换
    }
    return t;
}

string StringUtil::ReadLineWithoutSpace(string replaceWith) {
    string t = ReadLine();
    return ReplaceAll(t, " ", replaceWith);
}


string StringUtil::ReplaceWithSpace(string source, string replacement) {
    return ReplaceAll(source, replacement, " ");
}

string StringUtil::GetHash(string s) {
    //计算hash
    hash<string> hash_fn;
    size_t hash = hash_fn(s);

    //生成并返回字符串
    char buffer[64];
    ostringstream oss(buffer);
    oss << hash;
    return oss.str();
}

string StringUtil::ReadLine() {
    string t;
    while (getline(cin, t) && t.empty());//Read until not empty
    return t;
}

string StringUtil::GetLine() {
    string t;
    getline(cin, t);
    return t;
}

void StringUtil::Pause(int c) {
    cout << "请按回车键继续...";
    while (c--)//c->1
        StringUtil::GetLine();
}
