#ifndef CM_CAN_ID_H
#define CM_CAN_ID_H

#include <stdio.h>
#include <sys/types.h>
#include <stdint.h>

#define     IPC_NODE_MAC_ID						0x01
#define     PB_MASTER_NODE_MAC_ID				0x50
#define     PB_SUB_NODE_MAC_ID					0x51

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
typedef union {
    struct {
        uint32_t Reserve     : 3;
        uint32_t SrcMacID    : 8;
        uint32_t DstMacID    : 8;
        uint32_t Ack         : 1;
        uint32_t FuncID      : 4;
        uint32_t SourceID    : 8;
    } can_id_stru;
    uint32_t can_id;
} can_id_union;
#else
typedef union {
    struct {
        uint32_t SourceID    : 8;
        uint32_t FuncID      : 4;
        uint32_t Ack         : 1;
        uint32_t DstMacID    : 8;
        uint32_t SrcMacID    : 8;
        uint32_t Reserve     : 3;
    } can_id_stru;
    uint32_t can_id;
} can_id_union;
#endif

#endif

