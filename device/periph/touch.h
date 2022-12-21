/*
  touch.h: Definitions for the Touch related registers used by Padauk microcontrollers.

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

#ifndef __PDK_DEVICE_PERIPH_TOUCH_H__
#define __PDK_DEVICE_PERIPH_TOUCH_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/device/periph/touch.h" by itself."
#endif

// __sfr definitions
__sfr __at(TS_ADDR)           _ts;
__sfr __at(TCC_ADDR)          _tcc;
__sfr __at(TKE1_ADDR)         _tke1;
__sfr __at(TKE2_ADDR)         _tke2;
__sfr __at(TPS_ADDR)          _tps;
__sfr __at(TPS2_ADDR)         _tps2;
__sfr __at(TKCH_ADDR)         _tkch;
__sfr __at(TKCL_ADDR)         _tkcl;

#define TS                    _ts
#define TCC                   _tcc
#define TKE1                  _tke1
#define TKE2                  _tke2
#define TPS                   _tps
#define TPS2                  _tps2
#define TKCH                  _tkch
#define TKCL                  _tkcl


// TS (Touch Selection) register definitions
#define TS_DISCHARGE_WAIT_BIT0       0
#define TS_VREF_SEL_BIT0             2
#define TS_CLK_SEL_BIT0              4

#define TS_DISCHARGE_WAIT_0_CLKS     0x00
#define TS_DISCHARGE_WAIT_32_CLKS    (1 << TS_DISCHARGE_WAIT_BIT0)
#define TS_DISCHARGE_WAIT_64_CLKS    (2 << TS_DISCHARGE_WAIT_BIT0)
#define TS_DISCHARGE_WAIT_128_CLKS   (3 << TS_DISCHARGE_WAIT_BIT0)

#define TS_VREF_0_5_VCC              0x00
// For Type A (CS connected to VDD) ???
#define TS_VREF_0_6_VCC              (1 << TS_VREF_SEL_BIT0)
#define TS_VREF_0_7_VCC              (2 << TS_VREF_SEL_BIT0)
#define TS_VREF_0_8_VCC              (3 << TS_VREF_SEL_BIT0)
// For Type B (CS connected to GND) ???
#define TS_VREF_0_4_VCC              (1 << TS_VREF_SEL_BIT0)
#define TS_VREF_0_3_VCC              (2 << TS_VREF_SEL_BIT0)
#define TS_VREF_0_2_VCC              (3 << TS_VREF_SEL_BIT0)

#define TS_CLK_IHRC                  0x00
#define TS_CLK_IHRC_DIV2             (1 << TS_CLK_SEL_BIT0)
#define TS_CLK_IHRC_DIV4             (2 << TS_CLK_SEL_BIT0)
#define TS_CLK_IHRC_DIV8             (3 << TS_CLK_SEL_BIT0)
#define TS_CLK_IHRC_DIV16            (4 << TS_CLK_SEL_BIT0)
#define TS_CLK_IHRC_DIV32            (5 << TS_CLK_SEL_BIT0)
#define TS_CLK_IHRC_DIV64            (6 << TS_CLK_SEL_BIT0)
#define TS_CLK_IHRC_DIV128           (7 << TS_CLK_SEL_BIT0)
#define TS_CLK_ILRC                  (8 << TS_CLK_SEL_BIT0)

// TCC (Touch Charge Control) register definitions
#define TCC_CONTROL_BIT0             4

#define TCC_TK_STOP                  0x00
#define TCC_TK_RUN                   (1 << TCC_CONTROL_BIT0)
#define TCC_DISCHARGE                (3 << TCC_CONTROL_BIT0)

// TKE1 (Touch Key Enable 1) register definitions
#define TKE1_TK4_PB7_BIT             4
#define TKE1_TK5_PA3_BIT             5
#define TKE1_TK6_PA4_BIT             6
#define TKE1_TK7_PA0_BIT             7

#define TKE1_TK4_PB7                 (1 << TKE1_TK4_PB7_BIT)
#define TKE1_TK5_PA3                 (1 << TKE1_TK5_PA3_BIT)
#define TKE1_TK6_PA4                 (1 << TKE1_TK6_PA4_BIT)
#define TKE1_TK7_PA0                 (1 << TKE1_TK7_PA0_BIT)

// TKE2 (Touch Key Enable 2) register definitions
#define TKE2_TK8_PA6_BIT             0
#define TKE2_TK9_PA5_BIT             1
#define TKE2_TK10_PA7_BIT            2
#define TKE2_TK11_PB0_BIT            3

#define TKE2_TK8_PA6                 (1 << TKE2_TK8_PA6_BIT)
#define TKE2_TK9_PA5                 (1 << TKE2_TK9_PA5_BIT)
#define TKE2_TK10_PA7                (1 << TKE2_TK10_PA7_BIT)
#define TKE2_TK11_PB0                (1 << TKE2_TK11_PB0_BIT)

// TPS (Touch Parameter Setting) register definitions
#define TPS_FREQ_RANGE_BIT0          0
#define TPS_FREQ_PERIOD_BIT0         2
#define TPS_RESISTOR_BIT0            4
#define TPS_DEBOUNCE_BIT0            6

#define TPS_FREQ_RANGE_DISABLED      0x00
#define TPS_FREQ_RANGE_12_STEP       (1 << TPS_FREQ_RANGE_BIT0)
#define TPS_FREQ_RANGE_8_STEP        (2 << TPS_FREQ_RANGE_BIT0)
#define TPS_FREQ_RANGE_4_STEP        (3 << TPS_FREQ_RANGE_BIT0)

#define TPS_FREQ_PERIOD_8US          0x00
#define TPS_FREQ_PERIOD_16US         (2 << TPS_FREQ_PERIOD_BIT0)
#define TPS_FREQ_PERIOD_RANDOM       (3 << TPS_FREQ_PERIOD_BIT0)

#define TPS_RESISTOR_X1              0x00
#define TPS_RESISTOR_X2              (1 << TPS_RESISTOR_BIT0)
#define TPS_RESISTOR_X3              (2 << TPS_RESISTOR_BIT0)
#define TPS_RESISTOR_X4              (3 << TPS_RESISTOR_BIT0)

#define TPS_DEBOUNCE_2_CLKS          0x00
#define TPS_DEBOUNCE_4_CLKS          (1 << TPS_DEBOUNCE_BIT0)
#define TPS_DEBOUNCE_8_CLKS          (2 << TPS_DEBOUNCE_BIT0)
#define TPS_DEBOUNCE_16_CLKS         (3 << TPS_DEBOUNCE_BIT0)

// TPS2 (Touch Parameter Setting 2) register definitions
#define TPS2_VREF_CTRL_BIT0          0
#define TPS2_OHM_BIT                 2
#define TPS2_CURRENT_SRC_BIT0        3
#define TPS2_TYPE_BIT0               6

#define TPS2_VREF_ALWAYS_FLOATING    0x00
#define TPS2_VREF_ALWAYS_ON          (1 << TPS2_VREF_CTRL_BIT0)
#define TPS2_VREF_ON_FOR_64_CYCLES   (2 << TPS2_VREF_CTRL_BIT0)
#define TPS2_VREF_ON_FOR_128_CYCLES  (3 << TPS2_VREF_CTRL_BIT0)

#define TPS2_OHM_16M                 0x00
#define TPS2_OHM_8M                  (1 << TPS2_OHM_BIT)

#define TPS2_CURRENT_SRC_1U          0x00
#define TPS2_CURRENT_SRC_0_5U        (1 << TPS2_CURRENT_SRC_BIT0)
#define TPS2_CURRENT_SRC_0_25U       (2 << TPS2_CURRENT_SRC_BIT0)
#define TPS2_CURRENT_SRC_0_125U      (3 << TPS2_CURRENT_SRC_BIT0)

#define TPS2_TYPE_A_VDD              0x00
#define TPS2_TYPE_B_GND              (1 << TPS2_TYPE_BIT0)

#endif //__PDK_DEVICE_PERIPH_TOUCH_H__
