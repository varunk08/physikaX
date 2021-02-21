#include <android/log.h>
#include <android_native_app_glue.h>

#include <jni.h>
#include <string>

#include "renderer/renderer.h"

bool initialize(android_app* app) {
    Renderer* renderer_ = Renderer::CreateRenderer(RendererType::VULKAN);
    renderer_->Init();
    return true;
}

void terminate() {
}

// Process the next main command.
void handle_cmd(android_app* app, int32_t cmd) {
    switch (cmd) {
        case APP_CMD_INIT_WINDOW:
            // The window is being shown, get it ready.
            initialize(app);
            break;
        case APP_CMD_TERM_WINDOW:
            // The window is being hidden or closed, clean it up.
            terminate();
            break;
        default:
            //LOGI("event not handled: %d", cmd);
            break;
    }
}

void android_main(struct android_app *pApp) {
    pApp->onAppCmd = handle_cmd;

    int events;
    android_poll_source *pSource;
    do {
        if (ALooper_pollAll(0, nullptr, &events, (void **) &pSource) >= 0) {
            if (pSource) {
                pSource->process(pApp, pSource);
            }
        }
    } while (!pApp->destroyRequested);
}
