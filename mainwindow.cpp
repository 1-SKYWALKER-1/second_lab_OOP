#include "mainwindow.h"

#include <qboxlayout.h>
#include <qlineedit.h>

void MainWindow::removeAll() {
    observer->removeAll();
}

void MainWindow::removeItem() {
    QListWidgetItem *item = listWidget->currentItem();
    if (item != nullptr)
        observer->removeItem(item->text());
}

void MainWindow::replaceItem() {
    QListWidgetItem *oldItem = listWidget->currentItem();
    if (oldItem != nullptr)
        observer->replaceItem(oldItem->text(), lineEdit->text());
}

void MainWindow::addItem() {
    observer->addItem(lineEdit->text());
}

void MainWindow::insertAt() {
    QListWidgetItem *item = listWidget->currentItem();
    if (item != nullptr)
        observer->insertAt(lineEdit->text(), item->text());
}

void MainWindow::sort() {
    observer->sort();
}

void MainWindow::showSelected() {
    QListWidgetItem *item = listWidget->currentItem();
    if (item != nullptr)
        lineEdit->setText(item->text());
}

void MainWindow::addWidgets(MainWindow* window) {
    QWidget *centralWidget = new QWidget();
    QVBoxLayout *vLayout = new QVBoxLayout(centralWidget);
    QVBoxLayout *vLayoutButtons = new QVBoxLayout();
    QHBoxLayout *hLayout = new QHBoxLayout();

    vLayoutButtons->addWidget(viewButton);
    vLayoutButtons->addWidget(insertButton);
    vLayoutButtons->addWidget(removeButton);
    vLayoutButtons->addWidget(replaceButton);
    vLayoutButtons->addWidget(removeAllButton);
    vLayoutButtons->addWidget(sortButton);
    vLayoutButtons->addWidget(insertAtButton);

    hLayout->addWidget(listWidget);
    hLayout->addLayout(vLayoutButtons);

    vLayout->addLayout(hLayout);
    vLayout->addWidget(lineEdit);

    window->setCentralWidget(centralWidget);
    centralWidget->setLayout(vLayout);
}

void MainWindow::setupUi() {
    listWidget = new QListWidget();
    lineEdit = new QLineEdit();
    viewButton = new QPushButton("Переглянути обраний");
    insertButton = new QPushButton("Вставити");
    removeButton = new QPushButton("Видалити");
    replaceButton = new QPushButton("Замінити");
    removeAllButton = new QPushButton("Видалити все");
    sortButton = new QPushButton("Відсортувати");
    insertAtButton = new QPushButton("Вставити на позицію");

    observer = new Obs([this](const QStringList& data) {
        listWidget->clear();
        listWidget->addItems(data);
    });

    addWidgets(this);
}

void MainWindow::setupConnections() {
    connect(listWidget, &QListWidget::itemClicked, this, &MainWindow::showSelected);
    connect(viewButton, &QPushButton::clicked, this, &MainWindow::showSelected);
    connect(insertButton, &QPushButton::clicked, this, &MainWindow::addItem);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::removeItem);
    connect(replaceButton, &QPushButton::clicked, this, &MainWindow::replaceItem);
    connect(insertAtButton, &QPushButton::clicked, this, &MainWindow::insertAt);
    connect(sortButton, &QPushButton::clicked, this, &MainWindow::sort);
    connect(removeAllButton, &QPushButton::clicked, this, &MainWindow::removeAll);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    setupUi();
    setupConnections();
}

MainWindow::~MainWindow()
{
    delete listWidget;
    delete lineEdit;
    delete viewButton;
    delete insertButton;
    delete removeButton;
    delete replaceButton;
    delete removeAllButton;
    delete sortButton;
    delete insertAtButton;
    delete observer;
    delete ui;
}
