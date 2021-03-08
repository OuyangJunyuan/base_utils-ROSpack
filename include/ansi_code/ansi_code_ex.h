/*******************************************************************
 * 后缀：
 *      R(untime)表示运行时宏
 *      S(tatement)表示语句宏
 *      无表示构建时字面字符串常量宏
 *******************************************************************/

#ifndef BASE_UTILS_ANSI_CODE_EX_H
#define BASE_UTILS_ANSI_CODE_EX_H


#ifdef __cplusplus

#include <boost/preprocessor.hpp>

#endif

#include <stdio.h>
#include "ansi_code/ansi_code_base.h"


/**                         Color Macro
 *******************************************************************/
/**    c8    **/
/**
suffix free ：                  FG/BG 为前景或背景
  printf(BU_ANSI_NONE BU_ANSI_C8(FG, GREEN, H) "%s\n", "BU_ANSI_C8(FG,WHITE,H)");
  printf(BU_ANSI_NONE BU_ANSI_C8(FG, GREEN) "%s\n", "BU_ANSI_C8(FG, GREEN)");

_S:
  printf(BU_ANSI_NONE);
  BU_ANSI_C8_S(FG,GREEN)
  printf("%s\n","BU_ANSI_C8_S(BG,GREEN)");

_R0/1:
  int i=1;
  printf(BU_ANSI_C8_R0 "%s\n",BU_ANSI_C8_R1(FG,i),"BU_ANSI_C8_R0 + BU_ANSI_C8_R1(FG,i)");

_RS:
  printf(BU_ANSI_NONE);
  BU_ANSI_C8_RS(FG, i, H)
  printf("%s\n", "BU_ANSI_C8_RS(FG, i, H)");*/
#define BU_ANSI_C8(FB, VALUE, ...)              "\e[" STR(BU_ANSI_PF_ ##FB ##__VA_ARGS__) STR(BU_ANSI_SF_ ##VALUE)  "m"
#define BU_ANSI_C8_S(FB, VALUE, ...)            printf(BU_ANSI_C8(FB,VALUE,##__VA_ARGS__));
#define BU_ANSI_C8_R0                           "\e[%s%dm"
#define BU_ANSI_C8_R1(FB, VALUE, ...)           STR(BU_ANSI_PF_ ##FB ##__VA_ARGS__),(int(VALUE))%9
#define BU_ANSI_C8_RS(FB, VALUE, ...)           printf(BU_ANSI_C8_R0, BU_ANSI_C8_R1(FB,VALUE,__VA_ARGS__));

/**    c255    **/
#define BU_ANSI_C255(FB, VALUE)                 "\e[" STR(BU_ANSI_PF_ ##FB) "8;5;" #VALUE "m"
#define BU_ANSI_C255_S(FB, VALUE)               printf(BU_ANSI_C255(FB, VALUE));
#define BU_ANSI_C255_R0                         "\e[%s8;5;%dm"
#define BU_ANSI_C255_R1(FB, VALUE)              STR(BU_ANSI_PF_ ##FB),_Z256(VALUE)
#define BU_ANSI_C255_RS(FB, VALUE)              printf(BU_ANSI_C255_R0,BU_ANSI_C255_R1(FB,VALUE));

/**    crgb    **/
#define BU_ANSI_CRGB(FB, R, G, B)               "\e[" STR(BU_ANSI_PF_ ##FB) "8;2;" #R ";" #G ";" #B  "m"
#define BU_ANSI_CRGB_S(FB, R, G, B)             printf(BU_ANSI_CRGB(FB, R, G, B));
#define BU_ANSI_CRGB_R0                         "\e[%s8;2;%d;%d;%dm"
#define BU_ANSI_CRGB_R1(FB, R, G, B)            STR(BU_ANSI_PF_ ##FB), _Z256(R),_Z256(G),_Z256(B)
#define BU_ANSI_CRGB_RS(FB, R, G, B)            printf(BU_ANSI_CRGB_R0,BU_ANSI_CRGB_R1(FB,R,G,B));

