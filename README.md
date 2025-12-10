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
qmk compile -kb lily58/rev1 -km noxma'p
qmk flash -kb lily58/rev1 -km noxmap -bl dfu 
```
