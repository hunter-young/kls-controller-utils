#include <stdio.h>
#include <stdint.h>

#include "include/controllerdata.h"

int main() {
    /* Pretend this came from Serial.read() */
    uint8_t serial_data_in[] = { 0x3A, 0x10, 0x2D, 0x05, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x3B, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0xC6, 0x00 };

    import_bytes_to_packets(&packets, serial_data_in);

    uint8_t serial_data_in2[] = { 0x3B, 0x10, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15 };

    import_bytes_to_packets(&packets, serial_data_in2);

    puts("PACKET A VALUES");
    printf("Command: %i\n", packets.a.command);
    printf("Static var: %i\n", packets.a.static_var);
    printf("Throttle: %i\n", packets.a.throttle);
    printf("Brake_pedal: %i\n", packets.a.brake_pedal);
    printf("Foot switch: %i\n", packets.a.foot_switch);
    printf("Forward switch: %i\n", packets.a.forward_switch);
    printf("reverse: %i\n", packets.a.reverse);
    printf("hall_a: %i\n", packets.a.hall_a);
    printf("hall_b: %i\n", packets.a.hall_b);
    printf("hall_c: %i\n", packets.a.hall_c);
    printf("battery_voltage: %i\n", packets.a.battery_voltage);
    printf("motor_temp: %i\n", packets.a.motor_temp);
    printf("controller_temp: %i\n", packets.a.controller_temp);
    printf("setting_dir: %i\n", packets.a.setting_dir);
    printf("actual_dir: %i\n", packets.a.actual_dir);
    printf("crc: %i\n", packets.a.crc);

    puts("PACKET B VALUES");
    printf("RPM: %i\n", packets.b.rpm);
    printf("Phase current: %i\n", packets.b.phase_current);
    printf("crc: %i\n", packets.b.crc);
}
