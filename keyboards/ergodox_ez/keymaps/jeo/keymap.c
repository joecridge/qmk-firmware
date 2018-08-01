/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Jeo layout for ErgoDox EZ.  Intended for use on Ubuntu under a UK layout. *
 * When there's no clear winner for what to do with a certain key, this      *
 * layout just copies whatever the (UK, PC mode) Kinesis Advantage does in   *
 * its default configuration.                                                *
 *                                                                           *
 * Caveats:                                                                  *
 *                                                                           *
 *   - In order to provide the en dash and interpunct above the period and   *
 *     comma, respectively, this layout _emulates_ the action of the shift   *
 *     key through an 'upper' modifier.  If you need to register the shift   *
 *     keys _on its own_, or need to use Shift+, or Shift+. as part of a     *
 *     control sequence, use the button immediately beneath the (virtual)    *
 *     left shift key instead.  (This extra button doesn't exist on the      *
 *     Kinesis.)                                                             *
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
#define  CAPS  1  /* Upper-case layer          */
#define  SYMB  2  /* Symbol layer              */
#define  MBED  3  /* Kinesis-like keypad layer */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ergodox(

    /**
     * BASE: Left hand
     *
     *        ,--------------------------------------------------.
     *        | =      | 1    | 2    | 3    | 4    | 5    | Mute |
     *        |--------+------+------+------+------+-------------|
     *        | Tab    | q    | g    | m    | l    | w    | VolU |
     *        |--------+------+------+------+------+------|      |
     *        | Symbol | d    | s    | t    | n    | r    |------|
     *        |--------+------+------+------+------+------| VolD |
     *        | Upper  | z    | x    | c    | v    | j    |      |
     *        `--------+------+------+------+------+-------------'
     *          | Shft | `    | \    | Left | Rght |
     *          `----------------------------------'
     *                                                    ,-------------.
     *                                                    | Ctrl | Alt  |
     *                                             ,------+------+------|
     *                                             | Bksp | Esc  | Home |
     *                                             |      |      |------|
     *                                             |      |      | End  |
     *                                             `--------------------'
     */

     KC_EQL,    KC_1,    KC_2,     KC_3,     KC_4,     KC_5,     KC_MUTE,
     KC_TAB,    KC_Q,    KC_G,     KC_M,     KC_L,     KC_W,     KC_VOLU,
     MO(SYMB),  KC_D,    KC_S,     KC_T,     KC_N,     KC_R,
     MO(CAPS),  KC_Z,    KC_X,     KC_C,     KC_V,     KC_J,     KC_VOLD,
     KC_LSFT,   KC_GRV,  KC_NUBS,  KC_LEFT,  KC_RGHT,

                                                       KC_LCTL,  KC_LALT,
                                                                 KC_HOME,
                                             KC_BSPC,  KC_ESC,   KC_END,

    /**
     * BASE: Right hand
     *
     *               ,--------------------------------------------------.
     *               | Play | 6    | 7    | 8    | 9    | 0    | -      |
     *               |------+------+------+------+------+------+--------|
     *               | Next | y    | f    | u    | b    | -    | #      |
     *               |      |------+------+------+------+------+--------|
     *               |------| i    | a    | e    | o    | h    | Symbol |
     *               | Prev |------+------+------+------+------+--------|
     *               |      | k    | p    | ,    | .    | /    | Upper  |
     *               `-------------+------+------+------+------+--------'
     *                             | Up   | Down | [    | ]    | MBED |
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
     KC_MNXT,  KC_Y,     KC_F,   KC_U,     KC_B,     KC_MINS,  KC_NUHS,
               KC_I,     KC_A,   KC_E,     KC_O,     KC_H,     MO(SYMB),
     KC_MPRV,  KC_K,     KC_P,   KC_COMM,  KC_DOT,   KC_SLSH,  MO(CAPS),
                         KC_UP,  KC_DOWN,  KC_LBRC,  KC_RBRC,  TT(MBED),

     KC_RALT,  KC_RCTL,
     KC_PGUP,
     KC_PGDN,  KC_ENT,   KC_SPC

  ),

  [CAPS] = LAYOUT_ergodox(

    /**
     * CAPS: Left hand
     *
     *        ,--------------------------------------------------.
     *        | +      | !    | "    | £    | $    | %    |      |
     *        |--------+------+------+------+------+-------------|
     *        | TAB    | Q    | G    | M    | L    | W    |      |
     *        |--------+------+------+------+------+------|      |
     *        |        | D    | S    | T    | N    | R    |------|
     *        |--------+------+------+------+------+------|      |
     *        |        | Z    | X    | C    | V    | J    |      |
     *        `--------+------+------+------+------+-------------'
     *          |      | ¬    | |    | LEFT | RGHT |
     *          `----------------------------------'
     *                                                    ,-------------.
     *                                                    | CTRL | ALT  |
     *                                             ,------+------+------|
     *                                             | BKSP | ESC  | HOME |
     *                                             |      |      |------|
     *                                             |      |      | END  |
     *                                             `--------------------'
     */

     S(KC_EQL),    S(KC_1),    S(KC_2),     S(KC_3),     S(KC_4),     S(KC_5),     KC_TRNS,
     S(KC_TAB),    S(KC_Q),    S(KC_G),     S(KC_M),     S(KC_L),     S(KC_W),     KC_TRNS,
     KC_TRNS,      S(KC_D),    S(KC_S),     S(KC_T),     S(KC_N),     S(KC_R),
     KC_TRNS,      S(KC_Z),    S(KC_X),     S(KC_C),     S(KC_V),     S(KC_J),     KC_TRNS,
     KC_TRNS,      S(KC_GRV),  S(KC_NUBS),  S(KC_LEFT),  S(KC_RGHT),

                                                                      S(KC_LCTL),  S(KC_LALT),
                                                                                   S(KC_HOME),
                                                         S(KC_BSPC),  S(KC_ESC),   S(KC_END),

    /**
     * CAPS: Right hand
     *
     *               ,--------------------------------------------------.
     *               |      | ^    | &    | *    | (    | )    | _      |
     *               |------+------+------+------+------+------+--------|
     *               |      | Y    | F    | U    | B    | _    | ~      |
     *               |      |------+------+------+------+------+--------|
     *               |------| I    | A    | E    | O    | H    |        |
     *               |      |------+------+------+------+------+--------|
     *               |      | K    | P    | –    | ·    | ?    |        |
     *               `-------------+------+------+------+------+--------'
     *                             | UP   | DOWN | {    | }    |      |
     *                             `----------------------------------'
     *        ,-------------.
     *        | ALT  | CTRL |
     *        |------+------+------.
     *        | PGUP | ENTR | SPCE |
     *        |------|      |      |
     *        | PGDN |      |      |
     *        `--------------------'
     */

     KC_TRNS,     S(KC_6),     S(KC_7),   S(KC_8),     S(KC_9),        S(KC_0),     S(KC_MINS),
     KC_TRNS,     S(KC_Y),     S(KC_F),   S(KC_U),     S(KC_B),        S(KC_MINS),  S(KC_NUHS),
                  S(KC_I),     S(KC_A),   S(KC_E),     S(KC_O),        S(KC_H),     KC_TRNS,
     KC_TRNS,     S(KC_K),     S(KC_P),   UC(0x2013),  RALT(KC_DOT),   S(KC_SLSH),  KC_TRNS,
                               S(KC_UP),  S(KC_DOWN),  S(KC_LBRC),     S(KC_RBRC),  KC_TRNS,

     S(KC_RALT),  S(KC_RCTL),
     S(KC_PGUP),
     S(KC_PGDN),  S(KC_ENT),   S(KC_SPC)

  ),

  [SYMB] = LAYOUT_ergodox(

    /**
     * SYMB: Left hand
     *
     *        ,--------------------------------------------------.
     *        |        | §    | @    | £    | €    | ©    |      |
     *        |--------+------+------+------+------+-------------|
     *        |        | …    | _    | [    | ]    | ^    |      |
     *        |--------+------+------+------+------+------|      |
     *        |        | \    | /    | {    | }    | *    |------|
     *        |--------+------+------+------+------+------|      |
     *        |        | #    | $    | |    | ~    | `    |      |
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

     KC_TRNS,  UC(0x00A7),  S(KC_QUOT),  S(KC_3),     RALT(KC_4),  UC(0x00A9),  KC_TRNS,
     KC_TRNS,  UC(0x2026),  S(KC_MINS),  KC_LBRC,     KC_RBRC,     S(KC_6),     KC_TRNS,
     KC_TRNS,  KC_NUBS,     KC_SLSH,     S(KC_LBRC),  S(KC_RBRC),  S(KC_8),
     KC_TRNS,  KC_NUHS,     S(KC_4),     S(KC_NUBS),  S(KC_NUHS),  KC_GRV,      KC_TRNS,
     KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,

                                                                      KC_TRNS,        KC_TRNS,
                                                                                      KC_TRNS,
                                                         KC_TRNS,     KC_TRNS,        KC_TRNS,

    /**
     * SYMB: Right hand
     *
     *               ,--------------------------------------------------.
     *               |      | ®    | ‘    | ’    | “    | ”    |        |
     *               |------+------+------+------+------+------+--------|
     *               |      | !    | <    | >    | =    | &    |        |
     *               |      |------+------+------+------+------+--------|
     *               |------| ?    | (    | )    | -    | :    |        |
     *               |      |------+------+------+------+------+--------|
     *               |      | +    | %    | "    | '    | ;    |        |
     *               `-------------+------+------+------+------+--------'
     *                             |      |      |      |      |      |
     *                             `----------------------------------'
     *        ,-------------.
     *        |      |      |
     *        |------+------+------.
     *        |      |      |      |
     *        |------|      |      |
     *        |      |      |      |
     *        `--------------------'
     */

     KC_TRNS,  UC(0x00AE),  UC(0x2018),  UC(0x2019),  RALT(KC_V),  RALT(KC_B),  KC_TRNS,
     KC_TRNS,  S(KC_1),     S(KC_COMM),  S(KC_DOT),   KC_EQL,      S(KC_7),     KC_TRNS,
               S(KC_SLSH),  S(KC_9),     S(KC_0),     KC_MINS,     S(KC_SCLN),  KC_TRNS,
     KC_TRNS,  S(KC_EQL),   S(KC_5),     S(KC_2),     KC_QUOT,     KC_SCLN,     KC_TRNS,
                            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,

     KC_TRNS,  KC_TRNS,
     KC_TRNS,
     KC_TRNS,  KC_TRNS,        KC_TRNS

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
  set_unicode_input_mode(UC_LNX);
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
