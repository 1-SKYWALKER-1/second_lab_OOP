#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <obs.h>
#include <QMainWindow>
#include <qlistwidget.h>
#include <qpushbutton.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void removeItem();
    void replaceItem();
    void addItem();
    void removeAll();
    void insertAt();
    void sort();
    void showSelected();
private:
    Ui::MainWindow *ui;
    void setupConnections();
    void setupUi();
    void addWidgets(MainWindow* window);
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QPushButton *viewButton;
    QPushButton *insertAtButton;
    QPushButton *removeButton;
    QPushButton *replaceButton;
    QPushButton *removeAllButton;
    QPushButton *sortButton;
    QPushButton *insertButton;
    Obs* observer;
};
#endif // MAINWINDOW_H
