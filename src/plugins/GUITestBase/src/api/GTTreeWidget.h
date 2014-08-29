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

#ifndef _U2_GT_TREE_WIDGET_H_
#define _U2_GT_TREE_WIDGET_H_

#include "api/GTGlobals.h"

class QTreeWidget;
class QTreeWidgetItem;

namespace U2 {

class GTTreeWidget {
public:
    // expands treeWidget to the item and returns item's rect
    static QRect getItemRect(U2OpStatus &os, QTreeWidgetItem* item);

    static QPoint getItemCenter(U2OpStatus &os, QTreeWidgetItem* item);

    // recursively expands the tree making the given item visible
    // fails if item is NULL, item is hidden or item wasn't expanded
    static void expand(U2OpStatus &os, QTreeWidgetItem* item);

    // Checks the tree item or unchecks it if it is already checked
    static void checkItem(U2OpStatus &os, QTreeWidgetItem *item, int column = 0);

    // gets all items under root recursively and returns a list of them
    static QList<QTreeWidgetItem*> getItems(QTreeWidgetItem* root);

    static QTreeWidgetItem* findItem(U2OpStatus &os, QTreeWidget* tree, const QString& text, QTreeWidgetItem* parent = NULL, int column = 0);
    static void click(U2OpStatus &os, QTreeWidgetItem* item);
};

} // namespace

#endif
