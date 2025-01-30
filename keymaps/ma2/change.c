/*!
 *	@flie	change.c
 *	@brief
 *	@author Ma2
 *	@date   2025/01/22
 *	$Revision: $
 *
 */


#include QMK_KEYBOARD_H

#include "ledmap.h"

extern uint16_t NUM_LAYERS( void );

//#ifdef RGB_MATRIX_ENABLE
//#include "rgb_matrix.h"

/*!
 *  @fn
 *  ./qmk_firmware/quantum/split_common/split_util.c
 *  @brief  void keyboard_post_init_user( void );
 *  @return 戻り値 ... なし
 *  @sa     参照すべき関数を書けばリンクが貼れる
 *  @detail https://docs.qmk.fm/features/rgb_matrix#rgb-matrix-effects
 *          「RGB Matrix Effects」を参照
 *
 */
void keyboard_post_init_user( void )
{
    //! LEDの初期設定値は ./rev4_1/config.h の RGB_MATRIX_DEFAULT_MODE で設定できる
//    RGB_MATRIX_NONE // 0 = エフェクトなし
//    rgb_matrix_get_mode( RGB_MATRIX_SOLID_COLOR );  // 1 = エフェクトを「固定色（Solid Color）」に設定
//    RGB_MATRIX_BREATHING  // 5 = エフェクトを「呼吸エフェクト（Breathing）」に設定
}



/*!
 *  @fn
 *  @brief  set_color
 *  @param  int index        ... LEDインデックス(0 からRGB_MATRIX_LED_COUNT - 1)
 *  @param  uint8_t hsvred   ... 色相(Hue)
 *  @param  uint8_t hsvgreen ... 彩度(Saturation, Chroma)
 *  @param  uint8_t hsvblue  ... 明度(Value, Brightness)
 *  @return 戻り値 ... なし
 *  @sa     参照すべき関数を書けばリンクが貼れる
 *  @detail https://ja.wikipedia.org/wiki/HSV%E8%89%B2%E7%A9%BA%E9%96%93
 *
 */
 void set_color( uint8_t index, uint8_t hsvred, uint8_t hsvgreen, uint8_t hsvblue )
{
    HSV hsv = (HSV){ hsvred, hsvgreen, hsvblue };
    if( hsv.v > rgb_matrix_get_val() ){
        hsv.v = rgb_matrix_get_val();
    }

    RGB rgb = hsv_to_rgb( hsv );
    rgb_matrix_set_color( index, rgb.r, rgb.g, rgb.b );
}



/*!
 *  @fn
 *  @brief  set_color_all
 *  @param  uint8_t hsvred   ... 色相(Hue)
 *  @param  uint8_t hsvgreen ... 彩度(Saturation, Chroma)
 *  @param  uint8_t hsvblue  ... 明度(Value, Brightness)
 *  @return 戻り値 ... なし
 *  @sa     参照すべき関数を書けばリンクが貼れる
 *  @detail https://ja.wikipedia.org/wiki/HSV%E8%89%B2%E7%A9%BA%E9%96%93
 *
 */
void set_color_all( uint8_t hsvred, uint8_t hsvgreen, uint8_t hsvblue )
{
    HSV hsv = (HSV){ hsvred, hsvgreen, hsvblue };
    if( hsv.v > rgb_matrix_get_val() ){
        hsv.v = rgb_matrix_get_val();
    }

    RGB rgb = hsv_to_rgb( hsv );
    rgb_matrix_set_color_all( rgb.r, rgb.g, rgb.b );
}



/*!
 *  @fn
 *  @brief  rgb_matrix_indicators_advanced_user
 *  @param  uint8_t led_min ... LEDインデックスの最小値
 *  @param  uint8_t led_max ... LEDインデックスの最大値
 *  @return true を返す場合:
 *          RGBマトリックスのカスタムインジケータ処理が成功し、
 *          既定のインジケータ処理（例えばCaps LockやNum Lockの
 *          状態表示など）を上書きすることを示します。
 *          ⇢あなたのカスタムロジックが優先されます。
 *          false を返す場合:
 *          カスタムインジケータ処理が成功しなかった、
 *          または既定のインジケータ処理を維持することを示します。
 *          ⇢QMKのデフォルトのインジケータロジックが引き続き動作します。
 *  @sa     参照すべき関数を書けばリンクが貼れる
 *  @detail
 *
 */
bool rgb_matrix_indicators_advanced_user( uint8_t led_min, uint8_t led_max )
{
    uint8_t uLayer = 0;
//    HSV hsv = { 0x7f, 0x7f, 0x7f };
    RGB rgb;
    const HSV hsv[] = {
        { HSV_CHARTREUSE }, // 黄緑色(ライムグリーン,ブライトグリーン)
        { HSV_BLUE },       // 青色
        { HSV_RED },        // 赤色
//      { HSV_TURQUOISE },  // 青緑色(ターコイズ)
        { HSV_TEAL },       // 青緑色(ティール)
        { HSV_WHITE }       // 白色
    };

    //! 初期化のために全てのLEDを消灯
    rgb_matrix_set_color_all( RGB_OFF );
    uLayer = get_highest_layer( layer_state | default_layer_state );

    //! レイヤー共通部分の設定 ... Layer_Common_Parts
    //! レイヤー番号からバックライトの色を設定
    rgb = hsv_to_rgb( hsv[ uLayer ] );

    //! 各キーへの色設定
    if( is_keyboard_left() ){
        //! 左側キーボードの場合
        rgb_matrix_set_color( LD_L0,   rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_B,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_G,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_T,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_R,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_F,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_V,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_BB,   rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_VV,   rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_C,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_D,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_E,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_W,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_S,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_X,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_Z,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_A,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_Q,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_TAB,  rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_LCTL, rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_LSFT, rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_TT,   rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_GG,   rgb.r, rgb.g, rgb.b );
    }
    else{
        //! 右側キーボードの場合
        rgb_matrix_set_color( LD_R0,   rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_N,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_H,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_Y,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_U,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_J,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_M,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_NN,   rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_MM,   rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_COMM, rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_K,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_I,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_O,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_L,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_DOT,  rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_SLSH, rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_SCLN, rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_P,    rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_BSPC, rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_QUOT, rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_ESC,  rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_YY,   rgb.r, rgb.g, rgb.b );
        rgb_matrix_set_color( LD_HH,   rgb.r, rgb.g, rgb.b );
    }
    return true;
}

//#endif // RGB_MATRIX_ENABLE



/*!
 *  @fn
 *  @brief  process_record_user
 *  @param  uint16_t keycode ...
 *  @param  keyrecord_t *record ...
 *  @return true を返す場合:
 *          ⇢あなたのカスタムロジックが優先されます。
 *          false を返す場合:
 *          ⇢QMKのデフォルトのインジケータロジックが引き続き動作します。
 *  @sa     参照すべき関数を書けばリンクが貼れる
 *  @detail
 *
 */
bool process_record_user( uint16_t keycode, keyrecord_t *record )
{
    // 現在有効なレイヤーの中で最も高いレイヤー番号を取得
    uint16_t nIndex = 0;
    bool bReturn = false;

    for( nIndex = 0; nIndex < NUM_LAYERS(); nIndex++ ){
        if( keycode == TO( nIndex ) && (record->event.pressed != false) ){
            // TO(nIndex)が押されたときの追加処理
            layer_move( nIndex );
        }
    }
    return bReturn; // 他のキーを通常通り処理
}


