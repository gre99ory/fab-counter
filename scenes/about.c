
#include "about.h"

/**
 * @brief About scene initialization code
 * 
 * @param context 
 */
void app_scene_about_on_enter(void* context) {
    App* app = (App*)context;

    // Retrieve the widget and initialize its content
    Widget* widget = app->widget;
    widget_reset(widget);
    widget_add_text_scroll_element(
        widget,
        0, // 20,
        0, // 10,
        120,
        55,
        "This will be the summary page where we show the data. "
        "At the moment it is just a placeholder.");
    widget_add_button_element(
        widget, GuiButtonTypeCenter, "OK", app_scene_about_button_callback, app);

    kindalog("Showing");

    // Show view AppViewWidget
    view_dispatcher_switch_to_view(app->view_dispatcher, AppViewWidget);

    kindalog("Exiting About on enter");
}

/**
 * @brief Event handler
 * 
 * @param context 
 * @param event 
 */
bool app_scene_about_on_event(void* context, SceneManagerEvent event) {
    App* app = (App*)context;
    bool consumed = false;

    kindalog("aboutOnEvent");

    if(event.type == SceneManagerEventTypeBack) {
        // Back button pressed
        kindalog("back");
    } else if(event.type == SceneManagerEventTypeCustom) {
        consumed = true;
        if(event.event == AppWidgetEventDone) {
            kindalog("callingNextScene");
            scene_manager_next_scene(app->scene_manager, AppSceneArena);
        }
    }

    kindalog("returning from aboutOnEvent");
    return consumed;
}

void app_scene_about_on_exit(void* context) {
    kindalog("aboutOnExit");

    App* app = (App*)context;
    Widget* widget = app->widget;

    widget_reset(widget);
}

/**
 * @brief Callback for the 'OK' button
 * 
 * @param result 
 * @param type 
 * @param context 
 */
void app_scene_about_button_callback(GuiButtonType result, InputType type, void* context) {
    kindalog("aboutButtonCallback");

    App* app = (App*)context;
    UNUSED(type);

    if(result == GuiButtonTypeCenter) {
        view_dispatcher_send_custom_event(app->view_dispatcher, AppWidgetEventDone);
    }
}