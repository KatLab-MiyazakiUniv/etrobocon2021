#ifdef __cplusplus
extern "C" {
#endif

#include "ev3api.h"

#define MAIN_PRIORITY TMIN_APP_TPRI + 1

#ifndef STACK_SIZE
#define STACK_SIZE 4096
#endif /* STACK_SIZE */

#ifndef TOPPERS_MACRO_ONLY
extern void main_task(intptr_t exinf);   // メインタスク
extern void arm_task(intptr_t exinf);    // アームを水平に保つタスク
extern void route_task(intptr_t exinf);  // 経路計算を行うタスク
#endif                                   /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif
