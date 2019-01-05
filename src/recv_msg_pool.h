//
// Created by wujiahao on 2019-01-04.
//

#ifndef MPI_MSG_POOL_RECV_MSG_POOL_H
#define MPI_MSG_POOL_RECV_MSG_POOL_H

#include <vector>
#include "msg_pool.h"

#define INFINITE_MSG_NUM -1  // -1 means infinite
template <typename T, std::size_t N>
class RecvMsgPool : public MsgPool<T, N> {
public:
    std::vector<MsgMeta<T, N>> recv(int src_pid, int comm_tag);
    std::vector<MsgMeta<T, N>> recvDynInc(int src_pid, int comm_tag);
    RecvMsgPool(std::size_t _init_cap, MPI_Comm _mpi_comm);
    void setMaxMsgNum(int _maxMsgNum);

private:
    int useMsg2Recv(Msg<T, N> &msg, int src_pid, int comm_tag);
    int maxMsgNum = INFINITE_MSG_NUM;
};

template<typename T, size_t N>
std::vector<MsgMeta<T, N>> RecvMsgPool<T, N>::recv(int src_pid, int comm_tag) {
    std::vector<MsgMeta<T, N>> ret_msgs;
    for (Msg<T, N> &msg : this->msgs) {
        if (msg.hadFinishedLastComm()) {
            if ((src_pid == MPI_ANY_SOURCE || src_pid == msg.msgMeta.opp_pid)
                && ((comm_tag == MPI_ANY_TAG || src_pid == msg.msgMeta.mpi_tag))) {
                ret_msgs.push_back(msg.msgMeta);
                // msg can be reused to listen only when
                // this msg had finished last communication and the data had been return
                this->useMsg2Recv(msg, MPI_ANY_SOURCE, MPI_ANY_TAG);
            }
        }
    }
    return ret_msgs;
}


template<typename T, size_t N>
std::vector<MsgMeta<T, N>> RecvMsgPool<T, N>::recvDynInc(int src_pid, int comm_tag) {
    std::vector<MsgMeta<T, N>> ret_msgs = recv(src_pid, comm_tag);
    if (ret_msgs.size() <= 0) {  // todo whether set max msg size
        this->useMsg2Recv(this->newMsg(), MPI_ANY_SOURCE, MPI_ANY_TAG);
    }
    return ret_msgs;
}

template<typename T, size_t N>
RecvMsgPool<T, N>::RecvMsgPool(std::size_t _init_cap, MPI_Comm _mpi_comm)
                        : MsgPool<T, N>(_init_cap, _mpi_comm) {
    for (Msg<T, N> &msg : this->msgs) {
        this->useMsg2Recv(msg, MPI_ANY_SOURCE, MPI_ANY_TAG);
    }
}

template<typename T, size_t N>
int RecvMsgPool<T, N>::useMsg2Recv(Msg<T, N> &msg, int src_pid, int comm_tag) {
    return MPI_Irecv(msg.msgMeta.data.data(), N * sizeof(T), MPI_BYTE,
                     src_pid, comm_tag, this->mpi_comm, &msg.request_tag);;
}

template<typename T, size_t N>
void RecvMsgPool<T, N>::setMaxMsgNum(int _maxMsgNum) {
    this->maxMsgNum = _maxMsgNum;
}

#endif //MPI_MSG_POOL_RECV_MSG_POOL_H
