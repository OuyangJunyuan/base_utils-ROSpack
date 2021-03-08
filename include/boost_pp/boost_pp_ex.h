#ifndef BASE_UTILS_BOOST_PP_EX_H
#define BASE_UTILS_BOOST_PP_EX_H

#include <boost/preprocessor.hpp>

/**                         Extention Of The Boost PP-lib
 *******************************************************************/
/**
 * int a[10];
 * BOOST_PP_ENUM_ARRAY_ELEMENT(10,a)
 * ------
 * int a[10];
 * a[0], a[1], ..., a[9]
 * */
#define BOOST_PP_ENUM_ARRAY_ELEMENT_I(z, n, a)  a[n]
#define BOOST_PP_ENUM_ARRAY_ELEMENT(n, a)       BOOST_PP_ENUM(n,BOOST_PP_ENUM_ARRAY_ELEMENT_I,a)
/**
 * int a[10];
 * BOOST_PP_ENUM_ARRAY_ELEMENT(10,a)
 * ------
 * int a[10];
 * a, a, ..., a (10个a)
 * */
#define BOOST_PP_REPEAT_N_I(z, n, a)            a
#define BOOST_PP_REPEAT_N(n, a)                 BOOST_PP_ENUM(n,BOOST_PP_REPEAT_N_I,a)

#endif //BASE_UTILS_BOOST_PP_EX_H
