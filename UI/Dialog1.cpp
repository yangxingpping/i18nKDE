
#include "Dialog1.h"
#include <QStandardItemModel>

Dialog1::Dialog1(QWidget* parent)
	:QDialog(parent)
{
	this->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
	ui.setupUi(this);
    QStandardItemModel* model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({ QStringLiteral("Name"), QStringLiteral("Value") });

    QStandardItem* rootItem = model->invisibleRootItem();

    QStandardItem* parentItem = new QStandardItem(QStringLiteral("Parent Node"));
    parentItem->appendRow({ new QStandardItem(QStringLiteral("Child 1")), new QStandardItem(QStringLiteral("Value 1")) });
    parentItem->appendRow({ new QStandardItem(QStringLiteral("Child 2")), new QStandardItem(QStringLiteral("Value 2")) });
    rootItem->appendRow({ parentItem, new QStandardItem(QStringLiteral("Parent Value")) });
    rootItem->appendRow({ new QStandardItem(QStringLiteral("Another Node")), new QStandardItem(QStringLiteral("123")) });
	ui.treeView->setModel(model);
}

Dialog1::~Dialog1()
{
}
