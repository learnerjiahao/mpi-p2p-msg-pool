//
// Created by wujiahao on 2019-01-04.
//

#ifndef MPI_MSG_POOL_MSG_H
#define MPI_MSG_POOL_MSG_H

#include <array>
template <typename T, std::size_t N>
class Msg {
public:
    int ptag;
    std::array<T, N> data;
    Msg(T _data, int _ptag);
    Msg(int _ptag);
};

template <typename T, std::size_t N>
Msg<T, N>::Msg(T _data, int _ptag) : data(_data), ptag(_ptag) {}

template <typename T, std::size_t N>
Msg<T, N>::Msg(int _ptag) : ptag(_ptag) {}


#endif //MPI_MSG_POOL_MSG_H
