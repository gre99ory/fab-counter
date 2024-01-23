#ifndef __SCENE_MANAGER_FAB_COUNTER__
#define __SCENE_MANAGER_FAB_COUNTER__

#include "scenes/arena.h"
#include "scenes/about.h"

extern const SceneManagerHandlers app_scene_handlers;

/**
 * @brief Custom callback passes the event 
 *      to the current scene via scene_manager_handle_custom_event
 * 
 * @param context 
 * @param custom_event_id 
 * @return true 
 * @return false 
 */
bool app_scene_custom_callback(void* context, uint32_t custom_event_id);

/**
 * @brief Passes the 'back' event to the current scene via scene manager
 * 
 * @param context 
 * @return true 
 * @return false 
 */
bool app_back_event_callback(void* context);

#endif