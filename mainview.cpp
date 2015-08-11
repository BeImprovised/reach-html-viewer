#include "mainview.h"

MainView::MainView(QWidget *parent)
    : QWidget(parent)
{
  view = new QWebEngineView(parent);
  view->load(QUrl("http://qt-project.org/"));
  view->show();
}

MainView::~MainView()
{
    delete view;
}

