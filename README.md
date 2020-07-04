# pdk-includes
This repository contains include files for Padauk MCUs.

This repo is intended to be integrated into other projects either as a git Submodule or by manual file copy.

This repo should be installed into a pdk/ subdirectory in the root include file directory of a parent project.

#### To install as a git Submodule:
- From the root include directory:
  - `git submodule add https://github.com/free-pdk/pdk-includes.git pdk`
- More info: https://git-scm.com/book/en/v2/Git-Tools-Submodules

#### These include files assume the use of:
- The open source SDCC C compiler: http://sdcc.sourceforge.net/

#### File Layout:
- **pdk/device.h** - The main include file.
  - Factory that pulls in the appropriate pdk/device/XXX.h include file and other supporting files.
    - NOTE: Requires definition of the intended Padauk IC device, usually by specifying `-D$(DEVICE)` on the SDCC command line
- **pdk/device/XXX.h** - The main device specific include files, one per device.
  - Contain device specific configuration values like: register addresses, fuse address/values, factory calibration address(es), peripheral configuration, etc...
  - Usually pulled in automatically including pdk/device.h.
    - NOTE: If needed, up to one of these can be pulled in instead of pdk/device.h, but some of the other includes below would also need to be pulled in separately.  
- **pdk/device/periph/XXX.h** - Common device peripheral include files.
  - Contain peripheral specific register __sfr and value definitions.
  - The appropriate ones are pulled in automatically by pdk/device/XXX.h files.
  - When there is enough commonality between devices, they share the same peripheral file (with some configurability allowed), otherwise the peripheral files are split and the pdk/device/XXX.h file pulls in the appropriate one.
- **pdk/util.h** - Common utility macros.
  - Contains macros for built-in opcodes and inline assembler statements
  - This is pulled in automatically by pdk/device.h
- **pdk/fuse.h** - 
  - Contains a macro for setting the FUSE word at the appropriate address.
    - The FUSE address is usually the last word of the device
    - Requires definition of FUSE_ADDR and FUSE values, usually performed by pdk/device/XXX.h.
  - This is pulled in automatically by pdk/device.h
- **pdk/factory_calibration.h** - Factory calibration macros 
  - Contains macros for using factory installed calibration values (IHRCR and/or BGTR).
    - OTP devices usually only include factory calibration for BGTR (bandgap)
    - MTP devices usually contain factory calibration for boty IHRCR (internal 16MHz high speed oscillator) as well at BGTR (bandgap)
    - Requires definition of FACTORY_IHRCR_ADDR and/or FACTORY_BGTR_ADDR values, usually performed by pdk/device/XXX.h.
  - This is pulled in automatically by pdk/device.h
- **pdk/sysclock.h** - System clock macros
  - Contains macros for setting the system clock to the various IHRC and ILRC frequencies.
    - Requires definition of CLKMD_* values, usually performed by pdk/device/XXX.h.
  - This is pulled in automatically by pdk/device.h

