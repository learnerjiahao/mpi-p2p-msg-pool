//
// Created by wujiahao on 2019-01-04.
//

#ifndef MPI_MSG_POOL_MSG_META_H
#define MPI_MSG_POOL_MSG_META_H

#include <vector>
template <typename T, std::size_t N>
class MsgMeta {
public:
    int opp_pid;
    int ptag;
    std::vector<T> data;
    MsgMeta();
};

template<typename T, size_t N>
MsgMeta<T, N>::MsgMeta() {
    this->data.resize(N);
}


#endif //MPI_MSG_POOL_MSG_META_H
