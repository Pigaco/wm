#ifndef PIGA_LIBWM_WINDOWMANAGER_HPP_INCLUDED
#define PIGA_LIBWM_WINDOWMANAGER_HPP_INCLUDED

namespace piga
{
namespace wm
{
class WindowManager 
{
public:
    WindowManager();
    ~WindowManager();

    int init();

    /**
     * @brief run Executes the window manager. As soon as it is executed, no additional functions
     * can be run. This exits the program after finishing.
     * @return
     */
    int run();

    static void stop();
    static void signalDaemon();
private:
	bool m_started = false;
};
}
}

#endif