/**    c(8,255,RGB)    **/
/**
    printf(BU_ANSI_NONE BU_ANSI_C(8, (FG, YELLOW)) "%s\n", "BU_ANSI_C(8,(FG, YELLOW))");
    printf(BU_ANSI_NONE BU_ANSI_C(255, (FG, 125)) "%s\n", "BU_ANSI_C(255,(BG, 125))");
    printf(BU_ANSI_NONE BU_ANSI_C(RGB, (FG, 0, 255, 255)) "%s\n", "BU_ANSI_C(RGB,(FG,0, 255, 255))");

    printf(BU_ANSI_NONE);
    BU_ANSI_C_S(8,(FG, BLUE, H))
    printf("%s\n", "BU_ANSI_C_S(8,(FG, BLUE, H))");

    i=100;
    printf(BU_ANSI_NONE BU_ANSI_C_R0(RGB) "%s\n",
            BU_ANSI_C_R1(RGB, (FG,i,0,i)),
            "BU_ANSI_NONE BU_ANSI_C_R0(RGB) + BU_ANSI_C_R1(RGB, (FG,i,0,i))");*/
#define BU_ANSI_C(T, V)                         BU_ANSI_C##T V
#define BU_ANSI_C_S(T, V)                       printf( BU_ANSI_C(T, V));
#define BU_ANSI_C_R0(T)                         BU_ANSI_C##T##_R0
#define BU_ANSI_C_R1(T, V)                      BU_ANSI_C##T##_R1 V
#define BU_ANSI_C_RS(T, V)                      printf(BU_ANSI_C_R0(T),BU_ANSI_C_R1(T,V));

#ifdef __cplusplus
/*
#define BU_ANSI_Z_EMPTY BOOST_PP_EMPTY()
#define BU_ANSI_Z_CTYPE_RGB 1
#define BU_ANSI_Z_CTYPE_8 8
#define BU_ANSI_Z_CTYPE_255 255

#define BU_ANSI_ZC_1(z, n, tuple)               STR( BOOST_PP_TUPLE_ELEM(n,tuple)) \
                                                BOOST_PP_IF(BOOST_PP_SUB(2,n), ";" ,BOOST_PP_EMPTY())

#define BU_ANSI_ZC_2(z, n, tuple)               0 BOOST_PP_COMMA_IF(n)
#define BU_ANSI_C(T, FB, V, ...)                "\e[" STR(BU_ANSI_PF_ ##FB)\
                                                BOOST_PP_IF( BOOST_PP_EQUAL(BU_ANSI_Z_CTYPE_##T,BU_ANSI_Z_CTYPE_8) , \
                                                    STR(BU_ANSI_SF_##V),"8;" )\
                                                BOOST_PP_IF( BOOST_PP_EQUAL(BU_ANSI_Z_CTYPE_##T,BU_ANSI_Z_CTYPE_255),\
                                                    "5;" STR(V),BU_ANSI_Z_EMPTY)  \
                                                BOOST_PP_IF( BOOST_PP_EQUAL(BU_ANSI_Z_CTYPE_##T,BU_ANSI_Z_CTYPE_RGB), \
                                                    "2;" BOOST_PP_REPEAT(BOOST_PP_VARIADIC_SIZE(V,__VA_ARGS__) ,\
                                                                         BU_ANSI_ZC_1,(V,__VA_ARGS__)), \
                                                    BU_ANSI_Z_EMPTY) "m"
*/
#endif

/**    if    **/
/**
 suffix free:
    printf(BU_ANSI_NONE BU_ANSI_IF(1,BU_ANSI_C(8, (FG, YELLOW)),BU_ANSI_C(8, (FG, GREEN)))
            "%s\n","BU_ANSI_IF(1,BU_ANSI_C(8, (FG, YELLOW)),BU_ANSI_C(8, (FG, GREEN)))");

 _R0/1:
    bool isBlue = true;
    printf(BU_ANSI_NONE BU_ANSI_IF_R0 "%s\n",
           BU_ANSI_IF_R1(isBlue, BU_ANSI_C(8, (FG, BLUE)), BU_ANSI_C(8, (FG, GREEN))),
           "BU_ANSI_IF(1,BU_ANSI_C(8, (FG, YELLOW)),BU_ANSI_C(8, (FG, GREEN)))");



           */
#ifdef __cplusplus
#define BU_ANSI_IF(BOOL, C1, C2)                BOOST_PP_IF(BOOL,C1,C2)
#define BU_ANSI_IF_S(BOOL, C1, C2)              printf(BU_ANSI_IF(BOOL, C1, C2))
#endif
#define BU_ANSI_IF_R0                           "%s"
#define BU_ANSI_IF_R1(var, C1, C2)              (var)?(C1):(C2)
#define BU_ANSI_IF_RS(var, C1, C2)              printf(BU_ANSI_CIF_R0,BU_ANSI_CIF_R1(var,C1,C2));

