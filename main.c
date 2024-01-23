#include <furi.h>
#include <furi_hal.h>
#include <gui/gui.h>
#include <gui/view.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/submenu.h>
#include <gui/modules/text_input.h>
#include <gui/modules/widget.h>
#include <gui/modules/variable_item_list.h>
#include <notification/notification.h>
#include <notification/notification_messages.h>

#include "main.h"

#include "scene_manager.h"

#include "memory/memory.h"

/**
 * @brief Main entry point
 * 
 * @param p 
 * @return int32_t 
 */
int32_t main_fab_counter(void* p) {
    UNUSED(p);

    // Create app object
    App* app = app_alloc();

    // Show first scene
    scene_manager_next_scene(app->scene_manager, AppSceneAbout);
    view_dispatcher_run(app->view_dispatcher);

    // Free resources
    kindalog("free");
    app_free(app);

    kindalog("return");
    return 0;
}

/**
 * @brief Message log with a delay
 * 
 * @param message 
 */
void kindalog(char* message) {
    FURI_LOG_I(TAG, message);
    furi_delay_ms(10);
}