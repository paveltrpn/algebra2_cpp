
#include "cmplx.h"

cmplx_t cmplx_sum(cmplx_t a, cmplx_t b) {
    cmplx_t rt;

    rt[0] = a[0] + b[0];
    rt[1] = a[1] + b[1];

    return rt;
 }

 cmplx_t cmplx_sub(cmplx_t a, cmplx_t b) {
    cmplx_t rt;

    rt[0] = a[0] - b[0];
    rt[1] = a[1] - b[1];

    return rt;
 }

 cmplx_t cmplx_mult(cmplx_t a, cmplx_t b) {
     cmplx_t rt;

     rt[0] = a[0]*b[0] - a[1]*b[1];
     rt[1] = a[0]*b[1] + a[1]*b[0];

     return rt;
 }

 cmplx_t cmplx_div(cmplx_t a, cmplx_t b)  {
    cmplx_t rt;

    rt[0] = (a[0]*b[0] + a[1]*b[1]) / (b[0]*b[0] + b[1]*b[1]);
    rt[1] = (a[1]*b[0] - a[0]*b[1]) / (b[0]*b[0] + b[1]*b[1]);

    return rt;
}

cmplx_t cmplx_scale(cmplx_t a, float k) {
    cmplx_t rt;

    rt[0] = a[0]*k;
    rt[1] = a[1]*k;

    return rt;
}