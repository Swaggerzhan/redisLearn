//
// Created by Swagger on 2021/7/24.
//

#ifndef REDISLEARN_SDS_H
#define REDISLEARN_SDS_H


class sds{
public:

    sds(char* target);
    sds();
    ~sds();

    int strlen();
    void strcat(sds* right);
    char* getBuf();
    int sdsAvail();
    void sdsClear();

private:
    /**
     * 重新分配空间，并且复制内容到新空间去
     * @param len 为长度，当len小于1M时，分配的空间将是字符串长度的一倍，即2*len
     * 当空间大约1M时，多分配1M空间，即len + 1M
     **/
    void reAlloc(int len);

    /* data总长度需要+1，多出来的部分为'\0' */
    char* data_;
    int len_;           // 字符串长度
    int free_;          // 字符串剩余可用长度

};


#endif //REDISLEARN_SDS_H
