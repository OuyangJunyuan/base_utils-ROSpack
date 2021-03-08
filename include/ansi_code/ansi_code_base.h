#ifndef BASE_UTILS_ANSI_CODES_BASE_H
#define BASE_UTILS_ANSI_CODES_BASE_H

/**                         颜色码-基本
 *******************************************************************
    example：printf(BU_ANSI_NONE xxxx "%s\n","xxx");

ANSI控制码格式：
            \e[显示方式;前景色;背景色 m "输出字符串" \033[0m  、
            也可进行连续设置如下划线蓝色\e[4m\e[34m

    显示：
            0 (关闭属性)、8(消隐)
            1(粗体高亮)、22(非粗体)、
            4(单条下划线)、24(无下划线)、
            5(闪烁)、25(无闪烁)、
            7(反显、翻转前景色和背景色)、27(无反显)、
    颜色：
            简单:
                颜色:0(黑)、1(红)、2(绿)、 3(黄)、4(蓝)、5(洋红)、6(青)、7(白)
                前景色:
                        暗色: 30+x —— "\e[31m"  暗红
                        亮色: 90+x —— "\e[91m"  亮红
                背景色:
                        暗色: 40+x —— "\e[41m"  暗红
                        亮色:100+x —— "\e[101m" 亮红

            255色:
                x:
                16-231：6 × 6 × 6 立方（216色）: 16 + 36 × r + 6 × g + b (0 ≤ r, g, b ≤ 5)
                232-255：从黑到白的24阶灰度色
                前景色: "\e[38;5;xm"
                背景色："\e[48;5;xm"

            rgb:
                前景色："\e[38;2;<r>;<g>;<b>m"
                后景色："\e[48;2;<r>;<g>;<b>m"\
********************************************************************/
/**    color front/back ground prefix    */
#define BU_ANSI_PF_FG                           3
#define BU_ANSI_PF_FGH                          9
#define BU_ANSI_PF_BG                           4
#define BU_ANSI_PF_BGH                          10

/**    color suffix    */
#define BU_ANSI_SF_BLACK                        0
#define BU_ANSI_SF_RED                          1
#define BU_ANSI_SF_GREEN                        2
#define BU_ANSI_SF_YELLOW                       3
#define BU_ANSI_SF_BLUE                         4
#define BU_ANSI_SF_PURPLE                       5
#define BU_ANSI_SF_CYAN                         6
#define BU_ANSI_SF_GRAY                         7
#define BU_ANSI_SF_WHITE                        8

/**    frontground color    */
#define BU_ANSI_FG_BLACK                        "\e[30m"
#define BU_ANSI_FG_RED                          "\e[31m"
#define BU_ANSI_FG_GREEN                        "\e[32m"
#define BU_ANSI_FG_YELLOW                       "\e[33m"
#define BU_ANSI_FG_BLUE                         "\e[34m"
#define BU_ANSI_FG_PURPLE                       "\e[35m"
#define BU_ANSI_FG_CYAN                         "\e[36m"
#define BU_ANSI_FG_GRAY                         "\e[37m"
#define BU_ANSI_FG_WHITE                        "\e[38m"

/**    frontground light-color     */
#define BU_ANSI_FG_BLACK_H                      "\e[90m"
#define BU_ANSI_FG_RED_H                        "\e[91m"
#define BU_ANSI_FG_GREEN_H                      "\e[92m"
#define BU_ANSI_FG_YELLOW_H                     "\e[93m"
#define BU_ANSI_FG_BLUE_H                       "\e[94m"
#define BU_ANSI_FG_PURPLE_H                     "\e[95m"
#define BU_ANSI_FG_CYAN_H                       "\e[96m"
#define BU_ANSI_FG_GRAY_H                       "\e[97m"
#define BU_ANSI_FG_WHITE_H                      "\e[98m"

/**    background color     */
#define BU_ANSI_BG_BLACK                        "\e[40m"
#define BU_ANSI_BG_RED                          "\e[41m"
#define BU_ANSI_BG_GREEN                        "\e[42m"
#define BU_ANSI_BG_YELLOW                       "\e[43m"
#define BU_ANSI_BG_BLUE                         "\e[44m"
#define BU_ANSI_BG_PURPLE                       "\e[45m"
#define BU_ANSI_BG_CYAN                         "\e[46m"
#define BU_ANSI_BG_GRAY                         "\e[47m"
#define BU_ANSI_BG_WHITE                        "\e[48m"

