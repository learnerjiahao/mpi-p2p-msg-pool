//
// Created by wujiahao on 2019-01-05.
//

#ifndef MPI_MSG_POOL_SEND_MSG_POOL_H
#define MPI_MSG_POOL_SEND_MSG_POOL_H

#include "msg_pool.h"

template <typename T, std::size_t N>
class SendMsgPool : public MsgPool<T, N> {
public:
    int send(const T *data, int dest_pid, int mpi_tag);
    SendMsgPool(std::size_t _init_cap, MPI_Comm _mpi_comm);
private:
    int useMsg2Send(Msg<T, N> &msg, int dest_pid, int comm_tag);
};

template<typename T, size_t N>
SendMsgPool<T, N>::SendMsgPool(std::size_t _init_cap, MPI_Comm _mpi_comm)
                                : MsgPool<T, N>(_init_cap, _mpi_comm) {}

template<typename T, size_t N>
int SendMsgPool<T, N>::send(const T *data, int dest_pid, int mpi_tag) {
    Msg<T, N> *p_msg = nullptr;
    for (Msg<T, N> &msg : this->msgs) {
        if (msg.hadFinishedLastComm()) {
            p_msg = &msg;
            break;
        }
    }
    if (p_msg == nullptr) {
        p_msg = &this->newMsg();
    }

    return this->useMsg2Send(*p_msg, dest_pid, mpi_tag);
}

template<typename T, size_t N>
int SendMsgPool<T, N>::useMsg2Send(Msg<T, N> &msg, int dest_pid, int comm_tag) {
    return MPI_Isend(msg.msgMeta.data.data(), N * sizeof(T),
            MPI_BYTE, dest_pid, comm_tag, this->mpi_comm, &msg.request_tag);
}


#endif //MPI_MSG_POOL_SEND_MSG_POOL_H
