## Setup
  1. git clone
  1. cd qmk_firmware
  1. util/qmk_install.sh
  1. make git-submodule

## ergodox ez
  1. make ergodox_ez:tom
  1. flash with teensy loader https://www.pjrc.com/teensy/loader.html

## ergodox infinity
  1. make ergodox_infinity:tom
  1. put left half into flash mode
  1. `sudo make ergodox_infinity:tom:dfu-util`
  1. put right half into flash mode
  1. `sudo make ergodox_infinity:tom:dfu-util MASTER=right`
