// Copyright (c) 2017-2018 The PLUTUS developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZPLTCONTROLDIALOG_H
#define ZPLTCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zplt/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZPltControlDialog;
}

class CZPltControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZPltControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZPltControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZPltControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZPltControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZPltControlDialog(QWidget *parent);
    ~ZPltControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZPltControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZPltControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZPLTCONTROLDIALOG_H
