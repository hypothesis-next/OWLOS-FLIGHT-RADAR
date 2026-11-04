#pragma once

/* touch, whatever the board has (touch.c). named tp_* because touch_init/touch_read
 * already exist in ESP-IDF's librtc.a (for the ESP32's own touch pads) and the names clash */

void tp_init(void);                 // after disp_init, the 3.5" board shares the LCD bus
// returns 1 and raw chip values while pressed, 0 if not
int  tp_read(int *rx, int *ry);
// raw units the chip gives across the screen, to sanity check a stored alignment. after tp_init:
// the 3.5" board finds out there which touch it has
int  tp_raw_span(void);
/* power off (board.h RADAR_POWER_OFF). standby: the chip in power down with its pen interrupt on,
 * 0: this board can't be woken by a touch. up: T_IRQ is high, nothing presses the panel */
int  tp_pen_standby(void);
int  tp_pen_up(void);
