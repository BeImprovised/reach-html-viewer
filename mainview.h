#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QWebEngineView>

class MainView : public QWidget
{
    Q_OBJECT
public:
    MainView(QWidget *parent=0);
    ~MainView();

private:
   QWebEngineView *view; 
};

#endif // MAINVIEW_H
