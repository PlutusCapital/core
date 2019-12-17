// Copyright (c) 2019 The PLUTUS developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MASTERNODESWIDGET_H
#define MASTERNODESWIDGET_H

#include <QWidget>
#include "qt/plutus/pwidget.h"
#include "qt/plutus/furabstractlistitemdelegate.h"
#include "qt/plutus/mnmodel.h"
#include "qt/plutus/tooltipmenu.h"
#include <QTimer>

class PLUTUSGUI;

namespace Ui {
class MasterNodesWidget;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

class MasterNodesWidget : public PWidget
{
    Q_OBJECT

public:

    explicit MasterNodesWidget(PLUTUSGUI *parent = nullptr);
    ~MasterNodesWidget();

    void loadWalletModel() override;
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;

private slots:
    void onCreateMNClicked();
    void changeTheme(bool isLightTheme, QString &theme) override;
    void onMNClicked(const QModelIndex &index);
    void onEditMNClicked();
    void onDeleteMNClicked();
    void onInfoMNClicked();
    void updateListState();

private:
    Ui::MasterNodesWidget *ui;
    FurAbstractListItemDelegate *delegate;
    MNModel *mnModel = nullptr;
    TooltipMenu* menu = nullptr;
    QModelIndex index;
    QTimer *timer = nullptr;

    void startAlias(QString strAlias);
};

#endif // MASTERNODESWIDGET_H
