# rollow-qmk-config
stores configuration for rollow split keyboard

- add `rollow` folder to `keyboards` folder in `https://github.com/qmk/qmk_firmware`
  - run cmd in `qmk_firmware` directory : `make rollow:speed2exe:dfu-split-right`, plug in right side of keyboard, it should auto flash
  - do the same for the left side
- symlink: `ln -s /home/zx/rollow-qmk-config/rollow/ /home/zx/qmk/qmk_firmware/keyboards/`
