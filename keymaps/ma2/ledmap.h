#pragma once

// clang-format off
/*
  //,-------------------------------------------------------.  ,-------------------------------------------------------.
     LD_TAB,   LD_Q,   LD_W,   LD_E,   LD_R,   LD_T,   LD_TT,    LD_YY,   LD_Y,   LD_U,   LD_I,   LD_O,   LD_P, LD_BSPC,
  //|-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------|
    LD_LCTL,   LD_A,   LD_S,   LD_D,   LD_F,   LD_G,   LD_GG,    LD_HH,   LD_H,   LD_J,   LD_K,   LD_L, LD_SCLN,LD_QUOT,
  //|-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------|
    LD_LSFT,   LD_Z,   LD_X,   LD_C,   LD_V,   LD_B,                      LD_N,   LD_M,LD_COMM, LD_DOT, LD_SLSH, LD_ESC,
  //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
                                      LD_VV,  LD_BB,   LD_L0,    LD_R0,  LD_NN,  LD_MM
                                     //`---------------------'  `---------------------'
*/
// clang-format on


// clang-format off
/*
LAYOUT_split_3x6_3_ex2
        {  18,  17,  12,  11,   4,   3,  21},  {44,   26,  27,  34,  35,  40,   41 },
        {  19,  16,  13,  10,   5,   2,  22},  {45,   25,  28,  33,  36,  39,   42 },
        {  20,  15,  14,   9,   6,   1 },          {  24,  29,  32,  37,  38,   43 },
    { NO_LED, NO_LED, NO_LED,   8,   7,   0 }, { 23,  30,  31,  NO_LED, NO_LED, NO_LED }
*/
/*
LAYOUT_split_3x6_3
        {  24,  23,  18,  17,  10,   9 },          {  36,  37,  44,  45,  50,   51 },
        {  25,  22,  19,  16,  11,   8 },          {  35,  38,  43,  46,  49,   52 },
        {  26,  21,  20,  15,  12,   7 },          {  34,  39,  42,  47,  48,   53 },
    { NO_LED, NO_LED, NO_LED,  14,  13,   6 }, { 33,  40,  41,  NO_LED, NO_LED, NO_LED }
*/
// clang-format on



typedef enum {
    // left
#ifdef LAYOUT_split_3x6_3_ex2
    LD_L0 = 0,
#else
    //LAYOUT_split_3x6_3
    LD_L0 = 6,
#endif
    LD_B,
    LD_G,
    LD_T,
    LD_R,
    LD_F,
    LD_V,
    LD_BB,
    LD_VV,
    LD_C,
    LD_D,
    LD_E,
    LD_W,
    LD_S,
    LD_X,
    LD_Z,
    LD_A,
    LD_Q,
    LD_TAB,
    LD_LCTL,
    LD_LSFT,
#ifdef LAYOUT_split_3x6_3_ex2
    LD_TT,
    LD_GG,
#endif
    // right
#ifdef LAYOUT_split_3x6_3_ex2
    LD_R0,
#else
    //LAYOUT_split_3x6_3
    LD_R0 = 33,
#endif
    LD_N,
    LD_H,
    LD_Y,
    LD_U,
    LD_J,
    LD_M,
    LD_NN,
    LD_MM,
    LD_COMM,
    LD_K,
    LD_I,
    LD_O,
    LD_L,
    LD_DOT,
    LD_SLSH,
    LD_SCLN,
    LD_P,
    LD_BSPC,
    LD_QUOT,
    LD_ESC,
#ifdef LAYOUT_split_3x6_3_ex2
    LD_YY,
    LD_HH
#endif
}  led_map;