/**
    bool isBold = true;
    printf(BU_ANSI_NONE BU_ANSI_IF_BOLD(0) "%s\n","BU_ANSI_IF_BOLD(0)");
    printf(BU_ANSI_NONE BU_ANSI_IF_BOLD(1) "%s\n","BU_ANSI_IF_BOLD(1)");
    printf(BU_ANSI_NONE BU_ANSI_IF_ITALIC_R0 "%s\n",BU_ANSI_IF_ITALIC_R1(isBold),
           "BU_ANSI_IF_ITALIC_R0　+ BU_ANSI_IF_ITALIC_R1(isBold)");*/
#define BU_ANSI_IF_BOLD(BOOL)                   BU_ANSI_IF(BOOL,BU_ANSI_BOLD,"")
#define BU_ANSI_IF_BOLD_R0                      BU_ANSI_IF_R0
#define BU_ANSI_IF_BOLD_R1(BOOL)                BU_ANSI_IF_R1(BOOL,BU_ANSI_BOLD,"")

#define BU_ANSI_IF_WEAK(BOOL)                   BU_ANSI_IF(BOOL,BU_ANSI_WEAK,"")
#define BU_ANSI_IF_WEAK_R0                      BU_ANSI_IF_R0
#define BU_ANSI_IF_WEAK_R1(BOOL)                BU_ANSI_IF_R1(BOOL,BU_ANSI_WEAK,"")

#define BU_ANSI_IF_ITALIC(BOOL)                 BU_ANSI_IF(BOOL,BU_ANSI_ITALIC,"")
#define BU_ANSI_IF_ITALIC_R0                    BU_ANSI_IF_R0
#define BU_ANSI_IF_ITALIC_R1(BOOL)              BU_ANSI_IF_R1(BOOL,BU_ANSI_ITALIC,"")

#define BU_ANSI_IF_BLINK(BOOL)                  BU_ANSI_IF(BOOL,BU_ANSI_BLINK,"")
#define BU_ANSI_IF_BLINK_R0                     BU_ANSI_IF_R0
#define BU_ANSI_IF_BLINK_R1(BOOL)               BU_ANSI_IF_R1(BOOL,BU_ANSI_BLINK,"")

#define BU_ANSI_IF_HIDE(BOOL)                   BU_ANSI_IF(BOOL,BU_ANSI_HIDE,"")
#define BU_ANSI_IF_HIDE_R0                      BU_ANSI_IF_R0
#define BU_ANSI_IF_HIDE_R1(BOOL)                BU_ANSI_IF_R1(BOOL,BU_ANSI_HIDE,"")

#define BU_ANSI_IF_UNDERLINE(BOOL)              BU_ANSI_IF(BOOL,BU_ANSI_UNDERLINE,"")
#define BU_ANSI_IF_UNDERLINE_R0                 BU_ANSI_IF_R0
#define BU_ANSI_IF_UNDERLINE_R1(BOOL)           BU_ANSI_IF_R1(BOOL,BU_ANSI_UNDERLINE,"")


/**                         Control Macro
 *******************************************************************/
/**    clear screen    **/
/**         (第一个括号内可以任意调用无后缀的格式设置宏)(第二个括号就是printf) 结束自动清空格式
    BU_ANSI(BU_ANSI_C(8, (FG, PURPLE)), BU_ANSI_BOLD, BU_ANSI_ITALIC, BU_ANSI_UNDERLINE)("%s\n",
            "BU_ANSI(BU_ANSI_C(8,(FG,PURPLE)))(\"%s\\n\",\"123\")");
    printf("%s", "auto call BU_ANSI_NONE to reset font's format"); */
#define BU_ANSI_CLEAR_SCREEN_S                  printf(BU_ANSI_CLEAR_SCREEN);
#define BU_ANSI_CLEAR_SCREEN_BEHIND_S           printf(BU_ANSI_CLEAR_SCREEN_BEHIND);
#define BU_ANSI_CLEAR_LINE_S                    printf(BU_ANSI_CLEAR_LINE_WHOLD);

