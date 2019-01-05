//
// Created by wujiahao on 2019-01-03.
//

#ifndef MPI_MSG_POOL_MSG_POOL_H
#define MPI_MSG_POOL_MSG_POOL_H

#include <list>
#include "msg.h"
template <typename T, std::size_t N>
class MsgPool {
protected:
    std::list<Msg<T, N>> msgs;
    MPI_Comm mpi_comm;
    Msg<T, N> &newMsg();

public:
    MsgPool(std::size_t _init_cap);
};

template<typename T, size_t N>
MsgPool<T, N>::MsgPool(std::size_t _init_cap) {
    this->msgs.resize(_init_cap);
}

template<typename T, size_t N>
Msg<T, N> &MsgPool<T, N>::newMsg() {
    this->msgs.push_back(Msg<T, N>());
    return this->msgs.back();
}


#endif //MPI_MSG_POOL_MSG_POOL_H
