#ifndef __MAIN_FAB_COUNTER__
#define __MAIN_FAB_COUNTER__

#include <furi.h>
#include <furi_hal.h>

#include <furi_hal_gpio.h>
#include <furi_hal_resources.h>

#include <gui/gui.h>
#include <locale/locale.h>

#include <gui/scene_manager.h>
#include <gui/view_dispatcher.h>

#include <gui/modules/widget.h>

#include "modules/knob.h"

#define TAG "FABCOUNTER"

void kindalog(char*);

/**
 * @brief Scene List
 * 
 */
typedef enum {
    AppSceneArena,
    AppSceneAbout,
    // AppSceneSetVolume,
    // AppSceneSetFrequency,
    // AppSceneSummary,
    //
    AppSceneCount,
} appScenes;

/**
 * @brief Module List
 * 
 */
typedef enum {
    AppViewKnob,
    AppViewWidget,
} appViews;

/**
 * @brief Events List
 * 
 */
typedef enum {
    AppKnobEventDone,
    AppWidgetEventDone,
} appCustomEvents;

/**
 * @brief App Structure
 * 
 */
typedef struct App {
    SceneManager* scene_manager;
    ViewDispatcher* view_dispatcher;
    Knob* knob;
    Widget* widget;
    // App data
    float volume;
    float frequency;
} App;

#endif