/**
 * UGENE - Integrated Bioinformatics Tools.
 * Copyright (C) 2008-2014 UniPro <ugene@unipro.ru>
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

#include "ExportReadsDialog.h"

#include <U2Core/AppContext.h>
#include <U2Core/DocumentModel.h>

#include <U2Gui/LastUsedDirHelper.h>

#include <QtGui/QFileDialog>
#include <QtGui/QMessageBox>
#include <U2Gui/HelpButton.h>
#include <QtGui/QPushButton>


namespace U2 {

ExportReadsDialog::ExportReadsDialog(QWidget * p, const QList<DocumentFormatId> & formats) : QDialog(p) {
    setupUi(this);
    new HelpButton(this, buttonBox, "4227544");

    buttonBox->button(QDialogButtonBox::Ok)->setText(tr("Export"));
    buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("Cancel"));
    
    foreach(const DocumentFormatId & fid, formats) {
        documentFormatComboBox->addItem(fid, fid);
        DocumentFormat * df = AppContext::getDocumentFormatRegistry()->getFormatById(fid);
        assert(df != NULL);
        filter += QString("%1 - (*.%2);;").arg(fid).arg(df->getSupportedDocumentFileExtensions().first());
    }
    QPushButton *okPushButton = buttonBox->button(QDialogButtonBox::Ok);
    QPushButton *cancelPushButton = buttonBox->button(QDialogButtonBox::Cancel);

    connect(okPushButton, SIGNAL(clicked()), SLOT(accept()));
    connect(cancelPushButton, SIGNAL(clicked()), SLOT(reject()));
    connect(filepathToolButton, SIGNAL(clicked()), SLOT(sl_selectFile()));
    setMaximumHeight(layout()->minimumSize().height());

}

void ExportReadsDialog::accept() {
    if(filepathLineEdit->text().isEmpty()) {
        QMessageBox::critical(this, tr("Error!"), tr("Select destination file"));
        filepathLineEdit->setFocus(Qt::OtherFocusReason);
        return;
    }
    QDialog::accept();
}

void ExportReadsDialog::sl_selectFile() {
    LastUsedDirHelper lod("ExportReadsDialog");
    lod.url = QFileDialog::getSaveFileName(this, tr("Select file to save"), lod, filter);
    if (lod.url.isEmpty()) {
        return;
    }
    filepathLineEdit->setText(lod.url);
}

ExportReadsDialogModel ExportReadsDialog::getModel() const {
    ExportReadsDialogModel ret;
    ret.filepath = filepathLineEdit->text();
    ret.format = documentFormatComboBox->currentText();
    ret.addToProject = addToProjectCheckBox->isChecked();
    return ret;
}

} // U2
