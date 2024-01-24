
#include "playerinfo.h"

/**
 * @brief playerinfo scene initialization code
 * 
 * @param context 
 */
void app_scene_playerinfo_on_enter(void* context) {
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
        "Missing title => Player info page."
        "At the moment it is just a placeholder."
        "It can be used to store the GemID among other things."
        "Maybe a #random key to establish a connection."
        "Prefered hero(es) as well.");
    widget_add_button_element(
        widget, GuiButtonTypeCenter, "OK", app_scene_playerinfo_button_callback, app);

    kindalog("Showing");

    // Show view AppViewWidget
    view_dispatcher_switch_to_view(app->view_dispatcher, AppViewWidget);

    kindalog("Exiting playerinfo on enter");
}

/**
 * @brief Event handler
 * 
 * @param context 
 * @param event 
 */
bool app_scene_playerinfo_on_event(void* context, SceneManagerEvent event) {
    App* app = (App*)context;
    bool consumed = false;

    kindalog("playerinfoOnEvent");

    if(event.type == SceneManagerEventTypeBack) {
        // Back button pressed
        kindalog("back");
    } else if(event.type == SceneManagerEventTypeCustom) {
        consumed = true;
        if(event.event == AppWidgetEventDone) {
            kindalog("callingNextScene");
            scene_manager_next_scene(app->scene_manager, AppSceneAbout);
        }
    }

    kindalog("returning from playerinfoOnEvent");
    return consumed;
}

void app_scene_playerinfo_on_exit(void* context) {
    kindalog("playerinfoOnExit");

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
void app_scene_playerinfo_button_callback(GuiButtonType result, InputType type, void* context) {
    kindalog("playerinfoButtonCallback");

    App* app = (App*)context;
    UNUSED(type);

    if(result == GuiButtonTypeCenter) {
        view_dispatcher_send_custom_event(app->view_dispatcher, AppWidgetEventDone);
    }
}