/*
  rfc.h: Definitions for the Resistance to Frequency Converter related registers used by Padauk microcontrollers.
  - https://deploy-preview-50--free-pdk-preview.netlify.app/undocumented-features#resistance-to-frequency-converter-pfs154-and-pfs173
  - https://hackaday.io/project/174822/logs

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

#ifndef __PDK_DEVICE_PERIPH_RFC_H__
#define __PDK_DEVICE_PERIPH_RFC_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/device/periph/rfc.h" by itself."
#endif

// __sfr definitions
__sfr __at(RFCC_ADDR)         _rfcc;
__sfr __at(RFCCRH_ADDR)       _rfccrh;
__sfr __at(RFCCRL_ADDR)       _rfccrl;

#define RFCC                  _rfcc
#define RFCCRH                _rfccrh
#define RFCCRL                _rfccrl

// RFCC (Resistance to Frequency Converter) register definitions
#define RFCC_CH_SEL_EXT_BIT          0
#define RFCC_OE_BIT                  1
#define RFCC_OVF_BIT                 2
#define RFCC_MODE_BIT                3
#define RFCC_START_BIT               4
#define RFCC_CH_SEL_BIT0             5

#define RFCC_OUTPUT_DISABLED         0x00
#define RFCC_OUTPUT_ENABLED          (1 << RFCC_OE_BIT)

#define RFCC_OVERFLOW                (1 << RFCC_OVF_BIT)

#define RFCC_MODE_R_TYPE             0x00
#define RFCC_MODE_C_TYPE             (1 << RFCC_MODE_BIT)

#define RFCC_START                   (1 << RFCC_START_BIT)

#define RFCC_CH_NONE                 (7 << RFCC_CH_SEL_BIT0)
#define RFCC_CH_RFC0_PA4             0x00
#define RFCC_CH_RFC1_PA0             (1 << RFCC_CH_SEL_BIT0)
#define RFCC_CH_RFC2_PA3             (4 << RFCC_CH_SEL_BIT0)
#define RFCC_CH_RFC3_PB7             (5 << RFCC_CH_SEL_BIT0)
#define RFCC_CH_RFC4_PB6             (6 << RFCC_CH_SEL_BIT0)
#define RFCC_CH_RFC5_PB4             ((1 << RFCC_CH_SEL_EXT_BIT) | 0x00)
#define RFCC_CH_RFC6_PB3             ((1 << RFCC_CH_SEL_EXT_BIT) | (1 << RFCC_CH_SEL_BIT0))
#define RFCC_CH_RFC7_PB2             ((1 << RFCC_CH_SEL_EXT_BIT) | (2 << RFCC_CH_SEL_BIT0))
#define RFCC_CH_RFC8_PB1             ((1 << RFCC_CH_SEL_EXT_BIT) | (3 << RFCC_CH_SEL_BIT0))
#define RFCC_CH_RFC9_PB0             ((1 << RFCC_CH_SEL_EXT_BIT) | (4 << RFCC_CH_SEL_BIT0))

#endif //__PDK_DEVICE_PERIPH_RFC_H__
