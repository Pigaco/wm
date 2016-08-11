#include <piga/wm/WindowManager.hpp>
#include <cstdlib>

using namespace piga::wm;

int main(int argc, char *argv[])
{
    WindowManager wm;

    int status = 0;

    status = wm.init();

    if(status != EXIT_SUCCESS)
        return status;

    return wm.run();
}
