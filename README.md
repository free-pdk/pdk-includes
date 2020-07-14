# pdk-includes
This repository contains include files for Padauk MCUs.

> Example code that uses these include files can be found here: [free-pdk-examples](https://github.com/free-pdk/free-pdk-examples)

### Warning: This is a work in progress and may change significantly before being considered stable.  Use at your own risk.

This repo is intended to be integrated into other projects either as a git Submodule or by manual file copy.

This repo should be installed into a pdk/ subdirectory in the root includes directory of a parent project.

#### To install as a git Submodule:
- From the root includes directory:
  - `git submodule add https://github.com/free-pdk/pdk-includes.git pdk`
- More info: https://git-scm.com/book/en/v2/Git-Tools-Submodules

#### These include files assume the use of:
- The open-source [Small Device C Compiler (SDCC)](http://sdcc.sourceforge.net/)
  - requires version 3.9.0 or newer, version 4.0.0+ preferred

### File Layout:
- [**device.h**](device.h) - The main include file.
  - Factory that pulls in the appropriate device/XXX.h include file and other supporting files.
    - NOTE: Requires definition of the intended Padauk IC device, usually by specifying `-D$(DEVICE)` on the SDCC command line
- [**device/XXX.h**](device/) - The main device specific include files, one per device.
  - Contain device specific configuration values like: register addresses, fuse address/values, factory calibration address(es), peripheral configuration, etc...
  - Usually pulled in automatically by including device.h.
    - NOTE: If needed, up to one of these can be included manually instead of by including device.h.  Doing so may also require manual inclusion of the other include files below.  
- [**device/periph/XXX.h**](device/periph/) - Common device peripheral include files.
  - Contain peripheral specific register __sfr and value definitions.
  - The appropriate ones are pulled in automatically by device/XXX.h files.
  - When there is enough commonality between devices, they share the same peripheral file (with some configurability allowed), otherwise the peripheral files are split and the device/XXX.h file pulls in the appropriate one.
- [**util.h**](util.h) - Common utility macros.
  - Contains macros for built-in opcodes and inline assembler statements
  - This is pulled in automatically by device.h
- [**fuse.h**](fuse.h) - 
  - Contains a macro for setting the FUSE word at the appropriate address.
    - The FUSE address is usually the last word of the device
    - Requires definition of FUSE_ADDR and FUSE values, usually performed by device/XXX.h.
  - This is pulled in automatically by device.h
- [**factory_calibration.h**](factory_calibration.h) - Factory calibration macros 
  - Contains macros for using factory installed calibration values (IHRCR and/or BGTR).
    - OTP devices usually only include factory calibration for BGTR (bandgap)
    - MTP devices usually contain factory calibration for boty IHRCR (internal 16MHz high speed oscillator) as well at BGTR (bandgap)
    - Requires definition of FACTORY_IHRCR_ADDR and/or FACTORY_BGTR_ADDR values, usually performed by device/XXX.h.
  - This is pulled in automatically by device.h
- [**sysclock.h**](sysclock.h) - System clock macros
  - Contains macros for setting the system clock to the various IHRC and ILRC frequencies.
    - Requires definition of CLKMD_* values, usually performed by device/XXX.h.
  - This is pulled in automatically by device.h

### Copyright and License:
- Copyright (C) 2019-2020 - Original version by freepdk (https://free-pdk.github.io)
- Copyright (C) 2020 - Major refactor by serisman (github@serisman.com)
- License: [GPL v2 (or later) + Linking Exception](LICENSE)
  - The linking exception allows this library to be linked (by SDCC) with proprietary (closed source) applications.
