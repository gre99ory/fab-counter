#ifndef __ARENA_FAB_COUNTER__
#define __ARENA_FAB_COUNTER__

#include "main.h"

/**
 *
 * The Arena is the main scene where counters are shown and changed
 * 
 */

void app_scene_arena_on_enter(void* context);

bool app_scene_arena_on_event(void* context, SceneManagerEvent event);

void app_scene_arena_on_exit(void* context);

#endif