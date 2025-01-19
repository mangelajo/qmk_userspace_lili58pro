# Notes

This is a fork of the QMK Userspace template repository, where I build
my keymap and firmware for my Lili58 Pro keyboard.

# Setup

1. Run the normal `qmk setup` procedure if you haven't already done so -- see [QMK Docs](https://docs.qmk.fm/#/newbs) for details.
2. Clone this fork to your local machine
3. Enable userspace in QMK config using `qmk config user.overlay_dir="$(realpath qmk_userspace_lili58pro)"`


# Building

`qmk flash -kb lily58/rev1 -km ajo_mac_es -e CONVERT_TO=promicro_rp2040`

The CONVERT_TO is necessary because the keyboard definition and most of the
code is made to be compatible with the AVR microcontroller, and I am using
a RP2040 microcontroller with the [promicro rp2040 board](https://keeb.io/products/rp2040-pro-micro-usb-c-controller).

```
Ψ Compiling keymap with gmake -r -R -f builddefs/build_keyboard.mk -s flash KEYBOARD=lily58/rev1 KEYMAP=ajo_mac_es KEYBOARD_FILESAFE=lily58_rev1 TARGET=lily58_rev1_ajo_mac_es VERBOSE=false COLOR=true SILENT=false QMK_BIN="qmk" CONVERT_TO=promicro_rp2040 QMK_USERSPACE=/Users/ajo/qmk_userspace_lili58pro MAIN_KEYMAP_PATH_1=/Users/ajo/qmk_userspace_lili58pro/keyboards/lily58/rev1/keymaps/ajo_mac_es MAIN_KEYMAP_PATH_2=/Users/ajo/qmk_userspace_lili58pro/keyboards/lily58/rev1/keymaps/ajo_mac_es MAIN_KEYMAP_PATH_3=/Users/ajo/qmk_userspace_lili58pro/keyboards/lily58/rev1/keymaps/ajo_mac_es MAIN_KEYMAP_PATH_4=/Users/ajo/qmk_userspace_lili58pro/keyboards/lily58/rev1/keymaps/ajo_mac_es MAIN_KEYMAP_PATH_5=/Users/ajo/qmk_userspace_lili58pro/keyboards/lily58/rev1/keymaps/ajo_mac_es


arm-none-eabi-gcc (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)
Copyright (C) 2020 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Size before:
   text	   data	    bss	    dec	    hex	filename
      0	  38536	      0	  38536	   9688	lily58_rev1_ajo_mac_es_promicro_rp2040.uf2

Copying lily58_rev1_ajo_mac_es_promicro_rp2040.uf2 to qmk_firmware folder                           [OK]
Copying lily58_rev1_ajo_mac_es_promicro_rp2040.uf2 to userspace folder                              [OK]

Size after:
   text	   data	    bss	    dec	    hex	filename
      0	  38536	      0	  38536	   9688	lily58_rev1_ajo_mac_es_promicro_rp2040.uf2

Flashing for bootloader: rp2040
Waiting for drive to deploy...
````

At this point you can double-press the reset button on the keyboard to enter bootloader mode, and the firmware will be flashed.

In most cases, the main logic runs on the left side of the keyboard, so you only need to flash that part, unless you are changing anything specific to the
right side or any general settings (like debounce time, etc -I am guessing here-), or changing to a different version of the qmk base firmware.

If you want to be safe, repeat the flash on the right side.
