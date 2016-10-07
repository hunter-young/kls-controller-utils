#ifndef CONTROLLERDATA_H
#define CONTROLLERDATA_H

#include <stdint.h> 				/* fixed width integers */
#include <stdbool.h>				/* bool type */

#define PACKET_LENGTH   19
#define CRC_INDEX       18
#define ERROR           -1

enum packet_t { PACKET_A, PACKET_B };

struct packet_a {
	uint8_t 	command;
	uint8_t 	static_var;
	uint8_t 	throttle;
	uint8_t 	brake_pedal;
	uint8_t 	brake_switch;
	uint8_t 	foot_switch;
	uint8_t		forward_switch;
	bool 		reverse;
	bool 		hall_a;
	bool 		hall_b;
	bool 		hall_c;
	uint8_t 	battery_voltage;
	uint8_t 	motor_temp;
	uint8_t 	controller_temp;
	bool 		setting_dir;
	bool 		actual_dir;
	uint8_t 	unknown_1;
	uint8_t 	unknown_2;
	uint8_t     crc;
};

struct packet_b {
    uint8_t     padding_1;
    uint8_t     padding_2;
    uint8_t     padding_3;
    uint8_t     padding_4;
    uint16_t    rpm;
    uint16_t    phase_current;
    uint8_t     padding_5;
    uint8_t     padding_6;
    uint8_t     padding_7;
    uint8_t     padding_8;
    uint8_t     padding_9;
    uint8_t     padding_10;
    uint8_t     padding_11;
    uint8_t     padding_12;
    uint8_t     padding_13;
    uint8_t     padding_14;
    uint8_t     crc;
};

struct generic_packet {
    uint8_t     bytes[PACKET_LENGTH];
};

typedef struct {
    struct packet_a a;
    struct packet_b b;
} _packets_struct;

_packets_struct packets;

uint8_t 		_calculate_CRC(struct generic_packet *pkt);
bool 		    _validate_checksum(struct generic_packet *pkt);
enum packet_t 	_determine_packet_type(struct generic_packet *pkt);
void            _bytes_to_packet(struct generic_packet *pkt, uint8_t *bytes);
void            import_bytes_to_packets(_packets_struct *pkts, uint8_t *bytes);

#endif
