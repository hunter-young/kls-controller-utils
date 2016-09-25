#include <stdio.h>
#include <string.h>

#include "controllerdata.h"

uint8_t _calculate_CRC(struct generic_packet *pkt) {
    uint8_t checksum = 0;

    for(int i = 0; i < CRC_INDEX; i++) {
        checksum += pkt->bytes[i];
    }

    return checksum;
}

bool _validate_checksum(struct generic_packet *pkt) {
    return (_calculate_CRC(pkt) == pkt->bytes[CRC_INDEX]);
}

enum packet_t _determine_packet_type(struct generic_packet *pkt) {
    if(pkt->bytes[0] == 0x3A) {
        return PACKET_A;
    }
    else if (pkt->bytes[0] == 0x3B) {
        return PACKET_B;
    }
    else {
        return ERROR;
    }
}

void _bytes_to_packet(struct generic_packet *pkt, uint8_t *bytes) {
    for(int i = 0; i < PACKET_LENGTH; i++) {
        pkt->bytes[i] = bytes[i];
    }
}

void import_bytes_to_packets(_packets_struct *pkts, uint8_t *bytes) {
    struct generic_packet gpkt;
    _bytes_to_packet(&gpkt, bytes);

    if(_validate_checksum(&gpkt)) {
        switch(_determine_packet_type(&gpkt)) {
            case PACKET_A:
                memcpy(&(pkts->a), &gpkt, sizeof(struct packet_a));
                break;
            case PACKET_B:
                memcpy(&(pkts->b), &gpkt, sizeof(struct packet_b));
                break;
            default:
                break;
        }
    }
}
