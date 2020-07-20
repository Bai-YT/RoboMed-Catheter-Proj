/*

SparkFun_LPS33HW_Arduino_Library.h

This is an interface to the LPS33HW I2C absolute digital output barometer. The IC can be found in
the SparkFun Qwiic series of sensors

Created: May 2018
Last Updated: June 2018

Authors:
Owen Lyke

*/

#ifndef LPS33HW_H
#define LPS33HW_H


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>


/////////////////////////////////////
//				Defines
/////////////////////////////////////

// I2C addresses
#define LPS33HW_I2C_ADDR_DEF 	0b1011101	// Address used by default, ADDR pin is pulled high
#define LPS33HW_I2C_ADDR_ALT 	0b1011100	// Address used as alternate, when user bridges the ADR pads

#define LPS33HW_DEVID			0xB1		// Factory set identifier

// Register Configuration Options

// Resolution Configuration
#define LPS33HW_RES_CONF_DEFAULT 	0x0F 	// Default
//#define LPS33HW_RES_CONF_T_8        0x00    // Temperature 8 internal averages
//#define LPS33HW_RES_CONF_T_16        0x04    // Temperature 16 internal averages
//#define LPS33HW_RES_CONF_T_32        0x08    // Temperature 32 internal averages
//#define LPS33HW_RES_CONF_T_64        0x0C    // Temperature 64 internal averages
//#define LPS33HW_RES_CONF_P_8        0x00     // Pressure 8 internal averages
//#define LPS33HW_RES_CONF_P_32        0x01     // Pressure 32 internal averages
//#define LPS33HW_RES_CONF_P_128         0x02     // Pressure 128 internal averages
//#define LPS33HW_RES_CONF_P_512         0x03    // Pressure 512 internal averages

// Control Register 1
#define LPS33HW_CTRL_REG1_DEFAULT	0x00 	// Default
// #define LPS33HW_CTRL_REG1_PD_ACTIVE 0x80 	// Active mode - needed to turn on sensor
#define LPS33HW_CTRL_REG1_ODR_OS	0x00 	// Power-down / One shot mode
#define LPS33HW_CTRL_REG1_ODR_1HZ 	0x10 	// Both T and P at 1Hz
#define LPS33HW_CTRL_REG1_ODR_7HZ	0x20 	// Both T and P at 10Hz
#define LPS33HW_CTRL_REG1_ODR_12HZ5 0x30 	// Both T and P at 25Hz
#define LPS33HW_CTRL_REG1_ODR_25HZ 	0x40 	// Both T and P at 50Hz
#define LPS33HW_CTRL_REG1_ODR_25HZ  0x50    // Both T and P at 75Hz
#define LPS33HW_CTRL_REG1_DIFF_EN	0x08 	// Enable LPFP
#define LPS33HW_CTRL_REG1_BDU_EN	0x04 	// Low-pass configuration register
#define LPS33HW_CTRL_REG1_RESET_AZ  0x02 	// Block data update
#define LPS33HW_CTRL_REG1_SIM_4W	0x00 	// Select Interface Method : 4 Wire
#define LPS33HW_CTRL_REG1_SIM_4W	0x01 	// Select Interface Method : 3 Wire

// Control Register 2
#define LPS33HW_CTRL_REG2_DEFAULT 		0x10 	// Default
#define LPS33HW_CTRL_REG2_REBOOT_MEM	0x80 	// Reboots memory content, bit is self-cleared when BOOT complete
#define LPS33HW_CTRL_REG2_FIFO_EN		0x40 	// Enable FIFO
#define LPS33HW_CTRL_REG2_STOP_ON_FTH	0x20 	// Enable the FTH_FIFO bit in FIFO_STATUS for monitoring of FIFO level
#define LPS33HW_CTRL_REG2_IF_ADD_INC    0x10 	//Register address automatically incremented during a multiple byte access with a serial interface (I2C or SPI)
#define LPS33HW_CTRL_REG2_I2C_DIS 		0x08 	// Disable I2C interface
#define LPS33HW_CTRL_REG2_SWRESET		0x04 	// Perform software reset
// #define LPS33HW_CTRL_REG2_AUTOZERO		0x02 	// Enable autozero
#define LPS33HW_CTRL_REG2_ONE_SHOT		0x01 	// Acquire a new dataset

