#include "AddFriendDialog.h"
#include "ui_AddFriendDialog.h"

#include <QComboBox>

#include <QDebug>

AddFriendDialog::AddFriendDialog(QTableWidget* table, QWidget* parent) :
    QDialog(parent),
    ui_(new Ui::AddFriendDialog),
    table_(table)
{
    ui_->setupUi(this);
    connect(ui_->CancelButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui_->AcceptButton, SIGNAL(clicked()), this, SLOT(addFriend()));
}

AddFriendDialog::~AddFriendDialog()
{
    delete ui_;
}

void AddFriendDialog::addFriend()
{
    table_->insertRow(table_->rowCount());

    table_->setItem(table_->rowCount() - 1, 0, new QTableWidgetItem(QString(ui_->NameTextField->toPlainText())));

    auto combo_box_ptr = new QComboBox();
    combo_box_ptr->addItem("Приятель");
    combo_box_ptr->addItem("Друг");
    combo_box_ptr->addItem("Близкий друг");
    combo_box_ptr->setCurrentIndex(-2 - ui_->FriendLevelRadioButtonsGroup->checkedId());
    table_->setCellWidget(table_->rowCount() - 1, 1, combo_box_ptr);

    table_->setItem(table_->rowCount() - 1, 2, new QTableWidgetItem(QString(ui_->DescrTextField->toPlainText())));
    table_->setCellWidget(table_->rowCount() - 1, 3, new QDateEdit(ui_->FriendDateEdit->date()));

    close();
}
