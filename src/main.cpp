#include <execinfo.h>
#include <QApplication>

#include <MainWindow.h>
#include <zconf.h>
#include <csignal>

void handler(int sig) {
    size_t size;
    void *array[10];
    size = backtrace(array, 10);

    // print out all the frames to stderr
    fprintf(stderr, "Error: signal %d:\n", sig);
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}

int main(int argc, char *argv[])
{

    signal(SIGSEGV, handler);
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("ROSIDE");
    QCoreApplication::setApplicationVersion("0.0.1");

    MainWindow::get();

    return app.exec();
}
