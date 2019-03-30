#include "SysModule.h"
#include "MainWindow.h"

SysModule::SysModule()
{
    gUiService;
}

SysModule::~SysModule()
{
    MainWindow::destroyInstance();
}
