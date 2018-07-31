/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Kinesis-like layout for ErgoDox EZ.  Mimics UK layout in generic PC mode. *
 *                                                                           *
 * Caveats:                                                                  *
 *                                                                           *
 *   - The ErgoDox doesn't have a dedicated function row.  To toggle the     *
 *     embedded layer, tap the ErgoDox's extra key beneath the right shift;  *
 *     you can also hold it down to access the embedded layer  momentarily.  *
 *     The 3x5 grid of letters on the left split provides F1 through F15     *
 *     when the embedded layer is active.                                    *
 *                                                                           *
 *   - The keys on the inner column of each split (which don't exist on the  *
 *     Kinesis) are assigned to media keys.                                  *
 *                                                                           *
 * v1.0.0                                                                    *
 *                                                                           *
 * Joe Cridge, 2018.                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

/**
 * Keyboard layers
 */

#define  BASE  0  /* Default layer             */
#define  MBED  1  /* 'Embedded' (numpad) layer */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ergodox(

    /**
     * BASE: Left hand
     *
     *        ,--------------------------------------------------.
     *        | = +    | 1 !  | 2 "  | 3 £  | 4 $  | 5 %  | Mute |
     *        |--------+------+------+------+------+-------------|
     *        | Tab    | Q    | W    | E    | R    | T    | VolU |
     *        |--------+------+------+------+------+------|      |
     *        | Caps   | A    | S    | D    | F    | G    |------|
     *        |--------+------+------+------+------+------| VolD |
     *        | Shift  | Z    | X    | C    | V    | B    |      |
     *        `--------+------+------+------+------+-------------'
     *          | #### | ` ¬  | \ |  | Left | Rght |
     *          `----------------------------------'
     *                                                    ,-------------.
     *                                                    | Ctrl | Alt  |
     *                                             ,------+------+------|
     *                                             | Bksp | Del  | Home |
     *                                             |      |      |------|
     *                                             |      |      | End  |
     *                                             `--------------------'
     */

     KC_EQL,   KC_1,    KC_2,     KC_3,     KC_4,     KC_5,     KC_MUTE,
     KC_TAB,   KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,     KC_VOLU,
     KC_CAPS,  KC_A,    KC_S,     KC_D,     KC_F,     KC_G,
     KC_LSFT,  KC_Z,    KC_X,     KC_C,     KC_V,     KC_B,     KC_VOLD,
     KC_NO,    KC_GRV,  KC_NUBS,  KC_LEFT,  KC_RGHT,

                                                      KC_LCTL,  KC_LALT,
                                                                KC_HOME,
                                            KC_BSPC,  KC_DEL,   KC_END,

    /**
     * BASE: Right hand
     *
     *               ,--------------------------------------------------.
     *               | Play | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  | - _    |
     *               |------+------+------+------+------+------+--------|
     *               | Next | Y    | U    | I    | O    | P    | # ~    |
     *               |      |------+------+------+------+------+--------|
     *               |------| H    | J    | K    | L    | ; :  | ' @    |
     *               | Prev |------+------+------+------+------+--------|
     *               |      | N    | M    | , <  | . >  | / ?  | Shift  |
     *               `-------------+------+------+------+------+--------'
     *                             | Up   | Down | [ {  | ] }  | MBED |
     *                             `----------------------------------'
     *        ,-------------.
     *        | Alt  | Ctrl |
     *        |------+------+------.
     *        | PgUp | Entr | Spce |
     *        |------|      |      |
     *        | PgDn |      |      |
     *        `--------------------'
     */

     KC_MPLY,  KC_6,     KC_7,   KC_8,     KC_9,     KC_0,     KC_MINS,
     KC_MNXT,  KC_Y,     KC_U,   KC_I,     KC_O,     KC_P,     KC_NUHS,
               KC_H,     KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
     KC_MPRV,  KC_N,     KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                         KC_UP,  KC_DOWN,  KC_LBRC,  KC_RBRC,  TT(MBED),

     KC_RALT,  KC_RCTL,
     KC_PGUP,
     KC_PGDN,  KC_ENT,   KC_SPC

  ),

  [MBED] = LAYOUT_ergodox(

    /**
     * MBED: Left hand
     *
     *        ,--------------------------------------------------.
     *        |        |      |      |      |      |      |      |
     *        |--------+------+------+------+------+-------------|
     *        |        | F1   | F2   | F3   | F4   | F5   |      |
     *        |--------+------+------+------+------+------|      |
     *        |        | F6   | F7   | F8   | F9   | F10  |------|
     *        |--------+------+------+------+------+------|      |
     *        |        | F11  | F12  | F13  | F14  | F15  |      |
     *        `--------+------+------+------+------+-------------'
     *          |      |      |      |      |      |
     *          `----------------------------------'
     *                                                    ,-------------.
     *                                                    |      |      |
     *                                             ,------|------|------|
     *                                             |      |      |      |
     *                                             |      |      |------|
     *                                             |      |      |      |
     *                                             `--------------------'
     */

     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
     KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
     KC_TRNS,  KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                       KC_TRNS,  KC_TRNS,
                                                                 KC_TRNS,
                                             KC_TRNS,  KC_TRNS,  KC_TRNS,

    /**
     * MBED: Right hand
     *
     * These are all numpad keys, save for the equals key, which (in PC mode)
     * actually just sends the regular =+ key.
     *
     *               ,--------------------------------------------------.
     *               |      |      | NmLk | =    | /    | *    |        |
     *               |------+------+------+------+------+------+--------|
     *               |      |      | 7    | 8    | 9    | -    |        |
     *               |      |------+------+------+------+------+--------|
     *               |------|      | 4    | 5    | 6    | +    |        |
     *               |      |------+------+------+------+------+--------|
     *               |      |      | 1    | 2    | 3    | Entr |        |
     *               `-------------+------+------+------+------+--------'
     *                             |      |      | .    | Entr |      |
     *                             `----------------------------------'
     *        ,-------------.
     *        |      |      |
     *        |------+------+------.
     *        |      |      | 0    |
     *        |------|      |      |
     *        |      |      |      |
     *        `--------------------'
     */

     KC_TRNS,  KC_TRNS,  KC_NLCK,  KC_EQL,   KC_PSLS,  KC_PAST,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_P7,    KC_P8,    KC_P9,    KC_PMNS,  KC_TRNS,
               KC_TRNS,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_P1,    KC_P2,    KC_P3,    KC_PENT,  KC_TRNS,
                         KC_TRNS,  KC_TRNS,  KC_PDOT,  KC_PENT,  KC_TRNS,

     KC_TRNS,  KC_TRNS,
     KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_P0

  ),

};


