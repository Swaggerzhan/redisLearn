//
// Created by Swagger on 2021/7/24.
//

#ifndef REDISLEARN_DICT_H
#define REDISLEARN_DICT_H

#include "murmur2.h"


struct dictEntry; // 哈希表节点

/* 哈希表 */
class dictht{
public:

    dictht();
    ~dictht();

public:

    dictEntry** table;
    unsigned long size;                // 哈希表大小

    unsigned long sizeMask;            // 哈希表大小掩码，用于计算索引值，总是等于size-1

    unsigned long used;                // 已经使用的节点数量
};


class dict{
public:

    dict();
    ~dict();

    // 添加键值到字典中
    void dictAdd(void* arg);

    // 添加，如果键值已存在，则覆盖值
    void dictReplace(void* arg);

    // 通过对应键返回响应值
    void* dictFetchValue(void* arg);

    // 删除对应键的数据
    void dictDelete(void* arg);

private:

    dictht ht_[2];                      // 两个表，实际上只使用一个，另外一个用于扩展

    int reHashIdx_;                     // 记录扩展或者缩小状态进度


};



#endif //REDISLEARN_DICT_H
