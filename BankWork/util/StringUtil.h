#ifndef BANKWORK_UTIL_H
#define BANKWORK_UTIL_H

#include <string>

using namespace std;

/**
 * 字符串工具类
 */
namespace StringUtil {
    /**
     * 全局替换文本
     * @param 源文本
     * @param 被替换的文本
     * @param 替换的文本
     * @return 全局替换后的文本
     */
    string ReplaceAll(string, string, string);

    /**
     * 从标准输入流中读入一行，并替换空格
     * @return 替换空格后的文本
     */
    string ReadLineWithoutSpace(string);

    /**
     * 替换指定文本为空格
     * @return 替换后的文本
     */
    string ReplaceWithSpace(string, string);

    /**
     * 计算字符串的hash
     * @file 计算出的hash
     */
    string GetHash(string s);

    /**
     * 读入一行非空文本
     * @return 读入的一行文本
     */
    string ReadLine();
    /**
     * 读取一行，不保证非空
     * @return 一行的文本
     */
    string GetLine();
    /**
     * 暂停程序，等待用户输入回车
     * @param 等待回车个数
     */
    void Pause(int c=2);
};

#endif //BANKWORK_UTIL_H
