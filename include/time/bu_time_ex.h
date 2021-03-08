#ifndef BASE_UTILS_BU_TIME_EX_H
#define BASE_UTILS_BU_TIME_EX_H


#include <chrono>
#include "time/bu_time_def.h"
#include "ansi_code/bu_ansi_code.h"

/**                         Time Record
 *******************************************************************/
#ifdef __DEBUG__
/*******************************************************************
 *
 * {
 *      BU_SCOPE_TIME("this_scope"[,'\n'])
 *      //do something...
 * }
 * for(int i=0;i<10;i++){
 *      BU_SCOPE_TIME_MEAN("this_scope"[,'\n'])
 *      //do something...
 * }
 *******************************************************************/
#define BU_SCOPE_TIME(t, ...)                                       base_utils::ScopeTime __scopeTime(t,nullptr,nullptr,##__VA_ARGS__);

#define BU_SCOPE_TIME_MEAN(t, ...)                                  static double time = 0;\
                                                                    static size_t times = 0;\
                                                                    base_utils::ScopeTime  \
                                                                    __scopeTimeMean(t, &time, &times,##__VA_ARGS__);

#else
#define BU_SCOPE_TIME(TITLE)
#define BU_SCOPE_TIME_MEAN(TITLE)


#endif


#endif //BASE_UTILS_BU_TIME_EX_H
