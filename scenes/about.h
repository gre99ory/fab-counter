#ifndef __ABOUT_FAB_COUNTER__
#define __ABOUT_FAB_COUNTER__

#include "main.h"

/**
 *
 * About FAB Counter
 * 
 */

void app_scene_about_on_enter(void* context);

bool app_scene_about_on_event(void* context, SceneManagerEvent event);

void app_scene_about_on_exit(void* context);

void app_scene_about_button_callback(GuiButtonType result, InputType type, void* context);

#endif