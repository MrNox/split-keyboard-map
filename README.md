# split-keyboard-map
keymap for split keyboard that I use

```
ln -s $(pwd)/split-keyboard-map/lily58-noxmap/ $(pwd)/qmk_firmware/keyboards/lily58/keymaps/noxmap
cd qmk_firmware/
make lily58/rev1:noxmap:dfu
```
