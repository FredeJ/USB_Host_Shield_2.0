/* Copyright (C) 2012 Kristian Lauszus, TKJ Electronics. All rights reserved.
 
 This software may be distributed and modified under the terms of the GNU
 General Public License version 2 (GPL2) as published by the Free Software
 Foundation and appearing in the file GPL2.TXT included in the packaging of
 this file. Please note that GPL2 Section 2[b] requires that all works based
 on this software must also be made publicly available under the terms of
 the GPL2 ("Copyleft").
 
 Contact information
 -------------------
 
 Kristian Lauszus, TKJ Electronics
 Web      :  http://www.tkjelectronics.com
 e-mail   :  kristianl@tkjelectronics.com
 */

#ifndef _ps3enums_h
#define _ps3enums_h

#include "controllerEnums.h"

const uint8_t LEDS[] PROGMEM = {
    0x01, // LED1
    0x02, // LED2
    0x04, // LED3
    0x08, // LED4
    
    0x09, // LED5
    0x0A, // LED6
    0x0C, // LED7
    0x0D, // LED8
    0x0E, // LED9
    0x0F // LED10
};
const uint32_t BUTTONS[] PROGMEM = {
    0x10, // UP
    0x20, // RIGHT
    0x40, // DOWN
    0x80, // LEFT

    0x01, // SELECT
    0x02, // L3
    0x04, // R3
    0x08, // START
    
    0x0100, // L2
    0x0200, // R2
    0x0400, // L1
    0x0800, // R1

    0x1000, // TRIANGLE
    0x2000, // CIRCLE
    0x4000, // CROSS
    0x8000, // SQUARE
    
    0x010000, // PS   
    0x080000, // MOVE - covers 12 bits - we only need to read the top 8
    0x100000 // T - covers 12 bits - we only need to read the top 8
};

const uint8_t ANALOGBUTTONS[] PROGMEM = {
    // Note that the location is shiftet 9 when it's connected via USB    
    // Sixaxis Dualshcock 3 & Navigation controller
    23, // UP_ANALOG
    24, // RIGHT_ANALOG
    25, // DOWN_ANALOG
    26, // LEFT_ANALOG
    0,0,0,0, // Skip SELECT, L3, R3 and START
    
    27, // L2_ANALOG
    28, // R2_ANALOG
    29, // L1_ANALOG
    30, // R1_ANALOG
    31, // TRIANGLE_ANALOG
    32, // CIRCLE_ANALOG
    33, // CROSS_ANALOG
    34, // SQUARE_ANALOG
    0,0, // Skip PS and MOVE
    
    // Playstation Move Controller
    15 // T_ANALOG - Both at byte 14 (last reading) and byte 15 (current reading)
};

enum Colors {
    // Used to set the colors of the move controller
    Red = 0xFF0000, // r = 255, g = 0, b = 0
    Green = 0xFF00, // r = 0, g = 255, b = 0
    Blue = 0xFF, // r = 0, g = 0, b = 255
    
    Yellow = 0xFFEB04, // r = 255, g = 235, b = 4
    Lightblue = 0xFFFF, // r = 0, g = 255, b = 255
    Purble = 0xFF00FF, // r = 255, g = 0, b = 255
    
    White = 0xFFFFFF, // r = 255, g = 255, b = 255
    Off = 0x00, // r = 0, g = 0, b = 0
};
enum Sensor {
    // Note that the location is shiftet 9 when it's connected via USB
    // Sensors inside the Sixaxis Dualshock 3 controller
    aX = 50,
    aY = 52,
    aZ = 54,
    gZ = 56,
    
    // Sensors inside the Move Motion controller
    aXmove = 28,
    aZmove = 30,
    aYmove = 32,
    
    gXmove = 40,
    gZmove = 42,
    gYmove = 44,
    
    tempMove = 46,
    
    mXmove = 47,
    mZmove = 49,
    mYmove = 50,
};
enum Angle {
    // Used to get the angle calculated using atan2
    Pitch = 0x01,
    Roll = 0x02,
};
enum Status {
    // Note that the location is shiftet 9 when it's connected via USB
    // Byte location | bit location
    Plugged = (38 << 8) | 0x02,
    Unplugged = (38 << 8) | 0x03,
    
    Charging = (39 << 8) | 0xEE,
    NotCharging = (39 << 8) | 0xF1,
    Shutdown = (39 << 8) | 0x01,
    Dying = (39 << 8) | 0x02,
    Low = (39 << 8) | 0x03,
    High = (39 << 8) | 0x04,
    Full = (39 << 8) | 0x05,
    
    MoveCharging = (21 << 8) | 0xEE,
    MoveNotCharging = (21 << 8) | 0xF1,
    MoveShutdown = (21 << 8) | 0x01,
    MoveDying = (21 << 8) | 0x02,
    MoveLow = (21 << 8) | 0x03,
    MoveHigh = (21 << 8) | 0x04,
    MoveFull = (21 << 8) | 0x05,
    
    CableRumble = (40 << 8) | 0x10,//Opperating by USB and rumble is turned on
    Cable = (40 << 8) | 0x12,//Opperating by USB and rumble is turned off
    BluetoothRumble = (40 << 8) | 0x14,//Opperating by bluetooth and rumble is turned on
    Bluetooth = (40 << 8) | 0x16,//Opperating by bluetooth and rumble is turned off
};
enum Rumble {    
    RumbleHigh = 0x10,
    RumbleLow = 0x20,
};

#endif