// Control Register 3
#define LPS33HW_CTRL_REG3_DEFAULT 		0x00	// Default
#define LPS33HW_CTRL_REG3_INT_H			0x00	// Interrupts are active high
#define LPS33HW_CTRL_REG3_INT_L			0x80 	// Interrupts are active low
#define LPS33HW_CTRL_REG3_PP 			0x00 	// Interrupt pads are Push/Pull
#define LPS33HW_CTRL_REG3_OD 			0x40 	// Interrupt pads are Open Drain
#define LPS33HW_CTRL_REG3_INT_S_DATA	0x00 	// Data signal on interrupt
#define LPS33HW_CTRL_REG3_INT_S_P_H 	0x01 	// Interrupt on pressure high
#define LPS33HW_CTRL_REG3_INT_S_P_L 	0x02 	// Interrupt on pressure low
#define LPS33HW_CTRL_REG3_INT_S_P_E		0x03 	// Interrupt on pressure either high or low
#define LPS33HW_CTRL_REG3_F_FSS5        0x20    // FIFO full flag on INT_DRDY pin
#define LPS33HW_CTRL_REG3_F_FTH         0x10    // FIFO threshold (watermark) status on INT_DRDY pin.
#define LPS33HW_CTRL_REG3_F_OVR         0x08    // FIFO overrun interrupt on INT_DRDY pin
#define LPS33HW_CTRL_REG3_DRDY          0x04    // Data-ready signal on INT_DRDY pin

//// Control Register 4
//#define LPS33HW_CTRL_REG4_DEFAULT         0x00     // Default
//#define LPS33HW_CTRL_REG4_F_EMPTY        0x08     // Enable FIFO empty flag on INT_DRDY pin
//#define LPS33HW_CTRL_REG4_F_FTH            0x04     // Enable FIFO threshold (watermark) status on INT_DRDY pin to indicate that FIFO is filled up to the threshold level
//#define LPS33HW_CTRL_REG4_F_OVR         0x02     // Enable FIFO overrun interrupt on INT_DRDY pin to indicate that FIFO is full in FIFO mode or that an overrun occurred in Stream mode
//#define LPS33HW_CTRL_REG4_DRDY             0x01     // Enable Data-ready signal on INT_DRDY pin

// Interrupt Configuration
#define LPS33HW_INTERRUPT_CFG_DEFFAULT 	0x00 	// Default
#define LPS33HW_INTERRUPT_CFG_LIR 		0x04  	// Latch interrupt request
#define LPS33HW_INTERRUPT_CFG_PL_E		0x02 	// Enable interrupt generation on differential pressure low event
#define LPS33HW_INTERRUPT_CFG_PH_E 		0x01 	// Enable interrupt generation on differential pressure high event
#define LPS33HW_INTERRUPT_BOOT_STATUS   0x80    // If ‘1’ indicates that the Boot (Reboot) phase is running.

// FIFO Control
#define LPS33HW_FIFO_CTRL_DEFAULT		0x00 	// Default
#define LPS33HW_FIFO_CTRL_BYPASS		0x00	// Bypass FIFO
#define LPS33HW_FIFO_CTRL_FIFO			0x20 	// Use FIFO
#define LPS33HW_FIFO_CTRL_STREAM 		0x40 	// Stream mode
#define LPS33HW_FIFO_CTRL_SF			0x60 	// Stream to FIFO mode
#define LPS33HW_FIFO_CTRL_BS 			0x80 	// Bypass to stream mode
#define LPS33HW_FIFO_CTRL_MEAN			0xC0 	// FIFO Mean mode
#define LPS33HW_FIFO_CTRL_BF 			0xE0 	// Bypass to FIFO mode
#define LPS33HW_FIFO_CTRL_M_2			0x01 	// 2 sample moving average
#define LPS33HW_FIFO_CTRL_M_4			0x03 	// 4 sample moving average
#define LPS33HW_FIFO_CTRL_M_8			0x07 	// 8 sample moving average
#define LPS33HW_FIFO_CTRL_M_16			0x0F 	// 16 sample moving average
#define LPS33HW_FIFO_CTRL_M_32			0x1F 	// 32 sample moving average





