//
// Created by wujiahao on 2019-01-05.
//


#include <iostream>
#include "../src/recv_msg_pool.h"
#include "../src/send_msg_pool.h"

class MPIProcess {
public:
    MPI_Comm mpi_comm = MPI_COMM_WORLD;
    int pid;
    int prank;
};

MPIProcess initMPI(int *argc, char ***argv) {
    MPIProcess mpiProcess;
    MPI_Init(argc, argv);
    MPI_Comm_rank(mpiProcess.mpi_comm, &mpiProcess.pid);
    MPI_Comm_size(mpiProcess.mpi_comm, &mpiProcess.prank);
    return mpiProcess;
}

//void print_msgs(int pid, )

void example_sum(MPIProcess &mpiProcess) {
    std::cout << "example 1: mpi 100 sum" << std::endl;
    RecvMsgPool<int, 1> recvMsgPool(mpiProcess.prank, mpiProcess.mpi_comm);
    SendMsgPool<int, 1> sendMsgPool(mpiProcess.prank, mpiProcess.mpi_comm);
    int send_count = 0;
    int recv_count = 0;
    while (true) {
        if (send_count < 100) {
            sendMsgPool.send(&send_count, mpiProcess.prank-mpiProcess.pid-1, 200);
            send_count += 1;
        }
        if (recv_count >= 100) {
            break;
        }
        std::vector<MsgMeta<int, 1>> msgs = recvMsgPool.recv(mpiProcess.prank-mpiProcess.pid-1, MPI_ANY_TAG);
        std::cout << "P" << mpiProcess.pid << ":now_recv_count=" << msgs.size()
                  << ",recv_count=" << recv_count << std::endl;
        for (int i = 0; i < msgs.size(); ++i) {

        }
        recv_count += msgs.size();
    }
}

int main(int argc, char *argv[])
{
    MPIProcess mpiProcess = initMPI(&argc, &argv);
    example_sum(mpiProcess);
}

