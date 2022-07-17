#pragma once

// master side is the side connected to device
// flash left: make rollow:speed2exe:dfu-split-left
// flash right: make rollow:speed2exe:dfu-split-right
#define EE_HANDS

// This mirrors the master side matrix to the slave side for features that
// react or require knowledge of master side key presses on the slave side. The
// purpose of this feature is to support cosmetic use of key events (e.g. RGB
// reacting to keypresses).
// #define SPLIT_TRANSPORT_MIRROR

// This enables syncing of the layer state between both halves of the split
// keyboard. The main purpose of this feature is to enable support for use of
// things like OLED display of the currently active layer.
// #define SPLIT_LAYER_STATE_ENABLE

// This enables syncing of the Host LED status (caps lock, num lock, etc)
// between both halves of the split keyboard. The main purpose of this feature
// is to enable support for use of things like OLED display of the Host LED
// status.
// #define SPLIT_LED_STATE_ENABLE

// This enables transmitting modifier state (normal, weak and oneshot) to the
// non primary side of the split keyboard. The purpose of this feature is to
// support cosmetic use of modifer state (e.g. displaying status on an OLED
// screen).
// #define SPLIT_MODS_ENABLE

// This enables transmitting the current WPM to the slave side of the split
// keyboard. The purpose of this feature is to support cosmetic use of WPM
// (e.g. displaying the current value on an OLED screen).
// #define SPLIT_WPM_ENABLE

// This enables transmitting the current OLED on/off status to the slave side
// of the split keyboard. The purpose of this feature is to support state
// (on/off state only) syncing.
// #define SPLIT_OLED_ENABLE

// This enables transmitting the current ST7565 on/off status to the slave side
// of the split keyboard. The purpose of this feature is to support state
// (on/off state only) syncing.
// #define SPLIT_ST7565_ENABLE

// This enables transmitting the pointing device status to the master side of
// the split keyboard. The purpose of this feature is to enable use pointing
// devices on the slave side.
// #define SPLIT_POINTING_ENABLE


// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md
#define TAPPING_TERM 1024
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

// TODO: add LED stuff??
