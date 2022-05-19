#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QListWidgetItem>
#include <QTreeWidgetItem>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 10; ++i)
    {
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(QString("Valor %1").arg(i+1));
        item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        item->setCheckState(Qt::Unchecked);
        ui->listWidget->addItem(item);
    }

    QTreeWidgetItem *headerItem = new QTreeWidgetItem;
    headerItem->setText(0, "Prueba");
    ui->treeWidget->setHeaderItem(headerItem);
    for (int i = 0; i < 10; ++i)
    {
        QTreeWidgetItem *top = new QTreeWidgetItem;
        top->setText(0, QString("Valor %1").arg(i+1));

        QTreeWidgetItem *child1 = new QTreeWidgetItem;
        QTreeWidgetItem *child2 = new QTreeWidgetItem;
        QTreeWidgetItem *child3 = new QTreeWidgetItem;

        child1->setText(0, "Child 1");
        child1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        child1->setCheckState(0, Qt::Unchecked);

        child2->setText(0, "Child 2");
        child2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        child2->setCheckState(0, Qt::Unchecked);

        child3->setText(0, "Child 3");
        child3->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        child3->setCheckState(0, Qt::Unchecked);

        top->addChild(child1);
        top->addChild(child2);
        top->addChild(child3);

        ui->treeWidget->addTopLevelItem(top);
    }
    ui->treeWidget->expandAll();

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Col 1","Col 2", "Col 3"});
    for (int i = 0; i < 10; ++i)
    {
        const int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        QTableWidgetItem *col1Item = new QTableWidgetItem;
        QTableWidgetItem *col2Item = new QTableWidgetItem;
        QTableWidgetItem *col3Item = new QTableWidgetItem;
        col1Item->setText(QString("F%1C%2").arg(row).arg(1));
        col2Item->setText(QString("F%1C%2").arg(row).arg(2));
        col3Item->setText(QString("F%1C%2").arg(row).arg(3));
        col1Item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        col1Item->setCheckState(Qt::Unchecked);
        col2Item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        col2Item->setCheckState(Qt::Unchecked);
        col3Item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        col3Item->setCheckState(Qt::Unchecked);
        ui->tableWidget->setItem(row, 0, col1Item);
        ui->tableWidget->setItem(row, 1, col2Item);
        ui->tableWidget->setItem(row, 2, col3Item);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

