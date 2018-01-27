/*
 * name:        LIS3DHH
 * description: MEMS digital output motion sensor ultra low-power high performance 3-axes 'nano' accelerometer
 * manuf:       ST Microelectronics
 * version:     Version 0.1
 * url:         http://www.st.com/resource/en/datasheet/lis3dhh.pdf
 * date:        2018-01-26
 * author       https://chisl.io/
 * file:        LIS3DHH.hpp
 */

/*                                                                                                       *
 *                                   THIS FILE IS AUTOMATICALLY CREATED                                  *
 *                                    D O     N O T     M O D I F Y  !                                   *
 *                                                                                                       */

#include <cinttypes>

/* Derive from class LIS3DHH_Base and implement the read and write functions! */

/* LIS3DHH: MEMS digital output motion sensor ultra low-power high performance 3-axes 'nano' accelerometer */
class LIS3DHH_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	virtual uint16_t read16(uint16_t address, uint16_t n=16) = 0;  // 16 bit read
	virtual void write(uint16_t address, uint16_t value, uint16_t n=16) = 0;  // 16 bit write
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG WHO_AM_I                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG WHO_AM_I:
	 * 7.1
	 * Device identification register.
	 */
	struct WHO_AM_I
	{
		static const uint16_t __address = 15;
		
		/* Bits WHO_AM_I: */
		struct WHO_AM_I_
		{
			/* MODE r */
			static const uint8_t dflt = 0b00010001; // 8'b10001
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register WHO_AM_I */
	void setWHO_AM_I(uint8_t value)
	{
		write(WHO_AM_I::__address, value, 8);
	}
	
	/* Get register WHO_AM_I */
	uint8_t getWHO_AM_I()
	{
		return read8(WHO_AM_I::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG CTRL_REG1                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL_REG1:
	 * 7.2
	 * Control register 1.
	 */
	struct CTRL_REG1
	{
		static const uint16_t __address = 32;
		
		/* Bits NORM_MOD_EN: */
		/* Normal mode enable.  */
		struct NORM_MOD_EN
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t POWER_DOWN = 0b0; // power down
			static const uint8_t ENABLED = 0b1; // enabled
		};
		/* Bits IF_ADD_INC: */
		/* Register address automatically incremented during a multiple byte access with SPI serial interface.  */
		struct IF_ADD_INC
		{
			/* MODE rw */
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t DISABLED = 0b0; // disabled
			static const uint8_t ENABLED = 0b1; // enabled
		};
		/* Bits reserved_0: */
		/* These bits must be set to ‘0’ for the correct operation of the device.  */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00110000; // [4,5]
		};
		/* Bits BOOT: */
		/*
		 * Reboot memory content.
		 * Boot request is executed as soon as the internal oscillator is turned on. It is possible to set the bit
		 * while in power-down mode, in this case it will be served at the next normal mode.
		 */
		struct BOOT
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t NORMAL = 0b0; // normal mode
			static const uint8_t REBOOT_MEMORY = 0b1; // reboot memory content
		};
		/* Bits SW_RESET: */
		/*
		 * Software reset.
		 * With SW_RESET the values in the writable CTRL registers are changed to the default values.
		 * This bit is cleared by hardware at the end of the operation.
		 */
		struct SW_RESET
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t NORMAL = 0b0; // normal mode
			static const uint8_t RESET = 0b1; // reset device
		};
		/* Bits DRDY_PULSE: */
		/* Data ready on INT1 pin.  */
		struct DRDY_PULSE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t LATCHED = 0b0; // DRDY latched
			static const uint8_t PULSED = 0b1; // DRDY pulsed, pulse duration is 1/4 ODR
		};
		/* Bits BDU: */
		/* Block Data Update.  */
		struct BDU
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t CONTINUOUS = 0b0; // continuous update
			static const uint8_t NOT_UPDATED_UNTIL_READ = 0b1; // output registers not updated until MSB and LSB read
		};
	};
	
	/* Set register CTRL_REG1 */
	void setCTRL_REG1(uint8_t value)
	{
		write(CTRL_REG1::__address, value, 8);
	}
	
	/* Get register CTRL_REG1 */
	uint8_t getCTRL_REG1()
	{
		return read8(CTRL_REG1::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG INT1_CTRL                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG INT1_CTRL:
	 * 7.3
	 * INT1 pin control register.
	 */
	struct INT1_CTRL
	{
		static const uint16_t __address = 33;
		
		/* Bits INT1_DRDY: */
		/* Accelerometer data ready on INT1 pin.  */
		struct INT1_DRDY
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t DISABLED = 0b0; // disabled
			static const uint8_t ENABLED = 0b1; // enabled
		};
		/* Bits INT1_BOOT: */
		/* Boot status available on INT1 pin.  */
		struct INT1_BOOT
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t DISABLED = 0b0; // disabled
			static const uint8_t ENABLED = 0b1; // enabled
		};
		/* Bits INT1_OVR: */
		/* Overrun flag on INT1 pin.  */
		struct INT1_OVR
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t DISABLED = 0b0; // disabled
			static const uint8_t ENABLED = 0b1; // enabled
		};
		/* Bits INT1_FSS5: */
		/* FSS5 full FIFO flag on INT1 pin.  */
		struct INT1_FSS5
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t DISABLED = 0b0; // disabled
			static const uint8_t ENABLED = 0b1; // enabled
		};
		/* Bits INT1_FTH: */
		/* FIFO threshold flag on INT1 pin.  */
		struct INT1_FTH
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t DISABLED = 0b0; // disabled
			static const uint8_t ENABLED = 0b1; // enabled
		};
		/* Bits INT1_EXT: */
		/*
		 * INT1 pin configuration.
		 * It configures the INT1 pad as output for FIFO flags or as external asynchronous input trigger to FIFO.
		 * INT2 pad is always available as output for FIFO flags.
		 */
		struct INT1_EXT
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t INT1_OUTPUT_INTERRUPT = 0b0; // INT1 as output interrupt
			static const uint8_t INT1_INPUT_CHANNEL = 0b1; // INT1 as input channel
		};
		/* Bits reserved_0: */
		/* These bits must be set to ‘0’ for the correct operation of the device.  */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'd0
			static const uint8_t mask = 0b00000011; // [0,1]
		};
	};
	
	/* Set register INT1_CTRL */
	void setINT1_CTRL(uint8_t value)
	{
		write(INT1_CTRL::__address, value, 8);
	}
	
	/* Get register INT1_CTRL */
	uint8_t getINT1_CTRL()
	{
		return read8(INT1_CTRL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG INT2_CTRL                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG INT2_CTRL:
	 * 7.4
	 * INT2 pin control register.
	 */
	struct INT2_CTRL
	{
		static const uint16_t __address = 34;
		
		/* Bits INT2_DRDY: */
		/* Accelerometer data ready on INT2 pin.  */
		struct INT2_DRDY
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t DISABLED = 0b0; // disabled
			static const uint8_t ENABLED = 0b1; // enabled
		};
		/* Bits INT2_BOOT: */
		/* Boot status available on INT2 pin.  */
		struct INT2_BOOT
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t DISABLED = 0b0; // disabled
			static const uint8_t ENABLED = 0b1; // enabled
		};
		/* Bits INT2_OVR: */
		/* Overrun flag on INT2 pin.  */
		struct INT2_OVR
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t DISABLED = 0b0; // disabled
			static const uint8_t ENABLED = 0b1; // enabled
		};
		/* Bits INT2_FSS5: */
		/* FSS5 full FIFO flag on INT2 pin.  */
		struct INT2_FSS5
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t DISABLED = 0b0; // disabled
			static const uint8_t ENABLED = 0b1; // enabled
		};
		/* Bits INT2_FTH: */
		/* FIFO threshold flag on INT2 pin.  */
		struct INT2_FTH
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t DISABLED = 0b0; // disabled
			static const uint8_t ENABLED = 0b1; // enabled
		};
		/* Bits reserved_0: */
		/* These bits must be set to ‘0’ for the correct operation of the device.  */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'd0
			static const uint8_t mask = 0b00000111; // [0,1,2]
		};
	};
	
	/* Set register INT2_CTRL */
	void setINT2_CTRL(uint8_t value)
	{
		write(INT2_CTRL::__address, value, 8);
	}
	
	/* Get register INT2_CTRL */
	uint8_t getINT2_CTRL()
	{
		return read8(INT2_CTRL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG CTRL_REG4                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL_REG4:
	 * 7.5
	 * Control register 4.
	 */
	struct CTRL_REG4
	{
		static const uint16_t __address = 35;
		
		/* Bits DSP_LP_TYPE: */
		/* Digital filtering selection.  */
		struct DSP_LP_TYPE
		{
			/* MODE rw */
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t FIR_LINEAR = 0b0; // FIR Linear Phase
			static const uint8_t IIR_NONLINEAR = 0b1; // IIR Nonlinear Phase
		};
		/* Bits DSP_BW_SEL: */
		/* User-selectable bandwidth.  */
		struct DSP_BW_SEL
		{
			/* MODE rw */
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t BW_440Hz = 0b0; // 440 Hz typ.
			static const uint8_t BW_235Hz = 0b1; // 235 Hz typ.
		};
		/* Bits ST: */
		/* Self-test enable.  */
		struct ST
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00110000; // [4,5]
			static const uint8_t NORMAL_MODE = 0b00; // Normal mode
			static const uint8_t POSGATIVE_SIGN = 0b01; // Positive sign self-test
			static const uint8_t NEGATIVE_SIGN = 0b10; // Negative sign self-test
			static const uint8_t NOT_ALLOWS = 0b11; // Not allowed
		};
		/* Bits PP_OD_INT2: */
		/* Push-pull/open drain selection on INT2 pin.  */
		struct PP_OD_INT2
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t PUSH_PULL = 0b0; // push-pull mode
			static const uint8_t OPEN_DRAIN = 0b1; // open drain mode
		};
		/* Bits PP_OD_INT1: */
		/* Push-pull/open drain selection on INT1 pin.  */
		struct PP_OD_INT1
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t PUSH_PULL = 0b0; // push-pull mode
			static const uint8_t OPEN_DRAIN = 0b1; // open drain mode
		};
		/* Bits FIFO_EN: */
		/* FIFO memory enable.  */
		struct FIFO_EN
		{
			/* MODE rw */
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits reserved_0: */
		/* This bit must be set to ‘1’ for correct operation of the device.  */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register CTRL_REG4 */
	void setCTRL_REG4(uint8_t value)
	{
		write(CTRL_REG4::__address, value, 8);
	}
	
	/* Get register CTRL_REG4 */
	uint8_t getCTRL_REG4()
	{
		return read8(CTRL_REG4::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG CTRL_REG5                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL_REG5:
	 * 7.6
	 * Control register 5.
	 */
	struct CTRL_REG5
	{
		static const uint16_t __address = 36;
		
		/* Bits reserved_0: */
		/* These bits must be set to ‘0’ for correct operation of the device.  */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t mask = 0b11111110; // [1,2,3,4,5,6,7]
		};
		/* Bits FIFO_SPI_HS_ON: */
		/*
		 * Enables the SPI high speed configuration for the FIFO block that is used to guarantee a
		 * minimum duration of the window in which writing operation of RAM output is blocked.
		 * This bit is recommended for SPI clock frequencies higher than 6 MHz.
		 */
		struct FIFO_SPI_HS_ON
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t NOT_ENABLED = 0b0; // not enabled
			static const uint8_t ENABLED = 0b1; // enabled
		};
	};
	
	/* Set register CTRL_REG5 */
	void setCTRL_REG5(uint8_t value)
	{
		write(CTRL_REG5::__address, value, 8);
	}
	
	/* Get register CTRL_REG5 */
	uint8_t getCTRL_REG5()
	{
		return read8(CTRL_REG5::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG OUT_TEMP                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG OUT_TEMP:
	 * 7.7
	 * Temperature data output register. L and H registers together express a 16-bit word in two’s complement
	 * left-justified.
	 */
	struct OUT_TEMP
	{
		static const uint16_t __address = 37;
		
		/* Bits unused_0: */
		struct unused_0
		{
			/* MODE r */
			static const uint16_t dflt = 0b0000; // 4'd0
			static const uint16_t mask = 0b1111000000000000; // [12,13,14,15]
		};
		/* Bits Temp: */
		/*
		 * Temperature sensor output data.
		 * The value is expressed as two’s complement sign.
		 * 0 LSB represents T=25 °C ambient.
		 */
		struct Temp
		{
			/* MODE r */
			static const uint16_t mask = 0b0000111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11]
		};
	};
	
	/* Set register OUT_TEMP */
	void setOUT_TEMP(uint16_t value)
	{
		write(OUT_TEMP::__address, value, 16);
	}
	
	/* Get register OUT_TEMP */
	uint16_t getOUT_TEMP()
	{
		return read16(OUT_TEMP::__address, 16);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                            REG STATUS                                             *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG STATUS:
	 * 7.8
	 * Status register (r)
	 */
	struct STATUS
	{
		static const uint16_t __address = 39;
		
		/* Bits ZYXOR: */
		/* Logic OR of the single X-, Y- and Z-axis data overrun.  */
		struct ZYXOR
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t NO_OVERRUN = 0b0; // no overrun has occurred
			static const uint8_t OVERRUN = 0b1; // a new set of data has overwritten the previous set
		};
		/* Bits ZOR: */
		/* Z-axis data overrun.  */
		struct ZOR
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t NO_OVERRUN = 0b0; // no overrun has occurred
			static const uint8_t OVERRUN = 0b1; // a new data for the Z-axis has overwritten the previous data
		};
		/* Bits YOR: */
		/* Y-axis data overrun.  */
		struct YOR
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t NO_OVERRUN = 0b0; // no overrun has occurred
			static const uint8_t OVERRUN = 0b1; // new data for the Y-axis has overwritten the previous data
		};
		/* Bits XOR: */
		/* X-axis data overrun.  */
		struct XOR
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t NO_OVERRUN = 0b0; // no overrun has occurred
			static const uint8_t OVERRUN = 0b1; // new data for the X-axis has overwritten the previous data
		};
		/* Bits ZYXDA: */
		/* Logic AND of the single X-, Y- and Z-axis new data available.  */
		struct ZYXDA
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t NO_DATA = 0b0; // a new set of data is not yet available
			static const uint8_t DATA = 0b1; // a new set of data is available
		};
		/* Bits ZDA: */
		/* Z-axis new data available.  */
		struct ZDA
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t NO_DATA = 0b0; // new data for the Z-axis is not yet available
			static const uint8_t DATA = 0b1; // new data for the Z-axis is available
		};
		/* Bits YDA: */
		/* Y-axis new data available.  */
		struct YDA
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t NO_DATA = 0b0; // new data for the Y-axis is not yet available
			static const uint8_t DATA = 0b1; // new data for the Y-axis is available
		};
		/* Bits XDA: */
		/* X-axis new data available.  */
		struct XDA
		{
			/* MODE r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t NO_DATA = 0b0; // new data for the X-axis is not yet available
			static const uint8_t DATA = 0b1; // new data for the X-axis is available
		};
	};
	
	/* Set register STATUS */
	void setSTATUS(uint8_t value)
	{
		write(STATUS::__address, value, 8);
	}
	
	/* Get register STATUS */
	uint8_t getSTATUS()
	{
		return read8(STATUS::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG OUT_X                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG OUT_X:
	 * 7.9
	 * Linear acceleration sensor X-axis output register. The value is expressed as a 16-bit
	 * word in two’s complement.
	 */
	struct OUT_X
	{
		static const uint16_t __address = 40;
		
		/* Bits OUT_X: */
		struct OUT_X_
		{
			/* MODE r */
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register OUT_X */
	void setOUT_X(uint16_t value)
	{
		write(OUT_X::__address, value, 16);
	}
	
	/* Get register OUT_X */
	uint16_t getOUT_X()
	{
		return read16(OUT_X::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG OUT_Y                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG OUT_Y:
	 * 7.10
	 * Linear acceleration sensor Y-axis output register. The value is expressed as a 16-bit
	 * word in two’s complement.
	 */
	struct OUT_Y
	{
		static const uint16_t __address = 42;
		
		/* Bits OUT_Y: */
		struct OUT_Y_
		{
			/* MODE r */
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register OUT_Y */
	void setOUT_Y(uint16_t value)
	{
		write(OUT_Y::__address, value, 16);
	}
	
	/* Get register OUT_Y */
	uint16_t getOUT_Y()
	{
		return read16(OUT_Y::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG OUT_Z                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG OUT_Z:
	 * 7.11
	 * Linear acceleration sensor Z-axis output register. The value is expressed as a 16-bit
	 * word in two’s complement.
	 */
	struct OUT_Z
	{
		static const uint16_t __address = 44;
		
		/* Bits OUT_Z: */
		struct OUT_Z_
		{
			/* MODE r */
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register OUT_Z */
	void setOUT_Z(uint16_t value)
	{
		write(OUT_Z::__address, value, 16);
	}
	
	/* Get register OUT_Z */
	uint16_t getOUT_Z()
	{
		return read16(OUT_Z::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG FIFO_CTRL                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG FIFO_CTRL:
	 * 7.12
	 * FIFO control register.
	 */
	struct FIFO_CTRL
	{
		static const uint16_t __address = 46;
		
		/* Bits FMODE: */
		/* FIFO mode selection bits.  */
		struct FMODE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b11100000; // [5,6,7]
			static const uint8_t BYPASS = 0b00; // Bypass mode. FIFO turned off
			static const uint8_t FIFO = 0b01; // FIFO mode. Stops collecting data when FIFO is full.
			static const uint8_t reserved_0 = 0b10; // 
			static const uint8_t CONTINUOUS_UNTIL_TRIGGER = 0b11; // Continuous mode until trigger is asserted, then FIFO mode.
			static const uint8_t BYPASS_UNTUL_TRIGGER = 0b100; // Bypass mode until trigger is asserted, then Continuous mode.
			static const uint8_t reserved_1 = 0b101; // 
			static const uint8_t CONTINIOUS = 0b110; // Continuous mode. If the FIFO is full, the new sample over- writes the older sample.
			static const uint8_t reserved_2 = 0b111; // 
		};
		/* Bits FTH: */
		/* FIFO threshold level setting.  */
		struct FTH
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000; // 5'd0
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register FIFO_CTRL */
	void setFIFO_CTRL(uint8_t value)
	{
		write(FIFO_CTRL::__address, value, 8);
	}
	
	/* Get register FIFO_CTRL */
	uint8_t getFIFO_CTRL()
	{
		return read8(FIFO_CTRL::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG FIFO_SRC                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG FIFO_SRC:
	 * 7.13
	 * FIFO status register.
	 */
	struct FIFO_SRC
	{
		static const uint16_t __address = 47;
		
		/* Bits FTH: */
		/* FIFO threshold status.  */
		struct FTH
		{
			/* MODE r */
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t FIFO_BELOW_THRESH = 0b0; // FIFO filling is lower than threshold level
			static const uint8_t FIFO_AT_OR_ABOVR_THRESH = 0b1; // FIFO filling is equal to or higher than the threshold level
		};
		/* Bits OVRN: */
		/* FIFO overrun status.  */
		struct OVRN
		{
			/* MODE r */
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t FIFO_NOT_FILLED = 0b0; // FIFO is not completely filled
			static const uint8_t FIFO_FILLED = 0b1; // FIFO is completely filled and at least one sample has been overwritten) For further details refer to Table 31.
		};
		/* Bits FSS: */
		/*
		 * Number of unread samples stored in FIFO.
		 * When the number of unread samples in FIFO is equal to or greater than the threshold level set in register FIFO_CTRL (2Eh), the FTH value is ‘1’.
		 * The FSS is the FIFO stored data level of the unread samples. When it is equal to FTH, all data available in FIFO are read without additional read operations.
		 * The INT output is high when the number of samples to read is equal to or greater than FTH.
		 */
		struct FSS
		{
			/* MODE r */
			static const uint8_t mask = 0b00111111; // [0,1,2,3,4,5]
		};
	};
	
	/* Set register FIFO_SRC */
	void setFIFO_SRC(uint8_t value)
	{
		write(FIFO_SRC::__address, value, 8);
	}
	
	/* Get register FIFO_SRC */
	uint8_t getFIFO_SRC()
	{
		return read8(FIFO_SRC::__address, 8);
	}
	
};
