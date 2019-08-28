## Setup
  1. git clone
  1. cd qmk_firmware
  1. util/qmk_install.sh
  1. `make git-submodule`

## ergodox ez
  1. `make ergodox_ez:tom`
  1. flash with teensy loader
      - GUI https://www.pjrc.com/teensy/loader.html or
      - CLI: teensy-loader-cli -mmcu=atmega32u4 -w ergodox_ez_tom.hex

## ergodox infinity
  1. `sudo env CFLAGS="-Wno-error=deprecated" make ergodox_infinity:tom:dfu-util`
  1. quickly, while that is building, plug the left half into the pc directly
     and put it into flash mode
  1. `sudo env CFLAGS="-Wno-error=deprecated" make ergodox_infinity:tom:dfu-util MASTER=right`
  1. plug right half in directly, put it into flash mode
