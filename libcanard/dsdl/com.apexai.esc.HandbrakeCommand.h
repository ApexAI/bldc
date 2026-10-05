#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define COM_APEXAI_ESC_HANDBRAKECOMMAND_MAX_SIZE 41
#define COM_APEXAI_ESC_HANDBRAKECOMMAND_SIGNATURE (0xBA8B90A44BEAA270ULL)
#define COM_APEXAI_ESC_HANDBRAKECOMMAND_ID 20080

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class com_apexai_esc_HandbrakeCommand_cxx_iface;
#endif

struct com_apexai_esc_HandbrakeCommand {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = com_apexai_esc_HandbrakeCommand_cxx_iface;
#endif
    struct { uint8_t len; uint16_t data[20]; }current_cA;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t com_apexai_esc_HandbrakeCommand_encode(struct com_apexai_esc_HandbrakeCommand* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool com_apexai_esc_HandbrakeCommand_decode(const CanardRxTransfer* transfer, struct com_apexai_esc_HandbrakeCommand* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _com_apexai_esc_HandbrakeCommand_encode(uint8_t* buffer, uint32_t* bit_ofs, struct com_apexai_esc_HandbrakeCommand* msg, bool tao);
static inline bool _com_apexai_esc_HandbrakeCommand_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct com_apexai_esc_HandbrakeCommand* msg, bool tao);
void _com_apexai_esc_HandbrakeCommand_encode(uint8_t* buffer, uint32_t* bit_ofs, struct com_apexai_esc_HandbrakeCommand* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
    const uint8_t current_cA_len = msg->current_cA.len > 20 ? 20 : msg->current_cA.len;
#pragma GCC diagnostic pop
    if (!tao) {
        canardEncodeScalar(buffer, *bit_ofs, 5, &current_cA_len);
        *bit_ofs += 5;
    }
    for (size_t i=0; i < current_cA_len; i++) {
        canardEncodeScalar(buffer, *bit_ofs, 16, &msg->current_cA.data[i]);
        *bit_ofs += 16;
    }
}

/*
 decode com_apexai_esc_HandbrakeCommand, return true on failure, false on success
*/
bool _com_apexai_esc_HandbrakeCommand_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct com_apexai_esc_HandbrakeCommand* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;
    if (!tao) {
        canardDecodeScalar(transfer, *bit_ofs, 5, false, &msg->current_cA.len);
        *bit_ofs += 5;
    } else {
        msg->current_cA.len = ((transfer->payload_len*8)-*bit_ofs)/16;
    }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
    if (msg->current_cA.len > 20) {
        return true; /* invalid value */
    }
#pragma GCC diagnostic pop
    for (size_t i=0; i < msg->current_cA.len; i++) {
        canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->current_cA.data[i]);
        *bit_ofs += 16;
    }

    return false; /* success */
}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct com_apexai_esc_HandbrakeCommand sample_com_apexai_esc_HandbrakeCommand_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(com_apexai_esc_HandbrakeCommand, COM_APEXAI_ESC_HANDBRAKECOMMAND_ID, COM_APEXAI_ESC_HANDBRAKECOMMAND_SIGNATURE, COM_APEXAI_ESC_HANDBRAKECOMMAND_MAX_SIZE);
#endif
#endif
