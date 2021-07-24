//
// Created by Swagger on 2021/7/24.
//

#include "../include/sds.h"
#include <cstring>

#define M_1 1024 * 1024


sds::sds()
:   len_(0),
    free_(0x10)
{
    data_ = new char[0x10 + 1];
}

sds::sds(char* target)
:   data_(nullptr),
    len_(-1),
    free_(-1)
{
    int len = ::strlen(target) + 1;
    data_ = new char[len];
    strcpy(target, data_);
    data_[len] = '\0';
    len_ = len - 1;
    free_ = 0;

}

sds::~sds() {
    delete data_;
}


int sds::strlen() {
    return len_;
}

char* sds::getBuf() {
    return data_;
}

void sds::reAlloc(int len) {
    char* tmp;
    if ( len < M_1 ){ // 小于1兆情况
        tmp = new char[len * 2 + 1];
        free_ = len * 2 - len_; // 计算剩余长度
    }else {
        tmp = new char[len + M_1 + 1];
        free_ = len + M_1 - len_;
    }
    ::strcpy(tmp, data_);
    tmp[len] = '\0';
    delete data_;
    data_ = tmp;

}

void sds::strcat(sds *right) {
    /* 长度不够的情况 */
    if ( free_ < right->strlen() ){
        int total_len = len_ + right->strlen();
        reAlloc(total_len);
    }
    ::strcpy(data_ + len_, right->getBuf());

}

int sds::sdsAvail() {
    return free_;
}

void sds::sdsClear() {
    free_ += len_;
    len_ = 0;
    data_[0] = '\0';
}



