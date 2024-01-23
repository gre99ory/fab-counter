#include "memory/memory.h"

#include "scene_manager.h"

/**
 * @brief Initialize application data
 * 
 * @return App* 
 * 
 * Params : Use GUI 
 *          Type of GUI => ViewDispatcherTypeFullscreen
 * 
 */
App* app_alloc() {
    // Create app
    App* app = malloc(sizeof(App));

    // Create scene manager
    app->scene_manager = scene_manager_alloc(&app_scene_handlers, app);

    // Create view dispatcher
    app->view_dispatcher = view_dispatcher_alloc();
    view_dispatcher_enable_queue(app->view_dispatcher);
    view_dispatcher_set_event_callback_context(app->view_dispatcher, app);
    view_dispatcher_set_custom_event_callback(app->view_dispatcher, app_scene_custom_callback);
    view_dispatcher_set_navigation_event_callback(app->view_dispatcher, app_back_event_callback);

    // Create modules
    app->knob = knob_alloc();
    view_dispatcher_add_view(app->view_dispatcher, AppViewKnob, knob_get_view(app->knob));

    app->widget = widget_alloc();
    view_dispatcher_add_view(app->view_dispatcher, AppViewWidget, widget_get_view(app->widget));

    // Attach GUI and view dispatcher
    Gui* gui = furi_record_open(RECORD_GUI);
    view_dispatcher_attach_to_gui(app->view_dispatcher, gui, ViewDispatcherTypeFullscreen);

    // Returning fully initialized app
    return app;
}

/**
 * @brief Free application data
 * 
 * @param app 
 */
void app_free(App* app) {
    // Destroy modules
    view_dispatcher_remove_view(app->view_dispatcher, AppViewKnob);
    free(app->knob);

    view_dispatcher_remove_view(app->view_dispatcher, AppViewWidget);
    free(app->widget);

    // Destroy view dispatcher
    view_dispatcher_free(app->view_dispatcher);

    // Destroy scene manager
    scene_manager_free(app->scene_manager);

    // Destroy app
    free(app);

    furi_record_close(RECORD_GUI);
}
