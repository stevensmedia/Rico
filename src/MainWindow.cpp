#include "MainWindow.h"

#include <QDesktopServices>
#include <QDir>
#include <QSettings>
#include <QWebEngineNavigationRequest>
#include <QWebEngineNewWindowRequest>
#include <QWebEngineProfile>
#include <QWebEnginePage>
#include <QWebEngineView>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, profile(new QWebEngineProfile("Rico"))
	, page(new QWebEnginePage(profile))
	, view(new QWebEngineView(this))
{
	setWindowTitle("Rico");

	QSettings settings;
	restoreGeometry(settings.value("mainWindowGeometry").toByteArray());
	QDir().mkpath(profile->persistentStoragePath());
	setCentralWidget(view);
	view->setPage(page);
	page->load(QUrl("https://tweetdeck.twitter.com/"));

	connect(page, &QWebEnginePage::titleChanged, this, &QMainWindow::setWindowTitle);
	connect(page, &QWebEnginePage::navigationRequested, [] (QWebEngineNavigationRequest &req) {
		QString u = req.url().toString();
		if(!u.contains("tweetdeck.twitter.com/") &&
		   !u.contains("twitter.com/i/") &&
		   !u.contains("accounts.google.com") &&
		   !u.contains("twitter.com/login")) {
			QDesktopServices::openUrl(req.url());
			req.reject();
		}
	});

	connect(page, &QWebEnginePage::newWindowRequested, [] (QWebEngineNewWindowRequest &req) {
		QDesktopServices::openUrl(req.requestedUrl());
	});


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
