#include "app.h"
#include "EtRobocon2021.h"
#include <cmath>


/**
 * メインタスク
 */
// tag::main_task_1[]
void main_task(intptr_t unused)
{
  EtRobocon2021::start();
  ext_tsk();
}
// end::main_task_2[]
