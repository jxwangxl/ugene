/**
 * UGENE - Integrated Bioinformatics Tools.
 * Copyright (C) 2008-2016 UniPro <ugene@unipro.ru>
 * http://ugene.unipro.ru
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include "MaOverview.h"

#include <U2View/MSAEditor.h>
#include <U2View/MSAEditorSequenceArea.h>

#include <QtGui/QMouseEvent>
#include <QPainter>

namespace U2 {

MaOverview::MaOverview(MaEditorWgt *_ui)
    : editor(_ui->getEditor()),
      ui(_ui),
      sequenceArea(_ui->getSequenceArea())
{
    connect(sequenceArea, SIGNAL(si_visibleRangeChanged()), this, SLOT(sl_visibleRangeChanged()));
    connect(sequenceArea, SIGNAL(si_selectionChanged(MaEditorSelection,MaEditorSelection)),
            SLOT(sl_selectionChanged()));
    connect(editor->getMaObject(), SIGNAL(si_alignmentChanged(MultipleAlignment,MaModificationInfo)),
            SLOT(sl_redraw()));
}

void MaOverview::sl_visibleRangeChanged() {
    if (!isValid()) {
        return;
    }
    update();
}

void MaOverview::mousePressEvent(QMouseEvent *me) {
    if (!isValid()) {
        return;
    }

    if (me->buttons() == Qt::LeftButton) {
        visibleRangeIsMoving = true;
        setCursor(Qt::ClosedHandCursor);
        moveVisibleRange(me->pos());
    }
    QWidget::mousePressEvent(me);
}

void MaOverview::mouseMoveEvent(QMouseEvent *me) {
    if (!isValid()) {
        return;
    }

    if ((me->buttons() & Qt::LeftButton) && visibleRangeIsMoving) {
        moveVisibleRange(me->pos());
    }
    QWidget::mouseMoveEvent(me);
}

void MaOverview::mouseReleaseEvent(QMouseEvent *me) {
    if (!isValid()) {
        return;
    }

    if ((me->buttons() & Qt::LeftButton) && visibleRangeIsMoving) {
        visibleRangeIsMoving = false;
        setCursor(Qt::ArrowCursor);
    }
    QWidget::mouseReleaseEvent(me);
}

void MaOverview::setVisibleRangeForEmptyAlignment() {
    cachedVisibleRange = rect();
}

void MaOverview::showWarning(QPainter& painter, QPaintEvent *e, const QString& warningMessage) {
    painter.fillRect(rect(), Qt::gray);

    QFontMetrics metrics(painter.font(), this);
    painter.drawText(rect(), Qt::AlignCenter, metrics.elidedText(
        warningMessage,
        Qt::ElideRight,
        rect().width()));

    QWidget::paintEvent(e);
    return;
}

} // namespace
