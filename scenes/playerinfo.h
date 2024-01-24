#ifndef __PLAYERINFO_FAB_COUNTER__
#define __PLAYERINFO_FAB_COUNTER__

#include "main.h"

/**
 *
 * Player information FAB Counter
 * 
 */

void app_scene_playerinfo_on_enter(void* context);

bool app_scene_playerinfo_on_event(void* context, SceneManagerEvent event);

void app_scene_playerinfo_on_exit(void* context);

void app_scene_playerinfo_button_callback(GuiButtonType result, InputType type, void* context);

#endif