/**    background light-color     */
#define BU_ANSI_BG_BLACK_H                      "\e[100m"
#define BU_ANSI_BG_RED_H                        "\e[101m"
#define BU_ANSI_BG_GREEN_H                      "\e[102m"
#define BU_ANSI_BG_YELLOW_H                     "\e[103m"
#define BU_ANSI_BG_BLUE_H                       "\e[104m"
#define BU_ANSI_BG_PURPLE_H                     "\e[105m"
#define BU_ANSI_BG_CYAN_H                       "\e[106m"
#define BU_ANSI_BG_GRAY_H                       "\e[107m"
#define BU_ANSI_BG_WHITE_H                      "\e[108m"



/**                         控制码
 *    example：printf(BU_ANSI_NONE xxxx "%s\n","xxx");
 *******************************************************************/
/**    font    **/
#define BU_ANSI_NONE                            "\e[0m"     //取消所有设置
#define BU_ANSI_BOLD                            "\e[1m"     //粗体
#define BU_ANSI_WEAK                            "\e[2m"     //弱化亮度
#define BU_ANSI_ITALIC                          "\e[3m"     //斜体
#define BU_ANSI_UNDERLINE                       "\e[4m"     //下划线
#define BU_ANSI_UNDERLINE_MID                   "\e[9m"     //中划线
#define BU_ANSI_UNDERLINE_TOP                   "\e[53m"    //上划线
#define BU_ANSI_BLINK                           "\e[5m"     //闪烁
#define BU_ANSI_BLINK_FAST                      "\e[6m"     //快速闪烁(未广泛支持)
#define BU_ANSI_REVERSE                         "\e[7m"     //反显
#define BU_ANSI_HIDE                            "\e[8m"     //隐藏文字

/**    font    **/
#define BU_ANSI_FONT_NOMAL                      "\e[10m"    //正常字体(未广泛支持)
#define BU_ANSI_FONT_SONG                       "\e[11m"    //宋体(未广泛支持)
#define BU_ANSI_FONT_BLACK                      "\e[12m"    //黑体(未广泛支持)
#define BU_ANSI_FONT_KAI                        "\e[15m"    //楷体(未广泛支持)

/**    delete screen    **/
#define BU_ANSI_CLEAR_SCREEN                    "\e[2J"     //清屏且光标回到左上角
#define BU_ANSI_CLEAR_SCREEN_BEHIND             "\e[0J"     //清除光标到屏幕末尾
#define BU_ANSI_CLEAR_SCREEN_AHEAD              "\e[1J"     //清除光标到屏幕开头
#define BU_ANSI_CLEAR_SCREEN_AND_BUFFER         "\e[3J"     //清屏和回滚区

/**    delete line    **/
#define BU_ANSI_CLEAR_LINE                      "\r\e[K"    //清除整行光标回到开头
#define BU_ANSI_CLEAR_LINE_WHOLD                "\e[2K"     //清除整行,光标不变
#define BU_ANSI_CLEAR_LINE_BEHIND               "\e[0K"     //清除行中光标之后的,光标不变
#define BU_ANSI_CLEAR_LINE_AHEAD                "\e[1K"     //清除行中光标之前的,光标不变

/**    cursor    **/
#define BU_ANSI_CURSOR_SAVE                     "\e[s"
#define BU_ANSI_CURSOR_LOAD                     "\e[u"
#define BU_ANSI_CURSOR_HIDE                     "\e[?25l"
#define BU_ANSI_CURSOR_SHOW                     "\e[?25h"
#define BU_ANSI_CURSOR_MOVE(_Y_, _X_)           "\e[" #_Y_ ";" #_X_ "H"

#define BU_ANSI_SCROLL_UP(N)                    "\e[NS"     //整页上滚N行，新行添加到尾部
#define BU_ANSI_SCROLL_DOWN(N)                  "\e[NT"     //整页下滚N行，新行添加到顶部

#endif //BASE_UTILS_ANSI_CODES_BASE_H
