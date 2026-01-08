# split-keyboard-map
keymap for split keyboard that I use

```
# install qmk first, to get a fast repo clone
qmk setup # fast qmk repo clone
sudo apt-get install \ # probably just with gcc-avr and avr-libc it's enough
  gcc-avr avr-libc binutils-avr \
  dfu-programmer dfu-util avrdude
ln -s $(pwd)/split-keyboard-map/lily58-noxmap/ $(pwd)/qmk_firmware/keyboards/lily58/keymaps/noxmap/
cd qmk_firmware/
qmk compile -kb lily58/rev1 -km noxmap
qmk flash -kb lily58/rev1 -km noxmap -bl dfu 
```
Can't flash? use `dfu-programmer` then flash it

```
$ qmk flash -kb lily58/rev1 -km noxmap -bl dfu
 Ψ Compiling keymap with gmake -r -R -f
builddefs/build_keyboard.mk -s dfu KEYBOARD=lily58/rev1 KEYMAP=noxmap KEYBOARD_FILESAFE=lily58_rev1 TARGET=lily58_rev1_noxmap VERBOSE=false COLOR=true SILENT=false QMK_BIN="qmk"
avr-gcc (crosstool-NG 1.27.0.82_7f9d704 - qmk/qmk_toolchains @ a55a2b0)
15.2.0 Copyright (C)
2025 Free Software Foundation, Inc.
[OK] Checking file size of lily58_rev1_noxmap.hex
[OK] * The firmware size is fine - 23250/28672 (81%, 5422 bytes free)
Bootloader Version: 0x00 (0)
Checking memory from 0x0 to 0x6FFF... Empty.
Chip already blank, to force erase use --force. Checking memory from 0x0 to 0x5AFF... Empty.
0% 100% Programming 0x5B00 bytes...
[ X ERROR Memory write error, use debug for more info.

$ dfu-programmer --targets
$ dfu-programmer atmega32u4 erase
```
