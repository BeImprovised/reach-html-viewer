#include <QApplication>
#include <QSettings>
#include <QFileInfo>
#include <QDebug>
#include <QDir>
#include <QUrl>

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


    return app.exec();
}
