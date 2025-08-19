#pragma once
#include <QDialog>
#include "ui_dialog_1.h"
class Dialog1 : public QDialog
{
	Q_OBJECT
public:
	Dialog1(QWidget* parent = nullptr);
	virtual ~Dialog1();
private:
	Ui::Dialog_1 ui;
};
