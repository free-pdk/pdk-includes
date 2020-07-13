/*
  Copyright (C) 2020  serisman  <github@serisman.com>
  Copyright (C) 2019-2020  freepdk  https://free-pdk.github.io

  This library is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this library. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __PDK_DEVICE_PERIPH_EXTERNAL_OSCILLATOR_H__
#define __PDK_DEVICE_PERIPH_EXTERNAL_OSCILLATOR_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/device/periph/exernal_oscillator.h" by itself."
#endif

// __sfr definitions
__sfr __at(EOSCR_ADDR)        _eoscr;
#define EOSCR                 _eoscr

// EOSC (External Oscillator Setting) register definitions
#define EOSC_BG_LVR_SHUTDOWN_BIT     0
#if defined(__PDK_HAS_EOSC)
  #define EOSC_CRYSTAL_SEL_BIT0        5
  #define EOSC_ENABLE_BIT              7
#endif

#define EOSC_BG_LVR_SHUTDOWN         (1 << EOSC_BG_LVR_SHUTDOWN_BIT)
#if defined(__PDK_HAS_EOSC)
  #define EOSC_32KHZ_CRYSTAL           (1 << EOSC_CRYSTAL_SEL_BIT0)
  #define EOSC_1MHZ_CRYSTAL            (2 << EOSC_CRYSTAL_SEL_BIT0)
  #define EOSC_4MHZ_CRYSTAL            (3 << EOSC_CRYSTAL_SEL_BIT0)
  #define EOSC_ENABLE                  (1 << EOSC_BG_LVR_SHUTDOWN_BIT)
#endif

#endif //__PDK_DEVICE_PERIPH_EXTERNAL_OSCILLATOR_H__
