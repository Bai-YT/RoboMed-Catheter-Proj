/*
 * Hi-Tech C I2C library for 12F1822
 * Master mode routines for I2C MSSP port to read and write to slave device
 * Copyright (C)2011 HobbyTronics.co.uk 2011
 * Freely distributable.
 */

#define I2C_WRITE 0
#define I2C_READ 1

// Initialise MSSP port. (12F1822 - other devices may differ)
void i2c_Init(void){
    
    // Initialise I2C MSSP
    // Master 100KHz
    TRISA1=1;                    // set SCL and SDA pins as inputs
    TRISA2=1;
    
    SSPCON1 = 0b00101000;     // I2C enabled, Master mode
    SSPCON2 = 0x00;
    // I2C Master mode, clock = FOSC/(4 * (SSPADD + 1))
    SSPADD = 39;            // 100Khz @ 16Mhz Fosc
    
    SSPSTAT = 0b11000000;     // Slew rate disabled
    
}

// i2c_Wait - wait for I2C transfer to finish
void i2c_Wait(void){
    while ( ( SSP1CON2 & 0x1F ) || ( SSPSTAT & 0x04 ) );
}

// i2c_Start - Start I2C communication
void i2c_Start(void)
{
    i2c_Wait();
    SEN=1;
}

// i2c_Restart - Re-Start I2C communication
void i2c_Restart(void){
    i2c_Wait();
    RSEN=1;
}

// i2c_Stop - Stop I2C communication
void i2c_Stop(void)
{
    i2c_Wait();
    PEN=1;
}

// i2c_Write - Sends one byte of data
void i2c_Write(unsigned char data)
{
    i2c_Wait();
    SSPBUF = data;
}

// i2c_Address - Sends Slave Address and Read/Write mode
// mode is either I2C_WRITE or I2C_READ
void i2c_Address(unsigned char address, unsigned char mode)
{
    unsigned char l_address;
    
    l_address=address<<1;
    l_address+=mode;
    i2c_Wait();
    SSPBUF = l_address;
}

// i2c_Read - Reads a byte from Slave device
unsigned char i2c_Read(unsigned char ack)
{
    // Read data from slave
    // ack should be 1 if there is going to be more data read
    // ack should be 0 if this is the last byte of data read
    unsigned char i2cReadData;
    
    i2c_Wait();
    RCEN=1;
    i2c_Wait();
    i2cReadData = SSPBUF;
    i2c_Wait();
    if ( ack ) ACKDT=0;            // Ack
    else       ACKDT=1;            // NAck
    ACKEN=1;                    // send acknowledge sequence
    
    return( i2cReadData );
}

servo_master.c
#include <htc.h>
#include "i2c.h"
/*
 * Hi-Tech C Demo program for 12F1822
 *
 * Writes values to a slave servo chip and reads values from it
 * via I2C
 *
 * Copyright (C)2011 HobbyTronics.co.uk
 * Freely distributable.
 */

// MCLR Disabled, Code Protect on, Watchdog disabled, Brownout off, Internal Osc
__CONFIG(MCLRE_OFF & CP_ON & WDTE_OFF & BOREN_OFF & FOSC_INTOSC);

#define _XTAL_FREQ 16000000             // Used in __delay_ms() functions
#define I2C_SLAVE 40                    // Slave device I2C address\

// Read a char from servo ic
unsigned char i2c_servo_read(unsigned char address)
{
    unsigned char read_byte;
    // Read one byte (i.e. servo pos of one servo)
    i2c_Start();                        // send Start
    i2c_Address(I2C_SLAVE, I2C_WRITE);  // Send slave address - write operation
    i2c_Write(address);                    // Set register for servo 0
    i2c_Restart();                      // Restart
    i2c_Address(I2C_SLAVE, I2C_READ);   // Send slave address - read operation
    read_byte = i2c_Read(0);            // Read one byte
    // If more than one byte to be read, (0) should
    // be on last byte only
    // e.g.3 bytes= i2c_Read(1); i2c_Read(1); i2c_Read(0);
    i2c_Stop();                         // send Stop
    return read_byte;                   // return byte.
    // If reading more than one byte
    // store in an array
}

void main(void)
{
    unsigned char i;
    unsigned char result;
    unsigned char servo0_pos=0;
    
    OSCCON = 0b01111010;                // set internal osc to 16MHz
    TRISA = 0b000000;                   //
    PORTA = 0b000000;
    
    i2c_Init();                            // Start I2C as Master 100KHz
    
    while(1){
        
        pressure = i2c_servo_read(0);     // Read pos of servo 0
        
    }
}