/**
 * Called whenever the standard HID indicators are updated
 */

void
led_set_user (uint8_t usb_led)
{

  /**
   * Use the first (red) LED for caps lock
   */

  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    ergodox_right_led_1_on ();
  } else {
    ergodox_right_led_1_off ();
  }


  /**
   * Use the second (green) LED for num lock.
   *
   * Here we actually turn the LED _off_ when num lock is _on_.
   * This is because I find the light annoying -- much like the
   * annoyance when num lock is off and the number keys don't
   * work!
   */

  if (usb_led & (1<<USB_LED_NUM_LOCK)) {
    ergodox_right_led_2_off ();
  } else {
    ergodox_right_led_2_on ();
  }

}

/**
 * Run once during initialisation
 */

void
matrix_init_user (void)
{
  /* Do nothing */
}


/**
 * Run constantly as a background loop
 */

void
matrix_scan_user (void)
{

  uint8_t layer = biton32 (layer_state);


  /**
   * Turn off the LED on the Teensy board
   */

  ergodox_board_led_off ();


  /* Leave the first two LEDs as caps lock and num lock */


  /**
   * Use the third (blue) LED to indicate the embedded layer.
   * This overrides the default behaviour (scroll lock).
   */

  if (layer == MBED) {
    ergodox_right_led_3_on ();
  } else {
    ergodox_right_led_3_off ();
  }

}
