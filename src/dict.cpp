//
// Created by Swagger on 2021/7/24.
//

#include "../include/dict.h"

#define HASH_LEN 0x20

struct dictEntry{

    void *key;              // 键
    void *value;            // 值

    struct dictEntry* next; // 指向下一个节点
};


dictht::dictht() {

}

dictht::~dictht() {

}


dict::dict()
:   reHashIdx_(-1)
{
    ht_[0].table = new dictEntry*[HASH_LEN];
    ht_[1].table = nullptr;
}


dict::~dict() {

}