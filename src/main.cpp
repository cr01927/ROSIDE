#include <execinfo.h>
#include <QApplication>

#include <MainWindow.h>
#include <zconf.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("ROSIDE");
    QCoreApplication::setApplicationVersion("0.0.1");

    MainWindow::get();

    return app.exec();
}
