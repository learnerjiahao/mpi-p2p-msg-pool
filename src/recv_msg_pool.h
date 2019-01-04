//
// Created by wujiahao on 2019-01-04.
//

#ifndef MPI_MSG_POOL_RECV_MSG_POOL_H
#define MPI_MSG_POOL_RECV_MSG_POOL_H

#include <vector>
#include "msg_pool.h"

template <typename T, std::size_t N>
class RecvMsgPool : public MsgPool<T, N> {
public:
    std::vector<Msg<T, N>> recv(int src_pid, int comm_tag);
};


#endif //MPI_MSG_POOL_RECV_MSG_POOL_H
