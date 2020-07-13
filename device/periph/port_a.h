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

#ifndef __PDK_DEVICE_PERIPH_PORT_A_H__
#define __PDK_DEVICE_PERIPH_PORT_A_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/device/periph/port_a.h" by itself."
#endif

// __sfr definitions
__sfr __at(PADIER_ADDR)      _padier;
__sfr __at(PA_ADDR)          _pa;
__sfr __at(PAC_ADDR)         _pac;
__sfr __at(PAPH_ADDR)        _paph;

#define PADIER               _padier
#define PA                   _pa
#define PAC                  _pac
#define PAPH                 _paph

// PIN definitions (also useful for PORTB/PORTC)
#define PIN0	               (1)
#define PIN1	               (1<<1)
#define PIN2	               (1<<2)
#define PIN3	               (1<<3)
#define PIN4	               (1<<4)
#define PIN5	               (1<<5)
#define PIN6	               (1<<6)
#define PIN7	               (1<<7)

#endif //__PDK_DEVICE_PERIPH_PORT_A_H__
