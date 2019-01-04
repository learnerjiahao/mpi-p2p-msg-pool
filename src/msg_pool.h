//
// Created by wujiahao on 2019-01-03.
//

#ifndef MPI_MSG_POOL_MSG_POOL_H
#define MPI_MSG_POOL_MSG_POOL_H

#include <list>
#include "msg.h"

template <typename T, std::size_t N>
class MsgPool {
private:
    std::list<Msg<T, N>> msgs;
    MsgPool(std::size_t _init_cap);
};

template<typename T, size_t N>
MsgPool<T, N>::MsgPool(std::size_t _init_cap) {
    this->msgs.resize(_init_cap);
}


#endif //MPI_MSG_POOL_MSG_POOL_H
