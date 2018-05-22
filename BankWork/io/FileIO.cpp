/**
 * @file
 * 文档见 io/FileIO.h
 */

#include "FileIO.h"

void FileIO::SetDoInput(bool flag) {
    if (flag)
        file_in.open(file_name);
    else
        file_in.close();
}

void FileIO::SetDoOutput(bool flag) {
    if (flag)
        file_out.open(file_name);
    else
        file_out.close();
}

ifstream &FileIO::GetInputStream() {
    return file_in;
}

ofstream &FileIO::GetOutputStream() {
    return file_out;
}

FileIO::FileIO(string file_name) : file_name(file_name) {}