/////////////////////////////////////
//				TypeDefs
/////////////////////////////////////

// Register Addresses
typedef enum{
	LPS33HW_REG_REF_P_XL = 0x15,
	LPS33HW_REG_REF_P_L = 0x16,
	LPS33HW_REG_REF_P_H = 0x17,

	LPS33HW_REG_WHO_AM_I = 0x0F,

	LPS33HW_REG_RES_CONF = 0x1A,
	// Reserved 0x11-0x1F
	LPS33HW_REG_CTRL_REG1 = 0x10,
	LPS33HW_REG_CTRL_REG2 = 0x11,
	LPS33HW_REG_CTRL_REG3 = 0x12,
	LPS33HW_REG_INTERRUPT_CFG = 0x0B,
	LPS33HW_REG_INT_SOURCE = 0x25,
	// Reserved 0x26
	LPS33HW_REG_STATUS_REG = 0x27,
	LPS33HW_REG_PRESS_OUT_XL = 0x28,
	LPS33HW_REG_PRESS_OUT_L = 0x29,
	LPS33HW_REG_PRESS_OUT_H = 0x2A,
	LPS33HW_REG_TEMP_OUT_L = 0x2B,
	LPS33HW_REG_TEMP_OUT_H = 0x2C,
	// Reserved 0x2D
	LPS33HW_REG_FIFO_CTRL = 0x14,
	LPS33HW_REG_FIFO_STATUS,
	LPS33HW_REG_THS_P_L = 0x0c,
	LPS33HW_REG_THS_P_H = 0x0d,
	// Reserved 0x32-38
	LPS33HW_REG_RPDS_L = 0x18
}LPS33HW_RegistersTypeDef;


typedef enum{
	// General success/failure
	LPS33HW_CODE_ERR = 0x00,
	LPS33HW_CODE_NOM,

	// Setting failures
	LPS33HW_CODE_SET_FAIL,
	LPS33HW_CODE_RESET_FAIL,

	// Connection status
	LPS33HW_CODE_DISCONNECTED,
	LPS33HW_CODE_CONNECTED,
	LPS33HW_CODE_NO_DEV_AT_ADDRESS,
	LPS25_HB_CODE_WRONG_ID,

	//
	LPS33HW_CODE_RX_UNDERFLOW
	

}LPS33HW_CodesTypeDef;


class LPS33HW
{
public:

	// Parameters
	uint8_t 				sensor_address;	// Remembers the sensor address for the user. The best way to set this value is to call the begin funtion again
	LPS33HW_CodesTypeDef 	lastCode;		// Holds the last code returned from operations

	// Functions
	LPS33HW( void );																									// Constructor
	bool begin(	TwoWire &wirePort = Wire, uint8_t address = LPS33HW_I2C_ADDR_DEF, uint32_t clock_frequency = 100000 ); 	// Startup routine that uses the Wire port as the default

	// Getters
	bool isConnected(); 					
	uint8_t getID();
	uint8_t getStatus();

	int16_t		getTemperature_raw();
	float		getTemperature_degC();

	int32_t 	getPressure_raw();
	float		getPressure_hPa();

	// Setters
	bool setReferencePressure(uint32_t adc_val);
	bool setPressureThreshold(uint16_t adc_val);
	bool setTemperatureAverages(uint8_t avg_code);
	bool setPressureAverages(uint8_t avg_code);
	bool setOutputDataRate(uint8_t odr_code);
	bool setFIFOMode(uint8_t mode_code);
	bool setFIFOMeanNum(uint8_t mean_num);

	// Setting Changers
	bool applySetting(uint8_t reg_adr, uint8_t setting);
	bool removeSetting(uint8_t reg_adr, uint8_t setting);

	// I2C Interface Basics
	bool read( uint8_t reg_adr, uint8_t * pdata, uint8_t size);
	bool write( uint8_t reg_adr, uint8_t * pdata, uint8_t size);

private:

	TwoWire *_i2cPort;			// Allows user to specify which TwoWire port to use for the connection

};



#endif /* LPS33HW_H */
