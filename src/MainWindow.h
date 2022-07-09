#include <QMainWindow>

class QWebEnginePage;
class QWebEngineProfile;
class QWebEngineView;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

protected:
	void closeEvent(QCloseEvent *);

private:
	QWebEngineProfile *profile;
	QWebEnginePage *page;
	QWebEngineView *view;
};
