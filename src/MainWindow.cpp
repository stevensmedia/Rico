#include "MainWindow.h"

#include <QDir>
#include <QSettings>
#include <QWebEngineProfile>
#include <QWebEnginePage>
#include <QWebEngineView>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, profile(new QWebEngineProfile("Rico"))
	, page(new QWebEnginePage(profile))
	, view(new QWebEngineView(this))
{
	QSettings settings;
	restoreGeometry(settings.value("mainWindowGeometry").toByteArray());
	QDir().mkpath(profile->persistentStoragePath());
	setCentralWidget(view);
	view->setPage(page);
	page->load(QUrl("https://tweetdeck.twitter.com/"));

	restoreState(settings.value("mainWindowState").toByteArray());
}

void MainWindow::closeEvent(QCloseEvent *)
{
	QSettings settings;
	settings.setValue("mainWindowGeometry", saveGeometry());
	settings.setValue("mainWindowState", saveState());
}

MainWindow::~MainWindow()
{
	delete page;
	delete profile;
}
