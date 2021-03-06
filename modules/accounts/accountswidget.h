/*
 * Copyright (C) 2011 ~ 2017 Deepin Technology Co., Ltd.
 *
 * Author:     sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * Maintainer: sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ACCOUNTSWIDGET_H
#define ACCOUNTSWIDGET_H

#include "modulewidget.h"
#include "contentwidget.h"
#include "settingsgroup.h"
#include "nextpagewidget.h"
#include "user.h"

#include <QPushButton>
#include <QVBoxLayout>

namespace dcc {
namespace accounts {

class AccountsWidget : public ModuleWidget
{
    Q_OBJECT

public:
    explicit AccountsWidget();

signals:
    void showAccountsDetail(User *account) const;
    void requestCreateAccount() const;
#ifdef DCC_ENABLE_ADDOMAIN
    void requestShowADDialog() const;
#endif

public slots:
    void addUser(User *user);
    void removeUser(User *user);
#ifdef DCC_ENABLE_ADDOMAIN
    void setADState(bool isJoin);
#endif

private:
    dcc::widgets::SettingsGroup *m_userGroup;
    QPushButton *m_createBtn;
#ifdef DCC_ENABLE_ADDOMAIN
    QPushButton *m_adBtn;
#endif
};

}   // namespace accounts
}   // namespace dcc

#endif // ACCOUNTSWIDGET_H
