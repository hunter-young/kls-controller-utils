#ifndef CONTROLLERDATA_H
#define CONTROLLERDATA_H

#include <stdint.h> 				/* fixed width integers */
#include <stdbool.h>				/* bool type */

enum packet_t { PACKET_A, PACKET_B };

/* Actual network packet */
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

uint8_t 		_calculate_CRC(struct packet *pkt);
bool 		    validate_checksum(struct packet *pkt);
packet_t 		determine_packet_type(struct packet *pkt);


#endif
