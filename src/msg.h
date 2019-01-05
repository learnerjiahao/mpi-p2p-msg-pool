//
// Created by wujiahao on 2019-01-04.
//

#ifndef MPI_MSG_POOL_MSG_H
#define MPI_MSG_POOL_MSG_H

#include <array>
#include <mpi.h>
#include "msg_meta.h"

template <typename T, std::size_t N>
class Msg {
public:
    MPI_Request request_tag = MPI_REQUEST_NULL;
    MsgMeta<T, N> msgMeta;

public:
    Msg();
    bool hadFinishedLastComm();
};

template<typename T, size_t N>
Msg<T, N>::Msg() {}

template<typename T, size_t N>
bool Msg<T, N>::hadFinishedLastComm() {
    int tag = 0;
    MPI_Status status;
    MPI_Test(this->request_tag, &tag, &status);
    if (tag == 1) {
        this->msgMeta.mpi_tag = status.MPI_TAG;
        this->msgMeta.opp_pid = status.MPI_SOURCE;
        return true;
    }
    return false;
}

#endif //MPI_MSG_POOL_MSG_H
