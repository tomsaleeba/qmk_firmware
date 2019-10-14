## Setup
  1. git clone
  1. cd qmk_firmware
  1. util/qmk_install.sh
  1. `make git-submodule`

## ergodox ez
  1. `make ergodox_ez:tomsaleeba-minimal:teensy`

## ergodox infinity
  1. `sudo env CFLAGS="-Wno-error=deprecated" make ergodox_infinity:tomsaleeba-minimal:dfu-util`
  1. quickly, while that is building, plug the left half into the pc directly
     and put it into flash mode
  1. `sudo env CFLAGS="-Wno-error=deprecated" make ergodox_infinity:tomsaleeba-minimal:dfu-util MASTER=right`
  1. plug right half in directly, put it into flash mode
