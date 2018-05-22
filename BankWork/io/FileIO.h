#ifndef BANKWORK_FILEIO_H
#define BANKWORK_FILEIO_H

#include <fstream>
#include <string>

using namespace std;

/**
 * 文件IO类
 */
class FileIO {
public:
    /**
     * 使用文件名创建实例
     * @param 相对于运行目录的文件名
     */
    explicit FileIO(string);

    /**
     * 设置是否启用输入
     */
    void SetDoInput(bool);

    /**
     * 设置是否启用输出
     */
    void SetDoOutput(bool);

    /**
     * 获得文件输入流
     * @return 文件输入流
     */
    ifstream &GetInputStream();

    /**
     * 获得文件输出流
     * @return 文件输出流
     */
    ofstream &GetOutputStream();

private:
    /**
     * 文件名
     * @note 相对于运行目录
     */
    string file_name;
    /**
     * 文件输入流
     */
    ifstream file_in;
    /**
     * 文件输出流
     */
    ofstream file_out;
};


#endif //BANKWORK_FILEIO_H
