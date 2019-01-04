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
private:
    bool usable = true;
    MPI_Request request_tag = MPI_REQUEST_NULL;
    MsgMeta<T, N> msgMeta;

public:
    Msg();
    bool isFree();
    void makeUnusable();

    MsgMeta<T, N> &getMsgData();
};

template<typename T, size_t N>
Msg<T, N>::Msg() {}

template<typename T, size_t N>
bool Msg<T, N>::isFree() {
    int tag = 0;
    MPI_Status status;
    MPI_Test(this->request_tag, &tag, &status);
    if (tag == 1) { // todo status.MPI_ERROR status.tag status.MPI_TAG
        return true;
    }
    return false;
}

template<typename T, size_t N>
void Msg<T, N>::makeUnusable() {
    this->usable = false;
}

template<typename T, size_t N>
MsgMeta<T, N> &Msg<T, N>::getMsgData() {
    return this->msgMeta;
}


#endif //MPI_MSG_POOL_MSG_H