/**    cursor    **/
/**
    int x = 5, y = 0;
    BU_CURSOR_MOVE_RS(y,x)
    printf(BU_ANSI_NONE "%s\n","BU_CURSOR_MOVE_RS(y,x)");
    BU_CURSOR_MOVE_S(1,5)
    printf(BU_ANSI_NONE "%s\n","BU_CURSOR_MOVE_S(１,５)");
    BU_CURSOR_MOVE_HEAD_S */
#define BU_ANSI_CURSOR_MOVE_S(_Y_, _X_)         printf(BU_ANSI_CURSOR_MOVE(_Y_, _X_));
#define BU_ANSI_CURSOR_MOVE_RS(_Y_, _X_)        printf("\e[%d;%dH",(int)(_Y_),(int)(_X_));
#define BU_ANSI_CURSOR_MOVE_HEAD_S              printf(BU_ANSI_CURSOR_MOVE(0,0));
#define BU_ANSI_CURSOR_HIDE_S                   printf(BU_ANSI_CURSOR_HIDE);
#define BU_ANSI_CURSOR_SHOW_S                   printf(BU_ANSI_CURSOR_SHOW);
#define BU_ANSI_CURSOR_NEXT_LINE_S              printf("\n");


/**                         Function Macro
 *******************************************************************/
/**    colorful print    **/
#define BU_ANSI(...)                            BU_ANSI_PRINT_RS(__VA_ARGS__)
#define BU_ANSI_PRINT_RS(...)                   do{ printf("%s",  __printf_ansi_va_cfg("",##__VA_ARGS__,"")); \
                                                    printf( BU_ANSI_PRINT_RS_1
#define BU_ANSI_PRINT_RS_1(x, ...)                  x BU_ANSI_NONE ,##__VA_ARGS__); \
                                                }while(0);
/**    loading bar    **/
/** xy:开头位置(R) w:满程宽度(R) N:当前进度(R) G:是否出现刻度(R)
    I:显示如50.0%进度字样位置(R)　C:颜色设置(R),格式为(TYPE,VALUE,...)

    int lx=12,ly=2,lw=20,ln=5,lp=13,lc255=125,lcrgb=125,lc8=3;
    BU_ANSI_LOADING_BAR_RS(12, ly, lw, ln, 1, BU_ANSI_BAR_N, (8, lc8)) BU_CURSOR_NEXT_LINE_S
    BU_ANSI_LOADING_BAR_RS(12, ly, lw, ln, 1, lp, (255, lc255)) BU_CURSOR_NEXT_LINE_S
    BU_ANSI_LOADING_BAR_RS(lx, 2, 20, 5, 0, BU_ANSI_BAR_L, (RGB, lcrgb,50,lcrgb)) BU_CURSOR_NEXT_LINE_S
    BU_ANSI_LOADING_BAR_RS(12, ly, lw, ln, 1, BU_ANSI_BAR_M, (8, 1)) BU_CURSOR_NEXT_LINE_S
    BU_ANSI_LOADING_BAR_RS(lx, 2, 20, 5, 0, BU_ANSI_BAR_R, (255, i)) BU_CURSOR_NEXT_LINE_S*/
#define BU_ANSI_BAR_N                           __INT_MAX__
#define BU_ANSI_BAR_L                           0
#define BU_ANSI_BAR_M                           -1
#define BU_ANSI_BAR_R                           -2
#define BU_ANSI_C_BAR(T, V, ...)                BU_ANSI_C_RS(T,(BG,V,##__VA_ARGS__))
#define BU_ANSI_LOADING_BAR_RS(X, Y, W, N, G, I, C) \
                                                do{ \
                                                    BU_ANSI_C_BAR C   \
                                                    bu_loading(X, Y, W, N, G, I); \
                                                }while(0);


/**                         Type Define
 *******************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

const char *__printf_ansi_va_cfg(const char *format, ...);

void bu_loading(int _x, int _y, unsigned int _width, unsigned int _n, int _grid_on, int _info);

#ifdef __cplusplus
}
#endif


/**                         Support Macro
 *******************************************************************/
#define _MACRO(x) x
#define MACRO(x) _MACRO(x)
#define _STR(x) #x
#define STR(x) _STR(x)
#define _Z256(R)      (int(R))%256


#endif //BASE_UTILS_ANSI_CODE_EX_H
