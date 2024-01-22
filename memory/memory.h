#ifndef __MEMORY_FAB_COUNTER__
#define __MEMORY_FAB_COUNTER__

#include "main.h"

/**
 * @brief Allocates Application memory and objects
 * 
 * @return App* 
 */
App* app_alloc();

/**
 * @brief Deallocate Application objects and memory
 * 
 * @param app 
 */
void app_free(App* app);

#endif
