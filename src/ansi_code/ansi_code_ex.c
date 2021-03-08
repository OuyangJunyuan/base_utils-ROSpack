//
// Created by ou on 2021/2/18.
//

#include "ansi_code/bu_ansi_code.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

const char *__printf_ansi_va_cfg(const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    static char return_str[32];
    memset(return_str, '\0', 32);

    while (1) {
        char *p = va_arg(ap, char *);

        if (strcmp(p, "") == 0)
            break;
        strcat(return_str, p);
    }
    va_end(ap);
    return return_str;
}

void bu_loading(int _x, int _y, unsigned int _width, unsigned int _n, int _grid_on, int _info) {
    int w = _width < 6 ? 6 : _width, n = ((float) _n > w ? w : _n) * w / w;
    char pre[w + 2], num_buf[7];;
    memset(pre, ' ', w + 2);
    pre[n] = pre[w + 1] = '\0';
    if (_info != BU_ANSI_BAR_N) {

        sprintf(num_buf, "%3.1f%%", (float) (n) / w * 100.0);
        int len = strlen(num_buf), pos = (_info % (w - 4));
        pos = _info == -2 ? w - 5 : pos;
        pos = _info == -1 ? (w / 2) - 2 : pos;
        for (int i = pos; i < pos + len; ++i)
            pre[i < n ? i : i + 1] = num_buf[i - pos];
    }
    BU_ANSI_CURSOR_MOVE_RS(_x, _y)
    printf("%s%s" BU_ANSI_NONE, _grid_on ? BU_ANSI_UNDERLINE BU_ANSI_UNDERLINE_TOP : "", pre);
    printf("%s%s" BU_ANSI_NONE, _grid_on ? BU_ANSI_UNDERLINE BU_ANSI_UNDERLINE_TOP : "", pre + n + 1);
}