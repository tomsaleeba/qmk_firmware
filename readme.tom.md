## Setup
  1. git clone
  1. cd qmk_firmware
  1. util/qmk_install.sh
  1. `make git-submodule`

Can also use `flash` instead of `compile`. It seems that `sudo` is
*not* required any longer, yay.

## ergoslab
  1. `bin/qmk compile -kb ergoslab -km tomsaleeba`

## ergodox ez
  1. `bin/qmk compile -kb ergodox_ez -km tomsaleeba`, or
  1. `bin/qmk compile -kb ergodox_ez -km tomsaleeba-minimal`

## ergodox infinity
  1. `sudo env CFLAGS="-Wno-error=deprecated" make ergodox_infinity:tomsaleeba:dfu-util`
     (we need sudo to write to the micro controller)
  1. while that is building, plug the left half into the pc directly and put it
     into flash mode
  1. now we'll do the right side with:
     `sudo env CFLAGS="-Wno-error=deprecated" make ergodox_infinity:tomsaleeba:dfu-util MASTER=right`
  1. plug right half in directly, put it into flash mode

  Note: you can get away with flashing only the right when it's just a keymap
  change.

  Note2: you can also use `tomsaleeba-minimal` for the ergodox infinity

## ergotravel
  1. `bin/qmk compile -kb ergotravel -km tomsaleeba`
