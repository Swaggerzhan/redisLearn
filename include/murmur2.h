//
// Created by Swagger on 2021/7/24.
//

#ifndef REDISLEARN_MURMUR2_H
#define REDISLEARN_MURMUR2_H

#include <cstdint>
// for test
#define HASH_SEED 1000

uint32_t MurmurHash2 (const void* key, int len, uint32_t seed);

#endif //REDISLEARN_MURMUR2_H
