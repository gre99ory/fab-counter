#include "scene_manager.h"

/**
 * @brief Definition of scene handlers 
 *   J'aimerai mettre ca ailleurs c'est du code specifique
 * 
 */
void (*const app_on_enter_handlers[])(void*) = {
    app_scene_arena_on_enter,
    app_scene_about_on_enter,
    app_scene_playerinfo_on_enter,
};

bool (*const app_on_event_handlers[])(void*, SceneManagerEvent) = {
    app_scene_arena_on_event,
    app_scene_about_on_event,
    app_scene_playerinfo_on_event,
};

void (*const app_on_exit_handlers[])(void*) = {
    app_scene_arena_on_exit,
    app_scene_about_on_exit,
    app_scene_playerinfo_on_exit,
};

//
// Generic beyond this line
//
////////////////////////////////////////////////////////

/**
 * @brief Defining the SceneManagerHandlers list
 * 
 */
const SceneManagerHandlers app_scene_handlers = {
    .on_enter_handlers = app_on_enter_handlers,
    .on_event_handlers = app_on_event_handlers,
    .on_exit_handlers = app_on_exit_handlers,
    .scene_num = AppSceneCount,
};

/**
 * @brief Custom callback passes the event 
 *      to the current scene via scene_manager_handle_custom_event
 * 
 * @param context 
 * @param custom_event_id 
 * @return true 
 * @return false 
 */
bool app_scene_custom_callback(void* context, uint32_t custom_event_id) {
    App* app = (App*)context;
    kindalog("appCustomEvent");
    return scene_manager_handle_custom_event(app->scene_manager, custom_event_id);
}

/**
 * @brief Passes the 'back' event to the current scene via scene manager
 * 
 * @param context 
 * @return true 
 * @return false 
 */
bool app_back_event_callback(void* context) {
    App* app = (App*)context;
    kindalog("appBackEvent");
    return scene_manager_handle_back_event(app->scene_manager);
}