/*
  lvd.h: Definitions for the Low Voltage Detector related registers used by Padauk microcontrollers.

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

#ifndef __PDK_DEVICE_PERIPH_LVD_H__
#define __PDK_DEVICE_PERIPH_LVD_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/device/periph/lvd.h" by itself."
#endif

// __sfr definitions
__sfr __at(LVDC_ADDR)         _lvdc;

#define LVDC                  _lvdc

// LVDC (Low Voltage Detect) register definitions
#define LVDC_LVD_RESULT_BIT          0
#define LVDC_LVD_BIT0                4

#define LVDC_VDD_GT_LVD              0x00
#define LVDC_VDD_LT_LVD              (1 << LVDC_LVD_RESULT_BIT)

#define LVDC_LVD_1V8                 0x00
#define LVDC_LVD_1V9                 (1 << LVDC_LVD_BIT0)
#define LVDC_LVD_2V                  (2 << LVDC_LVD_BIT0)
#define LVDC_LVD_2V1                 (3 << LVDC_LVD_BIT0)
#define LVDC_LVD_2V2                 (4 << LVDC_LVD_BIT0)
#define LVDC_LVD_2V3                 (5 << LVDC_LVD_BIT0)
#define LVDC_LVD_2V4                 (6 << LVDC_LVD_BIT0)
#define LVDC_LVD_2V5                 (7 << LVDC_LVD_BIT0)
#define LVDC_LVD_2V75                (8 << LVDC_LVD_BIT0)
#define LVDC_LVD_3V                  (9 << LVDC_LVD_BIT0)
#define LVDC_LVD_3V15                (10 << LVDC_LVD_BIT0)
#define LVDC_LVD_3V3                 (11 << LVDC_LVD_BIT0)
#define LVDC_LVD_3V5                 (12 << LVDC_LVD_BIT0)
#define LVDC_LVD_3V75                (13 << LVDC_LVD_BIT0)
#define LVDC_LVD_4V                  (14 << LVDC_LVD_BIT0)
#define LVDC_LVD_4V5                 (15 << LVDC_LVD_BIT0)

#endif //__PDK_DEVICE_PERIPH_LVD_H__
