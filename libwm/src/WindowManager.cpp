#include <piga/wm/WindowManager.hpp>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <wlc/wlc.h>

namespace piga
{
namespace wm
{

// Wlc hooks
static bool view_created(wlc_handle view)
{
    wlc_view_set_mask(view, wlc_output_get_mask(wlc_view_get_output(view)));
    wlc_view_bring_to_front(view);
    wlc_view_focus(view);
    return true;
}

static void view_focus(wlc_handle view, bool focus)
{
    wlc_view_set_state(view, WLC_BIT_ACTIVATED, focus);
}

static bool keyboard_input(wlc_handle view, uint32_t time, const struct wlc_modifiers* mods, uint32_t key, enum wlc_key_state state)
{
    if(view == 0) {
        if(mods->mods & WLC_BIT_MOD_CTRL && mods->mods & WLC_BIT_MOD_ALT && state == WLC_KEY_STATE_RELEASED) {
            int keysym = wlc_keyboard_get_keysym_for_key(key, mods);
            if(keysym == XKB_KEY_Escape) {
                // CTRL + ALT + ESC equals shutdown.

				WindowManager::stop();

                return true;
            } else if(keysym == XKB_KEY_Return) {
                char *terminal = (getenv("TERMINAL") ? getenv("TERMINAL") : nullptr);
                bool del = false;
                if(terminal == nullptr) {
                    terminal = new char[sizeof("weston-terminal") + 1];
                    std::memcpy(terminal, "weston-terminal", sizeof("weston-terminal"));
                    del = true;
                }
                char * const *args = new char*[2]{terminal, nullptr};
			    wlc_exec(terminal, args);
                std::cout << "TERMINAL" << std::endl;

                if(del) {
					delete terminal;
                }
                delete[] args;
                return true;
            }
        }
    }
    return false;
}

static void cb_log(enum wlc_log_type type, const char *str)
{
    (void)type;
	std::cout << "WLC-Log: " << str << std::endl;
}

WindowManager::WindowManager()
{

}
WindowManager::~WindowManager()
{
    if(m_started) {
        stop();
    }
}
int WindowManager::init()
{
    m_started = true;
    wlc_set_view_created_cb(view_created);
    wlc_set_view_focus_cb(view_focus);
    wlc_set_keyboard_key_cb(keyboard_input);

    wlc_log_set_handler(cb_log);
    
    if (!wlc_init())
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
int WindowManager::run()
{
    wlc_run();
    return EXIT_SUCCESS;
}
void WindowManager::stop()
{
    wlc_terminate();
}
}
}
