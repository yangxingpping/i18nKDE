
#include "Dialog1.h"

Dialog1::Dialog1(QWidget* parent)
	:QDialog(parent)
{
	this->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
	ui.setupUi(this);
}

Dialog1::~Dialog1()
{
}
