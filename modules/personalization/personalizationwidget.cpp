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

#include "personalizationwidget.h"
#include "contentwidget.h"
#include "settingsgroup.h"
#include "personalizationmodel.h"
#include "nextpagewidget.h"
#include "settingsgroup.h"
#include "nextpagewidget.h"
#include "switchwidget.h"

#include <QPushButton>
#include <QDebug>

using namespace dcc;
using namespace dcc::personalization;
using namespace dcc::widgets;

PersonalizationWidget::PersonalizationWidget()
    : ModuleWidget(),

      m_userGroup(new SettingsGroup)
{
    setObjectName("Personalization");

    m_centralLayout->addWidget(m_userGroup);
    NextPageWidget *theme = new NextPageWidget;
    NextPageWidget *font = new NextPageWidget;

    m_wmSwitch = new SwitchWidget(tr("Enable window effect"));

    theme->setTitle(tr("Theme"));
    font->setTitle(tr("Font"));

    m_userGroup->appendItem(theme);
    m_userGroup->appendItem(font);
    m_userGroup->appendItem(m_wmSwitch);

    setTitle(tr("Personalization"));
    connect(theme, &NextPageWidget::clicked, this, &PersonalizationWidget::showThemeWidget);
    connect(font, &NextPageWidget::clicked, this, &PersonalizationWidget::showFontsWidget);
    connect(m_wmSwitch, &SwitchWidget::checkedChanged, this, &PersonalizationWidget::requestSwitchWM);
}

void PersonalizationWidget::setModel(PersonalizationModel * const model)
{
    connect(model, &PersonalizationModel::wmChanged, m_wmSwitch, &SwitchWidget::setChecked);

    m_wmSwitch->setChecked(model->is3DWm());
}
