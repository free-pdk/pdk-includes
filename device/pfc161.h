/*
  pfc161.h: FUSE and Register Definitions for the Padauk PFC161 device.

  Copyright (C) 2020  serisman  <github@serisman.com>
  Copyright (C) 2019-2020  freepdk  https://free-pdk.github.io

  This library is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the
  Free Software Foundation; either version 2, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this library. If not, see <http://www.gnu.org/licenses/>.

  As a special exception, if you link this library with other files,
  some of which are compiled with SDCC, to produce an executable,
  this library does not by itself cause the resulting executable to
  be covered by the GNU General Public License. This exception does
  not however invalidate any other reasons why the executable file
  might be covered by the GNU General Public License.
*/

#ifndef __PDK_DEVICE_PFC161_H__
#define __PDK_DEVICE_PFC161_H__

#if !defined(__PDK_DEVICE_XXX_H__)
	#define __PDK_DEVICE_XXX_H__ "pfc161.h"
#else
	#error "Attempt to include more than one "pdk/device/XXX.h" file."
#endif

#if !defined(__SDCC_pdk14)
	#error "PFC161 needs the PDK14 backend. You must compile with the -mpdk14 option."
#endif

#define ILRC_FREQ           64000

// Factory Calibration address locations
#define FACTORY_IHRCR_ADDR  0x07ed
#define FACTORY_BGTR_ADDR   0x07ee


// FUSE definitions
#define FUSE_WORD_ADDR      0x07ff
#define FUSE_RES_BITS_HIGH  0x303C // - - 1 1   0 0 0 0   D E 1 1   1 1 0 S
// Blank IC Values          0x3FFF // - - 1 1   1 1 1 1   1 1 1 1   1 1 1 1 (Security Off, EMI Disable, PA3_PA4 Drive Strong)
#define FUSE_SECURITY_ON    0x0000    //(S)
#define FUSE_SECURITY_OFF   (1 << 0)
#define FUSE_EMI_ENABLE     0x0000    //(E)
#define FUSE_EMI_DISABLE    (1 << 6)
#define FUSE_PA3_PA4_NORMAL 0x0000    //(D)
#define FUSE_PA3_PA4_STRONG (1 << 7)


// Register address definitions
#define FLAG_ADDR           0x00
//0x01
#define SP_ADDR             0x02
#define CLKMD_ADDR          0x03
#define INTEN_ADDR          0x04
#define INTRQ_ADDR          0x05
#define T16M_ADDR           0x06
//0x07
#define MISC_ADDR           0x08
//0x09
#define EOSCR_ADDR          0x0a
#define IHRCR_ADDR          0x0b
#define INTEGS_ADDR         0x0c
#define PADIER_ADDR         0x0d
#define PBDIER_ADDR         0x0e
#define MISC2_ADDR          0x0f
#define PA_ADDR             0x10
#define PAC_ADDR            0x11
#define PAPH_ADDR           0x12
#define PAPL_ADDR           0x13
#define PB_ADDR             0x14
#define PBC_ADDR            0x15
#define PBPH_ADDR           0x16
#define PBPL_ADDR           0x17
#define GPCC_ADDR           0x18
#define GPCS_ADDR           0x19
#define BGTR_ADDR           0x1a
#define MISCLVR_ADDR        0x1b
#define TM2C_ADDR           0x1c
#define TM2CT_ADDR          0x1d
#define TM2S_ADDR           0x1e
#define TM2B_ADDR           0x1f
#define TS_ADDR             0x20
#define TCC_ADDR            0x21
#define TKE2_ADDR           0x22
//0x23
#define TKE1_ADDR           0x24
//0x25
#define TPS_ADDR            0x26
//0x27
#define TPS2_ADDR           0x28
//0x29
//0x2a
#define TKCH_ADDR           0x2b
#define TKCL_ADDR           0x2c
#define LVDC_ADDR           0x2d
//0x2e
//0x2f
//0x30
//0x31
#define TM3C_ADDR           0x32
#define TM3CT_ADDR          0x33
#define TM3S_ADDR           0x34
#define TM3B_ADDR           0x35
//0x36
//0x37
//0x38
#define ILRCR_ADDR          0x39
#define ROP_ADDR            0x3a
//0x3b
//...
//0x3f

// ROP register BIT definitions
#define ROP_PB7_CS_SEL_BIT           0
#define ROP_PA7_CS_SEL_BIT           1
#define ROP_PA0_PA5_SEL_BIT          2
#define ROP_TMX_BIT_SEL_BIT          4
#define ROP_TMX_FREQ_SEL_BIT         5
#define ROP_PWM_SEL_BIT              6

// Peripheral definitions
#define __PDK_HAS_ILRC_DIV2
#define __PDK_HAS_COMP
#define __PDK_HAS_COMP_WAKEUP
#define __PDK_HAS_EOSC
#define __PDK_HAS_PORTB
#define __PDK_NO_PB1
#define __PDK_NO_PB2
#define __PDK_NO_PB3
#define __PDK_NO_PB4
#define __PDK_NO_PB5
#define __PDK_NO_PB6
#define __PDK_HAS_TM3
#define __PDK_HAS_TOUCH

#include "periph/accumulator.h"
#include "periph/stack.h"
#include "periph/clock.h"
#include "periph/external_oscillator.h"
#include "periph/interrupt.h"
#include "periph/port_a.h"
#include "periph/port_b.h"
#include "periph/timer_16.h"
#include "periph/timer_2.h"
#include "periph/timer_3.h"
#include "periph/bandgap.h"
#include "periph/comparator.h"
#include "periph/lvd.h"
#include "periph/misc.h"
#include "periph/misc2.h"
#include "periph/misclvr.h"
#include "periph/rop.h"
#include "periph/touch.h"

#endif //__PDK_DEVICE_PFC161_H__
