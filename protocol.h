//
// Created by izzy on 11/8/20.
//

#ifndef AGENT_PROTOCOL_H
#define AGENT_PROTOCOL_H

#include "constants.h"
#include "common.h"

#define TYPE_ACK 1
#define TYPE_ADD_FLOW_ROUTING 2
#define TYPE_REMOVE_FLOW_ROUTING 3
#define TYPE_TERMINATE 4

// Network Manager
#define TYPE_REGISTER_FLOW 5
#define TYPE_DELETE_FLOW 6

// Debug
#define TYPE_PRINT_STATE 99

typedef struct Ack_s {
    int data;
} Ack;

typedef struct FlowRouting_s {
    int spinesPort;
    int exitPoint;
} FlowRouting;

typedef struct RemoveFlowRouting_s {
    int srcAddr;
} RemoveFlowRouting;

typedef struct RegisterFlow_s {
    Location dst;
    Location switchAddr;
} RegisterFlow;

typedef struct DeleteFlow_s {
    int flowId;
} DeleteFlow;

typedef struct Message_s {
    int type;
    union {
        Ack ack;
        FlowRouting flowRouting;
        RemoveFlowRouting removeFlowRouting;
        RegisterFlow registerFlow;
        DeleteFlow deleteFlow;
    };
} Message;

#endif //AGENT_PROTOCOL_H
