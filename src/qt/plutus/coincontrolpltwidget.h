// Copyright (c) 2019 The PLUTUS developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLPLTWIDGET_H
#define COINCONTROLPLTWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlPltWidget;
}

class CoinControlPltWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlPltWidget(QWidget *parent = nullptr);
    ~CoinControlPltWidget();

private:
    Ui::CoinControlPltWidget *ui;
};

#endif // COINCONTROLPLTWIDGET_H
