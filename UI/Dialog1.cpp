
#include "Dialog1.h"
#include "KF5/KItemModels/KCheckableProxyModel"
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
    auto p2 = new QStandardItem(QStringLiteral("Another Node"));
    p2->setCheckable(true);
    rootItem->appendRow({p2 , new QStandardItem(QStringLiteral("123")) });

    KCheckableProxyModel* checkableModel = new KCheckableProxyModel;
    checkableModel->setSourceModel(model);

	ui.treeView->setModel(checkableModel);
    ui.treeView->expandAll();
    ui.treeView->setColumnWidth(0, 300);
}

Dialog1::~Dialog1()
{
}
