//
// Created by ou on 2021/2/9.
//

#include "base_utils.h"

int BU_ANSI_CODE_EXAMPLE() {
//int main() {

    {
        BU_SCOPE_TIME_MEAN("test_scope_time", '\n')
        uint32_t i = 0;
        BU_ANSI_CLEAR_SCREEN_S

        //ansi_code_base.h
        printf(BU_ANSI_NONE BU_ANSI_FG_BLACK "%s\n", "BU_ANSI_FG_BLACK");
        printf(BU_ANSI_NONE BU_ANSI_FG_BLACK_H "%s\n", "BU_ANSI_FG_BLACK_H");
        printf(BU_ANSI_NONE BU_ANSI_BG_BLACK "%s\n", "BU_ANSI_BG_BLACK");
        printf(BU_ANSI_NONE BU_ANSI_BG_BLACK_H "%s\n", "BU_ANSI_BG_BLACK_H");
        printf(BU_ANSI_NONE BU_ANSI_NONE"%s\n", "BU_ANSI_NONE");
        printf(BU_ANSI_NONE BU_ANSI_WEAK "%s\n", "BU_ANSI_WEAK");
        printf(BU_ANSI_NONE BU_ANSI_BOLD "%s\n", "BU_ANSI_BOLD");
        printf(BU_ANSI_NONE BU_ANSI_UNDERLINE "%s\n", "BU_ANSI_UNDERLINE");
        printf(BU_ANSI_NONE BU_ANSI_UNDERLINE_MID "%s\n", "BU_ANSI_UNDERLINE_MID");
        printf(BU_ANSI_NONE BU_ANSI_UNDERLINE_TOP "%s\n", "BU_ANSI_UNDERLINE_TOP");
        printf(BU_ANSI_NONE BU_ANSI_BLINK "%s\n", "BU_ANSI_BLINK");
        printf(BU_ANSI_NONE BU_ANSI_BLINK_FAST "%s\n", "BU_ANSI_BLINK_FAST");
        printf(BU_ANSI_NONE BU_ANSI_REVERSE "%s\n", "BU_ANSI_REVERSE");
        printf(BU_ANSI_NONE BU_ANSI_HIDE "%s\n", "BU_ANSI_HIDE");

        //ansi_code_ex.h
        printf(BU_ANSI_NONE BU_ANSI_C8(FG, GREEN, H) "%s\n", "BU_ANSI_C8(FG,WHITE,H)");
        printf(BU_ANSI_NONE BU_ANSI_C8(FG, GREEN) "%s\n", "BU_ANSI_C8(FG, GREEN)");
        printf(BU_ANSI_NONE BU_ANSI_C8(BG, GREEN, H) "%s\n", "BU_ANSI_C8(BG,WHITE,H)");
        printf(BU_ANSI_NONE BU_ANSI_C8(BG, GREEN) "%s\n", "BU_ANSI_C8(BG,WHITE)");

        printf(BU_ANSI_NONE);
        BU_ANSI_C8_S(FG, GREEN)
        printf("%s\n", "BU_ANSI_C8_S(BG,GREEN)");

        i = 1;
        printf(BU_ANSI_C8_R0 "%s\n", BU_ANSI_C8_R1(FG, i), "BU_ANSI_C8_R0 + BU_ANSI_C8_R1(FG,i)");

        printf(BU_ANSI_NONE);
        BU_ANSI_C8_RS(FG, i, H)
        printf("%s\n", "BU_ANSI_C8_RS(FG, i, H)");

        printf(BU_ANSI_NONE BU_ANSI_C(8, (FG, YELLOW)) "%s\n", "BU_ANSI_C(8,(FG, YELLOW))");
        printf(BU_ANSI_NONE BU_ANSI_C(255, (FG, 125)) "%s\n", "BU_ANSI_C(255,(BG, 125))");
        printf(BU_ANSI_NONE BU_ANSI_C(RGB, (FG, 255, 255, 255)) "%s\n", "BU_ANSI_C(RGB,(FG,0, 255, 255))");

        i = 100;
        printf(BU_ANSI_NONE BU_ANSI_C_R0(RGB) "%s\n", BU_ANSI_C_R1(RGB, (FG, i, 0, i)),
               "BU_ANSI_NONE BU_ANSI_C_R0(RGB) + BU_ANSI_C_R1(RGB, (FG,i,0,i))");

        printf(BU_ANSI_NONE BU_ANSI_IF(1, BU_ANSI_C(8, (FG, YELLOW)), BU_ANSI_C(8, (FG, GREEN)))
               "%s\n", "BU_ANSI_IF(1,BU_ANSI_C(8, (FG, YELLOW)),BU_ANSI_C(8, (FG, GREEN)))");

        bool isBlue = true;
        printf(BU_ANSI_NONE BU_ANSI_IF_R0 "%s\n",
               BU_ANSI_IF_R1(isBlue, BU_ANSI_C(8, (FG, BLUE)), BU_ANSI_C(8, (FG, GREEN))),
               "BU_ANSI_IF(1,BU_ANSI_C(8, (FG, YELLOW)),BU_ANSI_C(8, (FG, GREEN)))");


        bool isBold = true;
        printf(BU_ANSI_NONE BU_ANSI_IF_BOLD(0) "%s\n", "BU_ANSI_IF_BOLD(0)");
        printf(BU_ANSI_NONE BU_ANSI_IF_BOLD(1) "%s\n", "BU_ANSI_IF_BOLD(1)");
        printf(BU_ANSI_NONE BU_ANSI_IF_ITALIC_R0 "%s\n", BU_ANSI_IF_ITALIC_R1(isBold),
               "BU_ANSI_IF_ITALIC_R0　+ BU_ANSI_IF_ITALIC_R1(isBold)");

        int x = 5, y = 0;
        BU_ANSI_CURSOR_MOVE_RS(y, x)
        printf(BU_ANSI_NONE "%s\n", "BU_CURSOR_MOVE_RS(y,x)");
        BU_ANSI_CURSOR_MOVE_S(1, 5)
        printf(BU_ANSI_NONE "%s\n", "BU_CURSOR_MOVE_S(１,５)");
        BU_ANSI_CURSOR_MOVE_HEAD_S


        BU_ANSI(BU_ANSI_C(8, (FG, PURPLE)), BU_ANSI_BOLD, BU_ANSI_ITALIC, BU_ANSI_UNDERLINE)("%s\n",
                                                                                             "BU_ANSI(BU_ANSI_C(8,(FG,PURPLE)))(\"%s\\n\",\"123\")")
        printf("%s\n", "auto call BU_ANSI_NONE to reset font's format");


        int lx = 12, ly = 2, lw = 20, ln = 5, lp = 13, lc255 = 125, lcrgb = 125, lc8 = 3;

        BU_ANSI_LOADING_BAR_RS(12, ly, lw, ln, 1, BU_ANSI_BAR_N, (8, lc8))
        BU_ANSI_CURSOR_NEXT_LINE_S
        BU_ANSI_LOADING_BAR_RS(12, ly, lw, ln, 1, lp, (255, lc255))
        BU_ANSI_CURSOR_NEXT_LINE_S
        BU_ANSI_LOADING_BAR_RS(lx, 2, 20, 5, 0, BU_ANSI_BAR_L, (RGB, lcrgb, 50, lcrgb))
        BU_ANSI_CURSOR_NEXT_LINE_S
        BU_ANSI_LOADING_BAR_RS(12, ly, lw, ln, 1, BU_ANSI_BAR_M, (8, 1))
        BU_ANSI_CURSOR_NEXT_LINE_S
        BU_ANSI_LOADING_BAR_RS(lx, 2, 20, 5, 0, BU_ANSI_BAR_R, (255, i))
        BU_ANSI_CURSOR_NEXT_LINE_S
    }


    return 0;

}



