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

#ifndef __PDK_DEVICE_PERIPH_PORT_C_H__
#define __PDK_DEVICE_PERIPH_PORT_C_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/device/periph/port_c.h" by itself."
#endif

// __sfr definitions
__sfr __at(PCDIER_ADDR)      _pcdier;
__sfr __at(PC_ADDR)          _pc;
__sfr __at(PCC_ADDR)         _pcc;
__sfr __at(PCPH_ADDR)        _pcph;

#define PCDIER               _pcdier
#define PC                   _pc
#define PCC                  _pcc
#define PCPH                 _pcph

#if defined(PCPL_ADDR)
  __sfr __at(PCPL_ADDR)        _pcpl;
  #define PCPL                 _pcpl
#endif

#endif //__PDK_DEVICE_PERIPH_PORT_C_H__
