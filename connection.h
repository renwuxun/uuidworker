//
// Created by mofan on 1/30/16.
//

#ifndef UUIDWORKER_CONNECTION_H
#define UUIDWORKER_CONNECTION_H


#include <unistd.h>
#include <stdlib.h>
#include "lib/wxworker.h"


struct connection_s {
    struct wx_conn_s wx_conn;
    struct wx_timer_s close_timer;
    struct wx_buf_s recvbuf;
    struct wx_buf_s sendbuf;
    char bufchainwithbuf[sizeof(struct wx_buf_chain_s) + 128];
    struct connection_s* next;
    int keepalivems;
    int inuse;
};


int connections_alloc(struct wx_worker_s* wk, uint32_t count);
void connections_free();
struct connection_s* connection_get();
void connection_put(struct connection_s* conn);


#endif //UUIDWORKER_CONNECTION_H
