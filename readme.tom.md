## Setup
  1. `git clone`
  1. `cd qmk_firmware`
  1. `venv3`
  1. `pip install qmk`
  1. `qmk setup`

Can also use `compile` instead of `flash`.

## ergoslab
  1. `qmk flash -kb ergoslab -km tomsaleeba`

## Concertina
  1. `qmk flash -kb handwired/concertina/64key -km tomsaleeba`

## ergodox ez
  1. `qmk flash -kb ergodox_ez -km tomsaleeba`, or
  1. `qmk flash -kb ergodox_ez -km tomsaleeba-minimal`

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
  1. `qmk flash -kb ergotravel -km tomsaleeba`
