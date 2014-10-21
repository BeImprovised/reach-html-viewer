#include <QApplication>
#include <QSettings>
#include <QFileInfo>
#include <QDebug>
#include <QDir>
#include <QUrl>
#include <QWSServer>

#include "mainview.h"
#include "systemdefs.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QApplication::setOrganizationName("Reach Technology");
    QApplication::setOrganizationDomain("reachtech.com");
    QApplication::setApplicationName("HTML Viewer");
    QApplication::setApplicationVersion(APP_VERSION);
    QFileInfo settingsFile;

    QStringList args = app.arguments();

    foreach (QString item, args) {
        if(item == "--version" || item == "-v") {
            qDebug() << "HTML Viewer " << APP_VERSION;
            return 0;
        }
    }

    QString sb(QApplication::applicationDirPath());
    sb.append(QDir::separator());
    sb.append("settings.conf");
    // check to see if we have a settings file where we started from
    // if not fall back to system hard coded path
    QFileInfo file(sb.toLatin1());
    if (file.exists()) {
        qDebug() << "using local settings file";
        settingsFile.setFile(file.filePath());
    } else {
        qDebug() << "using system defined settings file";
        settingsFile.setFile(SYSTEM_SETTINGS_FILE);
    }

    QSettings settings(settingsFile.filePath(),QSettings::NativeFormat);

    settings.beginGroup(SYSTEM_SETTINGS_SECTION);
    MainView viewer;

    QUrl url(settings.value("main_view").toString());
    viewer.setUrl(url);
    qDebug() << "loading url: " << settings.value("main_view").toString();

    if (settings.value("full_screen",false).toBool()) {
        viewer.showFullScreen();
    }

    if (settings.value("hide_cursor",false).toBool()) {
        viewer.setCursor(QCursor(Qt::BlankCursor));
#ifdef Q_WS_QWS
    QWSServer::setCursorVisible(false);
#endif
    }

    viewer.setScrollbars(settings.value("hide_scrollbars",false).toBool());
    viewer.setCache(settings.value("enable_cache",false).toBool(), settings.value("cache_size_megabytes",5).toInt());

    settings.endGroup();

    viewer.show();

    return app.exec();
}
