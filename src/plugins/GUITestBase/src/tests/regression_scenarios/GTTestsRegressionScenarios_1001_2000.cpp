/**
 * UGENE - Integrated Bioinformatics Tools.
 * Copyright (C) 2008-2015 UniPro <ugene@unipro.ru>
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

#include "GTTestsRegressionScenarios.h"

#include "api/GTRadioButton.h"
#include "api/GTAction.h"
#include "api/GTCheckBox.h"
#include "api/GTClipboard.h"
#include "api/GTComboBox.h"
#include "api/GTFile.h"
#include "api/GTFileDialog.h"
#include "api/GTGlobals.h"
#include "api/GTKeyboardDriver.h"
#include "api/GTKeyboardUtils.h"
#include "api/GTLineEdit.h"
#include "api/GTListWidget.h"
#include "api/GTMenu.h"
#include "api/GTMouseDriver.h"
#include "api/GTSequenceReadingModeDialog.h"
#include "api/GTSequenceReadingModeDialogUtils.h"
#include "api/GTSlider.h"
#include "api/GTSpinBox.h"
#include "api/GTTabWidget.h"
#include "api/GTTableView.h"
#include "api/GTToolbar.h"
#include "api/GTTreeWidget.h"
#include "api/GTWidget.h"

#include "GTDatabaseConfig.h"
#include "GTUtilsAnnotationsTreeView.h"
#include "GTUtilsAnnotationsHighlightingTreeView.h"
#include "GTUtilsAssemblyBrowser.h"
#include "GTUtilsBookmarksTreeView.h"
#include "GTUtilsCircularView.h"
#include "GTUtilsDashboard.h"
#include "GTUtilsDialog.h"
#include "GTUtilsEscClicker.h"
#include "GTUtilsExternalTools.h"
#include "GTUtilsLog.h"
#include "GTUtilsMdi.h"
#include "GTUtilsMsaEditor.h"
#include "GTUtilsMsaEditorSequenceArea.h"
#include "GTUtilsNotifications.h"
#include "GTUtilsOptionPanelMSA.h"
#include "GTUtilsOptionsPanel.h"
#include "GTUtilsOptionPanelSequenceView.h"
#include "GTUtilsPhyTree.h"
#include "GTUtilsProject.h"
#include "GTUtilsProjectTreeView.h"
#include "GTUtilsSequenceView.h"
#include "GTUtilsSharedDatabaseDocument.h"
#include "GTUtilsTask.h"
#include "GTUtilsTaskTreeView.h"
#include "GTUtilsToolTip.h"
#include "GTUtilsWizard.h"
#include "GTUtilsWorkflowDesigner.h"

#include "runnables/qt/EscapeClicker.h"
#include "runnables/qt/MessageBoxFiller.h"
#include "runnables/qt/PopupChooser.h"
#include "runnables/ugene/corelibs/U2Gui/AlignShortReadsDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/AppSettingsDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/BuildIndexDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/ConvertAssemblyToSAMDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/CreateAnnotationWidgetFiller.h"
#include "runnables/ugene/corelibs/U2Gui/CreateDocumentFromTextDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/CreateObjectRelationDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/DownloadRemoteFileDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/EditAnnotationDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/EditConnectionDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/EditQualifierDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/EditSequenceDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/ExportDocumentDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/ExportImageDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/FindQualifierDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/FindRepeatsDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/FindTandemsDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/ImportBAMFileDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/PositionSelectorFiller.h"
#include "runnables/ugene/corelibs/U2Gui/ProjectTreeItemSelectorDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/RangeSelectionDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/RemovePartFromSequenceDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/ReplaceSubsequenceDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/SharedConnectionsDialogFiller.h"
#include "runnables/ugene/corelibs/U2Gui/util/RenameSequenceFiller.h"
#include "runnables/ugene/corelibs/U2View/ov_assembly/ExportReadsDialogFiller.h"
#include "runnables/ugene/corelibs/U2View/ov_msa/BuildTreeDialogFiller.h"
#include "runnables/ugene/corelibs/U2View/ov_msa/DeleteGapsDialogFiller.h"
#include "runnables/ugene/corelibs/U2View/ov_msa/DistanceMatrixDialogFiller.h"
#include "runnables/ugene/corelibs/U2View/ov_msa/ExportHighlightedDialogFiller.h"
#include "runnables/ugene/corelibs/U2View/ov_msa/ExtractSelectedAsMSADialogFiller.h"
#include "runnables/ugene/corelibs/U2View/ov_msa/LicenseAgreemntDialogFiller.h"
#include "runnables/ugene/corelibs/U2View/utils_smith_waterman/SmithWatermanDialogBaseFiller.h"
#include "runnables/ugene/plugins/annotator/FindAnnotationCollocationsDialogFiller.h"
#include "runnables/ugene/plugins/biostruct3d_view/StructuralAlignmentDialogFiller.h"
#include "runnables/ugene/plugins/cap3/CAP3SupportDialogFiller.h"
#include "runnables/ugene/plugins/dna_export/ExportAnnotationsDialogFiller.h"
#include "runnables/ugene/plugins/dna_export/ExportMSA2MSADialogFiller.h"
#include "runnables/ugene/plugins/dna_export/ExportMSA2SequencesDialogFiller.h"
#include "runnables/ugene/plugins/dna_export/ExportSelectedSequenceFromAlignmentDialogFiller.h"
#include "runnables/ugene/plugins/dna_export/ExportSequences2MSADialogFiller.h"
#include "runnables/ugene/plugins/dna_export/ExportSequencesDialogFiller.h"
#include "runnables/ugene/plugins/dna_export/ImportAnnotationsToCsvFiller.h"
#include "runnables/ugene/plugins/dotplot/BuildDotPlotDialogFiller.h"
#include "runnables/ugene/plugins/dotplot/DotPlotDialogFiller.h"
#include "runnables/ugene/plugins/enzymes/ConstructMoleculeDialogFiller.h"
#include "runnables/ugene/plugins/enzymes/DigestSequenceDialogFiller.h"
#include "runnables/ugene/plugins/enzymes/FindEnzymesDialogFiller.h"
#include "runnables/ugene/plugins/external_tools/BlastAllSupportDialogFiller.h"
#include "runnables/ugene/plugins/external_tools/ClustalOSupportRunDialogFiller.h"
#include "runnables/ugene/plugins/external_tools/FormatDBDialogFiller.h"
#include "runnables/ugene/plugins/external_tools/RemoteBLASTDialogFiller.h"
#include "runnables/ugene/plugins/external_tools/SpadesGenomeAssemblyDialogFiller.h"
#include "runnables/ugene/plugins/external_tools/TCoffeeDailogFiller.h"
#include "runnables/ugene/plugins/weight_matrix/PwmBuildDialogFiller.h"
#include "runnables/ugene/plugins/workflow_designer/AliasesDialogFiller.h"
#include "runnables/ugene/plugins/workflow_designer/ConfigurationWizardFiller.h"
#include "runnables/ugene/plugins/workflow_designer/CreateElementWithCommandLineToolFiller.h"
#include "runnables/ugene/plugins/workflow_designer/CreateElementWithScriptDialogFiller.h"
#include "runnables/ugene/plugins/workflow_designer/StartupDialogFiller.h"
#include "runnables/ugene/plugins/workflow_designer/WizardFiller.h"
#include "runnables/ugene/plugins/workflow_designer/WorkflowMetadialogFiller.h"
#include "runnables/ugene/plugins_3rdparty/hmm3/UHMM3PhmmerDialogFiller.h"
#include "runnables/ugene/plugins_3rdparty/hmm3/UHMM3SearchDialogFiller.h"
#include "runnables/ugene/plugins_3rdparty/kalign/KalignDialogFiller.h"
#include "runnables/ugene/plugins_3rdparty/umuscle/MuscleDialogFiller.h"
#include "runnables/ugene/plugins_3rdparty/clustalw/ClustalWDialogFiller.h"
#include "runnables/ugene/plugins_3rdparty/MAFFT/MAFFTSupportRunDialogFiller.h"
#include "runnables/ugene/plugins_3rdparty/primer3/Primer3DialogFiller.h"
#include "runnables/ugene/ugeneui/ConvertAceToSqliteDialogFiller.h"
#include "runnables/ugene/ugeneui/CreateNewProjectWidgetFiller.h"
#include "runnables/ugene/ugeneui/DocumentFormatSelectorDialogFiller.h"
#include "runnables/ugene/ugeneui/DocumentProviderSelectorDialogFiller.h"
#include "runnables/ugene/ugeneui/NCBISearchDialogFiller.h"
#include "runnables/ugene/ugeneui/SaveProjectDialogFiller.h"
#include "runnables/ugene/ugeneui/SelectDocumentFormatDialogFiller.h"
#include "runnables/ugene/ugeneui/SequenceReadingModeSelectorDialogFiller.h"

#include <U2Core/AppContext.h>
#include <U2Core/ExternalToolRegistry.h>
#include <U2Core/U2ObjectDbi.h>
#include <U2Core/U2OpStatusUtils.h>

#include <U2Gui/ProjectViewModel.h>
#include <U2Gui/ToolsMenu.h>

#include "../../workflow_designer/src/WorkflowViewItems.h"

#include <U2View/ADVConstants.h>
#include <U2View/ADVSingleSequenceWidget.h>
#include <U2View/AnnotatedDNAViewFactory.h>
#include <U2View/AnnotationsTreeView.h>
#include <U2View/AssemblyBrowser.h>
#include <U2View/AssemblyModel.h>
#include <U2View/AssemblyNavigationWidget.h>
#include <U2View/MSAEditor.h>
#include <U2View/MSAEditorNameList.h>

#include <QDialogButtonBox>
#include <QFileDialog>
#include <QHeaderView>
#include <QListWidget>
#include <QMainWindow>
#include <QMenu>
#include <QPlainTextEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QTableWidget>
#include <QWebElement>
#include <QWebFrame>
#include <QWebView>
#include <QWizard>

namespace U2 {

namespace GUITest_regression_scenarios {

GUI_TEST_CLASS_DEFINITION(test_1001_2) {

    GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
    GTUtilsProject::openFiles(os, testDir+"_common_data/fasta/human_T1_cutted.fa");
    GTGlobals::sleep();

    GTUtilsDialog::waitForDialog(os, new DotPlotFiller(os, 99, 99, true));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << ADV_MENU_ANALYSE << "build_dotplot_action", GTGlobals::UseMouse));
    GTMenu::showMainMenu(os, MWMENU_ACTIONS);
    GTGlobals::sleep();

    GTGlobals::sleep(5000);
}

GUI_TEST_CLASS_DEFINITION(test_1001_3) {

    GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
    GTUtilsProject::openFiles(os, testDir+"_common_data/fasta/human_T1_cutted.fa");
    GTGlobals::sleep();

    GTUtilsDialog::waitForDialog(os, new DotPlotFiller(os, 99, 99, true));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << ADV_MENU_ANALYSE << "build_dotplot_action", GTGlobals::UseMouse));
    GTMenu::showMainMenu(os, MWMENU_ACTIONS);
    GTGlobals::sleep(5000);

    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "human_T1.fa"));
    GTMouseDriver::click(os);
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);

    GTGlobals::sleep(5000);
}

GUI_TEST_CLASS_DEFINITION(test_1001_4) {

    GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
    GTUtilsProject::openFiles(os, testDir+"_common_data/fasta/human_T1_cutted.fa");
    GTGlobals::sleep();

    GTUtilsDialog::waitForDialog(os, new DotPlotFiller(os, 99, 99, true));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << ADV_MENU_ANALYSE << "build_dotplot_action", GTGlobals::UseMouse));
    GTMenu::showMainMenu(os, MWMENU_ACTIONS);
    GTGlobals::sleep(5000);

    GTUtilsMdi::click(os, GTGlobals::Close);

    GTGlobals::sleep(5000);
}

GUI_TEST_CLASS_DEFINITION(test_1015) {

    GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
    GTGlobals::sleep();

    GTUtilsDialog::waitForDialog(os, new DotPlotFiller(os, 3));
    GTWidget::click(os, GTWidget::findWidget(os, "build_dotplot_action_widget"));
    GTGlobals::sleep();

    GTUtilsMdi::click(os, GTGlobals::Close);

    GTGlobals::sleep(5000);
}

GUI_TEST_CLASS_DEFINITION(test_1015_1) {

    GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
    GTGlobals::sleep();

    GTUtilsDialog::waitForDialog(os, new DotPlotFiller(os, 30, 50));
    GTWidget::click(os, GTWidget::findWidget(os, "build_dotplot_action_widget"));
    GTGlobals::sleep();

    GTUtilsMdi::click(os, GTGlobals::Close);
    GTUtilsMdi::click(os, GTGlobals::Minimize);

    GTGlobals::sleep(5000);
}

GUI_TEST_CLASS_DEFINITION(test_1015_2) {

    GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
    GTGlobals::sleep();

    GTUtilsDialog::waitForDialog(os, new DotPlotFiller(os, 100, 50, true));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << ADV_MENU_ANALYSE << "build_dotplot_action", GTGlobals::UseMouse));
    GTMenu::showMainMenu(os, MWMENU_ACTIONS);
    GTGlobals::sleep();

    GTUtilsMdi::click(os, GTGlobals::Close);
    GTUtilsMdi::click(os, GTGlobals::Close);

    GTGlobals::sleep(5000);
}

GUI_TEST_CLASS_DEFINITION(test_1015_3) {

    GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
    GTGlobals::sleep();

    GTUtilsDialog::waitForDialog(os, new DotPlotFiller(os, 100, 50, true));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << ADV_MENU_ANALYSE << "build_dotplot_action", GTGlobals::UseMouse));
    GTMenu::showMainMenu(os, MWMENU_ACTIONS);
    GTGlobals::sleep();

    GTUtilsMdi::click(os, GTGlobals::Close);
    GTUtilsMdi::click(os, GTGlobals::Close);

    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "human_T1.fa"));
    GTMouseDriver::click(os);
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);

    GTGlobals::sleep(5000);
}

GUI_TEST_CLASS_DEFINITION(test_1015_4) {

    GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
    GTGlobals::sleep();

    GTUtilsDialog::waitForDialog(os, new DotPlotFiller(os, 100, 50, true));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << ADV_MENU_ANALYSE << "build_dotplot_action", GTGlobals::UseMouse));
    GTMenu::showMainMenu(os, MWMENU_ACTIONS);
    GTGlobals::sleep();

    GTUtilsMdi::click(os, GTGlobals::Close);
    GTUtilsMdi::click(os, GTGlobals::Minimize);

    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "human_T1.fa"));
    GTMouseDriver::click(os);
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);

    GTGlobals::sleep(5000);
}

GUI_TEST_CLASS_DEFINITION(test_1021) {
    GTUtilsMdi::click(os, GTGlobals::Close);
    for (int i=0; i<2; i++) {
        // 1) Open data\samples\FASTA\human_T1.fa
        GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
        GTGlobals::sleep();

        // 2) Click "build dotplot" tooltip
        // 3) Click OK in opened dotplot dialog
        GTUtilsDialog::waitForDialog(os, new DotPlotFiller(os, 100));
        GTWidget::click(os, GTWidget::findWidget(os, "build_dotplot_action_widget"));
        GTGlobals::sleep();

        // 4) Click on human_T1.fa project tree view item
        GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "human_T1.fa"));
        GTMouseDriver::click(os);

        // 5) Press delete key
        GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);
        GTGlobals::sleep();

        // Expected state: there are no empty MDI window opened, no bookmarks
        GTGlobals::sleep();
        QWidget* activeWindow = GTUtilsMdi::activeWindow(os, GTGlobals::FindOptions(false));
        CHECK_SET_ERR(activeWindow == NULL, "there is active window");

        QTreeWidget* bookmarksTree = GTUtilsBookmarksTreeView::getTreeWidget(os);
        CHECK_SET_ERR(bookmarksTree != NULL, "bookmarksTreeWidget is NULL");

        int bookmarksCount = bookmarksTree->topLevelItemCount();
        CHECK_SET_ERR(bookmarksCount == 0, "there are bookmarks");
    }

//    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["F4"], GTKeyboardDriver::key["alt"]);
//    GTGlobals::sleep();
}

GUI_TEST_CLASS_DEFINITION(test_1021_1) {
    GTUtilsMdi::click(os, GTGlobals::Close);
    for (int i=0; i<3; i++) {
        // 1) Open data\samples\FASTA\human_T1.fa
        GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
        GTGlobals::sleep();

        // 2) Click "build dotplot" tooltip
        // 3) Click OK in opened dotplot dialog
        GTUtilsDialog::waitForDialog(os, new DotPlotFiller(os, 100));
        GTWidget::click(os, GTWidget::findWidget(os, "build_dotplot_action_widget"));
        GTGlobals::sleep();

        // 4) Click on human_T1.fa project tree view item
        GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "human_T1.fa"));
        GTMouseDriver::click(os);

        // 5) Press delete key
        GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);
        GTGlobals::sleep();

        // Expected state: there are no empty MDI window opened, no bookmarks
        GTGlobals::sleep();
        QWidget* activeWindow = GTUtilsMdi::activeWindow(os, GTGlobals::FindOptions(false));
        CHECK_SET_ERR(activeWindow == NULL, "there is active window");

        QTreeWidget* bookmarksTree = GTUtilsBookmarksTreeView::getTreeWidget(os);
        CHECK_SET_ERR(bookmarksTree != NULL, "bookmarksTreeWidget is NULL");

        int bookmarksCount = bookmarksTree->topLevelItemCount();
        CHECK_SET_ERR(bookmarksCount == 0, "there are bookmarks");
    }

//    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["F4"], GTKeyboardDriver::key["alt"]);
//    GTGlobals::sleep();
}

GUI_TEST_CLASS_DEFINITION(test_1021_2) {
    GTUtilsMdi::click(os, GTGlobals::Close);
    for (int i=0; i<2; i++) {
        // 1) Open data\samples\FASTA\human_T1.fa
        GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
        GTGlobals::sleep();

        // 2) Click "build dotplot" tooltip
        // 3) Click OK in opened dotplot dialog
        GTUtilsDialog::waitForDialog(os, new DotPlotFiller(os, 100));
        GTWidget::click(os, GTWidget::findWidget(os, "build_dotplot_action_widget"));
        GTGlobals::sleep();

        // 4) Click on human_T1.fa project tree view item
        GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "human_T1.fa"));
        GTMouseDriver::click(os);

        // 5) Press delete key
        GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);
        GTGlobals::sleep();

        // Expected state: there are no empty MDI window opened, no bookmarks
        GTGlobals::sleep();
        QWidget* activeWindow = GTUtilsMdi::activeWindow(os, GTGlobals::FindOptions(false));
        CHECK_SET_ERR(activeWindow == NULL, "there is active window");

        QTreeWidget* bookmarksTree = GTUtilsBookmarksTreeView::getTreeWidget(os);
        CHECK_SET_ERR(bookmarksTree != NULL, "bookmarksTreeWidget is NULL");

        int bookmarksCount = bookmarksTree->topLevelItemCount();
        CHECK_SET_ERR(bookmarksCount == 0, "there are bookmarks");
    }

//    GTMenu::clickMenuItem(os, GTMenu::showMainMenu(os, MWMENU_FILE), ACTION__EXIT);
//    GTGlobals::sleep();

//    GTGlobals::sleep();
}

GUI_TEST_CLASS_DEFINITION(test_1021_3) {
    GTUtilsMdi::click(os, GTGlobals::Close);
    for (int i=0; i<2; i++) {
        // 1) Open data\samples\FASTA\human_T1.fa
        GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
        GTGlobals::sleep();

        // 2) Click "build dotplot" tooltip
        // 3) Click OK in opened dotplot dialog
        GTUtilsDialog::waitForDialog(os, new DotPlotFiller(os, 120, 100, true));
        GTWidget::click(os, GTWidget::findWidget(os, "build_dotplot_action_widget"));
        GTGlobals::sleep();

        if (i==0) {
            GTUtilsMdi::click(os, GTGlobals::Minimize);
            GTGlobals::sleep();
        }

        // 4) Click on human_T1.fa project tree view item
        GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "human_T1.fa"));
        GTMouseDriver::click(os);

        // 5) Press delete key
        GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);
        GTGlobals::sleep();

        // Expected state: there are no empty MDI window opened, no bookmarks
        GTGlobals::sleep();
        QWidget* activeWindow = GTUtilsMdi::activeWindow(os, GTGlobals::FindOptions(false));
        CHECK_SET_ERR(activeWindow == NULL, "there is active window");

        QTreeWidget* bookmarksTree = GTUtilsBookmarksTreeView::getTreeWidget(os);
        CHECK_SET_ERR(bookmarksTree != NULL, "bookmarksTreeWidget is NULL");

        int bookmarksCount = bookmarksTree->topLevelItemCount();
        CHECK_SET_ERR(bookmarksCount == 0, "there are bookmarks");
    }

//    GTMenu::clickMenuItem(os, GTMenu::showMainMenu(os, MWMENU_FILE), ACTION__EXIT);
//    GTGlobals::sleep();

//    GTGlobals::sleep();
}

GUI_TEST_CLASS_DEFINITION(test_1021_4) {
    GTUtilsMdi::click(os, GTGlobals::Close);
    for (int i=0; i<2; i++) {
        // 1) Open data\samples\FASTA\human_T1.fa
        GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
        GTGlobals::sleep();

        // 2) Click "build dotplot" tooltip
        // 3) Click OK in opened dotplot dialog
        GTUtilsDialog::waitForDialog(os, new DotPlotFiller(os, 110, 100, true));
        GTWidget::click(os, GTWidget::findWidget(os, "build_dotplot_action_widget"));
        GTGlobals::sleep();

        if (i==0) {
            GTUtilsMdi::click(os, GTGlobals::Minimize);
            GTGlobals::sleep();
        }

        // 4) Click on human_T1.fa project tree view item
        GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "human_T1.fa"));
        GTMouseDriver::click(os);

        // 5) Press delete key
        GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);
        GTGlobals::sleep();

        // Expected state: there are no empty MDI window opened, no bookmarks
        GTGlobals::sleep();
        QWidget* activeWindow = GTUtilsMdi::activeWindow(os, GTGlobals::FindOptions(false));
        CHECK_SET_ERR(activeWindow == NULL, "there is active window");

        QTreeWidget* bookmarksTree = GTUtilsBookmarksTreeView::getTreeWidget(os);
        CHECK_SET_ERR(bookmarksTree != NULL, "bookmarksTreeWidget is NULL");

        int bookmarksCount = bookmarksTree->topLevelItemCount();
        CHECK_SET_ERR(bookmarksCount == 0, "there are bookmarks");
    }

//    GTMenu::clickMenuItem(os, GTMenu::showMainMenu(os, MWMENU_FILE), ACTION__EXIT);
//    GTGlobals::sleep();
}

GUI_TEST_CLASS_DEFINITION(test_1022) {

    GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
    GTGlobals::sleep();

    GTUtilsDialog::waitForDialog(os, new DotPlotFiller(os, 3));
    GTWidget::click(os, GTWidget::findWidget(os, "build_dotplot_action_widget"));
    GTGlobals::sleep();

    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "human_T1.fa"));
    GTMouseDriver::click(os);

    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);
    GTGlobals::sleep();

    GTGlobals::sleep(5000);
}

GUI_TEST_CLASS_DEFINITION(test_1029) {
//    1. Open all files from "samples/genbank/" directory in separate mode
//    2. Close all views except one
//    3. Add other sequences to existing view using "add to view" from project context menu
//    4. Close all opened circular views with buttons on sequence view toolbar
//    5. Open circular views with button "Toggle circular views" on the UGENE toolbar
//    Expected state: all opened sequences have circular views
//    6. Close circular views with same button
//    Expected state: all circular views are closed

    GTSequenceReadingModeDialog::mode = GTSequenceReadingModeDialog::Separate;
    GTUtilsDialog::waitForDialog(os, new GTSequenceReadingModeDialogUtils(os));
    GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils_list(os, dataDir + "samples/Genbank/", QStringList() << "murine.gb" << "sars.gb" << "CVU55762.gb" << "PBR322.gb" << "NC_014267.1.gb"));

    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_FILE), QStringList()<<ACTION_PROJECTSUPPORT__OPEN_PROJECT);

    GTUtilsTaskTreeView::waitTaskFinished(os);
    GTGlobals::sleep(5000);

    QStringList windowsNames;
    windowsNames << "murine [s] NC_001363" << "sars [s] NC_004718" << "CVU55762 [s] CVU55762" << "PBR322 [s] SYNPBR322";

    foreach (const QString &window, windowsNames) {
        GTUtilsMdi::closeWindow(os, window);
        GTGlobals::sleep();
    }
    GTUtilsMdi::closeWindow(os, "Start Page");

    foreach (const QString &window, windowsNames) {
        GTUtilsDialog::waitForDialog(os, new PopupChooserbyText(os, QStringList() << "Add to view" << "Add to view: NC_014267.1 [s] NC_014267"));
        QString seqName = window.right( window.size() - window.indexOf("[s] ") - 4);
        GTUtilsProjectTreeView::click(os, seqName, Qt::RightButton);
        GTGlobals::sleep();
    }

    int seqNum = GTUtilsSequenceView::getSeqWidgetsNumber(os);
    QScrollArea* scroll = qobject_cast<QScrollArea*>(GTWidget::findWidget(os, "annotated_DNA_scrollarea"));
    CHECK_SET_ERR(scroll != NULL, "annotated_DNA_scrollarea not found");
    for (int i = 0; i < seqNum; i++) {
        ADVSingleSequenceWidget* seqWgt = GTUtilsSequenceView::getSeqWidgetByNumber(os, i);
        // Comment to UGENE-4076 : the following code should scroll to the single sequence widget and close CV if it is present, but is does not work
        // FAILED BLOCK start
        scroll->ensureWidgetVisible(seqWgt);
        if (GTUtilsCv::isCvPresent(os, seqWgt)) {
            GTUtilsCv::cvBtn::click(os, seqWgt);
            GTGlobals::sleep();
        }
        // FAILED BLOCK end
    }

    GTUtilsCv::commonCvBtn::click(os);

    for (int i = 0; i < seqNum; i++) {
        ADVSingleSequenceWidget* seqWgt = GTUtilsSequenceView::getSeqWidgetByNumber(os, i);
        CHECK_SET_ERR( GTUtilsCv::isCvPresent(os, seqWgt), QString("No CV for %1 single sequence view").arg(i) );
    }

    GTUtilsCv::commonCvBtn::click(os);

    for (int i = 0; i < seqNum; i++) {
        ADVSingleSequenceWidget* seqWgt = GTUtilsSequenceView::getSeqWidgetByNumber(os, i);
        CHECK_SET_ERR( !GTUtilsCv::isCvPresent(os, seqWgt), QString("No CV for %1 single sequence view").arg(i) );
    }
}

GUI_TEST_CLASS_DEFINITION(test_1038) {
//    1. Open WD
//    2. Create a scheme with the following elments: "Read assembly", "Write sequence", "Split assembly into sequences"
//    3. Set samples/Assembly/chrM.sorted.bam as an input assembly. Set any output sequence file
//    4. Run the scheme
//    5. Open chrM in assembly browser
//    Expected: output sequences file has the same sequences as you can see in Assmbly Browser

    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    WorkflowProcessItem* readAsmbl = GTUtilsWorkflowDesigner::addElement(os, "Read Assembly");
    GTUtilsWorkflowDesigner::setDatasetInputFile(os, testDir + "_common_data/bam", "small.bam.sorted.bam");

    WorkflowProcessItem* split = GTUtilsWorkflowDesigner::addElement(os, "Split Assembly into Sequences");
    WorkflowProcessItem* writeSeq = GTUtilsWorkflowDesigner::addElement(os, "Write Sequence");
    GTUtilsWorkflowDesigner::setParameter(os, "Output file", QDir(sandBoxDir).absolutePath() + "/test_1038_seq", GTUtilsWorkflowDesigner::textValue);

    GTUtilsWorkflowDesigner::connect(os, readAsmbl, split);
    GTUtilsWorkflowDesigner::connect(os, split, writeSeq);

    GTUtilsWorkflowDesigner::runWorkflow(os);
    GTUtilsTaskTreeView::waitTaskFinished(os);

    GTUtilsDialog::waitForDialog(os, new SequenceReadingModeSelectorDialogFiller(os));
    GTFileDialog::openFile(os, sandBoxDir, "test_1038_seq");
    GTUtilsTaskTreeView::waitTaskFinished(os);

    // get the list of sequences in file and read names in assembly
    Document* seqDoc = GTUtilsDocument::getDocument(os, "test_1038_seq");
    CHECK_SET_ERR(seqDoc != NULL, "Document is NULL");
    QList<GObject*> seqList = seqDoc->findGObjectByType(GObjectTypes::SEQUENCE, UOF_LoadedAndUnloaded);
    CHECK_SET_ERR(!seqList.isEmpty(), "The list of sequences is empty");
    QList<QByteArray> seqNames;
    foreach (GObject* obj, seqList) {
        CHECK_SET_ERR(obj != NULL, "GObject is NULL");
        seqNames << obj->getGObjectName().toLatin1();
    }

    GTUtilsDialog::waitForDialog(os, new ImportBAMFileFiller(os, sandBoxDir + "test_1038_bam"));
    GTFileDialog::openFile(os, testDir + "_common_data/bam", "small.bam.sorted.bam");
    GTUtilsTaskTreeView::waitTaskFinished(os);
    GTGlobals::sleep(5000);

    AssemblyBrowserUi* ui = GTUtilsAssemblyBrowser::getView(os, "test_1038_bam [as] ref_and_others");
    QSharedPointer<AssemblyModel> model = ui->getModel();

    U2DbiIterator<U2AssemblyRead> * it = model->getReads(U2Region(0, model->getModelLength(os)), os);
    CHECK_SET_ERR(it != NULL, "NULL iterator");

    int matchCount = 0;
    while(it->hasNext()) {
        U2AssemblyRead read = it->next();
        if ( seqNames.contains( read->name ) ){
            matchCount++;
        }
    }

    CHECK_SET_ERR(matchCount == seqNames.size(), QString("Number of reads and sequences are not matched: got %1, expected %2").arg(matchCount).arg((seqNames.size())));
}

GUI_TEST_CLASS_DEFINITION(test_1065_1) {
//    Building index with the "Bowtie" tool.
//    1. Select "Tools->Align to reference->Build index" from the main menu.
//    Expected state: the "Build index" dialog appeared.
//    2. Fill the dialog with the next values:
//        {Align short reads method}	Bowtie
//        {reference sequence}		_common_data/scenarios/_regression/1065/e_coli_1000.fa
//        {Index file name}		_tmp/e_coli_1000
//    Click the "Start" button.
//    Expected state: task completes successfully, there are six files in the _tmp directory:
//    e_coli_1000.1.ebwt
//    e_coli_1000.2.ebwt
//    e_coli_1000.3.ebwt
//    e_coli_1000.4.ebwt
//    e_coli_1000.rev.1.ebwt
//    e_coli_1000.rev.2.ebwt
    GTLogTracer l;

    GTUtilsDialog::waitForDialog(os, new BuildIndexDialogFiller(os, testDir + "_common_data/scenarios/_regression/1065/", "e_coli_1000.fa",
                                                                 "Bowtie", false, sandBoxDir, "e_colli_1000"));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_TOOLS), QStringList() << ToolsMenu::NGS_MENU << ToolsMenu::NGS_INDEX);
    GTUtilsTaskTreeView::waitTaskFinished(os);

    QDir dir(sandBoxDir);
    CHECK_SET_ERR( dir.entryList(QDir::Files).count() == 6, QString("Incorrect count of index files: got %1, expected 6").arg(dir.entryList(QDir::Files).count()));
    foreach (const QString &fileName, dir.entryList(QDir::Files)) {
        CHECK_SET_ERR(fileName.endsWith("ebwt"), "Incorrect result file");
    }

    GTUtilsLog::check(os, l);
}

GUI_TEST_CLASS_DEFINITION(test_1065_2) {
//    Align short reads with the "Bowtie" tool by index.
//    1. Select {Tools->Align to reference->Align short reads} in the main menu.
//    Expected state: the "Align sequencing reads" dialog appeared.
//    2. Fill the dialog with next values:
//        {Alignmnet method}	Bowtie
//        {Reference sequence}	_common_data/scenarios/_regression/1065/index/e_coli_100
//        {Result file name}	_tmp/e_coli_1000.sam
//        {Prebuild index}	checked
//        {Short reads}		_common_data/scanarios/_regression/1065/e_coli_1000.fq
//    And click the "Start" button.
//    Expected state: the Bowtie task successfully completes, the "Import SAM file" dialog appeared.
//    3. Set the {Destination URL} field with "_tmp/e_coli_1000.sam.ugenedb" value and click "Import" button.
//    Expected state: SAM importing task successfully finish, the Assembly Viewer opens.
    GTLogTracer l;

    GTUtilsDialog::waitForDialog(os, new ImportBAMFileFiller(os, sandBoxDir + "/1065_2"));
    AlignShortReadsFiller::Parameters p(testDir + "_common_data/scenarios/_regression/1065/", "e_coli_1000.fa",
                                        testDir + "_common_data/scenarios/_regression/1065/", "e_coli_1000.fq",
                                        AlignShortReadsFiller::Parameters::Bowtie);
    p.prebuiltIndex = true;
    p.useDefaultResultPath = false;
    p.resultDir = sandBoxDir;
    p.resultFileName = "1065_2";

    GTUtilsDialog::waitForDialog(os, new AlignShortReadsFiller(os, &p));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_TOOLS), QStringList() << ToolsMenu::NGS_MENU << ToolsMenu::NGS_MAP);
    GTGlobals::sleep();

    GTUtilsLog::check(os, l);
}

GUI_TEST_CLASS_DEFINITION(test_1065_3) {
//    Bowtie align without prebuilt index.
//    1. Select {Tools->Align to reference->Align short reads} in the main menu.
//    Expected state: the "Align sequencing reads" dialog appeared.
//    2. Fill the dialog with next values:
//        {Alignmnet method}	Bowtie
//        {Reference sequence}	_common_data/scenarios/_regression/1065/e_coli_100.fa
//        {Result file name}	_tmp/e_coli_1000.sam
//        {Prebuild index}	unchecked
//        {Short reads}		_common_data/scanarios/_regression/1065/e_coli_1000.fq
//    And click the "Start" button.
//    Expected state: the Bowtie task successfully completes, the "Import SAM file" dialog appeared.
//    3. Set the {Destination URL} field with "_tmp/e_coli_1000.sam.ugenedb" value and click "Import" button.
//    Expected state: SAM importing task successfully finish, the Assembly Viewer opens.
    GTLogTracer l;

    GTUtilsDialog::waitForDialog(os, new ImportBAMFileFiller(os, sandBoxDir + "/1065_3"));
    AlignShortReadsFiller::Parameters p(testDir + "_common_data/scenarios/_regression/1065/", "e_coli_1000.fa",
                                        testDir + "_common_data/scenarios/_regression/1065/", "e_coli_1000.fq",
                                        AlignShortReadsFiller::Parameters::Bowtie);
    p.useDefaultResultPath = false;
    p.resultDir = sandBoxDir;
    p.resultFileName = "1065_3";

    GTUtilsDialog::waitForDialog(os, new AlignShortReadsFiller(os, &p));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_TOOLS), QStringList() << ToolsMenu::NGS_MENU << ToolsMenu::NGS_MAP);
    GTGlobals::sleep();

    GTUtilsLog::check(os, l);
}

GUI_TEST_CLASS_DEFINITION(test_1078){ //Need to add the test
/* 1. File-New Project
 * 2. Open as - HannaRescued.fa(https://ugene.unipro.ru/tracker/browse/UGENE-1078) (FASTA format. Score:13 (Perfect match) - OK, As separate sequences in sequence viewer - OK)
 * Bug state: Then crush and hung of the program
 * Expected state: Error message with format error
 * System: Ubuntu 12.04
*/
    GTLogTracer l;

    GTFileDialogUtils *ob = new GTFileDialogUtils(os, testDir + "_common_data/scenarios/_regression/1078/", "HannaRescued.fa");
    GTUtilsDialog::waitForDialog(os, ob);
    GTUtilsDialog::waitForDialog(os, new DocumentFormatSelectorDialogFiller(os, "FASTA"));
    GTUtilsDialog::waitForDialog(os, new SequenceReadingModeSelectorDialogFiller(os, SequenceReadingModeSelectorDialogFiller::Separate));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_FILE), QStringList() << ACTION_PROJECTSUPPORT__OPEN_AS);
    GTUtilsTaskTreeView::waitTaskFinished(os);

    CHECK_SET_ERR(l.hasError(), "Error in log expected");
}

GUI_TEST_CLASS_DEFINITION(test_1083) {
//1. open files data\samples\FASTA\human_T1.fa
    GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
//2. select sequence oject in projrct tree view. press delete
    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "human_T1.fa"));
    GTMouseDriver::click(os);
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);
//Expected state: UGENE is not crashed
    GTUtilsProject::checkProject(os, GTUtilsProject::Empty);
}

GUI_TEST_CLASS_DEFINITION(test_1093) {
//    1. do menu "tools->Align to refrence->Align short reads"

//    2. fill next fields in appeared dialog:
//        Refrence sequence "_common_data\scenarios\_regression\1093\refrence.fa"
//        SAM output checkbox {set checked}
//        Short reads add next file: "_common_data\scenarios\_regression\1093\read.fa"

//    3. Press 'Align'
//    Expected state: message window appears "The short reads can't be mapped to the reference sequence!"
    AlignShortReadsFiller::Parameters parameters(testDir + "_common_data/scenarios/_regression/1093/",
                                                 "refrence.fa",
                                                 testDir + "_common_data/scenarios/_regression/1093/",
                                                 "read.fa");
    GTUtilsDialog::waitForDialog(os, new AlignShortReadsFiller(os, &parameters)) ;
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Ok));

    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_TOOLS), QStringList() << ToolsMenu::NGS_MENU << ToolsMenu::NGS_MAP);

    GTUtilsTaskTreeView::waitTaskFinished(os);
//The short reads can't be mapped to the reference sequence!
}

GUI_TEST_CLASS_DEFINITION(test_1107){//commit GUIInitionalChecks
//1) Open an MSA file (e.g. _common_data\scenarios\msa\ma2_gapped.aln)

    GTFileDialog::openFile(os, testDir+"_common_data/scenarios/msa/", "ma2_gapped.aln");
//2) Menu File->Close Project
//3) Press No in the Save current project dialog
    GTUtilsDialog::waitForDialog(os, new SaveProjectDialogFiller(os, QDialogButtonBox::No));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_FILE), QStringList()<<ACTION_PROJECTSUPPORT__CLOSE_PROJECT);
//Expected state: UGENE not crashes
}
GUI_TEST_CLASS_DEFINITION(test_1113){//commit AboutDialogController.cpp
//1. Open UGENE
//2. Press F1
    class EscClicker : public Filler {
    public:
        EscClicker(U2OpStatus& _os) : Filler(_os, "AboutDialog"){}
        virtual void run(){

            GTGlobals::sleep();
#ifdef Q_OS_MAC
            GTKeyboardDriver::keyRelease(os,GTKeyboardDriver::key["f1"]);
#endif

            QWidget* dialog = QApplication::activeModalWidget();
//getting an info string
            QWidget *w = new QWidget();
            w=dialog->findChild<QWidget*>("about_widget");
            CHECK_SET_ERR(w!=NULL, "aboutWidget not found");

            QObject *parent = new QObject();
            parent= w->findChild<QObject*>("parent");
            CHECK_SET_ERR(parent!=NULL, "parentObject not found");

            QObject *child = new QObject();
            child=parent->findChild<QObject*>();
            CHECK_SET_ERR(child!=NULL, "childObject not found");

            QString text = child->objectName();
            CHECK_SET_ERR(text.contains("64-bit")||text.contains("32-bit"),text);
#ifdef Q_OS_MAC
            GTWidget::click(os,GTWidget::findWidget(os,"close_button"));
#else
            GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["esc"]);
#endif
        }
    };
    GTGlobals::sleep(1000);
    GTUtilsDialog::waitForDialog(os, new EscClicker(os));
#ifdef Q_OS_MAC
    //hack for mac
    MainWindow *mw = AppContext::getMainWindow();
    CHECK_SET_ERR(mw != NULL, "MainWindow is NULL");
    QMainWindow *mainWindow = mw->getQMainWindow();
    CHECK_SET_ERR(mainWindow != NULL, "QMainWindow is NULL");
    QWidget* w = qobject_cast<QWidget*>(mainWindow);
    GTWidget::click(os, w, Qt::LeftButton, QPoint(5,5));
    GTGlobals::sleep(500);
#endif
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["f1"]);
    GTGlobals::sleep(1000);
//Expected state: About dialog appeared, shown info includes platform info (32/64)

}

GUI_TEST_CLASS_DEFINITION(test_1113_1){//commit AboutDialogController.cpp
//1. Open UGENE
//2. Help->About
    class EscClicker : public Filler {
    public:
        EscClicker(U2OpStatus& _os) : Filler(_os, "AboutDialog"){}
        virtual void run(){
            GTGlobals::sleep();
#ifdef Q_OS_MAC
            GTMouseDriver::release(os);
#endif
            QWidget* dialog = QApplication::activeModalWidget();
//getting an info string
            QWidget *w = new QWidget();
            w=dialog->findChild<QWidget*>("about_widget");
            CHECK_SET_ERR(w!=NULL, "aboutWidget not found");

            QObject *parent = new QObject();
            parent= w->findChild<QObject*>("parent");
            CHECK_SET_ERR(parent!=NULL, "parentObject not found");

            QObject *child = new QObject();
            child=parent->findChild<QObject*>();
            CHECK_SET_ERR(child!=NULL, "childObject not found");

            QString text = child->objectName();
            CHECK_SET_ERR(text.contains("64-bit")||text.contains("32-bit"),text);
#ifdef Q_OS_MAC
            GTWidget::click(os,GTWidget::findWidget(os,"close_button"));
#else
            GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["esc"]);
#endif
        }
    };

    GTUtilsDialog::waitForDialog(os, new EscClicker(os));
    QMenu *menu = GTMenu::showMainMenu(os, MWMENU_HELP);
    GTMenu::clickMenuItemByName(os, menu, QStringList() << ACTION__ABOUT);
    GTGlobals::sleep(1000);
//Expected state: About dialog appeared, shown info includes platform info (32/64)

}
GUI_TEST_CLASS_DEFINITION(test_1121) {
    GTLogTracer lt;

    //1) Open alignment with amino alphabet
    GTFileDialog::openFile(os, testDir + "_common_data/clustal/", "amino_ext.aln");

    //2) join line with nucl alphabet.
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "MSAE_MENU_LOAD_SEQ" << "Sequence from file"));
    GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, testDir + "_common_data/fasta/", "fa1.fa"));
    GTMenu::showContextMenu(os, GTWidget::findWidget(os, "msa_editor_name_list"));

    //3) Then delete line with amino alphabet.
    GTUtilsMSAEditorSequenceArea::selectSequence(os, "FOSB_HUMAN");
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);
    GTGlobals::sleep(500);

    //Expected state : Ugene did not crash on assert
    GTUtilsLog::check(os, lt);
}

GUI_TEST_CLASS_DEFINITION(test_1122){
//    1. Select "Tools->DNA Assembly->Contig assembly with CAP3" from the main menu.
//    Expected state: the "Contig Assembly With CAP3" dialog appeared.
//    2. Click "Add" button.
//    Expected state: the "Add sequences to assembly" dialog appeared.
//    3. Select two files: "_common_data/scenarios/CAP3/xyz.fa" and "_common_data/scenarios/CAP3/xyz.qual". Click "Open" button.
//    Expected state: this files had been added to the "Input files" field of the "Contig Assembly With CAP3" dialog. Some path in the "Result contig" field appeared.
//    4. Click the "Run" button.
//    Expected state: CAP3 task started. Multiply alignment as a result of the task appeared.
//    5. Run CAP3 again with "_common_data/scenarios/CAP3/xyz.fastq".
//    Expected state: Result is the same as in the step 4.

    GTLogTracer l;
    GTUtilsDialog::waitForDialog(os, new ConvertAceToSqliteDialogFiller(os, sandBoxDir + "test_1122_1.ugenedb"));
    GTUtilsDialog::waitForDialog(os, new DocumentProviderSelectorDialogFiller(os, DocumentProviderSelectorDialogFiller::AlignmentEditor));
    GTUtilsDialog::waitForDialog(os, new CAP3SupportDialogFiller(os, QStringList() << testDir + "_common_data/scenarios/CAP3/xyz.fa"
                                                                 << testDir + "_common_data/scenarios/CAP3/xyz.qual",
                                                                 sandBoxDir + "test_1122_1"));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << ToolsMenu::SANGER_MENU << ToolsMenu::SANGER_DENOVO));
    GTMenu::showMainMenu(os, "mwmenu_tools");
    GTUtilsTaskTreeView::waitTaskFinished(os);

    GTUtilsDialog::waitForDialog(os, new ConvertAceToSqliteDialogFiller(os, sandBoxDir + "test_1122_2.ugenedb"));
    GTUtilsDialog::waitForDialog(os, new DocumentProviderSelectorDialogFiller(os, DocumentProviderSelectorDialogFiller::AlignmentEditor));
    GTUtilsDialog::waitForDialog(os, new CAP3SupportDialogFiller(os, QStringList() << testDir + "_common_data/scenarios/CAP3/xyz.fastq",
                                                                 sandBoxDir + "test_1122_2"));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << ToolsMenu::SANGER_MENU << ToolsMenu::SANGER_DENOVO));
    GTMenu::showMainMenu(os, "mwmenu_tools");
    GTUtilsTaskTreeView::waitTaskFinished(os);

    CHECK_SET_ERR(GTFile::equals(os, sandBoxDir + "test_1122_1.ace", sandBoxDir + "test_1122_2.ace"), "Files are not equal");

    GTUtilsLog::check(os, l);
}

GUI_TEST_CLASS_DEFINITION(test_1133) {
//     1. Open human_t1.fa
//     2. Open Smith-Waterman search dialog
//     3. Paste sequence from text file to pattern field
//     4. Run search
//
//     Expected state: Search successfully perfoms
    GTFileDialog::openFile(os, dataDir + "/samples/FASTA/human_T1.fa");
    QString patttern = "ATGAA    GGAAAAA\nA T G CTA AG GG\nCAGC    CAGAG AGAGGTCA GGT";
    GTUtilsDialog::waitForDialog(os, new SmithWatermanDialogFiller(os, patttern));
    GTWidget::click(os, GTToolbar::getWidgetForActionTooltip(os, GTToolbar::getToolbar(os, MWTOOLBAR_ACTIVEMDI), "Find pattern [Smith-Waterman]"));
    GTGlobals::sleep();

    GTUtilsAnnotationsTreeView::findItem(os, "Misc. Feature  (0, 1)");
}

GUI_TEST_CLASS_DEFINITION(test_1156) {
    class DigestCircularSequenceScenario : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            QWidget *dialog = QApplication::activeModalWidget();

            QListWidget *availableEnzymeWidget = GTWidget::findExactWidget<QListWidget *>(os, "availableEnzymeWidget", dialog);
            CHECK_SET_ERR(NULL != availableEnzymeWidget, "Cannot find available enzyme list widget");

            QList<QListWidgetItem *> items = availableEnzymeWidget->findItems("BamHI", Qt::MatchStartsWith);
            CHECK_SET_ERR(items.size() == 1, "Unexpected number of enzymes starting with 'BamHI'");

            const QPoint enzymePosition = availableEnzymeWidget->mapToGlobal(availableEnzymeWidget->visualItemRect(items.first()).center());
            GTMouseDriver::moveTo(os, enzymePosition);
            GTMouseDriver::click(os);

            GTWidget::click(os, GTWidget::findWidget(os, "addButton"));

            GTCheckBox::setChecked(os, GTWidget::findExactWidget<QCheckBox *>(os, "circularBox"));

            GTUtilsDialog::clickButtonBox(os, dialog, QDialogButtonBox::Ok);
        }
    };

    // 1. Open human_T1
    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");

    // 2. Use menu{ Analyze->Find restriction sites }.
    // Expected state : "Find restriction sites" dialog has appeared
    // 3. Press "Ok" button in the dialog.
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "ADV_MENU_ANALYSE" << "Find restriction sites"));
    GTUtilsDialog::waitForDialog(os, new FindEnzymesDialogFiller(os, QStringList("BamHI")));
    GTMenu::showContextMenu(os, GTUtilsSequenceView::getSeqWidgetByNumber(os));
    GTUtilsTaskTreeView::waitTaskFinished(os);

    // 4. Use menu{ Cloning->Digest into fragments }.
    // Expected state : "Find restriction sites" dialog has appeared. It contains a checkbox "Circular molecule"
    // 5. Choose "Circular molecule" mode
    // 6. Press "Ok"
    GTUtilsDialog::waitForDialog(os, new DigestSequenceDialogFiller(os, new DigestCircularSequenceScenario));
    GTUtilsDialog::waitForDialog(os, new PopupChooserbyText(os, QStringList() << "Cloning" << "Digest into fragments..."));
    GTMenu::showContextMenu(os, GTUtilsSequenceView::getSeqWidgetByNumber(os));
    GTUtilsTaskTreeView::waitTaskFinished(os);

    QTreeWidgetItem *fragmentGroupItem = GTUtilsAnnotationsTreeView::findItem(os, "fragments  (0, 24)");
    CHECK_SET_ERR(24 == fragmentGroupItem->childCount(), "Unexpected sequence fragments count");
}

GUI_TEST_CLASS_DEFINITION(test_1157) {
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    WorkflowProcessItem *readSequence = GTUtilsWorkflowDesigner::addElement(os, "Read Sequence");
    WorkflowProcessItem *writeSequence = GTUtilsWorkflowDesigner::addElement(os, "Write Sequence");

    QString resultFilePath = testDir + "_common_data/scenarios/sandbox/test_1157.gb";
    GTUtilsWorkflowDesigner::setParameter(os, "Document format", "genbank", GTUtilsWorkflowDesigner::comboValue);
    GTUtilsWorkflowDesigner::setParameter(os, "Output file", resultFilePath, GTUtilsWorkflowDesigner::textValue);

    WorkflowProcessItem *callocationSearch = GTUtilsWorkflowDesigner::addElement(os, "Collocation Search");
    GTUtilsWorkflowDesigner::setParameter(os, "Result type", "Copy original annotations", GTUtilsWorkflowDesigner::comboValue);
    GTGlobals::sleep(750);
    GTUtilsWorkflowDesigner::setParameter(os, "Group of annotations", "mat_peptide, CDS", GTUtilsWorkflowDesigner::textValue);
    GTUtilsWorkflowDesigner::setParameter(os, "Must fit into region", "False", GTUtilsWorkflowDesigner::comboValue);

    GTUtilsWorkflowDesigner::addInputFile(os, "Read Sequence", dataDir + "samples/Genbank/sars.gb");

    GTUtilsWorkflowDesigner::connect(os, readSequence, callocationSearch);
    GTUtilsWorkflowDesigner::connect(os, callocationSearch, writeSequence);

    GTUtilsWorkflowDesigner::runWorkflow(os);
    GTUtilsTaskTreeView::waitTaskFinished(os);

    GTFileDialog::openFile(os, resultFilePath);

    GTUtilsAnnotationsTreeView::findItem(os, "CDS  (0, 17)");
    GTUtilsAnnotationsTreeView::findItem(os, "mat_peptide  (0, 32)");
}

GUI_TEST_CLASS_DEFINITION(test_1163){
    // 1. Open file *.ugenedb (for example _common_data\ugenedb\example-alignment.ugenedb) in assembly browser.
    // 2. right click it and choose "Unload selected documents".
    // 3. click "Yes" in appeared message box.
    // Expected state: UGENE not crashes

    GTFileDialog::openFile(os, testDir+"_common_data/ugenedb/", "example-alignment.ugenedb");

    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<<"action_project__unload_selected_action"));
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Yes));
    GTUtilsProjectTreeView::click(os, "example-alignment.ugenedb", Qt::RightButton);
}

GUI_TEST_CLASS_DEFINITION(test_1165){
//1. Open file "data/samples/CLUSTALW/COI.aln"
    GTFileDialog::openFile(os, dataDir+"samples/CLUSTALW/", "COI.aln");
//2. open context menu in msa, "Add"->"Sequence from file...",
//3. browse the file "data/samples/FASTA/human_T1.fa".
    QWidget *nameList;
    nameList=GTWidget::findWidget(os,"msa_editor_name_list");

    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "MSAE_MENU_LOAD_SEQ"<<"Sequence from file"));
    GTFileDialogUtils *ob = new GTFileDialogUtils(os, dataDir + "/samples/FASTA/", "human_T1.fa");
    GTUtilsDialog::waitForDialog(os, ob);

    GTMenu::showContextMenu(os,nameList);
//4. Then choose any sequence in sequence names area (except that which you've just added), press "Delete"
//Expected state: UGENE not crashes
    GTWidget::click(os,nameList);
    GTGlobals::sleep(500);
    GTKeyboardDriver::keyClick(os,GTKeyboardDriver::key["delete"]);
}

GUI_TEST_CLASS_DEFINITION(test_1172){
    // 1. Open file "\data\samples\Stockholm\CBS.sto" or "\data\samples\ACE\BL060C3.ace"
    // 2. Select any area in msa (or just one symbol)
    // 3. Press at selected area (or at selected symbol) again
    // Expected state: UGENE not crashes

    GTFileDialog::openFile(os, dataDir+"samples/Stockholm/", "CBS.sto");

    GTUtilsMSAEditorSequenceArea::click(os, QPoint(2, 2));
    GTGlobals::sleep();
    GTUtilsMSAEditorSequenceArea::click(os, QPoint(2, 2));


}

GUI_TEST_CLASS_DEFINITION(test_1180) {
    //1) Open Settings, External tools.
    //2) Set wrong path to the Bowtie tool.
    QString toolPath = QFileInfo(dataDir + "samples/FASTA/human_T1.fa").absoluteFilePath();
    GTUtilsExternalTools::setToolUrl(os, "Bowtie aligner", toolPath);
    GTUtilsExternalTools::setToolUrl(os, "Bowtie build indexer", toolPath);

    //3) Run Bowtie aligning on any data.
    //Expected state: UGENE not crashed.
    AlignShortReadsFiller::Parameters parameters(testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/index/",
        "chr6.fa",
        testDir + "_common_data/e_coli/",
        "e_coli_1000.fastq",
        AlignShortReadsFiller::Parameters::Bowtie);
    GTUtilsDialog::waitForDialog(os, new AlignShortReadsFiller(os, &parameters)) ;
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_TOOLS), QStringList() << ToolsMenu::NGS_MENU << ToolsMenu::NGS_MAP);
}

GUI_TEST_CLASS_DEFINITION(test_1184){
//    1. Open WD
//    2. Place worker on the scheme 'Write FASTA', set worker parameters to the next values:
//        {Output file} file.fa
//        {Existing file} Overwrite

//    3. Copy & Paste worker
//    Expected state: parameters of original worker are equal with parameters on copied worker

    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
    GTUtilsWorkflowDesigner::addAlgorithm(os, "Write FASTA");
    GTUtilsWorkflowDesigner::setParameter(os, "Output file", "file.fa", GTUtilsWorkflowDesigner::textValue);
    GTUtilsWorkflowDesigner::setParameter(os, "Existing file", "Overwrite", GTUtilsWorkflowDesigner::comboValue);

    GTUtilsWorkflowDesigner::click(os, "Write FASTA");
    GTKeyboardDriver::keyClick(os, 'c', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep();
    GTKeyboardDriver::keyClick(os, 'v', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep();

    CHECK_SET_ERR(GTUtilsWorkflowDesigner::getParameter(os, "Output file", true) == "file.fa",
                  QString("Incorrect output file parameter [%1]").arg(GTUtilsWorkflowDesigner::getParameter(os, "Output file")));
    CHECK_SET_ERR(GTUtilsWorkflowDesigner::getParameter(os, "Existing file", true) == "Overwrite",
                  QString("Incorrect existing file parameter [%1]").arg(GTUtilsWorkflowDesigner::getParameter(os, "Existing file")));
}

GUI_TEST_CLASS_DEFINITION(test_1189){
//1) Open samples/FASTA/human_T1.fa
    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");

//2) Press Ctrl+F
    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(500);

//3) Select any region of the sequence
    GTUtilsDialog::waitForDialog(os, new selectSequenceRegionDialogFiller(os, 100, 200));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "Select" << "Sequence region"));
    GTMenu::showContextMenu(os, GTWidget::findWidget(os, "ADV_single_sequence_widget_0"));

//4) Select "Selected region" in "Region" combobox of "Search in" area.
    GTWidget::click(os, GTWidget::findWidget(os, "ArrowHeader_Search in"));
    QComboBox *regBox = (QComboBox *)GTWidget::findWidget(os, "boxRegion");
    GTComboBox::setCurrentIndex(os, regBox, 2);

//5) Ensure that two lineedits became visible and contain correct region
    QLineEdit *start = (QLineEdit *)GTWidget::findWidget(os, "editStart");
    CHECK_SET_ERR(start->isVisible(), "editStart line is not visiable");
    CHECK_SET_ERR(start->text() == "100", "Wrong startValue. Current value is: " + start->text());

    QLineEdit *end = (QLineEdit *)GTWidget::findWidget(os, "editEnd");
    CHECK_SET_ERR(end->isVisible(), "editEnd line is not visiable");
    CHECK_SET_ERR(end->text() == "200", "Wrong endValue. Current value is: " + end->text());
}

GUI_TEST_CLASS_DEFINITION(test_1189_1){
//1) Open samples/FASTA/human_T1.fa
    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");

//2) Press Ctrl+F
    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(500);

//3) Select any region of the sequence
    GTWidget::click(os, GTWidget::findWidget(os, "ADV_single_sequence_widget_0"));
    QPoint p;
    p=GTMouseDriver::getMousePosition();
    p.setX(p.x() - 100);
    GTMouseDriver::moveTo(os, p);
    GTMouseDriver::press(os);
    p.setX(p.x() + 200);
    GTMouseDriver::moveTo(os, p);
    GTMouseDriver::release(os);

//4) Select "Selected region" in "Region" combobox of "Search in" area.
    GTWidget::click(os, GTWidget::findWidget(os, "ArrowHeader_Search in"));
    QComboBox *regBox =(QComboBox *)GTWidget::findWidget(os, "boxRegion");
    GTComboBox::setCurrentIndex(os, regBox, 2);

//5) Ensure that two lineedits became visible and contain correct region
    QLineEdit *start = (QLineEdit *)GTWidget::findWidget(os, "editStart");
    CHECK_SET_ERR(start->isVisible(), "editStart line is not visiable");

    QLineEdit *end = (QLineEdit *)GTWidget::findWidget(os,"editEnd");
    CHECK_SET_ERR(end->isVisible(), "editEnd line is not visiable");
}

GUI_TEST_CLASS_DEFINITION(test_1190){//add AlignShortReadsFiller

//1) Align shortreads with genome aligner
//Tools -> Align to reference -> Align short reads
    AlignShortReadsFiller::Parameters parameters(testDir + "_common_data/fasta/",
                                                 "N.fa",
                                                 testDir + "_common_data/fasta/",
                                                 "RAW.fa");
    GTUtilsDialog::waitForDialog(os, new AlignShortReadsFiller(os, &parameters)) ;
    QMenu *menu = GTMenu::showMainMenu(os, MWMENU_TOOLS);
    GTLogTracer l;

    GTMenu::clickMenuItemByName(os, menu, QStringList() << ToolsMenu::NGS_MENU << ToolsMenu::NGS_MAP);

    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os,QMessageBox::Ok));
    GTGlobals::sleep(10000);

    GTUtilsLog::check(os, l);

    //}
//Reference sequence: _common_data/fasta/N.fa  /home/vmalin/ugene/trunk/test/_common_data/fasta/N.ugenedb
//Short reads: _common_data/reads/shortreads15Mb.fasta

//Click "Start"

//2) wait for dialog to appear, click "OK"

//repeat these steps 3 times, UGENE shouldn't crash
}

GUI_TEST_CLASS_DEFINITION(test_1199) {
//1. Open any samples/PDB/1CF7.pdb file.
    GTFileDialog::openFile(os, dataDir+"samples/PDB/", "1CF7.PDB");

//2. Select document in project tree view. Press 'Delete'
    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "1CF7.PDB"));
    GTMouseDriver::click(os);
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);

//Expected state: document removed, UGENE not crashes.
    GTUtilsProject::checkProject(os, GTUtilsProject::Empty);
}

GUI_TEST_CLASS_DEFINITION(test_1204){
    // 1) Open files data\samples\FASTA\human_T1.fa
    // 2) Use context menu {Analyze -> Query NCBI BLAST database}
    // Expected state: "max hits" spinbox can be set to 5000

    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");

    GTUtilsDialog::waitForDialog(os, new RemoteBLASTDialogFiller(os));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "ADV_MENU_ANALYSE"
        << "Query NCBI BLAST database"));
    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));

}

GUI_TEST_CLASS_DEFINITION(test_1210){
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    WorkflowProcessItem *readSequence = GTUtilsWorkflowDesigner::addElement(os, "Read Sequence");
    WorkflowProcessItem *readAlignment = GTUtilsWorkflowDesigner::addElement(os, "Read Alignment");
    WorkflowProcessItem *callVariants = GTUtilsWorkflowDesigner::addElement(os, "Call Variants with SAMtools");

    GTUtilsWorkflowDesigner::addInputFile(os, "Read Sequence", dataDir + "samples/FASTA/human_T1.fa");
    GTUtilsWorkflowDesigner::addInputFile(os, "Read Alignment", dataDir + "samples/Assembly/ChrM.sam");

    GTUtilsWorkflowDesigner::connect(os, readSequence, callVariants);
    GTUtilsWorkflowDesigner::connect(os, readAlignment, callVariants);
}

GUI_TEST_CLASS_DEFINITION(test_1212){
//    1. Open any sequence. (human_t1.fa)
    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");
//    2. Do "Select->Sequence Region..."
//    3. In single selection mode enter any region
//    4. Press "Go" and UGENE hangs up/crashes
    GTUtilsDialog::waitForDialog(os, new selectSequenceRegionDialogFiller(os,"100..200"));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<<"Select"<< "Sequence region"));
    GTMenu::showContextMenu(os, GTWidget::findWidget(os,"ADV_single_sequence_widget_0"));
//    Expected: region is selected
    ADVSingleSequenceWidget *w=(ADVSingleSequenceWidget*)GTWidget::findWidget(os,"ADV_single_sequence_widget_0");
    CHECK_SET_ERR(!w->getSequenceSelection()->isEmpty(), "No selected region");
}

GUI_TEST_CLASS_DEFINITION(test_1212_1){
//    1. Open any sequence. (human_t1.fa)
    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");
//    2. Do "Select->Sequence Region..."
//    3. In single selection mode enter any region
//    4. Press "Go" and UGENE hangs up/crashes
    GTUtilsDialog::waitForDialog(os, new selectSequenceRegionDialogFiller(os,"1..199950"));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<<"Select"<< "Sequence region"));
    GTMenu::showContextMenu(os, GTWidget::findWidget(os,"ADV_single_sequence_widget_0"));
//    Expected: region is selected
    ADVSingleSequenceWidget *w=(ADVSingleSequenceWidget*)GTWidget::findWidget(os,"ADV_single_sequence_widget_0");
    CHECK_SET_ERR(!w->getSequenceSelection()->isEmpty(), "No selected region");

}

GUI_TEST_CLASS_DEFINITION(test_1229) {
    // 1. Open two sequences with same names in two documents.For instance, you can copy a file with a sequence to do that.
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/_regression/1229", "1.txt");
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/_regression/1229", "2.txt");

    // 2. The sequences in different documents have identical names. Rename both sequence objects. Now the sequences have different name.
    const QModelIndex firstDoc = GTUtilsProjectTreeView::findIndex(os, "1.txt");
    const QModelIndex secondDoc = GTUtilsProjectTreeView::findIndex(os, "2.txt");

    GTUtilsProjectTreeView::rename(os, GTUtilsProjectTreeView::findIndex(os, "tub", firstDoc), "tub_1");
    GTUtilsProjectTreeView::rename(os, GTUtilsProjectTreeView::findIndex(os, "tub", secondDoc), "tub_2");

    // 3. Select both sequence objects and export them as multiple alignment.
    GTKeyboardDriver::keyPress(os, GTKeyboardDriver::key["ctrl"]);

    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "tub_1"));
    GTMouseDriver::click(os);

    GTKeyboardDriver::keyRelease(os, GTKeyboardDriver::key["ctrl"]);

    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << ACTION_PROJECT__EXPORT_IMPORT_MENU_ACTION << ACTION_EXPORT_SEQUENCE_AS_ALIGNMENT));
    GTUtilsDialog::waitForDialog(os, new ExportSequenceAsAlignmentFiller(os, sandBoxDir, "test_1229.aln", ExportSequenceAsAlignmentFiller::Clustalw, true));
    GTMouseDriver::click(os, Qt::RightButton);

    GTUtilsTaskTreeView::waitTaskFinished(os);

    // 4. Sequences in the alignment have old names(identical).
    // Expected state : sequence in the alignment renamed properly.
    const QStringList msaNames = GTUtilsMSAEditorSequenceArea::getNameList(os);
    CHECK_SET_ERR(2 == msaNames.size(), "Unexpected sequence count in MSA");
    CHECK_SET_ERR(msaNames.contains("tub_1") && msaNames.contains("tub_2"), "Unexpected sequences names in MSA");
}

GUI_TEST_CLASS_DEFINITION(test_1232) {
// 1. Open "human_T1.fa".
    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");
// 2. Select {Actions->Statistics} from the main menu.
// Expected state: Statistic view si shown.
    QMenu* menu = GTMenu::showMainMenu(os, "mwmenu_actions");
    GTMenu::clickMenuItemByName(os, menu, QStringList() << "Statistics");
    GTGlobals::sleep();
    QWebView *wv = qobject_cast<QWebView*>(GTWidget::findWidget(os, "DNAStatWebViewhuman_T1 (UCSC April 2002 chr7:115977709-117855134)"));
    bool foundAtFirstWV = wv->findText("2223359500 I/mol (at 260 nm)");

    GTKeyboardDriver::keyClick(os, 'w',GTKeyboardDriver::key["ctrl"]);
    GTUtilsProjectTreeView::doubleClickItem(os, "human_T1 (UCSC April 2002 chr7:115977709-117855134)");
    GTGlobals::sleep();

    GTUtilsSequenceView::selectSequenceRegion(os, 100, 120);
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "ADV_MENU_EXPORT" << "action_export_selected_sequence_region", GTGlobals::UseMouse));
    GTUtilsDialog::waitForDialog(os, new ExportSelectedRegionFiller(os, sandBoxDir, "test_1232.fa", GTGlobals::UseMouse));

    QWidget* activeWindow = GTUtilsMdi::activeWindow(os);
    CHECK_SET_ERR(activeWindow != NULL, "there is no active MDI window");

    QPoint p = activeWindow->mapToGlobal(activeWindow->rect().center());
    GTMouseDriver::moveTo(os, QPoint(p.x(), 200));
    GTMouseDriver::click(os, Qt::RightButton);

    //GTMouseDriver::click(os, Qt::RightButton);
    GTGlobals::sleep(2000);

    menu = GTMenu::showMainMenu(os, "mwmenu_actions");
    GTMenu::clickMenuItemByName(os, menu, QStringList() << "Statistics");

    GTGlobals::sleep();
    QWebView *wv2 = qobject_cast<QWebView*>(GTWidget::findWidget(os, "DNAStatWebViewregion [100 120]"));
    bool foundAtSecondWV = wv2->findText("225500 I/mol (at 260 nm)");

    CHECK_SET_ERR(foundAtSecondWV && foundAtFirstWV, "Expected molar coeffs wasn't found");

// 3. Remember the "Molar ext. coef.". Close this statistics view.
//
// 4. Select and export some region of the sequence.
// Expected state: new sequence viewer with part of the whole human_T1.fa.
//
// 5. Call statistics view for the exported part.
// Expected state: "Molar ext. coef" should be different from the remembered value.

}

GUI_TEST_CLASS_DEFINITION(test_1234) {
/* 1. Select a sequence region.
 * 2. Do {Export->Export selected sequence region...}
 * 3. Check "Translate to amino alphabet" and "Save all amino frames"
 *   Expected state: no bad characters at the end of the frames. Sequences are translated correctly.
 */
    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");
    GTUtilsSequenceView::selectSequenceRegion(os, 100, 120);
    //DLSAETL
    //ISRQKP
    //SLGRNP

    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "ADV_MENU_EXPORT" << "action_export_selected_sequence_region", GTGlobals::UseMouse));
    GTUtilsDialog::waitForDialog(os, new ExportSelectedRegionFiller(os, sandBoxDir, "test_1234.fa", GTGlobals::UseMouse, true));

    QWidget* activeWindow = GTUtilsMdi::activeWindow(os);
    CHECK_SET_ERR(activeWindow != NULL, "there is no active MDI window");

    QPoint p = activeWindow->mapToGlobal(activeWindow->rect().center());
    GTMouseDriver::moveTo(os, QPoint(p.x(), 200));
    GTMouseDriver::click(os, Qt::RightButton);

    GTGlobals::sleep(2000);

    QWidget* parent=GTWidget::findWidget(os,"test_1234.fa");
    CHECK_SET_ERR(NULL != parent, "Failed to find parent widget!");

    ADVSingleSequenceWidget *seq0 = dynamic_cast<ADVSingleSequenceWidget*>(GTWidget::findWidget(os, "ADV_single_sequence_widget_0", parent));
    ADVSingleSequenceWidget *seq1 = dynamic_cast<ADVSingleSequenceWidget*>(GTWidget::findWidget(os, "ADV_single_sequence_widget_1", parent));
    ADVSingleSequenceWidget *seq2 = dynamic_cast<ADVSingleSequenceWidget*>(GTWidget::findWidget(os, "ADV_single_sequence_widget_2", parent));

    CHECK_SET_ERR(NULL != seq0, "Failed to find a sequence widget for seq0!");
    CHECK_SET_ERR(NULL != seq1, "Failed to find a sequence widget for seq1!");
    CHECK_SET_ERR(NULL != seq2, "Failed to find a sequence widget for seq2!");

    CHECK_SET_ERR("DLSAETL" == QString(seq0->getSequenceObject()->getWholeSequenceData()), QString("Unexpected sequence. Expected %1, Actual %2").arg("DLSAETL").arg(QString(seq0->getSequenceObject()->getWholeSequenceData())));
    CHECK_SET_ERR("ISRQKP" == QString(seq1->getSequenceObject()->getWholeSequenceData()), QString("Unexpected sequence. Expected %1, Actual %2").arg("ISRQKP").arg(QString(seq1->getSequenceObject()->getWholeSequenceData())));
    CHECK_SET_ERR("SLGRNP" == QString(seq2->getSequenceObject()->getWholeSequenceData()), QString("Unexpected sequence. Expected %1, Actual %2").arg("SLGRNP").arg(QString(seq2->getSequenceObject()->getWholeSequenceData())));
}

GUI_TEST_CLASS_DEFINITION(test_1241) {
    GTLogTracer lt;

    //1. Open file _common_data/scenarios/regression/1241/tt.fa.
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/_regression/1241/tt.fa");

    //2. Select ma959 sequence.
    GTUtilsMsaEditor::clickSequenceName(os, "ma959");

    //3. Press "Enable collapsing".
    GTWidget::click(os, GTAction::button(os, "Enable collapsing"));

    //Expected: UGENE doesn't crash, no errors in log.
    CHECK_SET_ERR(!lt.hasError(), "Errors in log");
}

GUI_TEST_CLASS_DEFINITION(test_1245){
//    1. Open the file human_T1.fa.
//    2. Click on the document context menu "Export Document" in the project view. The Export Document dialog appears.
//    3. Be sure what 'FASTA' format is choosen
//    4. Press on the browse button. Select file location dialog appears. Set the saving file: "test" and click "Save".
//    Expected state: In the "Save to file" field in the Export Document dialog path of the document "test" appears with "fa" extension

    GTFileDialog::openFile(os, dataDir + "samples/FASTA/", "human_T1.fa");

    class ExportDocumentCustomFiller : public Filler {
        public:
            ExportDocumentCustomFiller(U2OpStatus &os)
                : Filler(os, "ExportDocumentDialog") {}
            virtual void run() {
                QWidget *dialog = QApplication::activeModalWidget();
                CHECK_SET_ERR(dialog != NULL, "dialog not found");

                QComboBox *comboBox = dialog->findChild<QComboBox*>("formatCombo");
                CHECK_SET_ERR(comboBox != NULL, "ComboBox not found");
                int index = comboBox->findText("FASTA");

                CHECK_SET_ERR(index != -1, QString("item \"FASTA\" in combobox not found"));
                if (comboBox->currentIndex() != index){
                    GTComboBox::setCurrentIndex(os, comboBox, index);
                }

                GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, sandBoxDir, "test_1245", GTFileDialogUtils::Save));
                GTWidget::click(os, GTWidget::findWidget(os, "browseButton"));
                GTGlobals::sleep();

                QLineEdit* lineEdit = qobject_cast<QLineEdit*>(GTWidget::findWidget(os, "fileNameEdit"));
                CHECK_SET_ERR(lineEdit != NULL, "fileNameEdit not found");
                CHECK_SET_ERR(GTLineEdit::copyText(os, lineEdit).endsWith(".fa"), "Wrong extention");

                QDialogButtonBox* box = qobject_cast<QDialogButtonBox*>(GTWidget::findWidget(os, "buttonBox", dialog));
                CHECK_SET_ERR(box != NULL, "buttonBox is NULL");
                QPushButton* button = box->button(QDialogButtonBox::Cancel);
                CHECK_SET_ERR(button !=NULL, "cancel button is NULL");
                GTWidget::click(os, button);
            }
    };

    GTUtilsDialog::waitForDialog(os, new ExportDocumentCustomFiller(os));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "Export document"));
    GTUtilsProjectTreeView::click(os, "human_T1.fa", Qt::RightButton);
}

GUI_TEST_CLASS_DEFINITION(test_1246){
//    1. Open the file data/samples/Assembly/chrM.sorted.bam
//    2. Select file in the project view and click on the document context menu "Export Document" in the project view.
//    Expected state: the Export Document dialog appears.
//    3. Press on the browse button.
//    Expected state: Select file location dialog appears.
//    4. Fill this dialog with:
//        {Save to file:} anything
//        {File format:} SAM.
//    5. Click the Export button.
//    Expected state: UGENE does not crash.

    GTUtilsDialog::waitForDialog(os, new ImportBAMFileFiller(os, sandBoxDir + "/test_1246.ugenedb"));
    GTFileDialog::openFile(os, dataDir + "samples/Assembly/", "chrM.sorted.bam");
    GTUtilsTaskTreeView::waitTaskFinished(os);

    class ExportDocumentCustomFiller : public Filler {
        public:
            ExportDocumentCustomFiller(U2OpStatus &os)
                : Filler(os, "ExportDocumentDialog") {}
            virtual void run() {
                QWidget *dialog = QApplication::activeModalWidget();
                CHECK_SET_ERR(dialog != NULL, "dialog not found");

                GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, sandBoxDir, "test_1246", GTFileDialogUtils::Save));
                GTWidget::click(os, GTWidget::findWidget(os, "browseButton"));
                GTGlobals::sleep();

                QComboBox *comboBox = dialog->findChild<QComboBox*>("formatCombo");
                CHECK_SET_ERR(comboBox != NULL, "ComboBox not found");
                int index = comboBox->findText("SAM");

                CHECK_SET_ERR(index != -1, QString("item \"SAM\" in combobox not found"));
                if (comboBox->currentIndex() != index){
                    GTComboBox::setCurrentIndex(os, comboBox, index);
                }

                QDialogButtonBox* box = qobject_cast<QDialogButtonBox*>(GTWidget::findWidget(os, "buttonBox", dialog));
                CHECK_SET_ERR(box != NULL, "buttonBox is NULL");
                QPushButton* button = box->button(QDialogButtonBox::Ok);
                CHECK_SET_ERR(button !=NULL, "ok button is NULL");
                GTWidget::click(os, button);
            }
    };

    GTUtilsDialog::waitForDialog(os, new ImportBAMFileFiller(os, sandBoxDir + "/test_1246_2"));

    GTUtilsDialog::waitForDialog(os, new ExportDocumentCustomFiller(os));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "Export document"));
    GTUtilsProjectTreeView::click(os, "test_1246.ugenedb", Qt::RightButton);

    GTUtilsTaskTreeView::waitTaskFinished(os);
}

GUI_TEST_CLASS_DEFINITION(test_1249){

    // 1. Open human_T1.fa.
    // 2. Use menu {Analyze->Find restriction sites}.
    // 3. Press "Enzymes file.."
    // 4. Select file "data\enzymes\rebase_v003_all.bairoch".
    // Expected state: total number of enzymes is 4565(Enzymes with unknown sequence field are removed from list)

    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");
//    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "ADV_MENU_ANALYSE" << "Find restriction sites"));
//    GTMenu::showContextMenu(os, GTUtilsSequenceView::getSeqWidgetByNumber(os));

}

GUI_TEST_CLASS_DEFINITION(test_1252){
//    1. Open human_t1.fa
    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");
//    2. Find any pattern. A new annotation document is created
    GTUtilsOptionsPanel::runFindPatternWithHotKey("TTTTTAAAAA", os);

    GTWidget::click(os, GTWidget::findWidget(os, "getAnnotationsPushButton"));
    GTGlobals::sleep(500);
    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "Annotations"));
    QTreeWidgetItem *item = GTUtilsAnnotationsTreeView::findItem(os, "misc_feature");
    GTMouseDriver::moveTo(os, GTTreeWidget::getItemCenter(os, item));
//    3. Delete found annotations from human_t1 annotations tree
    GTMouseDriver::click(os);
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);
//    4. Delete created annotations document
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::No));
    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "MyDocument.gb"));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<<ACTION_PROJECT__REMOVE_SELECTED));
    GTMouseDriver::click(os, Qt::RightButton);
    GTGlobals::sleep(500);
//check delition of annotation document
    GTUtilsProjectTreeView::findIndex(os, "Annotations", GTGlobals::FindOptions(false));
//    5. Click search again

    GTWidget::click(os, GTWidget::findWidget(os, "getAnnotationsPushButton"));
    GTGlobals::sleep();

    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "Annotations"));
    item = GTUtilsAnnotationsTreeView::findItem(os, "misc_feature");
    GTMouseDriver::moveTo(os, GTTreeWidget::getItemCenter(os, item));
// delete annotations manually to cache MessageBox
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::No));
    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "MyDocument.gb"));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<<ACTION_PROJECT__REMOVE_SELECTED));
    GTMouseDriver::click(os, Qt::RightButton);
//    Expected: pattern is found and annotation is stored in a new document

}

GUI_TEST_CLASS_DEFINITION(test_1252_1){
//DIFFERENCE: DEL KEY IS USED TO DELETE ANNOTATION DOCUMENT
//    1. Open human_t1.fa
    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");
//    2. Find any pattern. A new annotation document is created
    GTUtilsOptionsPanel::runFindPatternWithHotKey("TTTTTAAAAA", os);
    GTWidget::click(os, GTWidget::findWidget(os, "getAnnotationsPushButton"));

    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "Annotations"));
    QTreeWidgetItem *item = GTUtilsAnnotationsTreeView::findItem(os, "misc_feature");
    GTMouseDriver::moveTo(os, GTTreeWidget::getItemCenter(os, item));
//    3. Delete found annotations from human_t1 annotations tree
    GTMouseDriver::click(os);
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);
//    4. Delete created annotations document
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::No));
    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "MyDocument.gb"));
    GTMouseDriver::click(os);
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);
    GTGlobals::sleep(500);
//check delition of annotation document
    GTUtilsProjectTreeView::findIndex(os, "Annotations", GTGlobals::FindOptions(false));//checks inside
//    5. Click search again
    GTWidget::click(os, GTWidget::findWidget(os, "getAnnotationsPushButton"));
    GTGlobals::sleep();

    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "Annotations"));
    item = GTUtilsAnnotationsTreeView::findItem(os, "misc_feature");
    GTMouseDriver::moveTo(os, GTTreeWidget::getItemCenter(os, item));
// delete annotations manually to cache MessageBox
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::No));
    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "MyDocument.gb"));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<<ACTION_PROJECT__REMOVE_SELECTED));
    GTMouseDriver::click(os, Qt::RightButton);
//    Expected: pattern is found and annotation is stored in a new document
}

GUI_TEST_CLASS_DEFINITION(test_1252_real) {
    // 1) Open WD.
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    // 2) Add Read Sequence(RS).
    WorkflowProcessItem *reader = GTUtilsWorkflowDesigner::addElement(os, "Read Sequence");

    // 3) Add ORF Finder(OF).
    WorkflowProcessItem *orfMarker = GTUtilsWorkflowDesigner::addElement(os, "ORF Marker");

    // 4) Connect RS with OF.
    GTUtilsWorkflowDesigner::connect(os, reader, orfMarker);

    // 5) Add Write Sequence(WS).
    WorkflowProcessItem *writer = GTUtilsWorkflowDesigner::addElement(os, "Write Sequence");

    // 6) Connect OF with WS.
    GTUtilsWorkflowDesigner::connect(os, orfMarker, writer);

    // Excepted state : Input "Annotations" slot of WS is not empty and contains annotations from ORF Finder
    GTUtilsWorkflowDesigner::click(os, "Write Sequence");

    QTableWidget* tw = GTUtilsWorkflowDesigner::getInputPortsTable(os, 0);
    CHECK_SET_ERR(tw != NULL, "InputPortsTable is NULL");

    QRect rect = tw->visualItemRect(tw->item(0, 1));
    QPoint globalP = tw->viewport()->mapToGlobal(rect.center());
    GTMouseDriver::moveTo(os, globalP);
    GTMouseDriver::click(os);
    GTGlobals::sleep(500);
    QComboBox* box = qobject_cast<QComboBox*>(tw->findChild<QComboBox*>());

    QStandardItemModel *checkBoxModel = qobject_cast<QStandardItemModel *>(box->model());
    CHECK_SET_ERR(checkBoxModel != NULL, "Unexpected checkbox model");

    QStandardItem *firstItem = checkBoxModel->item(0);
    CHECK_SET_ERR(firstItem->data(Qt::DisplayRole).toString() == "Set of annotations (by ORF Marker)", "Unexpected port");
    CHECK_SET_ERR(Qt::Checked == firstItem->checkState(), "Unexpected check state");
}

GUI_TEST_CLASS_DEFINITION(test_1255){
//1. Open human_T1.fa sequence
    GTFileDialog::openFile(os, dataDir + "samples/FASTA/", "human_T1.fa");

//2. Open Find Pattern on the Option Panel. Enter a vaild pattern
    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(200);
    GTKeyboardDriver::keySequence(os, "TA");

//3. Input invalid annotation name (empty, too long, illegal)
    GTWidget::click(os, GTWidget::findWidget(os, "ArrowHeader_Annotation parameters"));
    GTWidget::click(os, GTWidget::findWidget(os, "titleWidget"));
    QLabel *label;
    label = (QLabel*)GTWidget::findWidget(os,"lblErrorMessage");

    QLineEdit *annotationNameEdit;
    annotationNameEdit=(QLineEdit *)GTWidget::findWidget(os,"leAnnotationName");

//3.1 Input invalid annotation name (empty)
    GTLineEdit::setText(os,annotationNameEdit,"");
    QString s=label->text();
    CHECK_SET_ERR(s.contains("empty"),"Error message is: "+s);
    GTGlobals::sleep(500);

    for (int i=0; i<5; i++){
        GTKeyboardDriver::keyClick(os,GTKeyboardDriver::key["down"]);
        GTGlobals::sleep(50);
    }

//3.2 Input invalid annotation name (illegal)

    GTLineEdit::setText(os,annotationNameEdit," test");
    s=label->text();
    CHECK_SET_ERR(s.contains("Illegal"),"Error message is: "+s);
    GTGlobals::sleep(500);
}

GUI_TEST_CLASS_DEFINITION(test_1257){

    // 1. Open Find Pattern on the Options Panel
    // 2. Provide the widget with wrong input (no annotation name, bad region)
    // Expected: Search button is disabled

    GTFileDialog::openFile(os, dataDir + "samples/FASTA/", "human_T1.fa");
    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep();

    GTKeyboardDriver::keySequence(os, ">S");
    GTGlobals::sleep();

    QWidget* prevButton = GTWidget::findWidget(os, "prevPushButton");
    CHECK_SET_ERR(!prevButton->isEnabled(), "prevPushButton is unexpectidly enabled")
}

GUI_TEST_CLASS_DEFINITION(test_1259) {
//    1. Open FindPattern on the Options Panel
//    2. (Using ctrl+enter once) enter the following pattern:
//    >S
//    H
//    3. Remove H (with backspace)
//    Expected state: UGENE doesn't crash and the symbol is removed

    GTFileDialog::openFile(os, dataDir + "samples/FASTA/", "human_T1.fa");
    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep();

    GTKeyboardDriver::keySequence(os, ">S");
    GTGlobals::sleep();
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["enter"], GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep();
    GTKeyboardDriver::keySequence(os, "H");
    GTGlobals::sleep();
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["back"]);
    GTGlobals::sleep();

    QTextEdit* textEdit = qobject_cast<QTextEdit*>(GTWidget::findWidget(os, "textPattern"));
    CHECK_SET_ERR( textEdit->toPlainText() == ">S\n", "Wrong pattern");
}

GUI_TEST_CLASS_DEFINITION(test_1260) {
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/_regression/1260/", "51.fa");

    GTLogTracer lt;
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<<MSAE_MENU_EXPORT<<"Save subalignment"));
    GTUtilsDialog::waitForDialog(os, new ExtractSelectedAsMSADialogFiller(os,
        testDir + "_common_data/scenarios/sandbox/1260.sto",
        QStringList() << "Isophya_altaica_EF540820" << "Phaneroptera_falcata", 1, 51, true,
        false, false, false, true));
    GTMenu::showContextMenu(os,GTWidget::findWidget(os,"msa_editor_sequence_area"));
    CHECK_SET_ERR(!lt.hasError(), "Log should not contain errosrs");
}

GUI_TEST_CLASS_DEFINITION(test_1262) {
    //1. Open human_t1.fa
    GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
    //2. Find any pattern. A new annotation document is created
    GTUtilsOptionsPanel::runFindPatternWithHotKey("AGGAAAAAATGCTAAGGGCAGCCAGAGAGAGGTCAGG", os);
    GTGlobals::sleep(1000);

    GTWidget::click(os, GTWidget::findWidget(os, "getAnnotationsPushButton"));
    GTGlobals::sleep(500);
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<<ACTION_PROJECT__REMOVE_SELECTED));
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::No));

    //3. Delete created annotations document
    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "MyDocument.gb"));
    GTMouseDriver::click(os, Qt::RightButton);
    //4. Click search again

    GTWidget::click(os, GTWidget::findWidget(os, "getAnnotationsPushButton"));

    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "Annotations"));
    GTUtilsTaskTreeView::waitTaskFinished(os);
    QTreeWidgetItem *item = GTUtilsAnnotationsTreeView::findItem(os, "misc_feature");
    GTMouseDriver::moveTo(os, GTTreeWidget::getItemCenter(os, item));

    //delete new doc
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<<ACTION_PROJECT__REMOVE_SELECTED));
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::No));

    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "MyDocument.gb"));
    GTMouseDriver::click(os, Qt::RightButton);
}

GUI_TEST_CLASS_DEFINITION(test_1266) {
//    1. Open "Call variants" sample pipleine from the "NGS" category
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
    GTUtilsWorkflowDesigner::addSample(os, "call variants");

    class custom : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            QWidget *dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog, "activeModalWidget is NULL");

            GTUtilsWizard::clickButton(os, GTUtilsWizard::Next);
            QWidget* w = GTWidget::findWidget(os, "Disable BAQ computation label", dialog);
            QWidget* parent = qobject_cast<QWidget*>(w->parent());
            QString s = parent->toolTip();
            CHECK_SET_ERR(s.contains("<html>Disable"), "unexpected tooltip: " + s);

            GTUtilsWizard::clickButton(os, GTUtilsWizard::Cancel);
        }
    };
//    2. Run its wizzard
    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Call Variants Wizard", new custom()));
    GTWidget::click(os, GTAction::button(os, "Show wizard"));
//    Expected state: all parameters of the wizzard have tooltips with their descriptions
}

GUI_TEST_CLASS_DEFINITION(test_1274){
//    1. Select "Tabbed documents" mode in the Application Settings.
    class TabbedDoc : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            QWidget *dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog, "activeModalWidget is NULL");

            QWidget* tabbedMode = GTWidget::findWidget(os, "tabbedButton");
            CHECK_SET_ERR(tabbedMode != NULL, "No tubbedButton");
            GTWidget::click(os, tabbedMode);

            GTUtilsDialog::clickButtonBox(os, dialog, QDialogButtonBox::Ok);
        }
    };


    GTUtilsDialog::waitForDialog(os, new AppSettingsDialogFiller(os, new TabbedDoc()));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "action__settings"));
    GTMenu::showMainMenu(os, MWMENU_SETTINGS);
//    2. Open a document
    GTFileDialog::openFile(os, dataDir + "samples/Genbank/", "murine.gb");
//    3. Click the cross button of the window to close it
    GTKeyboardDriver::keyClick(os, 'w', GTKeyboardDriver::key["ctrl"]);
//    Expected state: UGENE not crashes
}

GUI_TEST_CLASS_DEFINITION(test_1273) {
    //1) Open "_common_data/genbank/JQ040024.1.gb".
    GTFileDialog::openFile(os, testDir + "_common_data/genbank/JQ040024.1.gb");

    //2) Switch the windows layout to the tabbed documents mode
    //(Settings -> Preferences -> General -> Windows Layout -> Tabbed documents -> OK)
    class Scenario : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            QList<QRadioButton*> buttons = GTRadioButton::getAllButtonsByText(os, "Tabbed documents", QApplication::activeModalWidget());
            foreach (QRadioButton *tabbedMode, buttons) {
                GTRadioButton::click(os, tabbedMode);
                break;
            }
            GTUtilsDialog::clickButtonBox(os, QApplication::activeModalWidget(), QDialogButtonBox::Ok);
        }
    };

    GTUtilsDialog::waitForDialog(os, new AppSettingsDialogFiller(os, new Scenario()));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "action__settings"));
    GTMenu::showMainMenu(os, MWMENU_SETTINGS);

    //Expected: the name of the sequence view tab starts with "JQ040024.1", but not with "JQ040024".
    QTabBar *tabs = AppContext::getMainWindow()->getQMainWindow()->findChild<QTabBar*>("");
    CHECK_SET_ERR(NULL != tabs, "No tab bar");
    CHECK_SET_ERR(tabs->tabText(1).startsWith("JQ040024.1"), "Wrong tab name");
}

GUI_TEST_CLASS_DEFINITION(test_1285) {
    //1. Open human_t1.fa
    GTFileDialog::openFile(os, dataDir+"samples/FASTA/", "human_T1.fa");
    //3. Click {show more options}
    //4. Check comboboxes: use pattern name, load pattern from file
    GTUtilsOptionPanelSequenceView::openTab(os, GTUtilsOptionPanelSequenceView::Search);
    GTUtilsOptionPanelSequenceView::toggleInputFromFilePattern(os);
    GTUtilsOptionPanelSequenceView::enterPatternFromFile(os, testDir + "_common_data/scenarios/_regression/1285/", "small.fa");
    CHECK_SET_ERR(GTUtilsOptionPanelSequenceView::checkResultsText(os, "Results: 1/1"), "Results string not match");
}

GUI_TEST_CLASS_DEFINITION(test_1288){
//    1) Open Workflow Designer.
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
//    2) Open Tab "Elements".

//    3) Create element "Basic Analysis->Find Pattern".
    WorkflowProcessItem* fp = GTUtilsWorkflowDesigner::addElement(os, "Find Pattern");
//    4) Create element "Data Readers->Read Sequence".
    WorkflowProcessItem* rs = GTUtilsWorkflowDesigner::addElement(os, "Read Sequence");
//    5) Connect "Read Sequence" to "Find Pattern".
    GTUtilsWorkflowDesigner::connect(os, rs, fp);
//    Wrong state: "Plain text" slot in "Find Pattern" has value "Dataset".
    GTUtilsWorkflowDesigner::click(os, "Find Pattern");
//    Expected: "Plain text" slot in "Find Pattern" has value "<empty>".
    QTableWidget* tw = GTUtilsWorkflowDesigner::getInputPortsTable(os, 0);
    CHECK_SET_ERR(tw != NULL, "InputPortsTable is NULL");
    QString s = GTUtilsWorkflowDesigner::getCellValue(os, "Plain text", tw);

    CHECK_SET_ERR(s == "<empty>", "unexpected value: " + s);
}

GUI_TEST_CLASS_DEFINITION(test_1289) {
//    1) Open samples/Genbank/murine.gb.
//    2) Open Workflow Designer.
//    3) Menu: Settings->Preferences.
//    4) "General" tab: switch on "Tabbed documents" window layout.
//    5) Press Ok.

//    Expected state:
//    UGENE not crashed
//    Tabs have red cross icons.

    GTFileDialog::openFile(os, dataDir + "samples/Genbank/", "murine.gb");
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    class TabbedDoc : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            QWidget *dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog, "activeModalWidget is NULL");

            QWidget* tabbedMode = GTWidget::findWidget(os, "tabbedButton");
            CHECK_SET_ERR(tabbedMode != NULL, "No tubbedButton");
            GTWidget::click(os, tabbedMode);

            GTUtilsDialog::clickButtonBox(os, dialog, QDialogButtonBox::Ok);
        }
    };

    GTLogTracer l;

    GTUtilsDialog::waitForDialog(os, new AppSettingsDialogFiller(os, new TabbedDoc()));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "action__settings"));
    GTMenu::showMainMenu(os, MWMENU_SETTINGS);

}

GUI_TEST_CLASS_DEFINITION(test_1295) {
    class CustomBuildTreeDialogFiller : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            QWidget *dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog, "activeModalWidget is NULL");
            GTUtilsDialog::waitForDialogWhichMayRunOrNot(os, new LicenseAgreemntDialogFiller(os));

            QComboBox *algorithmBox = qobject_cast<QComboBox *>(GTWidget::findWidget(os, "algorithmBox", dialog));
            GTComboBox::setIndexWithText(os, algorithmBox, "MrBayes");

            QLineEdit *saveLineEdit = qobject_cast<QLineEdit *>(GTWidget::findWidget(os, "fileNameEdit", dialog));
            GTLineEdit::setText(os, saveLineEdit, sandBoxDir + "1295.nwk");

            QDialogButtonBox *box = qobject_cast<QDialogButtonBox *>(GTWidget::findWidget(os, "buttonBox", dialog));
            QPushButton* button = box->button(QDialogButtonBox::Ok);
            CHECK_SET_ERR(button != NULL, "Ok button is NULL");
            GTWidget::click(os, button);
        }
    };

    GTLogTracer lt;
    // 1. Open file "data/samples/MSF/HMA.msf".
    GTFileDialog::openFile(os, dataDir + "samples/MSF/", "HMA.msf");

    // 2. Call context menu on MSA area.
    // 3. Choose { "Tree" -> "Build Tree" }.
    // Expected state: "Build Phylogenetic Tree" dialog appears.
    // 4. Set "Tree building method" to "MrBayes".
    // 5. Press "Build" button.
    // Expected state: Tree is built (can take a while), notification error message doesn't appear.

    GTUtilsDialog::waitForDialog(os, new BuildTreeDialogFiller(os, new CustomBuildTreeDialogFiller()));
    QAbstractButton *tree = GTAction::button(os, "Build Tree");
    GTWidget::click(os, tree);
    GTUtilsTaskTreeView::waitTaskFinished(os);
    // Expected: the tree appears synchronized with the MSA Editor.

    GTUtilsLog::check(os, lt);
}

GUI_TEST_CLASS_DEFINITION(test_1299) {
/* 1) Open WD, load "Find substrings in sequences" sample
 * 2) Click on "Find substrings", "Text" slot
 *  Expected state: Popup menu should appear, contains bold "Additional" item menu
 */
    QMenu* menu=GTMenu::showMainMenu(os, MWMENU_TOOLS);
    GTMenu::clickMenuItemByName(os, menu, QStringList() << ToolsMenu::WORKFLOW_DESIGNER);
    GTUtilsWorkflowDesigner::addSample(os, "Find substrings in sequences");

    GTUtilsWorkflowDesigner::click(os, "Find Substrings");

    QTableWidget* tw = GTUtilsWorkflowDesigner::getInputPortsTable(os, 0);
    CHECK_SET_ERR(tw != NULL, "InputPortsTable is NULL");

    GTUtilsWorkflowDesigner::setTableValue(os, "Plain text", "Source URL (by Read Sequence)", GTUtilsWorkflowDesigner::comboValue, tw);

    int row = -1;
    for(int i = 0; i<tw->rowCount(); i++){
        QString s = tw->item(i,0)->text();
        if(s == "Plain text"){
            row = i;
            break;
        }
    }
    QRect rect = tw->visualItemRect(tw->item(row, 1));
    QPoint globalP = tw->viewport()->mapToGlobal(rect.center());
    GTMouseDriver::moveTo(os, globalP);
    GTMouseDriver::click(os);
    GTGlobals::sleep(500);
    QComboBox* box = qobject_cast<QComboBox*>(tw->findChild<QComboBox*>());

    CHECK_SET_ERR(box->itemText(3) != "Additional", "Additional item not found");
}

GUI_TEST_CLASS_DEFINITION(test_1300_1) {
//    Show the opened view.

//    1. Open "murine.gb".
//    Expected state: the sequence view opens.
    GTFileDialog::openFile(os, dataDir + "samples/Genbank", "murine.gb");

    bool sequenceViewIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "murine [s] NC_001363");
    CHECK_SET_ERR(sequenceViewIsVisible, "Sequence view is unexpectedly not visible");

//    2. Open "COI.aln".
//    Expected state: the MSA Editor opens, sequence view is opened, but is not shown.
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");

    bool msaEditorIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI");
    CHECK_SET_ERR(msaEditorIsVisible, "Msa editor is unexpectedly not visible");

    sequenceViewIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "murine [s] NC_001363");
    CHECK_SET_ERR(!sequenceViewIsVisible, "Sequence view is unexpectedly visible");

//    3. Double click to the sequence of "murine.gb" in the project view ([s] NC_001363).
//    Expected state: the sequence view is shown, the MSA Editor is no  visible.
    GTUtilsProjectTreeView::doubleClickItem(os, "NC_001363");

    msaEditorIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI");
    CHECK_SET_ERR(!msaEditorIsVisible, "Msa editor is unexpectedly visible");

    sequenceViewIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "murine [s] NC_001363");
    CHECK_SET_ERR(sequenceViewIsVisible, "Sequence view is unexpectedly not visible");

//    4. Double click to the msa object in the project view ([m] COI).
//    Expected state: the MSA Editor is shown.
    GTUtilsProjectTreeView::doubleClickItem(os, "COI");

    msaEditorIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI");
    CHECK_SET_ERR(msaEditorIsVisible, "Msa editor is unexpectedly not visible");

    sequenceViewIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "murine [s] NC_001363");
    CHECK_SET_ERR(!sequenceViewIsVisible, "Sequence view is unexpectedly visible");

//    5. Double click to the annotation object of "murine.gb" in the project view ([a] NC_001363 features).
//    Expected state: the sequence View is shown.
    GTUtilsProjectTreeView::doubleClickItem(os, "NC_001363 features");

    msaEditorIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI");
    CHECK_SET_ERR(!msaEditorIsVisible, "Msa editor is unexpectedly visible");

    sequenceViewIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "murine [s] NC_001363");
    CHECK_SET_ERR(sequenceViewIsVisible, "Sequence view is unexpectedly not visible");

//    6. Double click to the COI document name in the project view (COI.aln).
//    Expected state: the MSA Editor is shown.
    GTUtilsProjectTreeView::doubleClickItem(os, "COI.aln");

    msaEditorIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI");
    CHECK_SET_ERR(msaEditorIsVisible, "Msa editor is unexpectedly not visible");

    sequenceViewIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "murine [s] NC_001363");
    CHECK_SET_ERR(!sequenceViewIsVisible, "Sequence view is unexpectedly visible");

//    7. Double click to the murine document name in the project view (murine.gb).
//    Expected state: the sequence view is shown.
    GTUtilsProjectTreeView::doubleClickItem(os, "murine.gb");

    msaEditorIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI");
    CHECK_SET_ERR(!msaEditorIsVisible, "Msa editor is unexpectedly visible");

    sequenceViewIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "murine [s] NC_001363");
    CHECK_SET_ERR(sequenceViewIsVisible, "Sequence view is unexpectedly not visible");
}

GUI_TEST_CLASS_DEFINITION(test_1300_2) {
//    Opening new views, opening the first view of several views.

//    1. Open "murine.gb".
//    Expected state: the sequence view opens.
    GTFileDialog::openFile(os, dataDir + "samples/Genbank", "murine.gb");

    bool sequenceViewIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "murine [s] NC_001363");
    CHECK_SET_ERR(sequenceViewIsVisible, "Sequence view is unexpectedly not visible");

//    2. Close sequence view with murine.gb.
//    Expected state: there is the "murine.gb" document in the project view, no views are opened.
    GTUtilsMdi::click(os, GTGlobals::Close);

    sequenceViewIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "murine [s] NC_001363");
    CHECK_SET_ERR(!sequenceViewIsVisible, "Sequence view is unexpectedly visible");

//    3. Open "COI.aln".
//    Expected state: the MSA Editor opens.
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");

    bool msaEditorIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI");
    CHECK_SET_ERR(msaEditorIsVisible, "Msa editor is unexpectedly not visible");

    sequenceViewIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "murine [s] NC_001363");
    CHECK_SET_ERR(!sequenceViewIsVisible, "Sequence view is unexpectedly visible");

//    4. Right click to the COI document in the project view, select {Open view->Open new view: alignment editor} from the context menu.
//    Expected state: there are two MSA Editors (the second one is active) and no sequence views.
    GTUtilsDialog::waitForDialog(os, new PopupChooserbyText(os, QStringList() << "Open view" << "Open new view: Alignment Editor"));
    GTUtilsProjectTreeView::click(os, "COI.aln", Qt::RightButton);

    msaEditorIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI");
    CHECK_SET_ERR(!msaEditorIsVisible, "Msa editor is unexpectedly visible");

    bool msaEditor2IsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI 2");
    CHECK_SET_ERR(msaEditor2IsVisible, "Msa editor is unexpectedly not visible");

    sequenceViewIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "murine [s] NC_001363");
    CHECK_SET_ERR(!sequenceViewIsVisible, "Sequence view is unexpectedly visible");

//    5. Double click to the murine.gb (document, sequence object, annotation object - different tests?) in the project view.
//    Expected state: the sequecne view opens. There are two MSA Editors and one sequence view (active).
//    5.1 document
    GTUtilsProjectTreeView::doubleClickItem(os, "murine.gb");

    sequenceViewIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "murine [s] NC_001363");
    CHECK_SET_ERR(sequenceViewIsVisible, "Sequence view is unexpectedly not visible");

    msaEditorIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI");
    CHECK_SET_ERR(!msaEditorIsVisible, "Msa editor is unexpectedly visible");

    msaEditor2IsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI 2");
    CHECK_SET_ERR(!msaEditor2IsVisible, "Msa editor is unexpectedly visible");

//    5.2 sequence
    GTUtilsMdi::click(os, GTGlobals::Close);
    GTUtilsProjectTreeView::doubleClickItem(os, "NC_001363");

    sequenceViewIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "murine [s] NC_001363");
    CHECK_SET_ERR(sequenceViewIsVisible, "Sequence view is unexpectedly not visible");

    msaEditorIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI");
    CHECK_SET_ERR(!msaEditorIsVisible, "Msa editor is unexpectedly visible");

    msaEditor2IsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI 2");
    CHECK_SET_ERR(!msaEditor2IsVisible, "Msa editor is unexpectedly visible");

//    5.3 sequence
    GTUtilsMdi::click(os, GTGlobals::Close);
    GTUtilsProjectTreeView::doubleClickItem(os, "NC_001363 features");

    sequenceViewIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "murine [s] NC_001363");
    CHECK_SET_ERR(sequenceViewIsVisible, "Sequence view is unexpectedly not visible");

    msaEditorIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI");
    CHECK_SET_ERR(!msaEditorIsVisible, "Msa editor is unexpectedly visible");

    msaEditor2IsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI 2");
    CHECK_SET_ERR(!msaEditor2IsVisible, "Msa editor is unexpectedly visible");

//    6. Double click to the COI in the project view.
//    Expected state: a popup menu is shown to select a MSA Editor to show. Select the first. There are two MSA Editors (the first one is active) and one sequence view.
    GTUtilsDialog::waitForDialog(os, new PopupChooserbyText(os, QStringList() << "Activate view: COI [m] COI"));
    GTUtilsProjectTreeView::doubleClickItem(os, "COI");

    sequenceViewIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "murine [s] NC_001363");
    CHECK_SET_ERR(!sequenceViewIsVisible, "Sequence view is unexpectedly visible");

    msaEditorIsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI");
    CHECK_SET_ERR(msaEditorIsVisible, "Msa editor is unexpectedly not visible");

    msaEditor2IsVisible = GTUtilsMdi::isAnyPartOfWindowVisible(os, "COI [m] COI 2");
    CHECK_SET_ERR(!msaEditor2IsVisible, "Msa editor is unexpectedly visible");
}

GUI_TEST_CLASS_DEFINITION(test_1310) {
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW/COI.aln");
    class Scenario : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            QWidget *dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(NULL != dialog, "activeModalWidget is NULL");

            QComboBox *algorithmBox = qobject_cast<QComboBox *>(GTWidget::findWidget(os, "algorithmBox", dialog));
            CHECK_SET_ERR(NULL != algorithmBox, "algorithmBox is NULL");
            GTComboBox::setIndexWithText(os, algorithmBox, "PHYLIP Neighbor Joining");

            GTUtilsDialog::waitForDialog(os, new LicenseAgreemntDialogFiller(os));
            GTUtilsDialog::clickButtonBox(os, dialog, QDialogButtonBox::Ok);
        }
    };

    GTUtilsDialog::waitForDialog(os, new BuildTreeDialogFiller(os, new Scenario()));
    GTWidget::click(os, GTAction::button(os, "Build Tree"));
}

GUI_TEST_CLASS_DEFINITION(test_1315_1) {
    //1. open murine.gb
    //2. open Primer3 dialog
    //3. Deselect "Pick left primer"
    //Expected state: 5 primers are found
    //Bug state: no primers are found
    GTFileDialog::openFile(os, dataDir + "/samples/Genbank/", "murine.gb");

    Primer3DialogFiller::Primer3Settings settings;
    settings.pickLeft = false;

    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "ADV_MENU_ANALYSE" << "primer3_action"));
    GTUtilsDialog::waitForDialog(os, new Primer3DialogFiller(os, settings));

    GTMouseDriver::click(os);
    GTMouseDriver::click(os, Qt::RightButton);
    GTUtilsTaskTreeView::waitTaskFinished(os);

    GTUtilsAnnotationsTreeView::findItem(os, "top_primers  (0, 5)");
}

GUI_TEST_CLASS_DEFINITION(test_1315_2) {
    //1. open murine.gb
    //2. open Primer3 dialog
    //3. Deselect "Pick right primer"
    //Expected state: 5 primers are found
    //Bug state: no primers are found
    GTFileDialog::openFile(os, dataDir + "/samples/Genbank/", "murine.gb");

    Primer3DialogFiller::Primer3Settings settings;
    settings.pickRight = false;

    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "ADV_MENU_ANALYSE" << "primer3_action"));
    GTUtilsDialog::waitForDialog(os, new Primer3DialogFiller(os, settings));

    GTMouseDriver::click(os);
    GTMouseDriver::click(os, Qt::RightButton);
    GTUtilsTaskTreeView::waitTaskFinished(os);

    GTUtilsAnnotationsTreeView::findItem(os, "top_primers  (0, 5)");
}

GUI_TEST_CLASS_DEFINITION(test_1321_1) {
//    This scenario is about crash found during fixing current bug
//    1. Open file _common_data/scenarios/_regression/2187/seq.fa
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/_regression/2187", "seq.fa");

//    2. Open 'find repeats' dialog, and set next parameters
//        {Minimim repeat length} 20bp
//        {Repeats identity} 80%
//    3. Press 'Start'
//    Expected state: one repeat unit was found, with region join(991..1011,1161..1181), and repeat homology 85%
    QDir().mkpath(sandBoxDir + "test_1321_1");
    GTUtilsDialog::waitForDialog(os, new FindRepeatsDialogFiller(os, sandBoxDir + "test_1321_1", false, 20, 80));
    GTWidget::click(os, GTToolbar::getWidgetForActionTooltip(os, GTToolbar::getToolbar(os, MWTOOLBAR_ACTIVEMDI), "Find repeats"));

    GTUtilsTaskTreeView::waitTaskFinished(os);

    const int annotationsCount = GTUtilsAnnotationsTreeView::findItems(os, "repeat_unit").size();
    CHECK_SET_ERR(1 == annotationsCount, QString("Unexpected annotations count: expect '%1', got '%2'").arg(1).arg(annotationsCount));

    const QString homology = GTUtilsAnnotationsTreeView::getQualifierValue(os, "repeat_homology(%)", "repeat_unit");
    CHECK_SET_ERR("85" == homology, QString("Unexpected repeat homology: expect '%1', got '%2'").arg(85).arg(homology));
}

GUI_TEST_CLASS_DEFINITION(test_1321_2) {
//    1. Open "\samples\FASTA\human_T1.fa"
//    Expected state: sequence view window appeared
    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");

//    2. Press 'Find tandems' tool button
//    Expected state: 'Find tandems' dialog appeared
//    3. Go to the 'Advanced' tab of the dialog
//    Expected state: 'Advanced' tab displayed, there is 'Advanced paremeters' groupbox without 'Repeats identity' parameter
    class Scenario : public CustomScenario {
        void run(U2OpStatus &os) {
            QWidget *dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(NULL != dialog, "Active modal widget is NULL");

            GTTabWidget::setCurrentIndex(os, GTWidget::findExactWidget<QTabWidget *>(os, "tabWidget"), 1);

        }
    };

}

GUI_TEST_CLASS_DEFINITION(test_1323) {
    // 1. Open \test\_common_data\_regression\1323\sample.bad
    // Expected state: document with file added to project

    GTFileDialog::openFile(os, testDir + "_common_data/regression/1323/", "sample.bed");
    }
GUI_TEST_CLASS_DEFINITION(test_1324) {
    // 1. Open WD
    // 2. Add "Search for TFBS with SITECON" element
    // 3. Make sure it is possible to enter 0.0001 for Min Err1

    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
    GTUtilsWorkflowDesigner::addAlgorithm(os, "Search for TFBS with SITECON");

    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Search for TFBS with SITECON"));
    GTMouseDriver::click(os);
    GTUtilsWorkflowDesigner::setParameter(os, "Min Err1", "0.00010", GTUtilsWorkflowDesigner::textValue);

}

GUI_TEST_CLASS_DEFINITION(test_1325) {
//    1. Open _common_data\regression\1325\long_gff.gff (choosing GFF format)
//    2. UGENE will no open the file with error
//    3. Double click on the unloaded document crashes UGENE

//    Expected: UGENE does not crash

    GTLogTracer l1;

    GTUtilsDialog::waitForDialog(os, new DocumentFormatSelectorDialogFiller(os, "GFF") );
    GTFileDialog::openFile(os, testDir + "_common_data/regression/1325/", "long_gff.gff");
    GTGlobals::sleep();
    CHECK_SET_ERR(l1.hasError(), "There is no error in the log");

    GTLogTracer l2;
    GTUtilsDocument::loadDocument(os, "long_gff.gff");
    CHECK_SET_ERR(l2.hasError(), "There is no error in the log");
}

GUI_TEST_CLASS_DEFINITION(test_1326) {
class CallVariantsWizardFiller : public Filler {
public:
        CallVariantsWizardFiller(U2OpStatus &os) :
        Filler(os, "Call Variants Wizard") {}
#define GT_CLASS_NAME "GTUtilsDialog::CallVariantsWizardFiller"
#define GT_METHOD_NAME "run"
        virtual void run() {
            QWidget* dialog = QApplication::activeModalWidget();
            GT_CHECK(dialog, "activeModalWidget is NULL");

            QSizePolicy actualPolicy = dialog->sizePolicy();
            QSizePolicy expectedPolicy = QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            QPoint bottomRight = dialog->mapToGlobal(dialog->rect().bottomRight());
            CHECK_SET_ERR(actualPolicy == expectedPolicy, "size policy dont match");
            QSize prevSize = dialog->size();
            QPoint newBottomRight = QPoint(bottomRight.x() + 5, bottomRight.y() + 5);
            GTMouseDriver::moveTo(os, bottomRight);
            GTMouseDriver::press(os);
            GTMouseDriver::moveTo(os, newBottomRight);
            GTMouseDriver::release(os);
            CHECK_SET_ERR(prevSize == dialog->size(), "size should not change");
            GTWidget::click(os, GTWidget::findButtonByText(os,"Cancel"));
        }
#undef GT_METHOD_NAME
#undef GT_CLASS_NAME
    };
    QMenu* menu=GTMenu::showMainMenu(os, MWMENU_TOOLS);
    GTMenu::clickMenuItemByName(os, menu, QStringList() << ToolsMenu::WORKFLOW_DESIGNER);
    GTUtilsWorkflowDesigner::addSample(os, "call variants");

    GTUtilsDialog::waitForDialog(os, new CallVariantsWizardFiller(os));
    GTWidget::click(os, GTAction::button(os, "Show wizard"));
}

GUI_TEST_CLASS_DEFINITION( test_1337 ) {
    //1) Click "Open file" button.
    //2) Choose two sequence files with different alphabets (e.g. "_common_data/fasta/DNA.fa" and "_common_data/fasta/amino_multy.fa") and click "Open" button.
    //Expected state: the dialog appears.
    //3) Choose "Merge sequence mode" and click "OK" button.
    //Expected state: the warning about different alphabets appears.
    GTSequenceReadingModeDialog::mode = GTSequenceReadingModeDialog::Merge;
    GTUtilsDialog::waitForDialog(os, new  GTSequenceReadingModeDialogUtils(os));
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Ok));
    GTFileDialog::openFileList(os, testDir + "_common_data/fasta/", QStringList() << "DNA.fa" << "amino_multy.fa");

    GTUtilsDialog::waitForDialog(os, new SaveProjectDialogFiller(os, QDialogButtonBox::No));
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::No));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_FILE), QStringList()<<ACTION_PROJECTSUPPORT__CLOSE_PROJECT);

    //4) Close the project and repeat these steps.
    //Current state: the warning does not appear.
    GTUtilsDialog::waitForDialog(os, new  GTSequenceReadingModeDialogUtils(os));
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Ok));
    GTFileDialog::openFileList(os, testDir + "_common_data/fasta/", QStringList() << "DNA.fa" << "amino_multy.fa");
}

GUI_TEST_CLASS_DEFINITION(test_1338) {
    // 1. Add the "Write annotation" element (or another element with a property in combo box)
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
    GTUtilsWorkflowDesigner::addAlgorithm(os, "Write Annotations");

    const QString initialText = GTUtilsWorkflowDesigner::getWorkerText(os, "Write Annotations");
    CHECK_SET_ERR(initialText.contains("genbank"), "Worker item doesn't contain format name");

    // 2. Select another document format
    GTUtilsWorkflowDesigner::setParameter(os, "Document format", "gff", GTUtilsWorkflowDesigner::comboValue);
    GTGlobals::sleep(500);

    // 3. Click on the scene
    // Expected state : the file format is changed in the description of the element
    const QString textAfter = GTUtilsWorkflowDesigner::getWorkerText(os, "Write Annotations");
    CHECK_SET_ERR(textAfter != initialText && textAfter.contains("gff"), "Worker item didn't change its content");
}

GUI_TEST_CLASS_DEFINITION(test_1342) {
    class CustomPopupChecker : public CustomScenario {
        void run(U2OpStatus &os) {
            QMenu *activePopupMenu = qobject_cast<QMenu *>(QApplication::activePopupWidget());
            CHECK_SET_ERR(NULL != activePopupMenu, "Active popup menu is NULL");

            GTMenu::clickMenuItemByText(os, activePopupMenu, QStringList() << "Add element");

            activePopupMenu = qobject_cast<QMenu *>(QApplication::activePopupWidget());
            QAction *dataReadersAction = GTMenu::getMenuItem(os, activePopupMenu, "Data Readers", true);
            CHECK_SET_ERR(NULL == dataReadersAction, "Data Readers item is unexpectly found");

            GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["esc"]);
            GTGlobals::sleep(200);
            GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["esc"]);
        }
    };

    // 1. Open WD
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
    GTUtilsWorkflowDesigner::setCurrentTab(os, GTUtilsWorkflowDesigner::algoriths);

    // 2. print "mer" in line "Name filter"
    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTKeyboardDriver::keySequence(os, "mer");

    // 3. use context menu at the edit field : Add element->Data readers->File lists
    // Expected : there is no "File list" element in the menu. UGENE doesn't crash
    GTUtilsDialog::waitForDialog(os, new PopupChecker(os, new CustomPopupChecker));
    GTWidget::click(os, GTWidget::findWidget(os, "sceneView"), Qt::RightButton);
}

GUI_TEST_CLASS_DEFINITION(test_1347) {
//    1. Run Ugene. Open file _common_data\scenarios\msa\ma2_gapped.aln
//    2. Select some symbols(for example first three symbols of first sequence)
//    3. Press ctrl+c
//    Expected state: selection is copied into clipboard

    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/", "ma2_gapped.aln");
    GTGlobals::sleep();

    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(0, 0), QPoint(3, 0));
    GTKeyboardDriver::keyClick(os, 'c', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep();

    GTFileDialog::openFile(os, dataDir + "samples/FASTA/", "human_T1.fa");
    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep();
    GTKeyboardDriver::keyClick(os, 'v', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep();

    QTextEdit* patternEdit = qobject_cast<QTextEdit*>(GTWidget::findWidget(os, "textPattern"));
    CHECK_SET_ERR(patternEdit != NULL, "textPattern is NULL");
    CHECK_SET_ERR(patternEdit->toPlainText() == "AAGA",
                  QString("Wrong text is in the buffer [%1]").arg(patternEdit->toPlainText()));
}

GUI_TEST_CLASS_DEFINITION(test_1348) {
//    1) Create "Element with command line tool" with name "test" and any slots.
//    2) Use context menu on "test" element in "Custom Elements with CMD Tools" in "Elements", click "Remove"
//    3) Use context menu on WD main window, add element -> "Custom Elements with CMD Tools". Select "test", UGENE DOES NOT crash.

//    Expected state: There shouldn't be "test" element on the step 3 after removing it

    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    CreateElementWithCommandLineToolFiller::ElementWithCommandLineSettings settings;
    settings.elementName = "Element_1348";

    QList<CreateElementWithCommandLineToolFiller::InOutData> input;
    CreateElementWithCommandLineToolFiller::InOutDataType inOutDataType;
    inOutDataType.first = CreateElementWithCommandLineToolFiller::Sequence;
    inOutDataType.second = "FASTA";
    input << CreateElementWithCommandLineToolFiller::InOutData("in1",
                                                               inOutDataType);
    settings.input = input;
    settings.executionString = "./ugenem $in1";

    GTUtilsDialog::waitForDialog(os, new CreateElementWithCommandLineToolFiller(os, settings));
    QAbstractButton *createElement = GTAction::button(os, "createElementWithCommandLineTool");
    GTWidget::click(os, createElement);
    GTGlobals::sleep();

    GTUtilsWorkflowDesigner::setCurrentTab(os, GTUtilsWorkflowDesigner::algoriths);
    QTreeWidgetItem* treeItem = GTUtilsWorkflowDesigner::findTreeItem(os, settings.elementName, GTUtilsWorkflowDesigner::algoriths);
    CHECK_SET_ERR(treeItem != NULL, "Element not found");

    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Ok));
    GTUtilsDialog::waitForDialog(os, new PopupChooserbyText(os, QStringList() << "Remove"));
    GTTreeWidget::click(os, treeItem);
    GTMouseDriver::click(os, Qt::RightButton);
    GTGlobals::sleep();

    GTUtilsDialog::waitForDialog(os, new PopupCheckerByText(os, QStringList() << "Add element"
                                                      << "Custom Elements with CMD Tools",
                                                      PopupChecker::NotExists));
    GTWidget::click(os, GTWidget::findWidget(os,"sceneView"), Qt::RightButton);
}

GUI_TEST_CLASS_DEFINITION(test_1358) {
    //1. Open file "test/_common_data/scenarios/workflow designer/222.uwl"
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    GTUtilsWorkflowDesigner::loadWorkflow(os, testDir + "_common_data/regression/1358/test_0001.uwl");
    CHECK_OP(os, );

    GTUtilsWorkflowDesigner::click(os, "Read Sequence");
    GTUtilsWorkflowDesigner::setDatasetInputFile(os, dataDir + "/samples/Genbank/", "murine.gb");
    //2. Press "Run schema"

    //Expected state: UGENE doesn't crash
    GTUtilsWorkflowDesigner::runWorkflow(os);
    GTUtilsTaskTreeView::waitTaskFinished(os);
}

GUI_TEST_CLASS_DEFINITION(test_1360){
//    1) Open WD
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
//    2) Connect a reader element with some writer element.
    GTUtilsWorkflowDesigner::addAlgorithm(os, "Read alignment");
    GTUtilsWorkflowDesigner::addAlgorithm(os, "Write alignment");
    WorkflowProcessItem* read = GTUtilsWorkflowDesigner::getWorker(os, "Read Alignment");
    WorkflowProcessItem* write = GTUtilsWorkflowDesigner::getWorker(os, "Write Alignment");
    GTUtilsWorkflowDesigner::connect(os, read, write);
//    3) Disconnect them.
    GTUtilsWorkflowDesigner::disconect(os, read, write);
//    4) Connect them again.
    GTUtilsWorkflowDesigner::connect(os, read, write);
//    5) Specify any input data
    GTUtilsWorkflowDesigner::click(os, "Read Alignment");
    GTUtilsWorkflowDesigner::setDatasetInputFile(os, dataDir + "samples/CLUSTALW", "COI.aln");

    QString s = read->getProcess()->getDescription()->toPlainText();
    CHECK_SET_ERR(s.contains("COI.aln"), "unexpected worker text: " + s);
//    Expected state: data from dataset s displayed on the read worker
}

GUI_TEST_CLASS_DEFINITION(test_1362) {
    //1) Open "_common_data/edit_alignment/COI_sub_same_with_gaps.fa".
    GTFileDialog::openFile(os, testDir + "_common_data/edit_alignment/COI_sub_same_with_gaps.fa");

    //2) MSA context menu: { Statistics -> Generate distance matrix }.
    //3) Fill in Generate distance matrix dialog:
    //    Distance algorithm : Identity.
    //    Profile mode: Percents.
    //    Exclude gaps: unchecked.
    //4) Run the task.
    GTUtilsDialog::waitForDialog(os, new PopupChooserbyText(os, QStringList() << "Statistics" << "Generate distance matrix"));
    DistanceMatrixDialogFiller *filler = new DistanceMatrixDialogFiller(os, false, false, false);
    filler->saveToFile = true;
    filler->format = DistanceMatrixDialogFiller::CSV;
    filler->path = sandBoxDir + "test_1362.csv";
    GTUtilsDialog::waitForDialog(os, filler);
    GTUtilsMSAEditorSequenceArea::callContextMenu(os);
    GTUtilsTaskTreeView::waitTaskFinished(os);

    //Expected state:
    // Generated report's table should contain "100%" in needed places (where sequences are the same).
    QFile result(sandBoxDir + "test_1362.csv");
    result.open(QIODevice::ReadOnly);
    QByteArray data = result.readAll();
    result.close();

    CHECK_SET_ERR(data.contains("Zychia_baranovi,100%,86%,86%,86%"), "Wrong matrix content 1");
    CHECK_SET_ERR(data.contains("Tettigonia_viridissima,86%,100%,100%,100%"), "Wrong matrix content 2");
    CHECK_SET_ERR(data.contains("Conocephalus_discolor,86%,100%,100%,100%"), "Wrong matrix content 3");
    CHECK_SET_ERR(data.contains("Conocephalus_sp.,86%,100%,100%,100%"), "Wrong matrix content 4");
}

GUI_TEST_CLASS_DEFINITION(test_1364) {
//    1. Open WD.
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
//    2. Add "Read Sequence" element on the scene.
    GTUtilsWorkflowDesigner::addAlgorithm(os, "Read Sequence", true);
//    3. Click the element.
//    Expected: Bottom datasets panel appears.
    GTUtilsWorkflowDesigner::click(os, "Read Sequence");
//    4. Click "Add file" button.
//    Expected: The file dialog appears with some directory A.
    GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, dataDir+"samples/FASTA/human_T1.fa"));
//    5. Choose some file from some directory B (A != B) and click "Open".
    GTWidget::click(os, GTWidget::findWidget(os, "addFileButton"));
//    6. Click "Add file" button again.
    class customFileDialog : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            QWidget* d = QApplication::activeModalWidget();
            CHECK_SET_ERR(d, "activeModalWidget is NULL");
            QFileDialog* dialog = qobject_cast<QFileDialog*>(d);
            CHECK_SET_ERR(dialog, "activeModalWidget is not file dialog");

            QString name = dialog->directory().dirName();
            CHECK_SET_ERR(name == "FASTA", "unexpectyed dir name: " + name);
            GTWidget::click(os, GTWidget::findButtonByText(os, "Cancel", dialog));
        }
    };
//    Expected: The file dialog opens with the directory B.
    GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, new customFileDialog()));
    GTWidget::click(os, GTWidget::findWidget(os, "addFileButton"));
}

GUI_TEST_CLASS_DEFINITION(test_1365){
    // 1. Open file "data/samples/COI.aln" in alignment editor
    // Expected state: "Save all" button on main toolbar is enabled
    // 2. Open Workflow Designer
    // Expected state: "Save all" button is still enabled

    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");

    GTUtilsDialog::waitForDialogWhichMayRunOrNot(os, new SaveProjectDialogFiller(os, QDialogButtonBox::No));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_FILE),
    QStringList() << ACTION_PROJECTSUPPORT__SAVE_PROJECT, GTGlobals::UseKey);

    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    GTUtilsDialog::waitForDialogWhichMayRunOrNot(os, new SaveProjectDialogFiller(os, QDialogButtonBox::No));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_FILE),
    QStringList() << ACTION_PROJECTSUPPORT__SAVE_PROJECT, GTGlobals::UseKey);

}

GUI_TEST_CLASS_DEFINITION(test_1368){
/* 1. Open _common_data\sam\crash.sam
 * Expected state: UGENE not crashes
*/
    QString ugenedbFileName = testDir + "_common_data/scenarios/sandbox/test_1368.ugenedb";
    GTUtilsDialog::waitForDialog(os, new ImportBAMFileFiller(os, ugenedbFileName));
    GTFileDialog::openFile(os, testDir + "_common_data/sam", "crash.sam");
}

GUI_TEST_CLASS_DEFINITION(test_1371) {
//    1. Open file "data/samples/ACE/BL060C3.ace" as msa.
//    Expected state: there are 2 MSA objects in document.
    GTUtilsDialog::waitForDialog(os, new DocumentProviderSelectorDialogFiller(os, DocumentProviderSelectorDialogFiller::AlignmentEditor));
    GTFileDialog::openFile(os, dataDir + "samples/ACE", "BL060C3.ace");
    GTUtilsTaskTreeView::waitTaskFinished(os);

    GTUtilsProjectTreeView::checkItem(os, "Contig1");
    GTUtilsProjectTreeView::checkItem(os, "Contig2");
    GTUtilsProjectTreeView::checkObjectTypes(os,
                                             QSet<GObjectType>() << GObjectTypes::MULTIPLE_ALIGNMENT,
                                             GTUtilsProjectTreeView::findIndex(os, "BL060C3.ace"));

//    2. Open file "data/samples/ACE/BL060C3.ace" as assembly.
//    Expected state: there are 2 assembly objects in document.

    GTUtilsDocument::removeDocument(os, "BL060C3.ace");
    QDir().mkpath(sandBoxDir + "test_1371");

    GTUtilsDialog::waitForDialog(os, new DocumentProviderSelectorDialogFiller(os, DocumentProviderSelectorDialogFiller::AssemblyBrowser));
    GTUtilsDialog::waitForDialog(os, new ConvertAceToSqliteDialogFiller(os, sandBoxDir + "test_1371/test_1371.ugenedb"));
    GTFileDialog::openFile(os, dataDir + "samples/ACE", "BL060C3.ace");
    GTUtilsTaskTreeView::waitTaskFinished(os);

    GTUtilsProjectTreeView::checkItem(os, "Contig1");
    GTUtilsProjectTreeView::checkItem(os, "ref1");
    GTUtilsProjectTreeView::checkItem(os, "Contig2");
    GTUtilsProjectTreeView::checkItem(os, "ref2");
    GTUtilsProjectTreeView::checkObjectTypes(os,
                                             QSet<GObjectType>() << GObjectTypes::ASSEMBLY << GObjectTypes::SEQUENCE,
                                             GTUtilsProjectTreeView::findIndex(os, "test_1371.ugenedb"));
}

GUI_TEST_CLASS_DEFINITION(test_1376){
    //1. Open data/position_weight_matrix/JASPAR/fungi/MA0276.1.pfm.
    GTFileDialog::openFile(os, dataDir + "position_weight_matrix/JASPAR/fungi/MA0276.1.pfm");
    GTUtilsTaskTreeView::waitTaskFinished(os);

    //Expected: PFM matrix view with logo and weight table is opened.
    //QWidget *mdi = GTUtilsMdi::findWindow(os, "Matrix Viewer");
    GTWidget::findWidget(os, "logoWidget");
    GTWidget::findWidget(os, "tableWidget");
}

GUI_TEST_CLASS_DEFINITION(test_1386){
//    1) Open a document (e.g. COI.aln)
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW/COI.aln");
//    2) Modify it (e.g. insert a gap)
    GTUtilsMSAEditorSequenceArea::click(os, QPoint(5,5));
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["space"]);
//    3) Close the view of the document
    GTUtilsMdi::click( os, GTGlobals::Close );
//    4) Select "Unload selected documents" for the document
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<<"action_project__unload_selected_action"));
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::No));
    GTUtilsProjectTreeView::click(os, "COI.aln", Qt::RightButton);
//    5) Select "No" not to save the document
    GTUtilsDocument::isDocumentLoaded(os, "COI.aln");
    GTUtilsProjectTreeView::itemModificationCheck(os, GTUtilsProjectTreeView::findIndex(os, "COI.aln"), false);
//    Expected state: the document is unloaded, not marked as modified (blue).
}

GUI_TEST_CLASS_DEFINITION(test_1387) {
    // 1) Open _common_data\regression\1387\col_of_gaps.aln
    // 2) Use context menu: {Edit -> Remove columns of gaps}
    // 3) In the appeared dialog select "Remove columns with percentage of gaps" and click the "Remove" button.
    // Expected state: UGENE not crashed

    GTFileDialog::openFile(os, testDir + "_common_data/regression/1387/", "col_of_gaps.aln");

    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << MSAE_MENU_EDIT << "remove_columns_of_gaps"));

    GTUtilsDialog::waitForDialog(os, new RemoveGapColsDialogFiller(os, RemoveGapColsDialogFiller::Percent, 15));
    GTMenu::showContextMenu(os, GTUtilsMSAEditorSequenceArea::getSequenceArea(os));

}
GUI_TEST_CLASS_DEFINITION(test_1390) {
/*  1. Open some assembly with assembly browser
    2. Open the "Assembly Browser Settings" tab in options panel
    3. Choose the "Difference" type of "Reads highlighting" (if not chosen by default)
        Expected state: the hint about setting reference sequence is displayed
    4. Set any other value for "Reads highlighting"
        Expected state: the hint has vanished
    5. Set the "Difference" again from assembly context menu { Reads highlighting -> Difference }
        Expected state: the hint has appeared again in options panel
*/

    QString ugenedbFileName = testDir + "_common_data/scenarios/sandbox/test_1390.ugenedb";
    GTUtilsDialog::waitForDialog(os, new ImportBAMFileFiller(os, ugenedbFileName));
    GTFileDialog::openFile( os, testDir + "_common_data/bam", "chrM.sorted.bam" );

    GTWidget::click(os, GTWidget::findWidget(os, "OP_ASS_SETTINGS"));
    QLabel* hint = qobject_cast<QLabel*>(GTWidget::findWidget(os, "HINT_HIGHLIGHTNING"));
    CHECK_SET_ERR( hint != NULL, "Hint not found");
    CHECK_SET_ERR(!hint->text().isEmpty(), "Hint is empty, but must not be");

    QComboBox* highlightingBox = qobject_cast<QComboBox *>(GTWidget::findWidget(os, "READS_HIGHLIGHTNING_COMBO"));
    CHECK_SET_ERR( highlightingBox != NULL, "READS_HIGHLIGHTNING_COMBO not found");
    GTComboBox::setIndexWithText(os, highlightingBox, "Nucleotide");
    CHECK_SET_ERR(hint->text().isEmpty(), "Hint is not empty, but must be");

    GTComboBox::setIndexWithText(os, highlightingBox, "Difference");
    CHECK_SET_ERR(!hint->text().isEmpty(), "Hint is empty, but must not be");
}

namespace {

QString getFileContent(const QString &path) {
    QFile file(path);
    CHECK(file.open(QFile::ReadOnly), QString());
    QTextStream fileReader(&file);
    return fileReader.readAll();
}

}

GUI_TEST_CLASS_DEFINITION(test_1393) {
    class ExportSeqsAsMsaScenario : public CustomScenario {
        void run(U2OpStatus &os) {
            QWidget *dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog != NULL, "dialog not found");

            QCheckBox *addToProjectBox = qobject_cast<QCheckBox *>(GTWidget::findWidget(os, "addToProjectBox", dialog));
            CHECK_SET_ERR(addToProjectBox->isChecked(), "'Add document to project' checkbox is not set");

            QLineEdit *lineEdit = qobject_cast<QLineEdit *>(GTWidget::findWidget(os, "fileNameEdit", dialog));
            GTLineEdit::setText(os, lineEdit, sandBoxDir + "test_1393.aln");

            GTUtilsDialog::clickButtonBox(os, QDialogButtonBox::Ok);
        }
    };

    // 1. Open file "_common_data/fasta/trim_fa.fa"
    GTUtilsDialog::waitForDialog(os, new SequenceReadingModeSelectorDialogFiller(os));
    GTFileDialog::openFile(os, testDir + "_common_data/fasta/", "trim_fa.fa");

    // 2. Choose{ Export->Export sequences as alignment } in context menu of project view
    // Expected state : "Export sequences as alignment" dialog appears
    // 3. Make sure that "Add document to project" checkbox is set and press "Export" button.
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << ACTION_PROJECT__EXPORT_IMPORT_MENU_ACTION << ACTION_EXPORT_SEQUENCE_AS_ALIGNMENT));
    GTUtilsDialog::waitForDialog(os, new ExportSequenceAsAlignmentFiller(os, new ExportSeqsAsMsaScenario));
    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "trim_fa.fa"));
    GTMouseDriver::click(os, Qt::RightButton);
    GTUtilsTaskTreeView::waitTaskFinished(os);

    // Expected state : New *.aln file appears in project view.Names of sequences in consensus area
    // are the same as if you open the *.aln file in text editor.
    GTUtilsProjectTreeView::checkItem(os, "test_1393.aln");

    const QString referenceMsaContent = getFileContent(testDir + "_common_data/clustal/test_1393.aln");
    const QString resultMsaContent = getFileContent(sandBoxDir + "test_1393.aln");
    CHECK_SET_ERR(!referenceMsaContent.isEmpty() && referenceMsaContent == resultMsaContent, "Unexpected MSA content");
}

GUI_TEST_CLASS_DEFINITION(test_1396){
/* 1. Open file test/_common_data/scenarios/_regression/1396/empty_rows.fa
 * Expected state: empty alignment and UGENE not crashes
*/
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/_regression/1396", "empty_rows.fa");
    CHECK_SET_ERR(GTUtilsMsaEditor::getSequencesCount(os) == 0, "MSA is not empty");
}


GUI_TEST_CLASS_DEFINITION(test_1404) {
    class ExportMsaToSeqScenario : public CustomScenario {
        void run(U2OpStatus &os) {
            QWidget *dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog != NULL, "dialog not found");

            // 3. Select "FASTQ" file format in "File format to use" field
            QComboBox *formatCombo = qobject_cast<QComboBox *>(GTWidget::findWidget(os, "formatCombo", dialog));
            GTComboBox::setIndexWithText(os, formatCombo, "FASTQ");

            // 4. Click the browse button and input "result" to "File name" field, then click "Save"
            // Expected state : Field "Export to file" contain "result.fastq" at the of string.
            GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, "", "result", GTFileDialogUtils::Save, GTGlobals::UseMouse));
            GTWidget::click(os, GTWidget::findWidget(os, "fileButton", dialog));

            QLineEdit *fileNameEdit = qobject_cast<QLineEdit *>(GTWidget::findWidget(os, "fileNameEdit", dialog));
            QString filePath = fileNameEdit->text();
            CHECK_SET_ERR(filePath.endsWith("result.fastq"), "Wrong file path");

            // 5. Select "FASTA" extension in "File format to use" field
            // Expected state : Field "Export to file" contain "result.fa" at the of string.
            GTComboBox::setIndexWithText(os, formatCombo, "FASTA");
            filePath = fileNameEdit->text();
            CHECK_SET_ERR(filePath.endsWith("result.fa"), "Wrong file path");

            GTUtilsDialog::clickButtonBox(os, QDialogButtonBox::Cancel);
        }
    };

    // 1. Open "data/samples/CLUSTALW/COI.aln"
    // Expected state : COI.aln is opened
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW/", "COI.aln");

    // 2. Select "Export > Save sequence" in the context menu
    // Expected state : Opened "Export selected sequence from alignment" dialog
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << MSAE_MENU_EXPORT << "Save sequence"));
    GTUtilsDialog::waitForDialog(os, new ExportSelectedSequenceFromAlignment(os, new ExportMsaToSeqScenario));
    GTUtilsMSAEditorSequenceArea::moveTo(os, QPoint(5, 5));
    GTMouseDriver::click(os, Qt::RightButton);
}

GUI_TEST_CLASS_DEFINITION(test_1405) {
    // 1) Open _common_data/scenarios/msa/ma2_gap_col.aln
    // 2) Try to delete columns with gaps (first option, 1 gap).
    // Expected state: Safe_point was not triggered, i.e. no error messages in log

    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/", "ma2_gap_col.aln");
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << MSAE_MENU_EDIT << "remove_columns_of_gaps"));

    GTUtilsDialog::waitForDialog(os, new RemoveGapColsDialogFiller(os, RemoveGapColsDialogFiller::Number, 1));
    GTMenu::showContextMenu(os, GTUtilsMSAEditorSequenceArea::getSequenceArea(os));
}

GUI_TEST_CLASS_DEFINITION(test_1408){
//    1) Open "data/samples/FASTA/human_T1.fa"
    GTFileDialog::openFile(os, dataDir + "samples/FASTA/", "human_T1.fa");
//    2) Right click on "human_T1.fa" in the project tab

    class innerScenario : public CustomScenario {
        void run(U2OpStatus &os) {
            QWidget *dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog != NULL, "dialog not found");

            GTWidget::findWidget(os, "groupRB", dialog);
            GTUtilsDialog::clickButtonBox(os, QDialogButtonBox::Cancel);
        }
    };

    class outerScenario : public CustomScenario {
        void run(U2OpStatus &os) {
            QWidget *dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog != NULL, "dialog not found");

            QLineEdit *readFileLineEdit = GTWidget::findExactWidget<QLineEdit*>(os, "readFileName", dialog);
            GTLineEdit::setText(os, readFileLineEdit, testDir + "_common_data/scenarios/annotations_import/anns1.csv");

            GTWidget::click(os, GTWidget::findWidget(os, "guessButton", dialog));

            QTableWidget *previewTable = dialog->findChild<QTableWidget*>("previewTable");
            QRect rect = previewTable->visualItemRect(previewTable->item(1, 1));
            GTUtilsDialog::waitForDialog(os, new RoleFiller(os, new innerScenario()));
            GTWidget::click(os, previewTable, Qt::LeftButton, rect.center());

            GTUtilsDialog::clickButtonBox(os, QDialogButtonBox::Cancel);
        }    };


    GTUtilsDialog::waitForDialog(os, new ImportAnnotationsToCsvFiller(os, new outerScenario()));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "action_project__export_import_menu_action"
                                                      << "import_annotations_from_CSV_file"));
    GTUtilsProjectTreeView::click(os, "human_T1.fa", Qt::RightButton);
//    3) Use menu {Export/Import->Import annotaions from CSV file}
//    Expected state: "Import annotations from CSV" dialog is appeared

//    4) Choose any CSV file for read
//    Expected state: table in "Results preview" is appeared

//    5) Left click on name of any column
//    Expected state: "Select the role of the column" dialog is appeared

//    6) Check that there is role "Annotation group"
}

GUI_TEST_CLASS_DEFINITION(test_1419) {
    // 1. Open "_common_data/scenarios/msa/big.aln".
    // Expected state : UGENE does not crash.File opened successfully.
    GTLogTracer lt;
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/", "big.aln");
    GTUtilsTaskTreeView::waitTaskFinished(os);
    GTUtilsLog::check(os, lt);
}

GUI_TEST_CLASS_DEFINITION(test_1420) {
//    1. Select {Tools->ALign to reference->Align short reads} from the main menu.
//    Expected state: the "Align sequencing reads" dialog appeared.
//    2. Fill this dialog with:
//        {Alignment method:}	BWA-SW
//        {Reference sequence:}	_common_data/fasta/NC_008253.fna
//        {Result file name:}	somewhere in the temp folder
//        {Short reads:}		_common_data/reads/long_reads.fasta
//        other options: default
//    3. Press the "Start" button.
//    Expected state: after the task's end the "Import SAM file" appeared.
//    4. Set {destination URL} and press the "Import" button.
//    Expected state: the Assembly browser with alignment result opened.

    QDir().mkpath(sandBoxDir + "test_1402");
    AlignShortReadsFiller::BwaSwParameters parameters(testDir + "_common_data/fasta", "NC_008253.fna", testDir + "_common_data/reads", "long_reads.fasta");
    parameters.resultDir = sandBoxDir + "test_1402";
    parameters.resultFileName = "test_1402.sam";

    GTUtilsDialog::waitForDialog(os, new AlignShortReadsFiller(os, &parameters));
    GTUtilsDialog::waitForDialog(os, new ImportBAMFileFiller(os, sandBoxDir + "test_1402/test_1402.ugenedb"));
    GTMenu::clickMenuItemByText(os, GTMenu::showMainMenu(os, MWMENU_TOOLS), QStringList() << ToolsMenu::NGS_MENU << ToolsMenu::NGS_MAP);

    GTUtilsTaskTreeView::waitTaskFinished(os);
    GTGlobals::sleep();
    GTUtilsTaskTreeView::waitTaskFinished(os);

    const int expectedLength = 4938920;
    const int expectedReads = 269;
    const int assemblyLength = GTUtilsAssemblyBrowser::getLength(os, "test_1402 [as] gi|110640213|ref|NC_008253.1|");
    const int assemblyReads = GTUtilsAssemblyBrowser::getReadsCount(os, "test_1402 [as] gi|110640213|ref|NC_008253.1|");
    CHECK_SET_ERR(expectedLength == assemblyLength, QString("An unexpected assembly length: expect  %1, got %2").arg(expectedLength).arg(assemblyLength));
    CHECK_SET_ERR(expectedReads == assemblyReads, QString("An unexpected assembly reads count: expect  %1, got %2").arg(expectedReads).arg(assemblyReads));
}

GUI_TEST_CLASS_DEFINITION(test_1427) {
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/_regression/1427/", "text");
    GTUtilsProjectTreeView::checkItem(os, "text");
}

GUI_TEST_CLASS_DEFINITION(test_1428) {
    //1. Open human_T1.fa.
    GTFileDialog::openFile(os, dataDir + "samples/FASTA/human_T1.fa");

    //2. Select the document and the sequence object itself in the Project View.
    QModelIndex docIdx = GTUtilsProjectTreeView::findIndex(os, "human_T1.fa", QModelIndex());
    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, docIdx));
    GTMouseDriver::click(os);
    QModelIndex seqIdx = GTUtilsProjectTreeView::findIndex(os, "human_T1 (UCSC April 2002 chr7:115977709-117855134)", docIdx);
    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, seqIdx));
    GTKeyboardDriver::keyPress(os, GTKeyboardDriver::key["ctrl"]);
    GTMouseDriver::click(os);
    GTKeyboardDriver::keyRelease(os, GTKeyboardDriver::key["ctrl"]);

    //3. Use context menu {Export/Import->Export Sequences} and export sequence to any file.
    GTUtilsDialog::waitForDialog(os, new ExportSelectedRegionFiller(os, sandBoxDir, "test_1428.fa", GTGlobals::UseMouse));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os,  QStringList() << ACTION_PROJECT__EXPORT_IMPORT_MENU_ACTION << ACTION_EXPORT_SEQUENCE));
    GTMouseDriver::click(os, Qt::RightButton);
    GTUtilsTaskTreeView::waitTaskFinished(os);

    //Expected state: there is only one sequence in the file (it's the same as in human_t1.fa).
    QModelIndex expIdx = GTUtilsProjectTreeView::findIndex(os, "test_1428.fa", QModelIndex());
    int objCount = GTUtilsProjectTreeView::getTreeView(os)->model()->rowCount(expIdx);
    CHECK_SET_ERR(1 == objCount, "Wrong exported sequence count");
}

GUI_TEST_CLASS_DEFINITION(test_1429){
    //    0. Ensure that Bowtie2 Build index tool is not set. Remove it, if it is.
    //    1. Do {main menu -> Tools -> ALign to reference -> Build index}.
    //    Expected state: a "Build index" dialog appeared.
    //    2. Fill the dialog:
    //        {Align short reads method}: Bowtie
    //        {Reference sequence}:       _common_data/fasta/amino_multy.fa
    //        {Index file name}:          set any valid data or use default
    //    Click a "Start" button.

    //    Expected state: there are no errors in the log, index files appeared in the destination folder.
    GTUtilsExternalTools::removeTool(os, "Bowtie 2 build indexer");

    GTLogTracer lt;
    class CheckBowtie2Filler : public Filler {
    public:
        CheckBowtie2Filler(U2OpStatus &os)
            : Filler (os, "BuildIndexFromRefDialog") {}
        virtual void run() {
            QWidget* dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog, "activeModalWidget is NULL");

            QComboBox* methodNamesBox = dialog->findChild<QComboBox*>("methodNamesBox");
            for(int i=0; i < methodNamesBox->count();i++){
                if(methodNamesBox->itemText(i) == "Bowtie"){
                    GTComboBox::setCurrentIndex(os, methodNamesBox, i);
                }
            }

            GTFileDialogUtils *ob = new GTFileDialogUtils(os, testDir + "_common_data/fasta/", "multy_fa.fa");
            GTUtilsDialog::waitForDialog(os, ob);
            GTWidget::click(os, GTWidget::findWidget(os, "addRefButton",dialog));

            QDialogButtonBox* box = qobject_cast<QDialogButtonBox*>(GTWidget::findWidget(os, "buttonBox", dialog));
            CHECK_SET_ERR(box != NULL, "buttonBox is NULL");

            //GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, "Start"));
            QPushButton* okButton = box->button(QDialogButtonBox::Ok);
            CHECK_SET_ERR(okButton !=NULL, "ok button is NULL");
            GTWidget::click(os, okButton);
        }
    };


    GTUtilsDialog::waitForDialog(os, new CheckBowtie2Filler(os));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_TOOLS), QStringList() << ToolsMenu::NGS_MENU << ToolsMenu::NGS_INDEX);
    CHECK_SET_ERR(lt.hasError() == false, "Errors in log!");
}

GUI_TEST_CLASS_DEFINITION(test_1432) {
//    1. Open WD
//    2. Add worker "sequence marker"
//    3. Click button "add" in Parameters
//    Expected state: create marker group dialog appeared
//    4. Add several similar markers
//    Expected state: each new marker has a number after name

    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
    GTUtilsWorkflowDesigner::addAlgorithm(os, "Sequence Marker");

    QToolButton* addButton = qobject_cast<QToolButton*>(GTWidget::findWidget(os, "addButton"));
    CHECK_SET_ERR( addButton != NULL, "AddButton not found!");

    class OkClicker : public Filler {
    public:
        OkClicker(U2OpStatus& _os) : Filler(_os, "EditMarkerGroupDialog"){}
        virtual void run() {
            QWidget *w = QApplication::activeWindow();
            CHECK(NULL != w, );
            QDialogButtonBox *buttonBox = w->findChild<QDialogButtonBox*>(QString::fromUtf8("buttonBox"));
            CHECK(NULL != buttonBox, );
            QPushButton *button = buttonBox->button(QDialogButtonBox::Ok);
            CHECK(NULL != button, );
            GTWidget::click(os, button);
        }
    };
    GTUtilsDialog::waitForDialog(os, new OkClicker(os));
    GTWidget::click(os, addButton);
    GTGlobals::sleep(2000);

    QTableView* groupTable = qobject_cast<QTableView *>(GTWidget::findWidget(os, "markerTable"));
    CHECK_SET_ERR( groupTable != NULL, "MarkerTable not found");
    for (int i = 1; i < 3; i++) {
        GTUtilsDialog::waitForDialog(os, new OkClicker(os));
        GTWidget::click(os, addButton);
        GTGlobals::sleep(2000);
        GTWidget::click(os, groupTable);

        QString name = GTTableView::data(os, groupTable, i, 0);
        CHECK_SET_ERR(name.endsWith(QString::number(i)), "Wrong marker group name");
    }
}

GUI_TEST_CLASS_DEFINITION(test_1434_1) {
    //1. Open data / samples / FASTA / human_T1.fa
    GTFileDialog::openFile(os, dataDir + "samples/FASTA/", "human_T1.fa");

    //2. Open find pattern option panel
    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(200);

    //3. Use these settings :
    //search for : > header
    //             ATTCACCAAAGTTGAA*TGAAGGAAAAAATGCT
    //Algorithm : Regular expression
    //Region : custom region(1 - 1000)

    GTWidget::click(os, GTWidget::findWidget(os, "ArrowHeader_Search algorithm"));

    QComboBox* algorithmBox = qobject_cast<QComboBox *>(GTWidget::findWidget(os, "boxAlgorithm"));
    GTComboBox::setIndexWithText(os, algorithmBox, "Regular expression");

    GTWidget::click(os, GTWidget::findWidget(os, "textPattern"));
    GTKeyboardDriver::keySequence(os, "> header");
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["enter"], GTKeyboardDriver::key["ctrl"]);
    GTKeyboardDriver::keySequence(os, "ATTCACCAAAGTTGAA");
    GTKeyboardDriver::keyClick(os, '8', GTKeyboardDriver::key["shift"]);
    GTKeyboardDriver::keySequence(os, "TGAAGGAAAAAATGCT");

    GTUtilsOptionPanelSequenceView::setRegionType(os, "Custom region");
    GTLineEdit::setText(os, qobject_cast<QLineEdit *>(GTWidget::findWidget(os, "editStart")), "1");
    GTLineEdit::setText(os, qobject_cast<QLineEdit *>(GTWidget::findWidget(os, "editEnd")), "1000");

    //Expected state : 1 pattern is found
    QLabel *resultLabel = qobject_cast<QLabel *>(GTWidget::findWidget(os, "resultLabel"));
    CHECK_SET_ERR(resultLabel->text() == "Results: 1/1", "Unexpected find algorithm result count");
}

GUI_TEST_CLASS_DEFINITION(test_1434_2) {
    //1. Open data / samples / FASTA / human_T1.fa
    GTFileDialog::openFile(os, dataDir + "samples/FASTA/", "human_T1.fa");

    //2. Open find pattern option panel
    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(200);

    //3. Use these settings :
    //	search for:ATTCACCAAAGTTGAA*TGAAGGAAAAAATGCT
    // ; comment
    //Algorithm : Regular expression
    //Region : custom region(1 - 1000)

    GTWidget::click(os, GTWidget::findWidget(os, "ArrowHeader_Search algorithm"));

    QComboBox* algorithmBox = qobject_cast<QComboBox *>(GTWidget::findWidget(os, "boxAlgorithm"));
    GTComboBox::setIndexWithText(os, algorithmBox, "Regular expression");

    GTWidget::click(os, GTWidget::findWidget(os, "textPattern"));
    GTKeyboardDriver::keySequence(os, "ATTCACCAAAGTTGAA");
    GTGlobals::sleep(200);
    GTKeyboardDriver::keyClick(os, '8', GTKeyboardDriver::key["shift"]);
    GTGlobals::sleep(200);
    GTKeyboardDriver::keySequence(os, "TGAAGGAAAAAATGCT");
    GTGlobals::sleep(200);
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["enter"], GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(200);
    GTKeyboardDriver::keyClick(os, ';');
    GTGlobals::sleep(200);
    GTKeyboardDriver::keySequence(os, " comment");

    GTUtilsOptionPanelSequenceView::setRegionType(os, "Custom region");
    GTLineEdit::setText(os, qobject_cast<QLineEdit *>(GTWidget::findWidget(os, "editStart")), "1");
    GTLineEdit::setText(os, qobject_cast<QLineEdit *>(GTWidget::findWidget(os, "editEnd")), "1000");

    //Expected state : 1 pattern is found
    QLabel *resultLabel = qobject_cast<QLabel *>(GTWidget::findWidget(os, "resultLabel"));
    CHECK_SET_ERR(resultLabel->text() == "Results: 1/1", "Unexpected find algorithm result count");
}

GUI_TEST_CLASS_DEFINITION(test_1446){
//    1) Open data/samples/CLUSTALW/COI.aln
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW/COI.aln");
//    2) Use context menu for COI.aln in project tree view {Export/Import->Export nucleic alignment to amino}
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os,  QStringList() << "action_project__export_import_menu_action"
                                                      << "action_project__export_to_amino_action"));
    GTUtilsDialog::waitForDialog(os, new ExportMSA2MSADialogFiller(os, -1, sandBoxDir + "test_1446.aln"));
    GTUtilsProjectTreeView::click(os, "COI.aln", Qt::RightButton);
    GTUtilsTaskTreeView::waitTaskFinished(os);

    GTUtilsProjectTreeView::click(os, "COI.aln");
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["delete"]);
    GTGlobals::sleep();

//    Expected state: none of sequences starts from (translated), only sequence names have (translated) in the end
    QStringList names = GTUtilsMSAEditorSequenceArea::getNameList(os);
    QString first = names[0];
    CHECK_SET_ERR(first.endsWith("(translated)"), "unexpected name end: " + first);
    foreach (QString name, names) {
        CHECK_SET_ERR(!name.startsWith("(translated)"), "unexpected name start: " + name);
    }

}

GUI_TEST_CLASS_DEFINITION(test_1457){
//    1. Open "_common_data/ugenedb/example-alignment.ugenedb".
//    Expected state: assymbly viewer had opened.
    GTFileDialog::openFile(os, testDir + "_common_data/ugenedb/example-alignment.ugenedb");
//    2. Find navigation tool on the toolbar.
//    Expected state: navigation tool is disabled.
    QToolBar* mwtoolbar_activemdi = GTToolbar::getToolbar(os, MWTOOLBAR_ACTIVEMDI);
    QWidget* go_to_pos_line_edit = GTWidget::findWidget(os, "go_to_pos_line_edit", mwtoolbar_activemdi);
    QWidget* go = GTWidget::findWidget(os, "Go!", mwtoolbar_activemdi);
    CHECK_SET_ERR(!go_to_pos_line_edit->isEnabled(), "go_to_pos_line_edit on toolbar is enabled");
    CHECK_SET_ERR(!go->isEnabled(), "go button on toolbar is enabled");
//    3. Open navigation tab on the options panel.
    GTWidget::click(os, GTWidget::findWidget(os, "OP_ASS_NAVIGATION"));
//    Expected state: navigation tool on the options panel is disabled.
    QWidget* OP_OPTIONS_WIDGET = GTWidget::findWidget(os, "OP_OPTIONS_WIDGET");
    QWidget* go_to_pos_line_edit_op = GTWidget::findWidget(os, "go_to_pos_line_edit", OP_OPTIONS_WIDGET);
    QWidget* go_op = GTWidget::findWidget(os, "Go!", OP_OPTIONS_WIDGET);
    CHECK_SET_ERR(!go_to_pos_line_edit_op->isEnabled(), "go_to_pos_line_edit on option panel is enabled");
    CHECK_SET_ERR(!go_op->isEnabled(), "go button on option panel is enabled");
//    4. Zoom to any location.
    QWidget* zoomInButton = GTToolbar::getWidgetForActionTooltip(os, mwtoolbar_activemdi, "Zoom in");
    GTWidget::click(os, zoomInButton);
//    Expected state: navigation was enabled both on the toolbar and on the options panel.
    CHECK_SET_ERR(go_to_pos_line_edit->isEnabled(), "go_to_pos_line_edit on toolbar is not enabled");
    CHECK_SET_ERR(go->isEnabled(), "go button on toolbar is not enabled");

    CHECK_SET_ERR(go_to_pos_line_edit_op->isEnabled(), "go_to_pos_line_edit on option panel is not enabled");
    CHECK_SET_ERR(go_op->isEnabled(), "go button on option panel is not enabled");
}

GUI_TEST_CLASS_DEFINITION(test_1458){
    //1. Open document "../Samples/ACE/BL060C3.ace"
    GTUtilsDialog::waitForDialog(os, new DocumentProviderSelectorDialogFiller(os, DocumentProviderSelectorDialogFiller::AlignmentEditor));
    GTFileDialog::openFile(os, dataDir + "samples/ACE/BL060C3.ace");

    //2. Right click on the document in project tab
    //Excepted state: popup menu has been appeared
    //3. Select "Export document"
    //4. Check, that for all output file formats export work correctly
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "Export document"));
    GTUtilsDialog::waitForDialog(os, new ExportDocumentDialogFiller(os, sandBoxDir, "test_1458.fa", ExportDocumentDialogFiller::FASTA, false, true));
    GTUtilsProjectTreeView::click(os, "BL060C3.ace", Qt::RightButton);
}

GUI_TEST_CLASS_DEFINITION(test_1435) {
//    1) Open WD
//    2) Click Create element with command line tool
//    3) input name test
//    4) input data in1 and in2 of FASTA
//    5) output data out1 and out2 of FASTA
//    6) Execution string any
//    Expected state created element with two input and two output ports

    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    CreateElementWithCommandLineToolFiller::ElementWithCommandLineSettings settings;
    settings.elementName = "Element_1435";

    QList<CreateElementWithCommandLineToolFiller::InOutData> input;
    CreateElementWithCommandLineToolFiller::InOutDataType inOutDataType;
    inOutDataType.first = CreateElementWithCommandLineToolFiller::Sequence;
    inOutDataType.second = "FASTA";

    input << CreateElementWithCommandLineToolFiller::InOutData("in1",
                                                               inOutDataType);
    input << CreateElementWithCommandLineToolFiller::InOutData("in2",
                                                               inOutDataType);
    settings.input = input;

    QList<CreateElementWithCommandLineToolFiller::InOutData> output;
    output << CreateElementWithCommandLineToolFiller::InOutData("out1",
                                                                inOutDataType);
    output << CreateElementWithCommandLineToolFiller::InOutData("out2",
                                                                inOutDataType);
    settings.output = output;

    settings.executionString = "./ugenem $in1 $in2 $out1 $out2";

    GTUtilsDialog::waitForDialog(os, new CreateElementWithCommandLineToolFiller(os, settings));
    QAbstractButton *createElement = GTAction::button(os, "createElementWithCommandLineTool");
    GTWidget::click(os, createElement);

    GTGlobals::sleep();

    GTUtilsWorkflowDesigner::click(os, "Element_1435");
    WorkflowProcessItem* element = GTUtilsWorkflowDesigner::getWorker(os, "Element_1435");
    CHECK_SET_ERR(element != NULL, "Worker not found");
    int portCount = GTUtilsWorkflowDesigner::getPorts(os, element).size();
    CHECK_SET_ERR(portCount == 3,
                  QString("Port number is wrong. Expected: 3. Current %1").arg(portCount));

}

GUI_TEST_CLASS_DEFINITION(test_1439) {
//    1. Open _common_data\scenarios\regression\1439\NC_000964_multi_region.fa in MSA Editor.
//    2. Do {Align->Align sequences to profile with MUSCLE...} in context menu, and use NC_000964.fa as alignment profile.
//    3. Select "NC_000964.fa" as profile.
//    Expected state: there is no error with following message
//                    "Task {MUSCLE align 'NC_000964.fa' by profile 'NC_000964_multi_region.fa'} finished with error:
//                    Subtask {MUSCLE add to profile 'NC_000964_multi_region.fa'} is failed:
//                    Subtask {MUSCLE alignment} is failed:
//                    Internal MUSCLE error: Internal error MSA::ExpandCache, ColCount changed"
    GTLogTracer l;

    GTUtilsDialog::waitForDialog(os, new SequenceReadingModeSelectorDialogFiller(os,
                                                                                 SequenceReadingModeSelectorDialogFiller::Join));
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/_regression/1439", "NC_000964_multi_region.fa");

    GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, testDir + "_common_data/scenarios/_regression/1439", "NC_000964.fa"));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << MSAE_MENU_ALIGN << "Align sequences to profile with MUSCLE", GTGlobals::UseMouse));
    GTWidget::click(os, GTUtilsMdi::activeWindow(os), Qt::RightButton);
    GTUtilsTaskTreeView::waitTaskFinished(os);
    GTGlobals::sleep(15000);

    CHECK_SET_ERR(l.hasError(), "There is no error in the log");
    CHECK_SET_ERR(l.getError().contains("Can't align sequence longer 100000"), "Wrong error in the log");
}

GUI_TEST_CLASS_DEFINITION(test_1442_1) {
//    1. Open file "data/position_weight_matrix/JASPAR/fungi/MA0265.1.pfm"
//    Expected state: Opened only window with position frequency matrix and it's Logo.
//    In Project View not added any items.

    GTFileDialog::openFile(os, dataDir + "position_weight_matrix/JASPAR/fungi", "MA0265.1.pfm");

    const int projectViewItemsCount = GTUtilsProjectTreeView::getTreeView(os)->model()->rowCount();
    CHECK_SET_ERR(0 == projectViewItemsCount, "Unexpected project view items count");

    GTWidget::findWidget(os, "Matrix viewer"); // check that matrix view is presented

    QWidget *logoWidget = GTWidget::findWidget(os, "logoWidget", NULL);
    CHECK_SET_ERR(logoWidget->isVisible(), "Logo widget is unexpectedly invisible");
}

GUI_TEST_CLASS_DEFINITION(test_1442_2) {
    // 1. Open file "data/position_weight_matrix/UniPROBE/Cell08/Alx3_3418.2.pwm"
    // Expected state : Opened only window with position weight matrix.
    // In Project View not added any items.
    GTFileDialog::openFile(os, dataDir + "/position_weight_matrix/UniPROBE/Cell08/", "Alx3_3418.2.pwm");

    const int projectViewItemsCount = GTUtilsProjectTreeView::getTreeView(os)->model()->rowCount();
    CHECK_SET_ERR(0 == projectViewItemsCount, "Unexpected project view items count");

    GTWidget::findWidget(os, "Matrix viewer"); // check that matrix view is presented

    QWidget *logoWidget = GTWidget::findWidget(os, "logoWidget", NULL);
    CHECK_SET_ERR(!logoWidget->isVisible(), "Logo widget is unexpectedly visible");
}

GUI_TEST_CLASS_DEFINITION(test_1445) {
/*  1. Open "data/samples/CLUSTALW/COI.aln"
    2. Choose last sequence (i.e. in bottom) with mouse in sequences area
    3. Choose { Edit -> Remove current sequence } in context menu
    Expected state: UGENE doesn't crash
*/
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW/", "COI.aln");

    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(-5, 17), QPoint(-4, 17));
    int numSelectedSequences = GTUtilsMSAEditorSequenceArea::getSelectedSequencesNum(os);
    CHECK_SET_ERR(numSelectedSequences == 1, "There is no selection in MSA, but expected");

    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << MSAE_MENU_EDIT << "Remove current sequence", GTGlobals::UseMouse));
    GTMouseDriver::click(os, Qt::RightButton);
}

GUI_TEST_CLASS_DEFINITION(test_1461_1) {
//    1. Open "_common_data/fasta/fa1.fa".
//    Expected state: sequence viewer had opened.
    GTFileDialog::openFile(os, testDir + "_common_data/fasta/fa1.fa");

//    2. Click on toolbar "Find pattern [Smith-Waterman]".
//    Expected state: "Smith-Waterman Search" dialog is opened.
//    3. Check "Scoring matrix" field
//    Expected state: "Scoring matrix" field not contain "rna" value.
    class Scenario : public CustomScenario {
        void run(U2OpStatus &os) {
            QComboBox *comboMatrix = GTWidget::findExactWidget<QComboBox *>(os, "comboMatrix", QApplication::activeModalWidget());
            CHECK_SET_ERR(NULL != comboMatrix, "Matrix combobox is NULL");
            U2OpStatusImpl innerOs;
            GTComboBox::setIndexWithText(innerOs, comboMatrix, "rna", false);
            CHECK_SET_ERR(innerOs.hasError(), "'rna' matrix unexpectedly presents in the matrix list");
            GTUtilsDialog::clickButtonBox(os, QDialogButtonBox::Cancel);
        }
    };

    GTUtilsDialog::waitForDialog(os, new SmithWatermanDialogFiller(os, new Scenario));
    GTWidget::click(os, GTToolbar::getWidgetForActionTooltip(os, GTToolbar::getToolbar(os, MWTOOLBAR_ACTIVEMDI), "Find pattern [Smith-Waterman]"));
    GTGlobals::sleep();
}

GUI_TEST_CLASS_DEFINITION(test_1461_2) {
//    1. Open "_common_data/fasta/RNA_1_seq.fa".
//    Expected state: sequence viewer had opened.
    GTFileDialog::openFile(os, testDir + "_common_data/fasta/RNA_1_seq.fa");

//    2. Click on toolbar "Find pattern [Smith-Waterman]".
//    Expected state: "Smith-Waterman Search" dialog is opened.
//    3. Check "Scoring matrix" field
//    Expected state: "Scoring matrix" field contain only "rna" value.
    class Scenario : public CustomScenario {
        void run(U2OpStatus &os) {
            QComboBox *comboMatrix = GTWidget::findExactWidget<QComboBox *>(os, "comboMatrix", QApplication::activeModalWidget());
            CHECK_SET_ERR(NULL != comboMatrix, "Matrix combobox is NULL");
            GTComboBox::setIndexWithText(os, comboMatrix, "rna");
            CHECK_SET_ERR(1 == comboMatrix->count(), "There are several unexpected matrices");
            GTUtilsDialog::clickButtonBox(os, QDialogButtonBox::Cancel);
        }
    };

    GTUtilsDialog::waitForDialog(os, new SmithWatermanDialogFiller(os, new Scenario));
    GTWidget::click(os, GTToolbar::getWidgetForActionTooltip(os, GTToolbar::getToolbar(os, MWTOOLBAR_ACTIVEMDI), "Find pattern [Smith-Waterman]"));
    GTGlobals::sleep();
}

GUI_TEST_CLASS_DEFINITION(test_1463) {
    //1. Open "human_T1.fa".
    GTFileDialog::openFile(os, dataDir + "samples/FASTA/human_T1.fa");

    //2. Click the "Find restriction sites" button on the toolbar.
    //Expected state: the "Find restriction sites" dialog had appeared.
    //3. Click the "OK" button.
    //Expected state: new auto annotations had been added.
    GTUtilsDialog::waitForDialog(os, new FindEnzymesDialogFiller(os, QStringList() << "BamHI" << "XmaI" << "DraI" << "ClaI"));
    GTWidget::click(os, GTWidget::findWidget(os, "Find restriction sites_widget"));
    GTUtilsTaskTreeView::waitTaskFinished(os);

    //4. Click the "Show circular view" button on the Sequence Viewer's toolbar.
    //Expected state: additional widget with circular view had opened.
    GTWidget::click(os, GTWidget::findWidget(os, "CircularViewAction"));

    //5. Look at the "Restrictions Sites Map" widget to the right of the circular view.
    QTreeWidget *tree = dynamic_cast<QTreeWidget*>(GTWidget::findWidget(os, "restrictionMapTreeWidget"));

    //Expected state: enzymes in this widget are ordered alphabetically.
    QString item1 = tree->topLevelItem(0)->text(0);
    QString item2 = tree->topLevelItem(1)->text(0);
    QString item3 = tree->topLevelItem(2)->text(0);
    QString item4 = tree->topLevelItem(3)->text(0);
    CHECK_SET_ERR((item1 < item2) && (item2 < item3) && (item3 < item4), "Wrong order");
}

GUI_TEST_CLASS_DEFINITION(test_1475) {
    GTUtilsDialog::waitForDialog(os, new SelectDocumentFormatDialogFiller(os));
    GTFileDialog::openFile(os, testDir + "_common_data/raw_sequence/", "NC_000117.txt");
}

GUI_TEST_CLASS_DEFINITION(test_1483){
//    1. Open "data/COI.aln" in MSA view
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW/", "COI.aln");
//    2. Press tool button "Enable collapsing"
    GTWidget::click(os, GTToolbar::getWidgetForActionName(os, GTToolbar::getToolbar(os, "mwtoolbar_activemdi"), "Enable collapsing"));
//    3. Start selection in sequences name list and then go for the lower boundary of the list
    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(-5, 5), QPoint(-4, 20));
//    Expected state: Ugene doesn't crashes
}

GUI_TEST_CLASS_DEFINITION(test_1491) {
    //1. Open UGENE
    //2. Press File->Open
    //3. Select more than three sequences (for instance all the sequences from samples/Genbank)
    class Scenario : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            GTGlobals::sleep();
            //4. Select "Join sequences..." mode
            GTRadioButton::click(os, dynamic_cast<QRadioButton*>(GTWidget::findWidget(os, "join2alignmentMode", QApplication::activeModalWidget())));

            //5. Select a sequence
            QListWidget *list = dynamic_cast<QListWidget*>(GTWidget::findWidget(os, "listDocuments", QApplication::activeModalWidget()));
            GTListWidget::click(os, list, "3. murine.gb");

            //6. Press "Up" or "Down" arrow.
            GTWidget::click(os, GTWidget::findWidget(os, "upperButton", QApplication::activeModalWidget()));

            //Expected state:
            //    1) the sequence goes up or down correspondingly
            QListWidgetItem *murine = list->item(1);
            CHECK_SET_ERR(murine->text() == "2. murine.gb", "Wrong order file");

            //    2) it is still selected
            QList<QListWidgetItem*> selection = list->selectedItems();
            CHECK_SET_ERR(selection.contains(murine), "Wrong selection");
            CHECK_SET_ERR(1 == selection.size(), "Wrong selection size");

            GTUtilsDialog::clickButtonBox(os, QApplication::activeModalWidget(), QDialogButtonBox::Cancel);
        }
    };
    GTUtilsDialog::waitForDialog(os, new GTSequenceReadingModeDialogUtils(os, new Scenario()));
    GTFileDialog::openFileList(os, dataDir + "samples/Genbank", QStringList() << "PBR322.gb" << "sars.gb" << "murine.gb" << "NC_014267.1.gb");
}

GUI_TEST_CLASS_DEFINITION(test_1497) {
    GTKeyboardDriver::keyClick(os, '3', GTKeyboardDriver::key["alt"]);
    uiLog.error("log should contain some text for test 1497");

    // 1. Create or open some scheme in WD.
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
    GTUtilsWorkflowDesigner::addSample(os, "Align sequences with MUSCLE");

    // 2. Select a few items(elements, links) in the scheme.
    GTKeyboardDriver::keyPress(os, GTKeyboardDriver::key["ctrl"]);

    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Read alignment"));
    GTMouseDriver::click(os);

    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Align with MUSCLE"));
    GTMouseDriver::click(os);

    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Write alignment"));
    GTMouseDriver::click(os);

    GTKeyboardDriver::keyRelease(os, GTKeyboardDriver::key["ctrl"]);

    // 3. Try to copy something from the log widget to the clipboard by hotkey(Ctrl + C).
    // Expected state : you've got in the clipboard selected text from the log widget.
    GTGlobals::sleep();
    uiLog.error("log must contain some text");
    QWidget *logView = GTWidget::findWidget(os, "dock_log_view");
    GTWidget::click(os, logView);

    GTKeyboardDriver::keyClick(os, 'a', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(500);
    GTKeyboardDriver::keyClick(os, 'c', GTKeyboardDriver::key["ctrl"]);

    const QString clipboardContent = GTClipboard::text(os);

    QPlainTextEdit *logTextEdit = logView->findChild<QPlainTextEdit *>();
    CHECK_SET_ERR(NULL != logTextEdit, "Log view text edit field is not found")

    const QString logTextEditContent = logTextEdit->toPlainText();
    CHECK_SET_ERR(logTextEditContent == clipboardContent,
        QString("Clipboard content differs from what is in the log widget. Clipboard: %1, log widget: %2").arg(clipboardContent).arg(logTextEditContent));
}

GUI_TEST_CLASS_DEFINITION(test_1499) {
    class CustomBuildTreeDialogFiller : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            QWidget *dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog, "activeModalWidget is NULL");
            GTUtilsDialog::waitForDialogWhichMayRunOrNot(os, new LicenseAgreemntDialogFiller(os));

            QComboBox *algorithmBox = qobject_cast<QComboBox *>(GTWidget::findWidget(os, "algorithmBox", dialog));
            GTComboBox::setIndexWithText(os, algorithmBox, "MrBayes");

            QLineEdit *saveLineEdit = qobject_cast<QLineEdit *>(GTWidget::findWidget(os, "fileNameEdit", dialog));
            GTLineEdit::setText(os, saveLineEdit, sandBoxDir + "1499.nwk");

            QDialogButtonBox *box = qobject_cast<QDialogButtonBox *>(GTWidget::findWidget(os, "buttonBox", dialog));
            QPushButton* button = box->button(QDialogButtonBox::Ok);
            CHECK_SET_ERR(button != NULL, "Ok button is NULL");
            GTWidget::click(os, button);
        }
    };

    GTLogTracer lt;
    // 1) Open "samples/CLUSTALW/COI.aln".
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW/", "COI.aln");

    // 2) Click the "Build Tree" button on the toolbar.
    // 3) Choose MrBayes tree building method.
    // 4) Choose "Display tree with alignment editor".
    // 5) Build.
    GTUtilsDialog::waitForDialog(os, new BuildTreeDialogFiller(os, new CustomBuildTreeDialogFiller()));
    QAbstractButton *tree = GTAction::button(os, "Build Tree");
    GTWidget::click(os, tree);
    GTUtilsTaskTreeView::waitTaskFinished(os);

    // Expected: the tree appears synchronized with the MSA Editor.
    const QStringList msaSequences0 = GTUtilsMSAEditorSequenceArea::getNameList(os);

    // 6) Click the "Sort alignment by tree" button on the Tree View toolbar.
    // = > UGENE does not crash.
    GTMouseDriver::moveTo(os, GTUtilsMsaEditor::getSequenceNameRect(os, "Zychia_baranovi").center());
    GTMouseDriver::click(os);
    GTGlobals::sleep(1000);
    GTMouseDriver::press(os);
    GTMouseDriver::moveTo(os, GTUtilsMsaEditor::getSequenceNameRect(os, "Montana_montana").center());
    GTMouseDriver::release(os);

    const QStringList msaSequences1 = GTUtilsMSAEditorSequenceArea::getNameList(os);
    CHECK_SET_ERR(msaSequences1 != msaSequences0, "MSA is not changed");

    GTWidget::click(os, GTAction::button(os, "Sort Alignment"));

    const QStringList msaSequences2 = GTUtilsMSAEditorSequenceArea::getNameList(os);
    CHECK_SET_ERR(msaSequences0 == msaSequences2, "MSA is not synchronized with tree");

    GTUtilsLog::check(os, lt);
}

GUI_TEST_CLASS_DEFINITION(test_1506){
//    1) Open "samples/CLUSTALW/COI.aln".
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW/COI.aln");
//    2) Click the "Build Tree" button on the toolbar.
    GTUtilsDialog::waitForDialog(os, new BuildTreeDialogFiller(os, testDir + "_common_data/scenarios/sandbox/1548.nwk", 0, 0, true));
    QAbstractButton *tree= GTAction::button(os,"Build Tree");
    GTWidget::click(os, tree);
    GTGlobals::sleep();
//    3) Choose "Display tree with alignment editor".
//    4) Build.
//    Expected: the tree appears synchronized with the MSA Editor. Clustering blue line is shown.
//    5) Click the "Layout" button on the Tree View toolbar and choose the circular or unrooted layout.
    QComboBox* layoutCombo = GTWidget::findExactWidget<QComboBox*>(os, "layoutCombo");
    GTComboBox::setIndexWithText(os, layoutCombo, "Circular");
//    6) Zoom in the tree using mouse scroll.
    GTWidget::click(os, GTWidget::findWidget(os, "treeView"));
    for(int i = 0; i<10; i++){
        GTMouseDriver::scroll(os, 1);
        GTGlobals::sleep(300);
    }
//    Expected: UGENE does not crash.

}

GUI_TEST_CLASS_DEFINITION(test_1508) {
    //1. Open COI2.fa as an alignment
    GTUtilsDialog::waitForDialog(os, new SequenceReadingModeSelectorDialogFiller(os, SequenceReadingModeSelectorDialogFiller::Join));
    GTFileDialog::openFile(os, testDir+"_common_data/fasta/", "COI2.fa");

    //2. {MSA Editor context menu} -> Align -> Align with MUSCLE
    //3. Choose the mode "Refine only"
    GTUtilsDialog::waitForDialog(os, new MuscleDialogFiller(os, MuscleDialogFiller::Refine));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << MSAE_MENU_ALIGN << "Align with muscle", GTGlobals::UseMouse));
    GTWidget::click(os, GTUtilsMdi::activeWindow(os), Qt::RightButton);
    GTGlobals::sleep();
}

GUI_TEST_CLASS_DEFINITION(test_1510) {
//    1. Open workflow sample "Call variants with SAMtools"
//    2. Substitute "Read assembly (BAM/SAM)" element with "Read Sequence" element
//    3. Set any input sequences for "Read sequence" elements.
//    4. Select "Call Variants" element with mouse
//    5. Set "Source URL (by Read Sequence 1)" as "Source URL" in "Input data" area in workflow editor
//    6. Run the scheme
//    Expected state: Error notification appears, UGENE doesn't crash
    GTLogTracer l;

    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
    GTUtilsWorkflowDesigner::addSample(os, "Call variants");

    GTUtilsWorkflowDesigner::removeItem(os, "Read Assembly (BAM/SAM)");
    GTGlobals::sleep(500);
    WorkflowProcessItem* toBam = GTUtilsWorkflowDesigner::getWorker(os, "To BAM");
    CHECK_SET_ERR(toBam != NULL, "\'To BAM\' element not found");

    GTUtilsWorkflowDesigner::addAlgorithm(os, "Read Sequence");
    GTGlobals::sleep(500);

    WorkflowProcessItem* readSeq = GTUtilsWorkflowDesigner::getWorker(os, "Read Sequence 1");
    CHECK_SET_ERR(readSeq != NULL, "\'Read Sequence 1\' element not found");
    GTGlobals::sleep(500);
    GTUtilsWorkflowDesigner::connect(os, readSeq, toBam);

    GTUtilsWorkflowDesigner::click(os, "Read Sequence");
    GTUtilsWorkflowDesigner::setDatasetInputFile(os, dataDir + "/samples/FASTA/", "human_T1.fa");
    GTGlobals::sleep();
    GTUtilsWorkflowDesigner::click(os, "Read Sequence 1");
    GTUtilsWorkflowDesigner::setDatasetInputFile(os, dataDir + "/samples/FASTA/", "human_T1.fa");
    GTGlobals::sleep();

    GTUtilsWorkflowDesigner::click(os, "Call Variants");
    GTGlobals::sleep(500);

    QTableWidget* w = GTUtilsWorkflowDesigner::getInputPortsTable(os, 0);
    GTUtilsWorkflowDesigner::setTableValue(os, "Source URL", "Source URL (by Read Sequence 1)", GTUtilsWorkflowDesigner::comboValue, w);

    GTUtilsWorkflowDesigner::runWorkflow(os);
    GTGlobals::sleep();

    CHECK_SET_ERR(l.hasError(), "No errors in the log");
}

GUI_TEST_CLASS_DEFINITION(test_1511) {
/*
 * 1. Open "data/COI.aln" in MSA view
 * 2. Select some region in Sequence Area
 * 3. Press Esc key
 * Expected state: selection is removed
 * 4. Select some sequences in Name Area
 * 5. Press Esc key
 * Expected state: selection is removed
*/
    GTFileDialog::openFile(os, dataDir+"samples/CLUSTALW/", "COI.aln");
    GTGlobals::sleep();
    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(2,2), QPoint(15,6));
    int numSelectedSequences = GTUtilsMSAEditorSequenceArea::getSelectedSequencesNum(os);
    CHECK_SET_ERR(numSelectedSequences == 5, "There is no selection in MSA, but expected (check #1)");
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["esc"]);
    GTGlobals::sleep(200);
    numSelectedSequences = GTUtilsMSAEditorSequenceArea::getSelectedSequencesNum(os);
    CHECK_SET_ERR(numSelectedSequences == 0, "There is selection in MSA, but not expected (check #1)");

    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(-5,2), QPoint(-5,6));
    numSelectedSequences = GTUtilsMSAEditorSequenceArea::getSelectedSequencesNum(os);
    CHECK_SET_ERR(numSelectedSequences == 5, "There is no selection in MSA, but expected (check #2)");
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["esc"]);
    GTGlobals::sleep(200);
    numSelectedSequences = GTUtilsMSAEditorSequenceArea::getSelectedSequencesNum(os);
    CHECK_SET_ERR(numSelectedSequences == 0, "There is selection in MSA, but not expected(check #2)");
}

GUI_TEST_CLASS_DEFINITION(test_1527) {
    //1. Open COI2.aln as an alignment
    GTFileDialog::openFile(os, dataDir+"samples/CLUSTALW/", "COI.aln");
    GTGlobals::sleep();

    //2. {MSA Editor context menu} -> Align -> Align profile to profile with MUSCLE
    //3. Select empty "test.aln" in the profile browsing dialog.
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << MSAE_MENU_ALIGN << "Align profile to profile with MUSCLE", GTGlobals::UseMouse));
    GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, testDir + "_common_data/regression/1527/", "test.aln"));
    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));

}

GUI_TEST_CLASS_DEFINITION(test_1527_1) {
    //1. Open COI2.aln as an alignment
    GTFileDialog::openFile(os, dataDir+"samples/CLUSTALW/", "COI.aln");
    GTGlobals::sleep();

    //2. {MSA Editor context menu} -> Align -> Align sequences to profile with MUSCLE
    //3. Select empty "test.aln" in the profile browsing dialog.
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << MSAE_MENU_ALIGN << "Align sequences to profile with MUSCLE", GTGlobals::UseMouse));
    GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, testDir + "_common_data/regression/1527/", "test.aln"));
    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
}

GUI_TEST_CLASS_DEFINITION(test_1529) {
    // 1. Open "data/samples/CLUSTALW/COI.aln".
    QFile sourceFile(dataDir + "samples/CLUSTALW/COI.aln");
    sourceFile.copy(sandBoxDir + "COI.aln");

    GTFileDialog::openFile(os, sandBoxDir, "COI.aln");

    // 2. Use context menu{ Export->Amino translation... }.
    // Expected state : "Export Amino Translation" dialog has appeared.
    // 3. Press the "Export" button.
    GTUtilsMSAEditorSequenceArea::moveTo(os, QPoint(10, 10));
    GTUtilsDialog::waitForDialog(os, new ExportMSA2MSADialogFiller(os));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << MSAE_MENU_EXPORT << "amino_translation_of_alignment_rows"));
    GTMouseDriver::click(os, Qt::RightButton);

    GTGlobals::sleep();

    // Expected state : A new file with MSA was created, added to the project.The MSA object name is "COI_transl.aln".
    const QModelIndex docIndex = GTUtilsProjectTreeView::findIndecies(os, "COI_transl.aln").first();
    const int objCount = docIndex.model()->rowCount(docIndex);
    CHECK_SET_ERR(1 == objCount, QString("Unexpected child object count in the project. Expected %1, found %2").arg(1).arg(objCount));
}

GUI_TEST_CLASS_DEFINITION(test_1531) {
    // 1. Open file "data/samples/CLUSTALW/COI.aln"
        //1. Open "samples/CLUSTALW/COI.aln".
        //2. Activate the "Statistics" options panel.
        //3. Click "Show distances column"
        //Expected: the hint about reference abcense is shown.
        //4. Right click "Phaneroptera_falcata" -> Set this sequence as reference.
        //Expected: the hint about reference abcense is not shown.
        //5. Activate the "General" options panel.
        //6. Click "Clear".
        //7. Activate the "Statistics" options panel.
        //Expected: the hint about reference abcense is shown.
    GTFileDialog::openFile(os, dataDir+"samples/CLUSTALW/", "COI.aln");

    GTUtilsMSAEditorSequenceArea::selectArea( os, QPoint(0, 17), QPoint(0, 17));

    GTUtilsOptionPanelMsa::toggleTab(os, GTUtilsOptionPanelMsa::Statistics);
    GTWidget::click(os, GTWidget::findWidget(os, "addSeq"));
    QCheckBox* showDistancesColumnCheck = qobject_cast<QCheckBox*>(GTWidget::findWidget(os, "showDistancesColumnCheck"));
    GTCheckBox::setChecked(os, showDistancesColumnCheck, true);

    QWidget* warningMessage = GTWidget::findWidget(os, "refSeqWarning");
    CHECK_SET_ERR(warningMessage->isHidden(), QString("Reference sequence warning must be hidden"));

    GTUtilsOptionPanelMsa::toggleTab(os, GTUtilsOptionPanelMsa::General);
    GTWidget::click(os, GTWidget::findWidget(os, "deleteSeq"));
    GTUtilsOptionPanelMsa::toggleTab(os, GTUtilsOptionPanelMsa::Statistics);
    warningMessage = GTWidget::findWidget(os, "refSeqWarning");
    CHECK_SET_ERR(warningMessage->isVisible(), QString("Reference sequence warning must be visible"));
}

GUI_TEST_CLASS_DEFINITION(test_1548) {
    // 1. Open file "data/samples/CLUSTALW/COI.aln"
    GTFileDialog::openFile(os, dataDir+"samples/CLUSTALW/", "COI.aln");

    // 2. Build tree for the alignment
    GTUtilsDialog::waitForDialog(os, new BuildTreeDialogFiller(os, testDir + "_common_data/scenarios/sandbox/1548.nwk", 0, 0, true));
    QAbstractButton *tree= GTAction::button(os,"Build Tree");
    GTWidget::click(os, tree);
    GTGlobals::sleep(500);

    //3. Ensure that the "Sort alignment by tree" button on the tree view toolbar is disabled.
    QAction *sortAction = GTAction::findAction(os, "Sort Alignment");
    CHECK_SET_ERR(NULL != sortAction, "'Sort alignment by tree' was not found");
    CHECK_SET_ERR(!sortAction->isEnabled(), "'Sort alignment by tree' is unexpectedly enabled");
}

GUI_TEST_CLASS_DEFINITION(test_1551) {
//    (Reproduced on MAC OS X)
//    1. Open COI.aln
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");

//    2. Select any sequence.
    GTUtilsMsaEditor::clickSequenceName(os, "Phaneroptera_falcata");

//    3. Call context menu in the name list widget.
//    4. Move the mouse cursor away from context menu and press the left mouse button.
//    5. Press right mouse button on the same place.
//    Expected state: there is no rename sequence dialog appeared.
//    GTUtilsDialog::waitForDialogWhichMustNotBeRunned(os, new MessageBoxDialogFiller(os));
    class Scenario : public CustomScenario {
        void run(U2OpStatus &os) {
            GTMouseDriver::moveTo(os, GTMouseDriver::getMousePosition() - QPoint(5, 0));
            GTMouseDriver::click(os);
            QWidget *contextMenu = QApplication::activePopupWidget();
            CHECK_SET_ERR(NULL == contextMenu, "There is an unexpected context menu");
        }
    };

    GTUtilsDialog::waitForDialog(os, new PopupChecker(os, new Scenario));
    GTWidget::click(os, GTUtilsMsaEditor::getNameListArea(os), Qt::RightButton);

    GTUtilsDialog::waitForDialogWhichMayRunOrNot(os, new PopupChecker(os, new Scenario));
    GTUtilsDialog::waitForDialogWhichMustNotBeRunned(os, new RenameSequenceFiller(os, "test_1551"));
    GTMouseDriver::click(os, Qt::RightButton);
    GTGlobals::sleep();
}

GUI_TEST_CLASS_DEFINITION(test_1554) {
//    1. Open {data/samples/CLUSTALW/COI.aln}.
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");

//    2. Click a "Build Tree" button on the toolbar.
//    Expected state: a "Build Philogenetic Tree" dialog appears.
//    3. Set the out file location and click a "Build" button.
//    Expected state: a tree view synchronized with msa appears.
    QDir().mkpath(sandBoxDir + "test_1554");
    GTUtilsDialog::waitForDialog(os, new BuildTreeDialogFiller(os, sandBoxDir + "test_1554/COI.nwk", 0, 0, true));
    GTWidget::click(os, GTToolbar::getWidgetForActionName(os, GTToolbar::getToolbar(os, MWTOOLBAR_ACTIVEMDI), "Build Tree"));
    GTUtilsTaskTreeView::waitTaskFinished(os);

//    4. Call a context menu of the tree view by the right mouse button clicking.
//    Expected state: Tree view contect menu appears.
    GTWidget::click(os, GTUtilsMsaEditor::getTreeView(os), Qt::RightButton);
    QWidget *contextMenu = QApplication::activePopupWidget();
    CHECK_SET_ERR(NULL != contextMenu, "There is no expected context menu");

//    5. Click somewhere on the tree view to close menu.
//    Expected state: The context menu closes, there are not any another menus.
    GTMouseDriver::moveTo(os, GTMouseDriver::getMousePosition() - QPoint(5, 0));
    GTMouseDriver::click(os, Qt::LeftButton);
    contextMenu = QApplication::activePopupWidget();
    CHECK_SET_ERR(NULL == contextMenu, "There is an unexpected context menu");
}

GUI_TEST_CLASS_DEFINITION( test_1567 ){
//    1. Start WD.
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
//    2. Open the "RNA-seq analysis with Tuxedo tools" sample.


    class customWizard : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            GTGlobals::sleep();
            QWidget* dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog, "activeModalWidget is NULL");
            QWizard* wizard = qobject_cast<QWizard*>(dialog);
            CHECK_SET_ERR(wizard, "activeModalWidget is not wizard");

            GTUtilsWizard::clickButton(os, GTUtilsWizard::Next);
            GTUtilsWizard::clickButton(os, GTUtilsWizard::Next);
            GTUtilsWizard::clickButton(os, GTUtilsWizard::Next);
            GTUtilsWizard::clickButton(os, GTUtilsWizard::Next);
            GTUtilsWizard::clickButton(os, GTUtilsWizard::Next);
            GTUtilsWizard::clickButton(os, GTUtilsWizard::Next);

            QString tophat = GTUtilsWizard::getParameter(os, "Tophat").toString();
            QString cufflinks = GTUtilsWizard::getParameter(os, "Cufflinks").toString();
            QString cuffmerge = GTUtilsWizard::getParameter(os, "Cuffmerge").toString();
            QString cuffdiff = GTUtilsWizard::getParameter(os, "Cuffdiff").toString();

            CHECK_SET_ERR(tophat == "tools_output", "unexpected tophat value: " + tophat);
            CHECK_SET_ERR(cufflinks == "tools_output", "unexpected cufflinks value: " + cufflinks);
            CHECK_SET_ERR(cuffmerge == "tools_output", "unexpected cuffmerge value: " + cuffmerge);
            CHECK_SET_ERR(cuffdiff == "tools_output", "unexpected cuffdiff value: " + cuffdiff);

            GTUtilsWizard::clickButton(os, GTUtilsWizard::Apply);
        }
    };

    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "Full"<<"Paired-end"));
    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard", new customWizard()));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");
    GTGlobals::sleep();
//    Expected state: a wizard for the scheme appears.

//    3. Click the "Setup" button, then click the  "Next" button until tou get to the last page: "Output data".
//    Expected state: the last page has four lineedits, every lineedit has predefined value ("tools_output").
}

GUI_TEST_CLASS_DEFINITION( test_1568 ) {
//    1. Open "COI.aln".
//    2. Add existing tree or build tree and display it in MSAEditor.
//    3. Close MSAEditor.
//    4. Unload document with tree.
//    5. Open "COI.aln" from the Project View.
//    6. Open document with tree.
//    Expected state: UGENE doesn't crash.
    GTLogTracer l;

    GTFileDialog::openFile(os, dataDir+"samples/CLUSTALW/", "COI.aln");

    GTUtilsDialog::waitForDialog(os, new BuildTreeDialogFiller(os, sandBoxDir + "test_1568.nwk", 0, 0, true));
    QAbstractButton *tree = GTAction::button(os,"Build Tree");
    CHECK_SET_ERR(tree != NULL, "Build Tree action not found");
    GTWidget::click(os, tree);
    GTGlobals::sleep();

    GTUtilsMdi::closeWindow(os, "COI [m] COI");
    GTGlobals::sleep();

    GTUtilsDocument::unloadDocument(os, "test_1568.nwk", false);
    GTGlobals::sleep();
    GTUtilsProjectTreeView::doubleClickItem(os, "COI.aln");
    GTGlobals::sleep();

    GTUtilsLog::check(os, l);
}

GUI_TEST_CLASS_DEFINITION(test_1573) {
    //1. Open "_common_data/scenarios/msa/ma.aln".
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/ma.aln");

    //2. Select some sequences in the NameList area.
    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(0, 2), QPoint(2, 6));

    //3. Click to the any sequence in this selection (in the NameList area).
    GTUtilsMSAEditorSequenceArea::selectSequence(os, "Montana_montana");

    //Expected state: only one sequence is selected (the clicked one).
    GTUtilsMSAEditorSequenceArea::checkSelectedRect(os, QRect(QPoint(0, 4), QPoint(11, 4)));
}

GUI_TEST_CLASS_DEFINITION(test_1574){
//    1. Open "_common_data/scenarios/msa/ma.aln".
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/ma.aln");
//    2. Turn on the collapsing mode with the "Switch on/off collapsing" button on the toolbar.
//    Expected state: there are two collapsed groups.
    GTWidget::click(os, GTToolbar::getWidgetForActionName(os, GTToolbar::getToolbar(os, "mwtoolbar_activemdi"), "Enable collapsing"));
//    3. Try to select some area in the Sequence area (selection start point must be in the white space under sequences).
    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(2, 15), QPoint(2, 0));
//    Expected state: A region from the alignment bottom to the selection end point is selected.
    GTUtilsMSAEditorSequenceArea::checkSelectedRect(os, QRect(QPoint(2, 0), QPoint(2, 13)));

//    4. Try to click to the white space under sequences.
    GTUtilsMSAEditorSequenceArea::click(os, QPoint(2, 15));
//    Expected state: Only one symbol is selected.
    GTUtilsMSAEditorSequenceArea::checkSelectedRect(os, QRect(QPoint(2, 13), QPoint(2, 13)));
//    5. Try to select some area in the NameList area (selection must start from the next row under the last row).
    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(-5, 14), QPoint(-5, 10));
//    Expected state: A region from the alignmnet bottom to the selection end point is selected.
    GTUtilsMSAEditorSequenceArea::checkSelectedRect(os, QRect(QPoint(0, 10), QPoint(11, 13)));
//    6. Try to select some area in the NameList area (selection must start from the bottom of widget.
    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(-5, 30), QPoint(-5, 10));
//    Expected state: A region from the alignment bottom to the selection end point is selected.
    GTUtilsMSAEditorSequenceArea::checkSelectedRect(os, QRect(QPoint(0, 10), QPoint(11, 13)));
}

GUI_TEST_CLASS_DEFINITION(test_1575) {
//    1. Open "_common_data/scenarios/msa/ma.aln".
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/ma.aln");

//    2. Click the "Enable collapsing" button on the toolbar.
    GTWidget::click(os, GTToolbar::getWidgetForActionName(os, GTToolbar::getToolbar(os, "mwtoolbar_activemdi"), "Enable collapsing"));

//    3. Open any group and try to edit any sequence:
    GTUtilsMSAEditorSequenceArea::clickCollapceTriangle(os, "Conocephalus_discolor");

//    3.1 Insert gap by pressing SPACE.
    GTUtilsMSAEditorSequenceArea::click(os, QPoint(0, 10));
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["space"]);

//    Expected state: gap was inserted in every sequence of this group.
    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(0, 10), QPoint(0, 12));
    GTKeyboardDriver::keyClick(os, 'c', GTKeyboardDriver::key["ctrl"]);
    QString clipboardText = GTClipboard::text(os);
    CHECK_SET_ERR(clipboardText == "-\n-\n-", "Unexpected selection: " + clipboardText);

//    3.2 Select some region of the grouped sequences in the Sequence area and drag this selection to the right.
    GTUtilsMSAEditorSequenceArea::click(os, QPoint(2, 11));
    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(2, 11), QPoint(3, 11));

//    Expected state: all sequences in the group are changed simultaneously.
    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(2, 10), QPoint(2, 12));
    GTKeyboardDriver::keyClick(os, 'c', GTKeyboardDriver::key["ctrl"]);
    clipboardText = GTClipboard::text(os);
    CHECK_SET_ERR(clipboardText == "-\n-\n-", "Unexpected selection 2: " + clipboardText);
}

GUI_TEST_CLASS_DEFINITION(test_1576) {
    // 1. Open {_common_data/scenarios/regression/1576/test.uwl}.
    // Expected state: the scema doesn't loaded, an error is in the log:
    // "Cannot bind convert-alignment-to-sequence:out-sequence to sequences-to-msa:in-sequence"
    GTLogTracer l;

    GTUtilsDialog::waitForDialog(os, new StartupDialogFiller(os));
    GTFileDialog::openFile(os, testDir+"_common_data/scenarios/_regression/1576", "test.uwl");
    GTGlobals::sleep();

    CHECK_SET_ERR(l.hasError(), "no error in log");
    QString error = l.getError();
    QString expectedError = "Cannot bind convert-alignment-to-sequence:out-sequence to sequences-to-msa:in-sequence";

    CHECK_SET_ERR(error.contains(expectedError), "actual error is " + error);

}
GUI_TEST_CLASS_DEFINITION(test_1576_1) {

    // 1. Open {_common_data/scenarios/regression/1576/test2.uwl}.
    // Expected state: the scema doesn't loaded, an error is in the log:
    // "Cannot bind sequences-to-msa:out-msa to convert-alignment-to-sequence:in-msa"
    GTLogTracer l;

    GTUtilsDialog::waitForDialog(os, new StartupDialogFiller(os));
    GTFileDialog::openFile(os, testDir+"_common_data/scenarios/_regression/1576", "test2.uwl");
    GTGlobals::sleep();

    CHECK_SET_ERR(l.hasError(), "no error in log");
    QString error = l.getError();
    QString expectedError = "Cannot bind sequences-to-msa:out-msa to convert-alignment-to-sequence:in-msa";

    CHECK_SET_ERR(error.contains(expectedError), "actual error is " + error);

}

GUI_TEST_CLASS_DEFINITION(test_1584) {
//    1. Check the first line of "_common_data/genbank/pBR322.gb".
//    Expected state:
//    LOCUS       SYNPBR322               4361 bp    DNA     circular SYN 30-SEP-2008
//    Look to the spaces between "bp" - "DNA" and "DNA" - "circular". There are must be 4 and 5 spaces by specification.
//    2. Open this file in UGENE.
//    3. Add any annotation.
//    Expected state: new annotation was added.
//    4. Export this document as genbank file.
//    5. Check the first line of the exported file.
//    Expected state: the first line of the exported file is the same as in original file.

    QFile f1(testDir + "_common_data/genbank/pBR322.gb");
    f1.open(QIODevice::ReadOnly);
    QByteArray firstLine = f1.read(64); // after 64 position the date of file modification is located,
                                        // so meaningfull part is before it
    f1.close();

    GTGlobals::sleep();

    GTFileDialog::openFile(os, testDir + "_common_data/genbank/pBR322.gb");
    GTUtilsAnnotationsTreeView::createAnnotation(os, "group", "annotation", "1..3", false);

    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "Export document"));
    GTUtilsDialog::waitForDialog(os, new ExportDocumentDialogFiller(os, sandBoxDir, "test_1584.gb"));
    GTUtilsProjectTreeView::click(os, "pBR322.gb", Qt::RightButton);
    GTGlobals::sleep();

    QFile f2(sandBoxDir + "test_1584.gb");
    f2.open(QIODevice::ReadOnly);
    QByteArray exportedFirstLine = f2.read(64);
    GTGlobals::sleep();

    CHECK_SET_ERR( firstLine == exportedFirstLine, QString("First line had been changed! Expected: '%1'. Current: '%2'")
                   .arg(firstLine.data()).arg(exportedFirstLine.data()) );
    f2.close();
}

GUI_TEST_CLASS_DEFINITION(test_1585) {
    // 1. Open "_common_data/scenarios/msa/ma.aln".
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa/", "ma.aln");
    // 2. Enable collapsing mode.
    GTWidget::click(os, GTToolbar::getWidgetForActionName(os, GTToolbar::getToolbar(os, "mwtoolbar_activemdi"), "Enable collapsing"));

    // 3. Select a sequence area including collapsed rows, sequences above and below them.
    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(3, 9), QPoint(10, 12));
    GTKeyboardDriver::keyClick(os, 'c', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(500);

    const QString selection1 = GTClipboard::text(os);

    // 4. Shift selected region.
    // Expected state : all sequences shifted simultaneously.If group is half - selected, the unselected sequences shifts too.
    GTUtilsMSAEditorSequenceArea::moveTo(os, QPoint(7, 10));
    GTMouseDriver::press(os);
    GTUtilsMSAEditorSequenceArea::moveTo(os, QPoint(10, 10));
    GTMouseDriver::release(os);

    GTUtilsMSAEditorSequenceArea::checkSelection(os, QPoint(6, 9), QPoint(13, 12), selection1);

    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["esc"]);

    GTUtilsMSAEditorSequenceArea::clickCollapceTriangle(os, "Conocephalus_discolor");
    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(6, 9), QPoint(11, 10));

    GTUtilsMSAEditorSequenceArea::moveTo(os, QPoint(9, 9));
    GTMouseDriver::press(os);
    GTUtilsMSAEditorSequenceArea::moveTo(os, QPoint(11, 9));
    GTMouseDriver::release(os);

    GTUtilsMSAEditorSequenceArea::checkSelection(os, QPoint(8, 9), QPoint(13, 10), "GTCTAT\nGCTTAT");

    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["esc"]);

    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(6, 11), QPoint(14, 12));
    GTUtilsMSAEditorSequenceArea::checkSelection(os, QPoint(6, 11), QPoint(14, 12), "--GCTTATT\n--GCTTATT");
}

GUI_TEST_CLASS_DEFINITION(test_1586) {
/*  1. Open file test/_common_data/scenarios/msa/ma2_gapped.aln
    2. Use context menu {align->align with MUSCLE}
    3. press undo toolbar button
    Expected state: alignment is similar to initial
    Bug state: alignments are not similar
*/

    GTFileDialog::openFile(os, testDir+"_common_data/scenarios/msa", "ma2_gapped.aln");
    GTGlobals::sleep();
    //Save the initial content
    GTUtilsMSAEditorSequenceArea::selectArea( os, QPoint( 0, 0 ), QPoint( 13, 10 ) );
    GTKeyboardDriver::keyClick( os, 'c', GTKeyboardDriver::key["ctrl"] );
    GTGlobals::sleep(200);
    const QString initialContent = GTClipboard::text( os );

    GTUtilsDialog::waitForDialog(os, new MuscleDialogFiller(os, MuscleDialogFiller::Default));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << MSAE_MENU_ALIGN << "Align with muscle", GTGlobals::UseMouse));

    GTUtilsMSAEditorSequenceArea::moveTo(os, QPoint(0, 0));
    GTMouseDriver::click(os, Qt::RightButton);
    GTGlobals::sleep(5000);

    QAbstractButton *undo = GTAction::button( os, "msa_action_undo" );
    CHECK_SET_ERR(undo != NULL, "MSA undo action not found");
    GTWidget::click( os, undo );

    //Deselect alignment
    GTUtilsMSAEditorSequenceArea::moveTo(os, QPoint(15, 15));
    GTMouseDriver::click( os );

    //Check the undone state
    GTUtilsMSAEditorSequenceArea::selectArea( os, QPoint( 0, 0 ), QPoint( 13, 10 ) );
    GTKeyboardDriver::keyClick( os, 'c', GTKeyboardDriver::key["ctrl"] );
    GTGlobals::sleep(200);
    const QString undoneContent = GTClipboard::text( os );
    CHECK_SET_ERR( undoneContent == initialContent,
        "Undo works wrong. Found text is: " + undoneContent );

}

GUI_TEST_CLASS_DEFINITION(test_1587) {
/*  1. Open WD and create Read sequence -> Write sequence scheme
    2. Set any output file
    3. Use human_t1 and any image file
    4. Run the scheme

    Expected state: human_t1 is written to the output file, there is a message in log about unsupported doucment format for the image file. The scheme is finished with successful report
    Bug state: the scheme is finished with the error report
*/
    GTLogTracer l;
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    WorkflowProcessItem *reader = GTUtilsWorkflowDesigner::addElement(os, "Read Sequence", true);
    WorkflowProcessItem *writer = GTUtilsWorkflowDesigner::addElement(os, "Write Sequence", true);
    GTUtilsWorkflowDesigner::connect(os, reader, writer);

    GTUtilsWorkflowDesigner::addInputFile(os, "Read Sequence", testDir + "_common_data/regression/1587/some_image.png");
    GTUtilsWorkflowDesigner::addInputFile(os, "Read Sequence", dataDir + "samples/FASTA/human_T1.fa");

    GTUtilsWorkflowDesigner::click(os, "Write Sequence");
    QFile outputFile(sandBoxDir + "out.fa");
    const QString outputFilePath = QFileInfo(outputFile).absoluteFilePath();
    GTUtilsWorkflowDesigner::setParameter(os, "Output file", outputFilePath, GTUtilsWorkflowDesigner::textValue);

    GTUtilsWorkflowDesigner::runWorkflow(os);
    GTUtilsTaskTreeView::waitTaskFinished(os);

    CHECK_SET_ERR(l.checkMessage("Unsupported document format"), "The image file has been processed by Workflow Designer");
    CHECK_SET_ERR(outputFile.exists() && outputFile.size() > 0, "Workflow output file is invalid");
}

GUI_TEST_CLASS_DEFINITION(test_1588) {
//    1. Open WD
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
//    2. Launch tuxedo pipeline with valid data(get from _common_data/NIAID_pipelines/tuxedo_pipeline/data)
    QMap<QString, QVariant> map;
    map.insert("Bowtie index directory", QDir().absoluteFilePath(testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/index/"));
    map.insert("Bowtie index basename", "chr6");
    map.insert("Bowtie version", "Bowtie1");
    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "Single-sample"<<"Single-end"));
    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard", QStringList()<<testDir +
                                                      "_common_data/NIAID_pipelines/tuxedo_pipeline/data/lymph_aln.fastq", map));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");
//    3. Wait for finishing
    GTUtilsWorkflowDesigner::runWorkflow(os);
    //GTGlobals::sleep(5000);
    GTUtilsTaskTreeView::waitTaskFinished(os);
//    4. Go to dashboard, click "External tools" button
    GTUtilsDashboard::openTab(os, GTUtilsDashboard::ExternalTools);
//    Expected state: A tree appeared, it contains information about every tool launch including errors
    QWebElement topHat = GTUtilsDashboard::findElement(os, "TopHat run 1", "SPAN");
    GTUtilsDashboard::findElement(os, "Cufflinks run 1", "SPAN");

    GTUtilsDashboard::click(os, topHat);
    GTUtilsDashboard::findElement(os, "Run info", "SPAN");
    GTUtilsDashboard::findElement(os, "Executable file", "SPAN");
    GTUtilsDashboard::findElement(os, "Arguments", "SPAN");
    GTUtilsDashboard::findElement(os, "Error log", "SPAN");
    GTUtilsDashboard::findElement(os, "--mate-inner-dist 50", "LI", false);
    GTUtilsDashboard::findElement(os, "tophat-2.0.8b", "SPAN", false);
    GTUtilsDashboard::findElement(os, "Beginning TopHat run", "LI", false);



//    GTMouseDriver::moveTo(os,dashboard->mapToGlobal(result.geometry().center()));
//    GTMouseDriver::click(os);
    GTGlobals::sleep(5000);
}

GUI_TEST_CLASS_DEFINITION( test_1597 ) {

    // 1. Open a sequence in UGENE.
    // 2. Input a pattern and search for it.
    // 3. Select "Create new table" in the "Save annotations(s)" group. You may also modify the pattern. Search again.
    // Expected result: the new table is created and found annotations are written to it.

    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");
    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(500);
    GTKeyboardDriver::keySequence(os, "ACAATGTATGCCTCTTGGTTTCTTCTATC");

    QLabel *obj = qobject_cast<QLabel*>(GTWidget::findWidget(os, "ArrowHeader_Save annotation(s) to"));
    GTWidget::click(os, obj);

    QRadioButton *newTable = qobject_cast<QRadioButton *>(GTWidget::findWidget(os, "rbCreateNewTable"));
    GTWidget::click(os, newTable);

    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(500);
    GTKeyboardDriver::keySequence(os, "ACGTCGTCGTCGTCAATGTATGCCTCTTGGTTTCTTCTATC");
}

GUI_TEST_CLASS_DEFINITION( test_1603 ) {
    // 1. Open "_data/samples/CLUSTALW/COI.aln"
    // 2. Add a tree to the alignment by creating a new one
    // 3. Close MSA View
    // 4. Unload tree from project
    // 5. Open "COI.aln" from the Project View
    // Expected state: MSA Editor opens with the Tree View inside

    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");
    GTUtilsDialog::waitForDialog(os, new BuildTreeDialogFiller(os, testDir + "_common_data/scenarios/sandbox/1603.nwk", 0, 0, true));
    QAbstractButton *tree = GTAction::button(os,"Build Tree");
    GTWidget::click(os, tree);
    GTGlobals::sleep();

    GTUtilsMdi::closeWindow(os, "COI [m] COI");
    QString docName = "1603.nwk";

    GTUtilsDocument::unloadDocument(os, docName, false);
    GTGlobals::sleep();
    GTMouseDriver::moveTo( os, GTUtilsProjectTreeView::getItemCenter(os, "COI.aln"));
    GTMouseDriver::doubleClick(os);
    //TODO: check the expected state
}

GUI_TEST_CLASS_DEFINITION( test_1606 ) {
//    1.  File->Access remote database...
//    2.  Fill    "Resource ID": 1ezg
//                "Database": PDB
//        Open.
//    3.  Build SAS molecular surface.
//    4.  Close UGENE.
//    Expected state: UGENE doesn't crash on closing.
    GTLogTracer l;

    GTUtilsDialog::waitForDialog(os, new RemoteDBDialogFillerDeprecated(os, "1ezg", 3, true, false,
                                                                        sandBoxDir));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_FILE),
                                QStringList() << ACTION_PROJECTSUPPORT__ACCESS_REMOTE_DB, GTGlobals::UseKey);
    GTUtilsTaskTreeView::waitTaskFinished(os);

    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "Molecular Surface" << "SES"));
    QWidget *widget3d = GTWidget::findWidget(os, "1-1EZG");
    GTWidget::click(os, widget3d, Qt::RightButton);
    GTGlobals::sleep();

    GTUtilsLog::check(os, l);
}

GUI_TEST_CLASS_DEFINITION(test_1607) {
    GTLogTracer l;
    //1. Open WD
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    //2. Create schema read variations->write variations
    WorkflowProcessItem *reader = GTUtilsWorkflowDesigner::addElement(os, "Read Variations");
    WorkflowProcessItem *writer = GTUtilsWorkflowDesigner::addElement(os, "Write Variations");
    GTUtilsWorkflowDesigner::connect(os, reader, writer);

    //3. Use input file "_common_data/NIAID_pipelines/Call_variants/data_to_compare_with/test_0001/out.vcf"
    GTUtilsWorkflowDesigner::addInputFile(os, "Read Variations", testDir + "_common_data/NIAID_pipelines/Call_variants/data_to_compare_with/test_0001/out.vcf");

    GTUtilsWorkflowDesigner::click(os, "Write Variations");
    QFile outputFile(sandBoxDir + "out.vcf");
    const QString outputFilePath = QFileInfo(outputFile).absoluteFilePath();
    GTUtilsWorkflowDesigner::setParameter(os, "Output file", outputFilePath, GTUtilsWorkflowDesigner::textValue);

    //4. Run schema
    GTUtilsWorkflowDesigner::runWorkflow(os);
    GTUtilsTaskTreeView::waitTaskFinished(os);

    //Expected state : output file not empty
    CHECK_SET_ERR(outputFile.exists() && outputFile.size() > 0, "Workflow output file is invalid");
    GTUtilsLog::check(os, l);
    outputFile.remove();
}

GUI_TEST_CLASS_DEFINITION(test_1609) {
    // 1) Open any file in UGENE
    QFile::copy(dataDir + "samples/FASTA/human_T1.fa", sandBoxDir + "human_T1.fa");
    GTFileDialog::openFile(os, sandBoxDir, "human_T1.fa");

    class CustomFileDialogUtils : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            QWidget *dialog = QApplication::activeModalWidget();
            GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::No));
            GTWidget::click(os, GTWidget::findButtonByText(os, "Cancel", dialog));
        }
    };

    // 2) Delete that file from the file system
    // 3) Press "Yes" in appeared UGENE "Do you wish to save" dialog
    // 4) Press "Cancel" in appeared "Save as" dialog
    // Expected state : "Do you wish to save" dialog appeared
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Yes));
    GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, new CustomFileDialogUtils()));
    QFile::remove(sandBoxDir + "human_T1.fa");
    GTGlobals::sleep(5000);
}

GUI_TEST_CLASS_DEFINITION( test_1616 ) {
    // 1. Open "COI.aln".
    // 2. Select any symbol in the last sequence.
    // 3. Click the "Switch on\off collapsing" button on the toolbar.
    // Expected state: UGENE not crashes

    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");

    GTUtilsMSAEditorSequenceArea::selectArea( os, QPoint(0, 17), QPoint(0, 17));

    GTWidget::click(os, GTToolbar::getWidgetForActionName(os, GTToolbar::getToolbar(os, "mwtoolbar_activemdi"), "Enable collapsing"));
    GTGlobals::sleep();
    GTWidget::click(os, GTToolbar::getWidgetForActionName(os, GTToolbar::getToolbar(os, "mwtoolbar_activemdi"), "Enable collapsing"));
}

GUI_TEST_CLASS_DEFINITION( test_1622 )
{
    // 1. Open document "ma.aln"
    GTFileDialog::openFile( os, testDir + "_common_data/scenarios/msa", "ma.aln" );

    // 2. Save the initial content
    GTUtilsMSAEditorSequenceArea::selectArea( os, QPoint( 0, 0 ), QPoint( 11, 17 ) );
    GTKeyboardDriver::keyClick( os, 'c', GTKeyboardDriver::key["ctrl"] );
    GTGlobals::sleep(200);
    const QString initialContent = GTClipboard::text( os );

    // 2.1. Remove selection
    GTKeyboardDriver::keyClick( os, GTKeyboardDriver::key["esc"] );
    GTGlobals::sleep(200);
    GTUtilsMSAEditorSequenceArea::checkSelectedRect( os, QRect( ) );

    // 3. Select a region in the sequence area
    GTUtilsMSAEditorSequenceArea::selectArea( os, QPoint( 5, 4 ), QPoint( 10, 12 ) );

    // 4. Shift the region
    GTUtilsMSAEditorSequenceArea::selectArea( os, QPoint( 6, 7 ), QPoint( 11, 7 ) );

    // 5. Obtain undo button
    QAbstractButton *undo = GTAction::button( os, "msa_action_undo" );

    // 6. Undo shifting, e.g. alignment should restore to the init state
    GTWidget::click( os, undo );

    // 7. Check the undone state
    GTUtilsMSAEditorSequenceArea::selectArea( os, QPoint( 0, 0 ), QPoint( 11, 17 ) );
    GTKeyboardDriver::keyClick( os, 'c', GTKeyboardDriver::key["ctrl"] );
    GTGlobals::sleep(200);
    const QString undoneContent = GTClipboard::text( os );
    CHECK_SET_ERR( undoneContent == initialContent,
        "Undo works wrong. Found text is: " + undoneContent );
}

GUI_TEST_CLASS_DEFINITION(test_1626) {
    //1. Open file _common_data/regression/1626/1626.fa
    GTFileDialog::openFile(os, testDir + "_common_data/regression/1626", "1626.fa");
    GTUtilsTaskTreeView::waitTaskFinished(os);

    //2. Align with KAlign
    //Expected state: UGENE not crasesh, KAlign can return error message, its okay
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<<MSAE_MENU_ALIGN<<"align_with_kalign", GTGlobals::UseKey));
    GTUtilsDialog::waitForDialog(os, new KalignDialogFiller(os));
    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
    GTUtilsTaskTreeView::waitTaskFinished(os);

    //3. Change color scheme
    //Expected state: color scheme changed successfully
    GTUtilsDialog::waitForDialog( os, new PopupChooser( os, QStringList( ) << "Colors" << "Tailor"));
    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
}

GUI_TEST_CLASS_DEFINITION( test_1628 ) {
    //CORRECT DISPLAYUNG OF RUSSIAN LATTERS CAN NOT BE TESTED

//    1. Open COI.aln
//    2. Renames any row in an alignment, use a non-english characters in the alignment name.
//    3. Undo and redo.
//    Expected state: renamed named with name given at step 2

    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");
    GTUtilsMSAEditorSequenceArea::renameSequence(os, "Montana_montana", "йцукен123");

    QAbstractButton *undo = GTAction::button( os, "msa_action_undo" );
    CHECK_SET_ERR(undo != NULL, "Undo button is NULL");
    GTWidget::click(os, undo);

    QAbstractButton *redo = GTAction::button( os, "msa_action_redo" );
    CHECK_SET_ERR(redo != NULL, "Redo button is NULL");
    GTWidget::click(os, redo);

    GTGlobals::sleep();
    QStringList names = GTUtilsMSAEditorSequenceArea::getNameList(os);

    CHECK_SET_ERR(names.contains("йцукен123") && !names.contains("Montana_montana"), "Undo-redo worked incorrectly");
}

GUI_TEST_CLASS_DEFINITION(test_1629) {
    //1. Open UGENE.
    //2. Close currect project if it is opened.
    //3. Click the menu item "File".
    //Expected: "Open As" sub-item exists and is available to click.
    GTUtilsDialog::waitForDialog(os, new PopupChecker(os, QStringList() << ACTION_PROJECTSUPPORT__OPEN_AS,
        PopupChecker::IsEnabled, GTGlobals::UseMouse));
    GTMenu::showMainMenu(os, MWMENU_FILE);
}

GUI_TEST_CLASS_DEFINITION(test_1631) {
//    1. Open "data/samples/CLUSTALW/COI.aln".
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");

//    2. Open "Tree Settings" options panel tab.
    GTUtilsOptionPanelMsa::openTab(os, GTUtilsOptionPanelMsa::TreeSettings);

//    3. Click "Open tree" button.
//    4. Select "data/samples/Newick/COI.nwk".
//    Expected state: the tree is added to the MSA Editor.
    GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, dataDir + "samples/Newick", "COI.nwk"));
    GTWidget::click(os, GTWidget::findWidget(os, "OpenTreeButton"));
    GTUtilsTaskTreeView::waitTaskFinished(os);
    GTUtilsMsaEditor::getTreeView(os);

//    5. Reopen the view.
//    Expected state: the tree is still shown with the msa.
    GTUtilsMdi::click(os, GTGlobals::Close);
    GTUtilsProjectTreeView::doubleClickItem(os, "COI");
    GTUtilsTaskTreeView::waitTaskFinished(os);
    GTUtilsMsaEditor::getTreeView(os);
}

GUI_TEST_CLASS_DEFINITION(test_1640) {
    //1. Open "_common_data/scenarios/msa/ma.aln".
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/msa", "ma.aln");

    //2. Click the MSA Editor.
    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(4, 3), QPoint(4, 3));

    //3. Press ctrl+left arrow to remove the selection.
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["left"], GTKeyboardDriver::key["ctrl"]);

    //4. Press and hold a bit shift+right arrow.
    //GTKeyboardDriver::keyPress(os, GTKeyboardDriver::key["shift"]);
    for (int i=0; i<12; i++) {
        GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["right"], GTKeyboardDriver::key["shift"]);
    }
    //GTKeyboardDriver::keyRelease(os, GTKeyboardDriver::key["shift"]);

    //Expected state: all sequences of each selected column are selected
    GTKeyboardDriver::keyClick(os, 'c', GTKeyboardDriver::key["ctrl"]);
    QString chars = GTClipboard::text(os);
    CHECK_SET_ERR(chars == "TCAGTCTATTAA", "Wrong selection: " + chars);
}

GUI_TEST_CLASS_DEFINITION(test_1643) {
//    1. Open {data/samples/CLUSTALW/COI.aln}.
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");

//    2. Do not select any sequence, click the right mouse button at the name list area (or at the sequence area).
//    Expected state: context menu appeared. It contains an item "Set this sequence as reference" and does not contain "unset the reference sequence".

//    3. Select the "Set this sequence as reference" item in the context manu.
//    Expected state: the clicked in the 2 step sequence was set as reference.
    GTUtilsDialog::waitForDialog(os, new PopupChooserbyText(os, QStringList() << "Set this sequence as reference"));
    GTUtilsMSAEditorSequenceArea::callContextMenu(os, QPoint(5, 5));
    QString currentReference = GTUtilsMsaEditor::getReferenceSequenceName(os);
    CHECK_SET_ERR("Metrioptera_japonica_EF540831" == currentReference, QString("An unexpected reference sequence is set: expect '%1', got '%2'").arg("Metrioptera_japonica_EF540831").arg(currentReference));

//    4. Select any sequence. Call context menu on any another sequence (not on the reference).
//    Expected sate: the content menu contains both set and unset reference items.
    GTUtilsDialog::waitForDialog(os, new PopupChecker(os, QStringList() << "unset_reference"));
    GTUtilsMSAEditorSequenceArea::callContextMenu(os, QPoint(6, 6));
    GTUtilsDialog::waitForDialog(os, new PopupChecker(os, QStringList() << "set_seq_as_reference"));
    GTUtilsMSAEditorSequenceArea::callContextMenu(os, QPoint(6, 6));

//    5. Select the "Set this sequence as reference" item in the context manu.
//    Expected state: the clicked in the 4 step sequence was set as reference (not the selected).
    GTUtilsDialog::waitForDialog(os, new PopupChooserbyText(os, QStringList() << "Set this sequence as reference"));
    GTUtilsMSAEditorSequenceArea::callContextMenu(os, QPoint(6, 6));
    currentReference = GTUtilsMsaEditor::getReferenceSequenceName(os);
    CHECK_SET_ERR("Gampsocleis_sedakovii_EF540828" == currentReference, QString("An unexpected reference sequence is set: expect '%1', got '%2'").arg("Gampsocleis_sedakovii_EF540828").arg(currentReference));

//    6. Call context menu below all sequences, on the white space.
//    Expected state: there is the "unset" item on the context menu, but no "set" item.
    GTUtilsDialog::waitForDialog(os, new PopupChecker(os, QStringList() << "set_seq_as_reference", PopupChecker::NotExists));
    GTUtilsMSAEditorSequenceArea::callContextMenu(os, QPoint(6, 20));
    GTUtilsDialog::waitForDialog(os, new PopupChecker(os, QStringList() << "unset_reference"));
    GTUtilsMSAEditorSequenceArea::callContextMenu(os, QPoint(6, 20));

//    7. Select the "unset" menu item.
//    Expected state: There is no reference sequences, context menu does contains the "set" item, but does not contain the "unset" item.
    GTUtilsDialog::waitForDialog(os, new PopupChooserbyText(os, QStringList() << "Unset reference sequence"));
    GTUtilsMSAEditorSequenceArea::callContextMenu(os, QPoint(6, 20));

//    8. Call context menu below all sequences, on the white space.
//    Expected state: there is neither "set" no "unset" items on the context menu.
    GTUtilsDialog::waitForDialog(os, new PopupChecker(os, QStringList() << "set_seq_as_reference", PopupChecker::NotExists));
    GTUtilsMSAEditorSequenceArea::callContextMenu(os, QPoint(6, 20));
    GTUtilsDialog::waitForDialog(os, new PopupChecker(os, QStringList() << "unset_reference", PopupChecker::NotExists));
    GTUtilsMSAEditorSequenceArea::callContextMenu(os, QPoint(6, 20));
}

GUI_TEST_CLASS_DEFINITION( test_1644 ) {
//    1) Run UGENE
//    2) Choose File/Access remote database
//    3) Choose UniProt (DAS) or Ensembl Human Genes (DAS) from combobox
//    4) Enter Resourse Id
//    State: if Ensembl Human Genes is choosen and example ID (ENSG00000139618) is entered then UGENE crashes
//    trying to recognize .gb format ( failed to detect ...)
    GTLogTracer l;
    GTUtilsDialog::waitForDialog(os, new RemoteDBDialogFillerDeprecated(os, "ENSG00000139618", 7, true, false,
                                                                        sandBoxDir));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_FILE),
                                QStringList() << ACTION_PROJECTSUPPORT__ACCESS_REMOTE_DB, GTGlobals::UseKey);
    GTGlobals::sleep(5000);

    GTUtilsLog::check(os, l);
}

GUI_TEST_CLASS_DEFINITION(test_1645) {
    //1. Open "_common_data/fasta/base_ext_nucl_all_symb.fa".

    //2. Select the "Join sequences into alignment and open in multiple alignment viewer" option and click "OK" in the appeared "Sequence reading options" dialog.
    //Expected state: The file opens in the MSA Editor.

    //3. Right click to the loaded document in the project view and select "Unload selected objects" from the context menu.
    //Expected state: The message box appeares.

    //4. Agree to close an opened view in the appeared message box.
    //Expected state: the document unloads.
    //GTFileDialog::openFile(os, testDir + "_common_data/fasta/", "base_ext_nucl_all_symb.fa");
    GTUtilsDialog::waitForDialog(os, new SequenceReadingModeSelectorDialogFiller(os, SequenceReadingModeSelectorDialogFiller::Join));
    GTUtilsProject::openFiles(os, testDir + "_common_data/fasta/base_ext_nucl_all_symb.fa");
    GTGlobals::sleep();
    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "base_ext_nucl_all_symb.fa"));
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Yes));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<<ACTION_PROJECT__UNLOAD_SELECTED));
    GTMouseDriver::click(os, Qt::RightButton);
    CHECK_SET_ERR(!GTUtilsDocument::isDocumentLoaded(os, "base_ext_nucl_all_symb.fa"), "Document should't be loaded");
}

GUI_TEST_CLASS_DEFINITION( test_1653 ) {
/*  1. Open some sequence
    2. Open find pattern option panel
    3. click "Show more options"
    Expected state: Algorithm - exact
    "should match" spinbox is not shown
    Actual: spinbox is shown
*/
    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");
    GTWidget::click(os, GTWidget::findWidget(os, "OP_FIND_PATTERN"));
    GTGlobals::sleep(500);
    GTWidget::click(os, GTWidget::findWidget(os, "ArrowHeader_Search algorithm"));
    QSpinBox* spin = qobject_cast<QSpinBox*>(GTWidget::findWidget(os, "spinBoxMatch"));
    CHECK_SET_ERR(spin != NULL, "spinBoxMatch not found!");
    CHECK_SET_ERR(spin->isHidden(), "Warning spinbox is unexpectedly visible");
}

GUI_TEST_CLASS_DEFINITION( test_1654 ) {
    // 1. Open some sequence
    // 2. Copy some subsequence(for example first 10 symbols)
    // 3. Open find pattern option panel
    // 4. Use ctrl+v to paste subsequence to find pattern text area
    // 5. Collapse option panel
    // 6. Expand it and paste subsequence again
    // Expected state: {Search} button is enabled
    // Actual: {Search} button is disabled

    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");

    GTUtilsDialog::waitForDialog(os, new selectSequenceRegionDialogFiller(os, 1, 15));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "Select" << "Sequence region"));
    GTMenu::showContextMenu(os, GTWidget::findWidget(os, "ADV_single_sequence_widget_0"));

    GTKeyboardDriver::keyClick(os, 'c', GTKeyboardDriver::key["ctrl"]);

    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(500);

    GTKeyboardDriver::keyClick(os, 'v', GTKeyboardDriver::key["ctrl"]);

    GTWidget::click(os, GTWidget::findWidget(os, "OP_FIND_PATTERN"));
    GTGlobals::sleep(500);

    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(500);

    GTKeyboardDriver::keyClick(os, 'v', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(5000);

    QWidget *createAnnotationsButton = GTWidget::findWidget(os, "getAnnotationsPushButton");
    GTGlobals::sleep(500);
    CHECK_SET_ERR(!createAnnotationsButton->isEnabled(), "Create annotations button is enabled!");
}

GUI_TEST_CLASS_DEFINITION( test_1660 ) {
    // 1. Open any sequence
    // 2. Open find pattern option panel
    // 3. Enter any valid pattern
    // 4. Click "Show more options" and select "custom region" in "Region" combobox
    // 5. Delete default value from right edge line edit
    // Expected state: lineedit became red Actual: UGENE crashes

    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");

    GTUtilsDialog::waitForDialog(os, new selectSequenceRegionDialogFiller(os, 1, 15));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "Select" << "Sequence region"));
    GTMenu::showContextMenu(os, GTWidget::findWidget(os, "ADV_single_sequence_widget_0"));

    GTKeyboardDriver::keyClick(os, 'c', GTKeyboardDriver::key["ctrl"]);

    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(500);

    GTKeyboardDriver::keyClick(os, 'v', GTKeyboardDriver::key["ctrl"]);

    //TODO setSearchInregion method checking
}
GUI_TEST_CLASS_DEFINITION(test_1661) {
    // 1. Open human_T1.fa
    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");

    // 2. Open find pattern option panel
    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(500);

    // 3. Enter pattern ACAATGTATGCCTCTTGGTTTCTTCTATC
    GTKeyboardDriver::keySequence(os, "ACAATGTATGCCTCTTGGTTTCTTCTATC");

    // 4. Use settings : Region - custom region; 1 - 10000.
    GTUtilsOptionPanelSequenceView::setRegionType(os, "Custom region");
    GTLineEdit::setText(os, qobject_cast<QLineEdit *>(GTWidget::findWidget(os, "editStart")), "1");
    GTLineEdit::setText(os, qobject_cast<QLineEdit *>(GTWidget::findWidget(os, "editEnd")), "10000");

    // Expected state : nothing found
    QLabel *resultLabel = qobject_cast<QLabel *>(GTWidget::findWidget(os, "resultLabel"));
    CHECK_SET_ERR(resultLabel->text() == "Results: 0/0", "Unexpected find algorithm result count");

    // 5. Use settings : Region - Whole sequence.
    GTUtilsOptionPanelSequenceView::setRegionType(os, "Whole sequence");
    GTUtilsTaskTreeView::waitTaskFinished(os);

    // Expected state : One match found
    CHECK_SET_ERR(resultLabel->text() == "Results: 1/1", "Unexpected find algorithm result count");
}

GUI_TEST_CLASS_DEFINITION(test_1662){
//    1. Open WD
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
//    2. Add sample: Multiple dataset tuxedo: Single-end
    QMap<QString, QVariant> map;
    map.insert("Bowtie index directory", QDir().absoluteFilePath(testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/bowtie2_index/"));
    map.insert("Bowtie index basename", "NC_010473");
    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "Full"<<"Single-end"));
    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard", QList<QStringList>()<<(QStringList()<<
                                                       testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/fastq1/exp_1_1.fastq"<<
                                                       testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/fastq1/exp_1_2.fastq")<<
                                                      (QStringList()<<testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/fastq2/exp_2_1.fastq"<<
                                                       testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/fastq2/exp_2_2.fastq"), map));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");
//    3. Click {show wizard} toolbar button
//    4. Add several files to each dataset. Fill other fields with proper data
//    5. Run schema
    GTUtilsWorkflowDesigner::runWorkflow(os);
    GTUtilsTaskTreeView::waitTaskFinished(os, 360000);
//    Expected state: Tophat tool ran 2 times
    GTUtilsDashboard::openTab(os, GTUtilsDashboard::ExternalTools);
    GTGlobals::sleep();
    GTUtilsDashboard::findElement(os, "TopHat run 1", "SPAN");
    GTUtilsDashboard::findElement(os, "TopHat run 2", "SPAN");
    GTUtilsDashboard::checkElement(os, "TopHat run 3", "SPAN", false);
}

GUI_TEST_CLASS_DEFINITION(test_1664){
//    1. Open COI.aln.
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");
//    2. Select something in the sequence area.
    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(0,0), QPoint(5,5));
//    3. Try to modify the selection with SHIFT+arrows.
    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["right"], GTKeyboardDriver::key["shift"]);
    GTGlobals::sleep();
//    Expected state: selection changes its size.
    QRect expected = QRect(0, 0, 7, 6);
    GTUtilsMSAEditorSequenceArea::checkSelectedRect(os, expected);
//    Bug state: UGENE crashes.
}

GUI_TEST_CLASS_DEFINITION(test_1672) {
    //1. Open "COI.aln".
    //2. Set the "Zychia_baranovi" sequence as reference.
    //3. Open the "Statistics" options panel tab.
    //4. Set checked "Show distance algorithm" box, select the "Identity" algorithm.
    //Expected state: the reference sequence has 100% match with itself.
    //Bug state: the reference sequence has 103% match with itself.

    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");
    GTGlobals::sleep();
    GTWidget::click(os, GTWidget::findWidget(os, "OP_SEQ_STATISTICS_WIDGET"));
    GTUtilsMSAEditorSequenceArea::click(os, QPoint(-8, 8));
    GTWidget::click(os, GTWidget::findWidget(os, "addSeq"));
    QCheckBox* showDistancesColumnCheck = qobject_cast<QCheckBox*>(GTWidget::findWidget(os, "showDistancesColumnCheck"));
    GTCheckBox::setChecked(os, showDistancesColumnCheck, true);
    QComboBox *algoCombo = qobject_cast<QComboBox*>(GTWidget::findWidget(os, "algoComboBox"));
    GTComboBox::setIndexWithText(os, algoCombo, "Identity");
    QString num1 = GTUtilsMSAEditorSequenceArea::getSimilarityValue(os, 8);
    CHECK_SET_ERR(num1 == "100%", "unexpected sumilarity value an line 1: " + num1);
}

GUI_TEST_CLASS_DEFINITION(test_1673) {
//    1. Open file COI.aln
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");

//    2. Select a options panel tab header
//    Expected result: the tab has been opened
    GTUtilsOptionPanelMsa::toggleTab(os, GTUtilsOptionPanelMsa::General);
    bool isTabOpened = GTUtilsOptionPanelMsa::isTabOpened(os, GTUtilsOptionPanelMsa::General);
    CHECK_SET_ERR(isTabOpened, "The 'General' tab is unexpectedly closed");

//    3. Select the same tab header again
//    Expected result: the tab has been closed
    GTUtilsOptionPanelMsa::toggleTab(os, GTUtilsOptionPanelMsa::General);
    isTabOpened = GTUtilsOptionPanelMsa::isTabOpened(os, GTUtilsOptionPanelMsa::General);
    CHECK_SET_ERR(!isTabOpened, "The 'General' tab is unexpectedly opened");

//    4. Select the same tab header again
//    Expected result: the tab has been opened again
    GTUtilsOptionPanelMsa::toggleTab(os, GTUtilsOptionPanelMsa::General);
    isTabOpened = GTUtilsOptionPanelMsa::isTabOpened(os, GTUtilsOptionPanelMsa::General);
    CHECK_SET_ERR(isTabOpened, "The 'General' tab is unexpectedly closed");
}

GUI_TEST_CLASS_DEFINITION(test_1673_2) {
//    1. Open file COI.aln
//    2. Select a options panel tab header
//    Expected result: the tab has been opened
//    3. Select different tab
//    Expected result: only one selected group is shown at a time
//    4. Select different tabs, holding "Ctrl"
//    Expected result: only one selected group is shown at a time

    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");

    GTUtilsOptionPanelMsa::toggleTab(os, GTUtilsOptionPanelMsa::General);
    bool isTabOpened = GTUtilsOptionPanelMsa::isTabOpened(os, GTUtilsOptionPanelMsa::General);
    CHECK_SET_ERR(isTabOpened, "The 'General' tab is unexpectedly closed");

    GTUtilsOptionPanelMsa::toggleTab(os, GTUtilsOptionPanelMsa::Statistics);
    isTabOpened = GTUtilsOptionPanelMsa::isTabOpened(os, GTUtilsOptionPanelMsa::General);
    CHECK_SET_ERR(!isTabOpened, "The 'General' tab is unexpectedly opened");
    isTabOpened = GTUtilsOptionPanelMsa::isTabOpened(os, GTUtilsOptionPanelMsa::Statistics);
    CHECK_SET_ERR(isTabOpened, "The 'Statictics' tab is unexpectedly closed");

    GTKeyboardDriver::keyPress(os, GTKeyboardDriver::key["Ctrl"]);
    GTUtilsOptionPanelMsa::toggleTab(os, GTUtilsOptionPanelMsa::General);
    GTUtilsOptionPanelMsa::toggleTab(os, GTUtilsOptionPanelMsa::ExportConsensus);
    GTKeyboardDriver::keyRelease(os, GTKeyboardDriver::key["Ctrl"]);

    isTabOpened = GTUtilsOptionPanelMsa::isTabOpened(os, GTUtilsOptionPanelMsa::General);
    CHECK_SET_ERR(!isTabOpened, "The 'General' tab is unexpectedly opened");
    isTabOpened = GTUtilsOptionPanelMsa::isTabOpened(os, GTUtilsOptionPanelMsa::ExportConsensus);
    CHECK_SET_ERR(isTabOpened, "The 'Export Consensus' tab is unexpectedly closed");

}

GUI_TEST_CLASS_DEFINITION(test_1673_3) {
    //1. Open human_T1.fa
    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");
    //2. Press "Ctrl+F"
    //Expected result: "Search in Sequence" tab has been opened, the pattern field is in focus
    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(500);

    QWidget* wgt = QApplication::focusWidget();
    QTextEdit *edit = qobject_cast<QTextEdit*>(wgt);
    CHECK_SET_ERR(edit != NULL, "Text edit is not in focus");
}

GUI_TEST_CLASS_DEFINITION(test_1673_4) {
    //1. Open human_T1.fa
    GTFileDialog::openFile(os, dataDir + "samples/FASTA/human_T1.fa");

    //2. Open "Annotations Highlighting" tab of the Options Panel, press "Ctrl+F"
    GTWidget::click(os, GTWidget::findWidget(os, "OP_ANNOT_HIGHLIGHT"));
    GTGlobals::sleep(500);
    GTWidget::findWidget(os, "prevAnnotationButton");
    GTKeyboardDriver::keyClick(os, 'f', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(500);

    //Expected result: "Search in Sequence" tab has been opened, other tabs have been closed
    QWidget *prevButton = GTWidget::findWidget(os, "prevAnnotationButton", NULL, GTGlobals::FindOptions(false));
    CHECK_SET_ERR(NULL == prevButton, "Annotations options panel is not closed");
    GTWidget::findWidget(os, "FindPatternWidget");
}

namespace {
class customFileDialog_1681: public GTFileDialogUtils{
public:
    customFileDialog_1681(U2OpStatus &os, QString path): GTFileDialogUtils(os, path){}
    void commonScenario(){
        GTFileDialogUtils::commonScenario();
        GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Yes));
    }
};
}


GUI_TEST_CLASS_DEFINITION(test_1677){
//    1. Open WD
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
//    2. Add sample: "Main Tuxedo: Paired-end"
    class customWizard : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            GTGlobals::sleep();
            QWidget* dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog, "activeModalWidget is NULL");
            QWizard* wizard = qobject_cast<QWizard*>(dialog);
            CHECK_SET_ERR(wizard, "activeModalWidget is not wizard");

            GTUtilsDialog::waitForDialog(os, new customFileDialog_1681(os, testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/fastq1/exp_1_1.fastq"));
            QList<QWidget* > list = wizard->currentPage()->findChildren<QWidget*>("addFileButton");
            foreach (QWidget* w, list) {
                if(w->isVisible()){
                    GTWidget::click(os, w);
                    break;
                }
            }

            QMap<QString, QVariant> map;
            map.insert("Bowtie index directory", QDir().absoluteFilePath(testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/bowtie2_index/"));
            map.insert("Bowtie index basename", "NC_010473");
            map.insert("Input transcripts annotations", QDir().absoluteFilePath(testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/accepted_hits.bam"));
            GTUtilsWizard::setAllParameters(os, map);

            GTUtilsWizard::clickButton(os, GTUtilsWizard::Apply);
        }
    };

    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "Full"<<"Paired-end"));
    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard", new customWizard()));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");
    GTGlobals::sleep();
//    3. Press {show widget} toolbutton
//    Expected state: wizard appears
//    4. Add file {test/_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/fastq1/exp_1_1.fastq} to {First short  reads files} window
//    Expected state:Adding exp_1_2.fastq offer has appeared

//    5. Fill all other fields with proper values except second dataset. Press {finish} at the end
//    6. Press {validate schema} toolbar button
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Ok));
    GTWidget::click( os,GTAction::button(os, "Validate workflow"));
    GTGlobals::sleep();
//    Expected state: warnings about empty datasets appeared
    GTUtilsWorkflowDesigner::checkErrorList(os, "Dataset");
}

GUI_TEST_CLASS_DEFINITION(test_1680) {
//    For Mac only

//    1. Open "data/samples/CLUSTALW/COI.aln"
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");

//    2. Choose some sequence by mouse in the name list area
    GTUtilsMsaEditor::clickSequenceName(os, "Tettigonia_viridissima");

//    3. Press "Shift"+"Arrow Up" a few times, then "Shift"+"Arrow Down" a few times
//    Expected state: The selection changes on every keystroke, for "Arrow Up" it grows to
//    the top of sequences list, for "Arrow Down" it does to the bottom
    GTKeyboardDriver::keyPress(os, GTKeyboardDriver::key["shift"]);

    int expectedSelectionSize = 1;
    for (int i = 0; i < 9; i++) {
        GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["up"]);
        expectedSelectionSize++;
        const int currentSelectionSize = GTUtilsMSAEditorSequenceArea::getSelectedSequencesNum(os);
        CHECK_SET_ERR(expectedSelectionSize == currentSelectionSize, QString("An unexpected selection size: expect %1, got %2").arg(expectedSelectionSize).arg(currentSelectionSize));
        GTGlobals::sleep(100);
    }

    {
        GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["up"]);
        const int currentSelectionSize = GTUtilsMSAEditorSequenceArea::getSelectedSequencesNum(os);
        CHECK_SET_ERR(10 == currentSelectionSize, QString("An unexpected selection size: expect %1, got %2").arg(10).arg(currentSelectionSize));
        GTGlobals::sleep(100);
    }

    for (int i = 0; i < 9; i++) {
        GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["down"]);
        expectedSelectionSize--;
        const int currentSelectionSize = GTUtilsMSAEditorSequenceArea::getSelectedSequencesNum(os);
        CHECK_SET_ERR(expectedSelectionSize == currentSelectionSize, QString("An unexpected selection size: expect %1, got %2").arg(expectedSelectionSize).arg(currentSelectionSize));
        GTGlobals::sleep(100);
    }

    for (int i = 0; i < 8; i++) {
        GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["down"]);
        expectedSelectionSize++;
        const int currentSelectionSize = GTUtilsMSAEditorSequenceArea::getSelectedSequencesNum(os);
        CHECK_SET_ERR(expectedSelectionSize == currentSelectionSize, QString("An unexpected selection size: expect %1, got %2").arg(expectedSelectionSize).arg(currentSelectionSize));
        GTGlobals::sleep(100);
    }

    {
        GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["down"]);
        const int currentSelectionSize = GTUtilsMSAEditorSequenceArea::getSelectedSequencesNum(os);
        CHECK_SET_ERR(9 == currentSelectionSize, QString("An unexpected selection size: expect %1, got %2").arg(9).arg(currentSelectionSize));
        GTGlobals::sleep(100);
    }

    {
        GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["up"]);
        const int currentSelectionSize = GTUtilsMSAEditorSequenceArea::getSelectedSequencesNum(os);
        CHECK_SET_ERR(8 == currentSelectionSize, QString("An unexpected selection size: expect %1, got %2").arg(8).arg(currentSelectionSize));
        GTGlobals::sleep(100);
    }

    GTKeyboardDriver::keyClick(os, GTKeyboardDriver::key["shift"]);
}

GUI_TEST_CLASS_DEFINITION(test_1681){
//    1. Open WD
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
//    2. Add sample: Multiple dataset tuxedo: Single-end
    QMap<QString, QVariant> map;
    map.insert("Bowtie index directory", QDir().absoluteFilePath(testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/bowtie2_index/"));
    map.insert("Bowtie index basename", "NC_010473");
    map.insert("Input transcripts annotations", QDir().absoluteFilePath(testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/accepted_hits.bam"));
    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "No-new-transcripts"<<"Single-end"));
    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard", QList<QStringList>()<<(QStringList()<<testDir +
                                                      "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/fastq1/exp_1_1.fastq")<<
                                                      (QStringList()<<testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/fastq2/exp_2_1.fastq"), map));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");
//    3. Click {show wizard} toolbar button
//    4. Fill wizard with proper data
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Ok, "Well done!"));
    GTWidget::click( os,GTAction::button(os, "Validate workflow"));
    GTGlobals::sleep();

//    5. Run schema
//    Expected state: Pipeline executed without errors
}

GUI_TEST_CLASS_DEFINITION(test_1681_1) {
//    1. Open WD
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
//    2. Add sample: Multiple dataset tuxedo: Paired-end



    class customWizard : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            GTGlobals::sleep();
            QWidget* dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog, "activeModalWidget is NULL");
            QWizard* wizard = qobject_cast<QWizard*>(dialog);
            CHECK_SET_ERR(wizard, "activeModalWidget is not wizard");

            GTUtilsDialog::waitForDialog(os, new customFileDialog_1681(os, testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/fastq1/exp_1_1.fastq"));
            QList<QWidget* > list = wizard->currentPage()->findChildren<QWidget*>("addFileButton");
            foreach (QWidget* w, list) {
                if(w->isVisible()){
                    GTWidget::click(os, w);
                    break;
                }
            }

            QTabWidget* tabWidget = dialog->findChild<QTabWidget*>();
            CHECK_SET_ERR(tabWidget != NULL, "tabWidget not found");
            GTTabWidget::setCurrentIndex(os, tabWidget, 1);

            GTUtilsDialog::waitForDialog(os, new customFileDialog_1681(os, testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/fastq2/exp_2_1.fastq"));
            list = wizard->currentPage()->findChildren<QWidget*>("addFileButton");
            foreach (QWidget* w, list) {
                if(w->isVisible()){
                    GTWidget::click(os, w);
                    break;
                }
            }

            QMap<QString, QVariant> map;
            map.insert("Bowtie index directory", QDir().absoluteFilePath(testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/bowtie2_index/"));
            map.insert("Bowtie index basename", "NC_010473");
            map.insert("Input transcripts annotations", QDir().absoluteFilePath(testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/accepted_hits.bam"));
            GTUtilsWizard::setAllParameters(os, map);

            GTUtilsWizard::clickButton(os, GTUtilsWizard::Apply);
        }
    };

    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "No-new-transcripts"<<"Paired-end"));
    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard", new customWizard()));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");
    GTGlobals::sleep();
//    3. Click {show wizard} toolbar button
//    4. Fill wizard with proper data
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Ok, "Well done!"));
    GTWidget::click( os,GTAction::button(os, "Validate workflow"));
    GTGlobals::sleep();
//    5. Run schema
//    Expected state: Pipeline executed without errors
}

GUI_TEST_CLASS_DEFINITION(test_1681_2){
//    1. Open WD
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
//    2. Add sample: Single dataset tuxedo: Single-end
    QMap<QString, QVariant> map;
    map.insert("Bowtie index directory", QDir().absoluteFilePath(testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/bowtie2_index/"));
    map.insert("Bowtie index basename", "NC_010473");
    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "Single-sample"<<"Single-end"));
    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard",QStringList()<<testDir +
                                                      "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/fastq1/exp_1_1.fastq", map));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");
//    3. Click {show wizard} toolbar button
//    4. Fill wizard with proper data
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Ok, "Well done!"));
    GTWidget::click( os,GTAction::button(os, "Validate workflow"));
    GTGlobals::sleep();

//    5. Run schema
//    Expected state: Pipeline executed without errors
}

GUI_TEST_CLASS_DEFINITION(test_1681_3) {
//    1. Open WD
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
//    2. Add sample: Single dataset tuxedo: Paired-end
    class customWizard : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            GTGlobals::sleep();
            QWidget* dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog, "activeModalWidget is NULL");
            QWizard* wizard = qobject_cast<QWizard*>(dialog);
            CHECK_SET_ERR(wizard, "activeModalWidget is not wizard");

            GTUtilsDialog::waitForDialog(os, new customFileDialog_1681(os, testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/fastq1/exp_1_1.fastq"));
            QList<QWidget* > list = wizard->currentPage()->findChildren<QWidget*>("addFileButton");
            foreach (QWidget* w, list) {
                if(w->isVisible()){
                    GTWidget::click(os, w);
                    break;
                }
            }

            QMap<QString, QVariant> map;
            map.insert("Bowtie index directory", QDir().absoluteFilePath(testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/bowtie2_index/"));
            map.insert("Bowtie index basename", "NC_010473");
            GTUtilsWizard::setAllParameters(os, map);

            GTUtilsWizard::clickButton(os, GTUtilsWizard::Apply);
        }
    };

    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "Single-sample"<<"Paired-end"));
    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard", new customWizard()));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");
    GTGlobals::sleep();
//    3. Click {show wizard} toolbar button
//    4. Fill wizard with proper data
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Ok, "Well done!"));
    GTWidget::click( os,GTAction::button(os, "Validate workflow"));
    GTGlobals::sleep();
//    5. Run schema
//    Expected state: Pipeline executed without errors
}

GUI_TEST_CLASS_DEFINITION(test_1687) {
    // 1. open samples / clustalW / COI.aln
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");

    // 2. Open 'statistic tab'
    GTUtilsOptionPanelMsa::openTab(os, GTUtilsOptionPanelMsa::Statistics);

    // 3. Be sure here is no reference sequence selected.
    QLineEdit *refSeqEdit = qobject_cast<QLineEdit *>(GTWidget::findWidget(os, "sequenceLineEdit"));
    CHECK_SET_ERR(refSeqEdit->text().isEmpty(), "Unexpected reference sequence in MSA");

    QLabel *refSeqWarning = qobject_cast<QLabel *>(GTWidget::findWidget(os, "refSeqWarning"));
    CHECK_SET_ERR(refSeqWarning->isHidden(), "Warning label is unexpectedly visible");

    // 4. Set 'Set distance column' checked
    QCheckBox *check = qobject_cast<QCheckBox *>(GTWidget::findWidget(os, "showDistancesColumnCheck"));
    GTCheckBox::setChecked(os, check);

    // Expected state : hint with green text appears at the bottom of the tab.
    CHECK_SET_ERR(refSeqWarning->isVisible(), "Warning label is unexpectedly invisible");
    CHECK_SET_ERR(!refSeqWarning->text().isEmpty(), "Warning label contains no text");
}

GUI_TEST_CLASS_DEFINITION( test_1688 ) {
    // 1) Open file "_common_data/scenarios/_regression/1688/sr100.000.fa"
    // Expected state: UGENE show error, not crashed
    GTLogTracer l;

    GTUtilsDialog::waitForDialog(os, new SequenceReadingModeSelectorDialogFiller(os) );
    GTFileDialog::openFile( os, testDir + "_common_data/scenarios/_regression/1688/", "sr100.000.fa");
    GTUtilsTaskTreeView::waitTaskFinished(os);
    GTUtilsLog::check( os, l );
}

GUI_TEST_CLASS_DEFINITION(test_1693) {
//    1. Open WD.
//    2. Launch tuxedo pipeline.
//    3. Try to open any other sample while pipeline is running.
//    Expected state: UGENE doesn't crash.
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    QMap<QString, QVariant> map;
    map.insert("Bowtie index directory", QDir().absoluteFilePath(testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/bowtie2_index/"));
    map.insert("Bowtie index basename", "NC_010473");
    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "Full"<<"Single-end"));
    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard", QList<QStringList>()<<(QStringList()<<testDir +
                                                      "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/fastq1/exp_1_1.fastq")<<
                                                      (QStringList()<<testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/test_0004/fastq2/exp_2_1.fastq"), map));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");
    GTUtilsWorkflowDesigner::setCurrentTab(os, GTUtilsWorkflowDesigner::samples);
    GTUtilsWorkflowDesigner::runWorkflow(os);

    GTGlobals::sleep();
    const int tasksCount = GTUtilsTaskTreeView::getTopLevelTasksCount(os);
    CHECK_SET_ERR(1 == tasksCount, QString("An unexpected top level tasks count: expect %1, got %2. Workflow didn't launch?").arg(1).arg(tasksCount));

    GTUtilsWorkflowDesigner::returnToWorkflow(os);
    QWidget *samplesWidget = GTWidget::findWidget(os, "samples");
    CHECK_SET_ERR(NULL != samplesWidget, "Samples widget is NULL");
    CHECK_SET_ERR(!samplesWidget->isEnabled(), "Samples widget is unexpectedly enabled");
}

GUI_TEST_CLASS_DEFINITION(test_1700) {
    //    1. Open file "https://ugene.unipro.ru/tracker/secure/attachment/12864/pdb1a07.ent.gz".
    GTFileDialog::openFile(os, testDir + "_common_data/pdb/", "pdb1a07.ent.gz");

    // Expected state: UGENE displays sequence and 3d structure
    GTUtilsMdi::findWindow(os, "pdb1a07.ent.gz");


    // 2. In context menu of 3d view: {Render style -> Ball-and-Stick}
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<< "Render Style"<< "Ball-and-Stick"));
    GTMenu::showContextMenu(os, GTWidget::findWidget(os, "1-1A07"));

    //3) In context menu of 3d view: {Coloring scheme -> <Any different from current scheme>}
    //Repeat step 3) many times

    bool curSchemeFlag = true;
    for(int i = 0; i < 10; i++) {
        if(curSchemeFlag) {
            GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "Coloring Scheme" << "Chemical Elements"));
            curSchemeFlag = false;
        }
        else {
            GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "Coloring Scheme" << "Secondary Structure"));
            curSchemeFlag = true;
        }
        GTMenu::showContextMenu(os, GTWidget::findWidget(os, "1-1A07"));
    }
}

GUI_TEST_CLASS_DEFINITION( test_1701 ) {
    //1. Open 2 PDB files("_common_data/pdb/1A5H.pdb" and "_common_data/pdb/1CF7.pdb")
    //2. In each of them set {Render style -> Ball and Stick}
    //3. Close one of the views
    //Expected state: UGENE works fine. The opened view is displayed correctly(no black screen instead of molecule).

    GTFileDialog::openFile( os, testDir + "_common_data/pdb", "1A5H.pdb");
    GTFileDialog::openFile( os, testDir + "_common_data/pdb", "1CF7.pdb");

    QWidget* pdb1 = GTWidget::findWidget(os, "1-1A5H");
    QWidget* pdb2 = GTWidget::findWidget(os, "2-1CF7");
    CHECK_SET_ERR( NULL != pdb1, "No 1A5H view");
    CHECK_SET_ERR( NULL != pdb2, "No 1CF7 view");

    GTUtilsProjectTreeView::click(os, "1CF7.pdb");
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<< "Render Style"<< "Ball-and-Stick"));
    GTMenu::showContextMenu(os, pdb2);

    GTGlobals::sleep();
    QPixmap before = QPixmap::grabWidget(pdb2, pdb2->rect());

    GTMouseDriver::moveTo( os, GTUtilsProjectTreeView::getItemCenter(os, "1A5H.pdb"));
    GTMouseDriver::doubleClick(os);

    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<< "Render Style"<< "Ball-and-Stick"));
    GTMenu::showContextMenu(os, pdb1);

    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_ACTIONS), QStringList()<<"Close active view", GTGlobals::UseKey);

    GTGlobals::sleep();
    QPixmap after = QPixmap::grabWidget(pdb2, pdb2->rect());

    GTGlobals::sleep(500);
    CHECK_SET_ERR( before.toImage() == after.toImage(), "The view has changed");
}

GUI_TEST_CLASS_DEFINITION( test_1703 )
{
    // 1. Open document "ma.aln"
    GTFileDialog::openFile( os, testDir + "_common_data/scenarios/msa", "ma.aln" );

    // 2. Select some row in the name list area
    GTUtilsMSAEditorSequenceArea::click( os, QPoint( -5, 6 ) );
    GTGlobals::sleep(200);
    GTUtilsMSAEditorSequenceArea::checkSelectedRect( os, QRect( 0, 6, 12, 1 ) );

    GTKeyboardDriver::keyPress(os,GTKeyboardDriver::key["shift"]);
    // 3. Select the upper row
    GTKeyboardDriver::keyClick( os, GTKeyboardDriver::key["up"] );
    GTGlobals::sleep(500);
    GTUtilsMSAEditorSequenceArea::checkSelectedRect( os, QRect( 0, 5, 12, 2 ) );

    // 4. Select the bottom row
    GTKeyboardDriver::keyClick( os, GTKeyboardDriver::key["down"] );
    GTGlobals::sleep(500);
    GTKeyboardDriver::keyClick( os, GTKeyboardDriver::key["down"] );
    GTGlobals::sleep(500);
    GTKeyboardDriver::keyRelease(os,GTKeyboardDriver::key["shift"]);
    GTUtilsMSAEditorSequenceArea::checkSelectedRect( os, QRect( 0, 6, 12, 2 ) );
}

GUI_TEST_CLASS_DEFINITION( test_1704 ){
//    1. Open _common_data\_regession\1704\lrr_test_new.gb
    GTFileDialog::openFile( os, testDir + "_common_data/regression/1704", "lrr_test_new.gb" );
//    2. Search HMM3 signals with _common_data\_regession\1704\LRR_4.hmm model
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()
                                                      << "ADV_MENU_ANALYSE"
                                                      << "Search HMM signals with HMMER3"));
    GTUtilsDialog::waitForDialog(os, new UHMM3SearchDialogFiller(os, testDir + "_common_data/regression/1704/LRR_4.hmm",
                                                                 sandBoxDir + "1704.gb"));

    GTMenu::showMainMenu(os, "mwmenu_actions");
    GTGlobals::sleep(1000);
//    3. Export document with annotations into genbank format. Do not add to the project
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "Export document"));
    GTUtilsDialog::waitForDialog(os, new ExportDocumentDialogFiller(os, sandBoxDir, "1704_exported.gb"));
    GTUtilsProjectTreeView::click(os, "1704.gb", Qt::RightButton);
    GTGlobals::sleep();
//    4. Open the exported file with UGENE
    GTFileDialog::openFile(os, sandBoxDir, "1704_exported.gb");
    GTUtilsProjectTreeView::doubleClickItem(os, "1704_exported.gb");
    GTGlobals::sleep(1000);
//    Expected state: all the annotations of the new file are identical to annotations of the old file
    GTUtilsAnnotationsTreeView::findItem(os, "hmm_signal  (0, 27)");
//    Bug state: only the first annotations without qualifiers is opened
}

GUI_TEST_CLASS_DEFINITION(test_1708){
    //1. Open COI.aln or HIV-1.aln from samples
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "COI.aln");

    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(0,0), QPoint(9,1));
    GTKeyboardDriver::keyClick(os, 'c', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(500);
    QString initAln = GTClipboard::text(os);

    QString expectedAln("TAAGACTT-C\n"
                        "TAAG-CTTAC");

    //2. Align with KAlign
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList()<<MSAE_MENU_ALIGN<<"align_with_kalign", GTGlobals::UseKey));
    GTUtilsDialog::waitForDialog(os, new KalignDialogFiller(os,10));
    GTMenu::showContextMenu(os, GTUtilsMdi::activeWindow(os));
    GTUtilsTaskTreeView::waitTaskFinished(os);

    GTWidget::click(os, GTUtilsMdi::activeWindow(os));
    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(0,0), QPoint(9,1));
    GTKeyboardDriver::keyClick(os, 'c', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(500);
    QString changedAln = GTClipboard::text(os);
    CHECK_SET_ERR(changedAln==expectedAln, "Unexpected alignment\n" + changedAln);

    QAbstractButton *undo= GTAction::button(os,"msa_action_undo");

    //3. Press Undo
    GTWidget::click(os,undo);
    GTWidget::click(os, GTUtilsMdi::activeWindow(os));
    GTUtilsMSAEditorSequenceArea::selectArea(os, QPoint(0,0), QPoint(9,1));
    GTKeyboardDriver::keyClick(os, 'c', GTKeyboardDriver::key["ctrl"]);
    GTGlobals::sleep(500);
    changedAln = GTClipboard::text(os);

    CHECK_SET_ERR(changedAln==initAln, "Undo works wrong\n" + changedAln);
}

GUI_TEST_CLASS_DEFINITION(test_1710_1){
    //1. Open WD.
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    //2. Add the "Find Patterns" sample.
    GTUtilsWorkflowDesigner::addSample(os, "Find patterns");

    //3. Setup inputs and outputs.
    GTUtilsWorkflowDesigner::addInputFile(os, "Read Sequence", dataDir + "samples/FASTA/human_T1.fa");
    GTUtilsWorkflowDesigner::click(os, "Find Pattern");
    GTUtilsWorkflowDesigner::setParameter(os, "Pattern(s)", "AAA", GTUtilsWorkflowDesigner::textValue);

    //4) Press the validate button.
    //Expected state: The message appeared saying "Well done!".
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Ok, "Well done!"));
    GTWidget::click( os,GTAction::button(os, "Validate workflow"));
}

GUI_TEST_CLASS_DEFINITION(test_1710_2){
    //1. Open Settings -> Preferences -> External Tools.
    //2. Select any invalid file for Blast -> BlastAll.
    GTUtilsExternalTools::setToolUrl(os, "BlastAll", dataDir + "samples/FASTA/human_T1.fa");

    //3. Open WD.
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    //4. Add the "Gene-by-gene approach" sample.
    GTUtilsWorkflowDesigner::addSample(os, "Gene-by-gene approach");

    //5. Setup inputs and outputs.
    GTUtilsWorkflowDesigner::addInputFile(os, "Read Sequence", dataDir + "samples/FASTA/human_T1.fa");
    GTUtilsWorkflowDesigner::click(os, "Local BLAST Search");
    GTUtilsWorkflowDesigner::setParameter(os, "Database Path", sandBoxDir, GTUtilsWorkflowDesigner::textValue);
    GTUtilsWorkflowDesigner::setParameter(os, "Database Name", "test", GTUtilsWorkflowDesigner::textValue);

    //6. Press the validate button.
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Ok, "non-critical warnings"));
    GTWidget::click( os,GTAction::button(os, "Validate workflow"));

    //Expected state: there must be a warning "External tool is invalid. UGENE may not support this version of the tool or a wrong path to the tools is selected".
    GTUtilsWorkflowDesigner::checkErrorList(os, "External tool \"BlastAll\" is invalid. UGENE may not support this version of the tool or a wrong path to the tools is selected");
}

GUI_TEST_CLASS_DEFINITION(test_1714){
//    1. Open the "external tools" configuration window using Settings/Preferences menu
//    2. Select path for external tools package (if not set). External tools package can be downloaded from http://ugene.unipro.ru/external.html
//    3. Deselect all Cistrome tools
//    4. Deselect python external tool
//    Expected state: the python tool is deselected. UGENE doesn't hangs up (or crashes)

    class DeselectCistromeAndPython : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            QStringList cistromeTools;
            cistromeTools << "go_analysis" << "seqpos" << "conservation_plot" << "peak2gene"
                          << "MACS" << "CEAS Tools";

            foreach (QString toolName, cistromeTools) {
                AppSettingsDialogFiller::clearToolPath(os, toolName);
            }
            GTGlobals::sleep(2000);

            AppSettingsDialogFiller::clearToolPath(os, "python");
            GTGlobals::sleep(2000);

            QWidget *dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog, "activeModalWidget is NULL");
            GTUtilsDialog::clickButtonBox(os, dialog, QDialogButtonBox::Ok);
        }
    };

    GTLogTracer l;
    GTUtilsDialog::waitForDialog(os, new AppSettingsDialogFiller(os, new DeselectCistromeAndPython()));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "action__settings"));
    GTMenu::showMainMenu(os, MWMENU_SETTINGS);
    GTGlobals::sleep();
}

GUI_TEST_CLASS_DEFINITION(test_1720){
//1. Use menu {File->Access remote database...}
    GTUtilsDialog::waitForDialog(os, new RemoteDBDialogFillerDeprecated(os, "D11266", 0));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_FILE), QStringList()<<ACTION_PROJECTSUPPORT__ACCESS_REMOTE_DB, GTGlobals::UseKey);

    GTLogTracer l;
    GTGlobals::sleep(8000);//some time needed for request
//2. Fill field "Resource ID" with value D11266. Click "OK"

//3. Use menu {File->Access remote database...}
    GTUtilsDialog::waitForDialog(os, new RemoteDBDialogFillerDeprecated(os, "D11266", 0));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_FILE), QStringList()<<ACTION_PROJECTSUPPORT__ACCESS_REMOTE_DB, GTGlobals::UseKey);

    GTGlobals::sleep(8000);
//4. Fill field "Resource ID" with value D11266. Click "OK"
    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "D11266.gb"));
    GTUtilsLog::check(os,l);
//Expected state: project view with document "D11266.gb", no error messages in log appear
}

GUI_TEST_CLASS_DEFINITION(test_1747){
    //1. Open \data\samples\CLUSTALW\ty3.aln.gz
    //2. Enable the distances column in options panel or create distances matrix by using menu {statistics->Generate distance matrix}
    //Expected state: progress for "Generete distance matrix" correctly displays current state of calculation
    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "ty3.aln.gz");
    GTUtilsDialog::waitForDialog(os, new PopupChooserbyText(os, QStringList() << "Statistics" << "Generate distance matrix"));
    GTUtilsDialog::waitForDialog(os, new DistanceMatrixDialogFiller(os));
    GTUtilsMSAEditorSequenceArea::callContextMenu(os);


    QProgressBar* taskProgressBar = GTWidget::findExactWidget<QProgressBar*>(os, "taskProgressBar");
    QString text = taskProgressBar->text();
    CHECK_SET_ERR(text.contains("%"), "unexpected text: " + text);
    text = text.left(text.length() - 1);
    bool isNumber = false;
    int progress = text.toInt(&isNumber);
    CHECK_SET_ERR(isNumber, QString("The progress must be a number: %1").arg(text));
    CHECK_SET_ERR(progress >= 0 && progress <= 100, QString("Incorrect progress: %1").arg(progress));
    int oldProgress = progress;

    GTGlobals::sleep(5000);
    text = taskProgressBar->text();
    CHECK_SET_ERR(text.contains("%"), "unexpected text: " + text);
    text = text.left(text.length() - 1);
    isNumber = false;
    progress = text.toInt(&isNumber);
    CHECK_SET_ERR(isNumber, QString("The progress must be a number: %1").arg(text));
    CHECK_SET_ERR(progress >= 0 && progress <= 100, QString("Incorrect progress: %1").arg(progress));

    CHECK_SET_ERR(progress > oldProgress, "Progress didn't groving up");
}
GUI_TEST_CLASS_DEFINITION(test_1756){
/*  1. Open WD.
    2. Add the element "Collect Motifs with SeqPos" to the scene.
    3. Click the element.
    Expected: the property "Motif database" is not required (no bold text).
*/
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
    GTUtilsWorkflowDesigner::addAlgorithm(os, "Collect Motifs with SeqPos");
    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Collect Motifs with SeqPos"));
    GTMouseDriver::click(os);
    GTUtilsWorkflowDesigner::setParameter(os, "Motif database", QStringList(), GTUtilsWorkflowDesigner::ComboChecks);
    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Collect Motifs with SeqPos"));
    GTMouseDriver::click(os);

    GTUtilsDialog::waitForDialog( os, new MessageBoxDialogFiller( os, QMessageBox::Ok,
        "Please fix issues listed in the error list (located under workflow)."));
    GTWidget::click(os,GTAction::button( os,"Validate workflow" ));
    GTGlobals::sleep(500);


    CHECK_SET_ERR( 0 == GTUtilsWorkflowDesigner::checkErrorList( os, "Required parameter is not set: Motif database" ),
                   "The property Motif database is required. This is wrong.");

}
GUI_TEST_CLASS_DEFINITION(test_1731){
    //1. Open \data\samples\CLUSTALW\ty3.aln.gz

    //2. Select CopCinTy34 as a reference

    //3. Enable the distances column

    //4. Select the Identity algorithm
    //Expected state: identity of CopCinTy34 with each sequence is shown in the column

    GTFileDialog::openFile(os, dataDir + "samples/CLUSTALW", "ty3.aln.gz");
    GTWidget::click(os, GTWidget::findWidget(os, "OP_SEQ_STATISTICS_WIDGET"));
    GTUtilsMSAEditorSequenceArea::click(os, QPoint(-5, 5));
    GTWidget::click(os, GTWidget::findWidget(os, "addSeq"));
    QCheckBox* showDistancesColumnCheck = qobject_cast<QCheckBox*>(GTWidget::findWidget(os, "showDistancesColumnCheck"));
    GTCheckBox::setChecked(os, showDistancesColumnCheck, true);
    GTUtilsTaskTreeView::waitTaskFinished(os, 200000);
    QString num1 = GTUtilsMSAEditorSequenceArea::getSimilarityValue(os, 1);
    QString num3 = GTUtilsMSAEditorSequenceArea::getSimilarityValue(os, 3);
    CHECK_SET_ERR(num1 != "100%", "unexpected sumilarity value an line 1: " + num1);
    CHECK_SET_ERR(num3 != "100%", "unexpected sumilarity value an line 3: " + num3);
}

GUI_TEST_CLASS_DEFINITION(test_1733){
    // 1) Run UGENE
    // 2) Open Workflow Designer
    // 3) Open Call Variant Pipeline scheme from the samples
    // 4) Try to specify parameters (using wizard or wd standard interface) with files
    // (for example specify any of file from "data/samples/Genbank" directory as "Bed or position list file" on page #2 of wizard )
    // Expected state: UGENE doesn't ask to specify folder
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    GTUtilsWorkflowDesigner::addSample(os, "Call variants with SAMtools");

    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Read Assembly (BAM/SAM)"));
    GTMouseDriver::click(os);
    GTUtilsWorkflowDesigner::setDatasetInputFile(os, dataDir + "samples/Assembly/", "chrM.sam");

    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Read Sequence"));
    GTMouseDriver::click(os);
    GTUtilsWorkflowDesigner::setDatasetInputFile(os, dataDir + "samples/Assembly/", "chrM.fa");

}

GUI_TEST_CLASS_DEFINITION(test_1734){
//    1. Open WD
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
//    2. Select "Call variants sample"

    class custom : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            QWidget *dialog = QApplication::activeModalWidget();
            QWizard* wizard = qobject_cast<QWizard*>(dialog);
            CHECK_SET_ERR(wizard, "activeModalWidget is not wizard");

            GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, testDir + "_common_data/NIAID_pipelines/Call_variants/input_data/chrM/chrM.sorted.bam"));
            GTWidget::click(os, GTWidget::findWidget(os, "addFileButton", wizard->currentPage()));
            GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, testDir + "_common_data/NIAID_pipelines/Call_variants/input_data/chrM/chrM.sorted.bam"));
            GTWidget::click(os, GTWidget::findWidget(os, "addFileButton", wizard->currentPage()));
            GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, testDir + "_common_data/NIAID_pipelines/Call_variants/input_data/chrM/chrM.sorted.bam"));
            GTWidget::click(os, GTWidget::findWidget(os, "addFileButton", wizard->currentPage()));

            QListWidget* itemsArea = GTWidget::findExactWidget<QListWidget*>(os, "itemsArea", wizard);
            CHECK_SET_ERR(itemsArea->count()==3,"unexpected items number");

            GTUtilsWizard::clickButton(os, GTUtilsWizard::Cancel);
        }
    };

    GTUtilsWorkflowDesigner::addSample(os, "Call variants with SAMtools");
//    3. Open wizard. Try to add several bams on the first page
    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Call Variants Wizard", new custom()));
    GTWidget::click(os, GTAction::button(os, "Show wizard"));
//    Expected state: adding several bams is enebled
}

GUI_TEST_CLASS_DEFINITION(test_1735){
//    1) Run UGENE
//    2) Open Workflow Designer
    GTLogTracer l;
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
//    3) Open Call variant pipeline scheme from samples

    class custom : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            QWidget *dialog = QApplication::activeModalWidget();
            QWizard* wizard = qobject_cast<QWizard*>(dialog);
            CHECK_SET_ERR(wizard, "activeModalWidget is not wizard");

            GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, testDir + "_common_data/NIAID_pipelines/Call_variants/input_data/chrM/chrM.fa"));
            GTWidget::click(os, GTWidget::findWidget(os, "browseButton", GTWidget::findWidget(os, "Reference sequence file labeledWidget", dialog)));

            GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, testDir + "_common_data/NIAID_pipelines/Call_variants/input_data/chrM/chrM.sorted.bam"));
            GTWidget::click(os, GTWidget::findWidget(os, "addFileButton", wizard->currentPage()));

            GTUtilsWizard::clickButton(os, GTUtilsWizard::Next);
            GTUtilsWizard::clickButton(os, GTUtilsWizard::Next);
            GTUtilsWizard::clickButton(os, GTUtilsWizard::Next);

            QString title = GTUtilsWizard::getPageTitle(os);
            CHECK_SET_ERR(title == "SAMtools <i>vcfutils varFilter</i> parameters", "unexpected title: " + title);

            GTUtilsWizard::clickButton(os, GTUtilsWizard::Next);
            GTUtilsWizard::clickButton(os, GTUtilsWizard::Run);
        }
    };

    GTUtilsWorkflowDesigner::addSample(os, "Call variants with SAMtools");
//    4) Click on "Show wizard" at the top of WD window yo specify vcfutils.pl parameters (page #4 of Call Variants Wizard)
//    5) Run scheme at last page (if you specify all parameters: SAM/BAM file for Read Assembly and sequence file for Read Sequence)
    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Call Variants Wizard", new custom()));
    GTWidget::click(os, GTAction::button(os, "Show wizard"));

//    Expected state: there are no errors when this pipeline scheme is running
    GTUtilsTaskTreeView::waitTaskFinished(os);
    GTUtilsLog::check(os, l);
}

GUI_TEST_CLASS_DEFINITION(test_1738){
    // 1. Open WD and load "Call variants with SAMtools" scheme from samples
    // 2. Set files "_common_data/fasta/Mycobacterium.fna" and "_common_data/bam/Mycobacterium.sorted.bam" as input reference
    // and assembly respectively.
    // 2. Run the Call Variants pipeline with standard options
    // 3. Press "Stop scheme" button on the main toolbar
    // Expected state: the pipeline is stopped almost immediately

    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    GTUtilsWorkflowDesigner::addSample(os, "Call variants with SAMtools");

    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Read Assembly (BAM/SAM)"));
    GTMouseDriver::click(os);
    GTUtilsWorkflowDesigner::setDatasetInputFile(os, testDir + "bam/", "Mycobacterium.sorted.bam");

    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Read Sequence"));
    GTMouseDriver::click(os);
    GTUtilsWorkflowDesigner::setDatasetInputFile(os, testDir + "fasta/", "Mycobacterium.fa");

    GTWidget::click(os,GTAction::button(os,"Run workflow"));
    GTGlobals::sleep(5000);

    GTWidget::click(os,GTAction::button(os,"Run workflow"));
    GTGlobals::sleep(5000);

}

GUI_TEST_CLASS_DEFINITION(test_1751){
    //1. Prepend dot symbol to some valid file name, for instance "data/samples/COI.aln" => "data/samples/.COI.aln"
    //2. Open it
    GTLogTracer lt;
    GTUtilsProject::openFiles(os, testDir + "_common_data/scenarios/_regression/1751/.COI.aln");

    //Expected state: Check log for errors
    CHECK_SET_ERR(!lt.hasError(), "Log sholdn't contain errors");
}

GUI_TEST_CLASS_DEFINITION(test_1759){
//    1. Open file "data/workflow_samples/NGS/tuxedo/tuxedo_main.uwl"
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
//    2. Press "Show wizard" button on the main toolbar

    class custom : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            QWidget* dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog, "activeModalWidget is NULL");
            //    2. Go to the second page
            GTUtilsWizard::clickButton(os, GTUtilsWizard::Next);
            if(GTUtilsWizard::getPageTitle(os) != "Tophat settings"){
                GTUtilsWizard::clickButton(os, GTUtilsWizard::Next);
            }
            GTGlobals::sleep();
            QWidget* version = GTWidget::findWidget(os, "Bowtie version widget", dialog);
            CHECK_SET_ERR(version->isVisible(), "version widget is not visiable");

            GTUtilsWizard::clickButton(os, GTUtilsWizard::Cancel);
        }
    };
    //single
    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard", new custom()));
    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "Full"<<"Single-end"));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");

    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard", new custom()));
    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "Single-sample"<<"Single-end"));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");

    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard", new custom()));
    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "No-new-transcripts"<<"Single-end"));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");

    //paired
    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard", new custom()));
    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "Full"<<"Paired-end"));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");

    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard", new custom()));
    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "Single-sample"<<"Paired-end"));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");

    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard", new custom()));
    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "No-new-transcripts"<<"Paired-end"));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");
//    Expected state: "Tuxedo Wizard" dialog has appeared

//    3. Press the "Next" button

//    Expected state: the "TopHat input" groupbox contains the following fields: "Bowtie index directory",
//    "Bowtie index basename", "Bowtie version".

//    4. Repeat 2nd and 3rd steps for all the versions of the Tuxedo pipeline
}

GUI_TEST_CLASS_DEFINITION(test_1771){
//    1. Open WD
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
//    2. Select tuxedo sample
    class custom : public CustomScenario {
    public:
        void run(U2OpStatus &os) {
            QWidget* dialog = QApplication::activeModalWidget();
            CHECK_SET_ERR(dialog, "activeModalWidget is NULL");
            //    2. Go to the second page
            GTUtilsWizard::clickButton(os, GTUtilsWizard::Next);
            GTUtilsWizard::clickButton(os, GTUtilsWizard::Next);

            //    3. Set bowtie index and a known transcript file.(_common_data/NIAID_pipelines/tuxedo)
            GTUtilsDialog::waitForDialog(os, new GTFileDialogUtils(os, testDir + "_common_data/NIAID_pipelines/tuxedo_pipeline/data/index/chr6.1.ebwt"));
            GTWidget::click(os, GTWidget::findButtonByText(os, "Select\nbowtie index file", dialog));

            QString name = GTUtilsWizard::getParameter(os, "Bowtie index basename").toString();
            QString version = GTUtilsWizard::getParameter(os, "Bowtie version").toString();
            CHECK_SET_ERR(name == "chr6", "unexpected name: " + name);
            CHECK_SET_ERR(version == "Bowtie1", "unexpected bowtie version: " + version);

            GTUtilsWizard::clickButton(os, GTUtilsWizard::Cancel);
        }
    };

    GTUtilsDialog::waitForDialog(os, new WizardFiller(os, "Tuxedo Wizard", new custom()));
    GTUtilsDialog::waitForDialog(os, new ConfigurationWizardFiller(os, "Configure Tuxedo Workflow", QStringList()<<
                                                                   "Full"<<"Single-end"));
    GTUtilsWorkflowDesigner::addSample(os, "RNA-seq analysis with Tuxedo tools");
//    3. Select some configuration
//    Expected state: wizard appeared
//    4. go to "tophat settings" page. click button "Select bowtie index file"
//    5. select file _common_data/NIAID_pipelines/tuxedo_pipeline/data/index/chr6.1.ebwt
//    Expected state: bowtie index basename is set to "chr6", bowtie version is set to "bowtie1"
}

GUI_TEST_CLASS_DEFINITION(test_1784){
    //1. Open murine.gb
    GTFileDialog::openFile(os, dataDir + "/samples/Genbank/", "murine.gb");

    //2. Export it as alignment
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << ACTION_PROJECT__EXPORT_IMPORT_MENU_ACTION << ACTION_EXPORT_SEQUENCE_AS_ALIGNMENT));
    GTUtilsDialog::waitForDialog(os, new ExportSequenceAsAlignmentFiller(os, testDir + "_common_data/scenarios/sandbox", "test_1784.aln", ExportSequenceAsAlignmentFiller::Clustalw, true));
    GTMouseDriver::moveTo(os, GTUtilsProjectTreeView::getItemCenter(os, "NC_001363"));
    GTMouseDriver::click(os, Qt::RightButton);
    GTGlobals::sleep();
    //3. Drag and drop one more murine sequence object to the alignment
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << MSAE_MENU_LOAD << "Sequence from current project"));
    GTUtilsDialog::waitForDialog(os, new ProjectTreeItemSelectorDialogFiller(os, "murine.gb", "NC_001363"));
    GTMenu::showMainMenu(os, MWMENU_ACTIONS);
    GTGlobals::sleep();

    //4. Select the first sequence as reference
    GTUtilsMSAEditorSequenceArea::moveTo(os, QPoint(0,0));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "set_seq_as_reference"));
    GTMouseDriver::click(os, Qt::RightButton);

    GTUtilsMSAEditorSequenceArea::moveTo(os, QPoint(0,1));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << "set_seq_as_reference"));
    GTMouseDriver::click(os, Qt::RightButton);
    //Expected state: The only selected sequence is the reference.
}

GUI_TEST_CLASS_DEFINITION(test_1786){
    // 1. Use menu {File->Access remote database...}
    // 2. Select database UniProt(DAS)
    // 3. Fill resource id: 1CRN. Press ok
    GTUtilsDialog::waitForDialog(os, new RemoteDBDialogFillerDeprecated(os, "1CRN", 7));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_FILE), QStringList()<<ACTION_PROJECTSUPPORT__ACCESS_REMOTE_DB, GTGlobals::UseKey);
    GTUtilsTaskTreeView::waitTaskFinished(os);
    // Expected state: document P01542_das.gb appeared in project
    GTUtilsProjectTreeView::findIndex(os, "P01542_das.gb");
}

GUI_TEST_CLASS_DEFINITION(test_1797){
    // 1) Open _common_data\scenarios\formats\test_1797 file
    // 2) Choose "BED" format at appeared format dialog
    // Expected state: UGENE doesn't crash - it shows error: "BED parsing error: incorrect number of fields at line 1!"

    GTUtilsDialog::waitForDialog(os, new SelectDocumentFormatDialogFiller(os));
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/formats", "test_1797.svg");
}

GUI_TEST_CLASS_DEFINITION(test_1798){
    //1. Open file _common_data\scenarios\_regression\1798\1.4k.aln.
    GTFileDialog::openFile(os, testDir + "_common_data/scenarios/_regression/1798", "1.4k.aln");
    //2. Start MAFFT with default values.
    GTUtilsDialog::waitForDialog(os, new MAFFTSupportRunDialogFiller(os, new MAFFTSupportRunDialogFiller::Parameters()));
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << MSAE_MENU_ALIGN << "Align with MAFFT", GTGlobals::UseMouse));
    GTWidget::click(os, GTUtilsMdi::activeWindow(os), Qt::RightButton);
    GTGlobals::sleep(3000);

    //3. Open Tasks tab
    //   Expected state: check tasks progress percentage is correct
    QProgressBar* taskProgressBar = GTWidget::findExactWidget<QProgressBar*>(os, "taskProgressBar");
    QString text = taskProgressBar->text();
    CHECK_SET_ERR(text.contains("%"), "unexpected text: " + text);
    text = text.left(text.length() - 1);
    bool isNumber = false;
    int progress = text.toInt(&isNumber);
    CHECK_SET_ERR(isNumber, QString("The progress must be a number: %1").arg(text));
    CHECK_SET_ERR(progress >= 0 && progress <= 100, QString("Incorrect progress: %1").arg(progress));
    GTUtilsTaskTreeView::waitTaskFinished(os);
}

GUI_TEST_CLASS_DEFINITION(test_1807) {
    //1. Open {data/samples/FASTA/human_T1.fa}
    GTFileDialog::openFile(os, dataDir + "samples/FASTA", "human_T1.fa");

    //Expected state: there isn't the "DAS Annotations" tab on the options panel.
    QWidget *dasButton = GTWidget::findWidget(os, "OP_DAS", NULL, GTGlobals::FindOptions(false));
    CHECK_SET_ERR(NULL == dasButton, "DAS Annotations button is shown for a nucleic sequence");

    //2. Open {data/samples/Swiss-Prot/P01375.txt} as Swiss-Prot file.
    GTUtilsDialog::waitForDialog(os, new SelectDocumentFormatDialogFiller(os));
    GTFileDialog::openFile(os, dataDir + "samples/Swiss-Prot", "P01375.txt");

    //Expected state: there is the "DAS Annotations' tab on the options panel.
    dasButton = GTWidget::findWidget(os, "OP_DAS");
}

GUI_TEST_CLASS_DEFINITION(test_1808) {
    QDir outputDir(testDir + "_common_data/scenarios/sandbox");
    const QString outputFilePath = outputDir.absolutePath( ) + "/test_1808.gb";

    // 1.Open WD
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    // 2.Create schema "Read Annotations"->"Write annotations"
    GTUtilsWorkflowDesigner::addAlgorithm(os, "Read Annotations");
    GTUtilsWorkflowDesigner::addAlgorithm(os, "Write Annotations");
    WorkflowProcessItem *read = GTUtilsWorkflowDesigner::getWorker(os, "Read Annotations");
    WorkflowProcessItem *write = GTUtilsWorkflowDesigner::getWorker(os, "Write Annotations");
    GTUtilsWorkflowDesigner::connect(os, read, write);

    // 3.Select any input and output file
    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Read Annotations"));
    GTMouseDriver::click(os);
    GTUtilsWorkflowDesigner::setDatasetInputFile(os, dataDir + "samples/Genbank", "sars.gb");
    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Write Annotations"));
    GTMouseDriver::click(os);
    GTUtilsWorkflowDesigner::setParameter(os, "Output file", outputFilePath, GTUtilsWorkflowDesigner::textValue);

    // 4.Validate schema
    // Expected state: No warning about empty input sequence slot
    GTUtilsDialog::waitForDialog(os, new MessageBoxDialogFiller(os, QMessageBox::Ok, "Well done!"));
    GTWidget::click( os,GTAction::button( os,"Validate workflow" ) );
}

GUI_TEST_CLASS_DEFINITION(test_1811_1) {
    GTUtilsDialog::waitForDialog(os, new RemoteDBDialogFillerDeprecated(os, "A0N8V2", 5));
    GTUtilsDialog::waitForDialog(os, new SelectDocumentFormatDialogFiller(os));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_FILE), QStringList()<<ACTION_PROJECTSUPPORT__ACCESS_REMOTE_DB, GTGlobals::UseKey);

    GTGlobals::sleep(10000);//some time needed for request
    GTUtilsDocument::isDocumentLoaded(os, "A0N8V2.txt");
}

GUI_TEST_CLASS_DEFINITION( test_1813 )
{
    // 1) Select the menu {File->Access remote database}
    // 2) Fill the "Fetch Data from Remote Database" dialog with the next values:
    //      Resource ID: I7G8J3
    //      Database: UniProt (DAS)
    // 3) Press "OK"
    GTUtilsDialog::waitForDialog(os, new RemoteDBDialogFillerDeprecated(os, "I7G8J3", 7));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_FILE), QStringList()<<ACTION_PROJECTSUPPORT__ACCESS_REMOTE_DB, GTGlobals::UseMouse);

    // Expected: the sequence view with I7G8J3 sequence is opened. UGENE does not crash.
    GTGlobals::sleep(5000);
    GTUtilsTaskTreeView::waitTaskFinished(os);
    GTUtilsDocument::isDocumentLoaded(os, "I7G8J3_das.gb");
    GTUtilsDocument::checkDocument(os, "I7G8J3_das.gb", AnnotatedDNAViewFactory::ID);
}

GUI_TEST_CLASS_DEFINITION( test_1821 ) {
    QString workflowOutputDirPath( testDir + "_common_data/scenarios/sandbox" );
    QDir workflowOutputDir( workflowOutputDirPath );

    GTUtilsDialog::waitForDialog( os, new StartupDialogFiller( os,
        workflowOutputDir.absolutePath( ) ) );

    //1. Open WD
    QMenu* menu=GTMenu::showMainMenu( os, MWMENU_TOOLS );
    GTMenu::clickMenuItemByName( os, menu, QStringList() << ToolsMenu::WORKFLOW_DESIGNER );
    GTGlobals::sleep( 500 );

    //2. Select "Align sequences with MUSCLE"
//    GTUtilsWorkflowDesigner::addSample( os, "Align sequences with MUSCLE" );
//    GTGlobals::sleep( 500 );

//    //3. Change the value of the scale spinbox. E.g. set it to 75%
//    QComboBox *scaleCombo = dynamic_cast<QComboBox *>( GTWidget::findWidget( os, "wdScaleCombo" ) );
//    CHECK_SET_ERR( NULL != scaleCombo, "Unable to find scale combobox!" );
//    GTComboBox::setIndexWithText( os, scaleCombo, "75%" );

    //4. Store the scheme to some file using "Save scheme as" button
//    GTUtilsDialog::waitForDialog( os, new WorkflowMetaDialogFiller( os,
//        workflowOutputDir.absolutePath( ) + "/" + "test.uwl", "Scheme") );
//    GTMenu::clickMenuItemByName( os, GTMenu::showMainMenu( os, MWMENU_ACTIONS ),
//        QStringList( ) <<  "Save workflow action", GTGlobals::UseKey );

//    //5. Close WD
//    GTUtilsMdi::click( os, GTGlobals::Close );
//    GTMouseDriver::click( os );

    //6. Open the file containing the saved scheme using "Open" button
//    GTFileDialog::openFile( os, workflowOutputDirPath, "test.uwl" );

//    //Expected state: scheme is opened in WD, its scale is 75%
//    scaleCombo = dynamic_cast<QComboBox *>( GTWidget::findWidget( os, "wdScaleCombo" ) );
//    CHECK_SET_ERR( NULL != scaleCombo, "Unable to find scale combobox!" );
//    CHECK_SET_ERR( scaleCombo->currentText( ) == "75%", "Unexpected scale value!" );
//    GTGlobals::sleep();
}

GUI_TEST_CLASS_DEFINITION(test_1831) {
    // 1) Create a schema with shrunk elements state.
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
    GTUtilsWorkflowDesigner::addSample(os, "Align sequences with MUSCLE");

    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Align with MUSCLE"));
    GTMouseDriver::doubleClick(os);

    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Write alignment"));
    GTMouseDriver::doubleClick(os);

    CHECK_SET_ERR(!GTUtilsWorkflowDesigner::isWorkerExtended(os, "Align with MUSCLE"), "\"Align with MUSCLE\" unexpectedly has extended style");
    CHECK_SET_ERR(!GTUtilsWorkflowDesigner::isWorkerExtended(os, "Write alignment"), "\"Write alignment\" unexpectedly has extended style");
    CHECK_SET_ERR(GTUtilsWorkflowDesigner::isWorkerExtended(os, "Read alignment"), "\"Read alignment\" unexpectedly has simple style");

    // 2) Save the schema.
    const QString workflowOutputDirPath(testDir + "_common_data/scenarios/sandbox");
    QDir workflowOutputDir(workflowOutputDirPath);

    GTUtilsDialog::waitForDialog(os, new WorkflowMetaDialogFiller(os, workflowOutputDir.absolutePath() + "/" + "test.uwl", "Workflow"));
    GTMenu::clickMenuItemByName(os, GTMenu::showMainMenu(os, MWMENU_ACTIONS), QStringList() << "Save workflow action", GTGlobals::UseKey);

    GTUtilsMdi::click(os, GTGlobals::Close);
    GTMouseDriver::click(os);

    // 3) Reopen UGENE WD.
    GTFileDialog::openFile(os, workflowOutputDirPath, "test.uwl");

    // Expected: the state is saved.
    CHECK_SET_ERR(!GTUtilsWorkflowDesigner::isWorkerExtended(os, "Align with MUSCLE"), "\"Align with MUSCLE\" unexpectedly has extended style");
    CHECK_SET_ERR(!GTUtilsWorkflowDesigner::isWorkerExtended(os, "Write alignment"), "\"Write alignment\" unexpectedly has extended style");
    CHECK_SET_ERR(GTUtilsWorkflowDesigner::isWorkerExtended(os, "Read alignment"), "\"Read alignment\" unexpectedly has simple style");
}

GUI_TEST_CLASS_DEFINITION(test_1834) {
    //1. Open WD.
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    //2. Drag the "Read Alignment" and "File Format Conversion" elements to the scene and link them.
    WorkflowProcessItem *reader = GTUtilsWorkflowDesigner::addElement(os, "Read Alignment");
    WorkflowProcessItem *converter = GTUtilsWorkflowDesigner::addElement(os, "File Format Conversion");
    GTUtilsWorkflowDesigner::connect(os, reader, converter);

    //3. Set the input file for the "Read Alignment" element to "data/samples/COI.aln".
    GTUtilsWorkflowDesigner::addInputFile(os, "Read Alignment", dataDir + "samples/CLUSTALW/COI.aln");

    //4. Set the "Document format" parameter of the "File Format Conversion" element to "mega".
    GTUtilsWorkflowDesigner::click(os, "File Format Conversion");
    GTUtilsWorkflowDesigner::setParameter(os, "Document format", "mega", GTUtilsWorkflowDesigner::comboValue, GTGlobals::UseMouse);
    GTUtilsWorkflowDesigner::setParameter(os, "Output directory", 0, GTUtilsWorkflowDesigner::comboValue, GTGlobals::UseMouse);
    GTUtilsWorkflowDesigner::setParameter(os, "Custom directory", QDir().absoluteFilePath(sandBoxDir + "regression_1834"), GTUtilsWorkflowDesigner::textValue);

    //5. Run the scheme.
    GTWidget::click(os, GTAction::button(os, "Run workflow"));
    GTUtilsTaskTreeView::waitTaskFinished(os);

    //Expected state: Scheme ran successfully, the "COI.aln.mega" output file has appeared on the "Output Files" panel of the dashboard.
    //The output file is valid, might be opened with MSA editor and has the same content as the source file.
    CHECK_SET_ERR(QFile::exists(sandBoxDir + "regression_1834/COI.aln.meg"), "File does not exist");
}

GUI_TEST_CLASS_DEFINITION( test_1859 ) {
    QString workflowOutputDirPath( testDir + "_common_data/scenarios/sandbox" );
    QDir workflowOutputDir( workflowOutputDirPath );
    const QString outputFilePath = workflowOutputDir.absolutePath( ) + "/test.gb";

    // 1) Open Workflow Designer
    GTUtilsWorkflowDesigner::openWorkflowDesigner( os );

    const QString annReaderName = "Read Annotations";
    const QString annWriterName = "Write Annotations";

    // 2) Build workflow of elements: "Write Annotations" and "Read Annotations"
    GTUtilsWorkflowDesigner::addAlgorithm( os, annReaderName );
    GTUtilsWorkflowDesigner::addAlgorithm( os, annWriterName );

    WorkflowProcessItem *annReader = GTUtilsWorkflowDesigner::getWorker( os, annReaderName );
    WorkflowProcessItem *annWriter = GTUtilsWorkflowDesigner::getWorker( os, annWriterName );

    GTUtilsWorkflowDesigner::connect(os, annReader, annWriter );

    // 3) Set output file

    GTMouseDriver::moveTo( os, GTUtilsWorkflowDesigner::getItemCenter( os, annWriterName ) );
    GTMouseDriver::click( os );
    GTUtilsWorkflowDesigner::setParameter( os, "Output file", outputFilePath,
        GTUtilsWorkflowDesigner::textValue );

    // 4) Set input file
    GTMouseDriver::moveTo( os, GTUtilsWorkflowDesigner::getItemCenter( os, annReaderName ) );
    GTMouseDriver::click( os );
    GTUtilsWorkflowDesigner::setDatasetInputFile( os, dataDir + "samples/Genbank", "sars.gb" );

    GTLogTracer lt;

    // 5) Run workflow
    GTWidget::click( os,GTAction::button( os,"Run workflow" ) );
    GTGlobals::sleep( );

    // 6) Block file for writing
    PermissionsSetter permSetter;
    QFile::Permissions p = QFile::WriteOwner | QFile::WriteUser | QFile::WriteGroup
        | QFile::WriteOther;
    bool res = permSetter.setPermissions( outputFilePath, ~p );
    CHECK_SET_ERR( res, "Can't set permissions" );

    // 7) Run workflow again
    GTWidget::click( os,GTAction::button( os,"Run workflow" ) );
    GTGlobals::sleep( );

    CHECK_SET_ERR(lt.hasError(), "no error in log");
}

GUI_TEST_CLASS_DEFINITION(test_1860) {
    // 1) Open Workflow Designer
    GTUtilsDialog::waitForDialog(os, new StartupDialogFiller(os));
    QMenu *menu=GTMenu::showMainMenu( os, MWMENU_TOOLS );
    GTMenu::clickMenuItemByName( os, menu, QStringList() << ToolsMenu::WORKFLOW_DESIGNER );

    const QString textReaderName = "Read Plain Text";
    const QString textWriterName = "Write Plain Text";

    //2) Add elements: "Write plain text" and "Read plain text"
    GTUtilsWorkflowDesigner::addAlgorithm( os, textReaderName);
    GTUtilsWorkflowDesigner::addAlgorithm( os, textWriterName);

    WorkflowProcessItem *textReader = GTUtilsWorkflowDesigner::getWorker( os, textReaderName);
    WorkflowProcessItem *textWriter = GTUtilsWorkflowDesigner::getWorker( os, textWriterName);

    //3) Connect them to each other
    GTUtilsWorkflowDesigner::connect(os, textReader, textWriter);

    //4) Try to set output file

    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, textWriterName));
    GTMouseDriver::click(os);
    GTUtilsWorkflowDesigner::setParameter(os, "Output file", "test", GTUtilsWorkflowDesigner::textValue );
    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, textReaderName));
    GTMouseDriver::click(os);
}

GUI_TEST_CLASS_DEFINITION(test_1865) {
    // 1) Open Workflow Designer
    GTUtilsDialog::waitForDialog(os, new StartupDialogFiller(os));
    QMenu *menu=GTMenu::showMainMenu( os, MWMENU_TOOLS );
    GTMenu::clickMenuItemByName( os, menu, QStringList() << ToolsMenu::WORKFLOW_DESIGNER );

    const QString sequenceWriterName = "Write Sequence";

    //2) Add elements: "Write sequence"
    GTUtilsWorkflowDesigner::addAlgorithm( os, sequenceWriterName);

    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, sequenceWriterName));
    GTMouseDriver::click(os);

    }

GUI_TEST_CLASS_DEFINITION( test_1883 ){
// 1. Open file "data/samples/CLUSTALW/COI.aln"
    GTFileDialog::openFile( os, testDir + "_common_data/scenarios/msa", "ma.aln" );
// 2. Select any area in sequence view
    const int startRowNumber = 6;
    const int alignmentLength = 12;
    GTUtilsMSAEditorSequenceArea::click( os, QPoint( -5, startRowNumber ) );
    GTGlobals::sleep( 200 );
    GTUtilsMSAEditorSequenceArea::checkSelectedRect( os, QRect( 0, startRowNumber,
        alignmentLength, 1 ) );
// 3. Use context menu: "Edit -> Replace selected rows with complement" or "reverse" or "reverse-complement"
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << MSAE_MENU_EDIT
        << "replace_selected_rows_with_reverse") );
    GTMouseDriver::click(os, Qt::RightButton);
// Expected state: the bases in the selected area were replaced accordingly to the chosen variant
    GTKeyboardDriver::keyClick( os, 'c', GTKeyboardDriver::key["ctrl"] );
    GTGlobals::sleep(200);
    QString selectionContent = GTClipboard::text( os );
    CHECK_SET_ERR( "AATTATTAGACT" == selectionContent, "MSA changing is failed" );
// 4. Press "Ctrl + Z"
    GTKeyboardDriver::keyClick( os, 'z', GTKeyboardDriver::key["ctrl"] );
    GTGlobals::sleep(200);
// Expected result: all rows in the selection were restored
    GTKeyboardDriver::keyClick( os, 'c', GTKeyboardDriver::key["ctrl"] );
    GTGlobals::sleep(200);
    selectionContent = GTClipboard::text( os );
    CHECK_SET_ERR( "TCAGATTATTAA" == selectionContent, "MSA changing is failed" );
}

GUI_TEST_CLASS_DEFINITION( test_1884 )
{
    // 1. Open document "ma.aln"
    GTFileDialog::openFile( os, testDir + "_common_data/scenarios/msa", "ma.aln" );

    // 2. Select some row in the name list area
    const int startRowNumber = 6;
    const int alignmentLength = 12;
    GTUtilsMSAEditorSequenceArea::click( os, QPoint( -5, startRowNumber ) );
    GTGlobals::sleep( 200 );
    GTUtilsMSAEditorSequenceArea::checkSelectedRect( os, QRect( 0, startRowNumber,
        alignmentLength, 1 ) );

    // 3. Select all the upper rows and make some extra "selection"
    const int extraUpperSelectionCount = 3;
    GTKeyboardDriver::keyPress( os, GTKeyboardDriver::key["shift"] );
    GTGlobals::sleep(2000);
    for ( int i = 0; i < extraUpperSelectionCount; ++i ) {
        GTKeyboardDriver::keyClick( os, GTKeyboardDriver::key["up"] );
        GTGlobals::sleep(200);
    }
    const int upperSequencesCount = 4;
    GTUtilsMSAEditorSequenceArea::checkSelectedRect( os, QRect( 0, startRowNumber-extraUpperSelectionCount,
        alignmentLength, upperSequencesCount ) );

    // 4. Decrease the selection
    const int deselectionCount = extraUpperSelectionCount - 1;
    for ( int i = 0; i < deselectionCount; ++i ) {
        GTKeyboardDriver::keyClick( os, GTKeyboardDriver::key["down"] );
        GTGlobals::sleep(200);
    }
    GTUtilsMSAEditorSequenceArea::checkSelectedRect( os, QRect( 0, startRowNumber-1,
        alignmentLength, upperSequencesCount - deselectionCount ) );
    GTKeyboardDriver::keyRelease( os, GTKeyboardDriver::key["shift"] );
}

GUI_TEST_CLASS_DEFINITION( test_1886_1 )
{
    // 1. Open document "ma.aln"
    GTFileDialog::openFile( os, testDir + "_common_data/scenarios/msa", "ma.aln" );

    // 2. Select a region in the sequence area
    GTUtilsMSAEditorSequenceArea::selectArea( os, QPoint( 5, 4 ), QPoint( 10, 12 ) );

    // 3. Shift the region but don't release left mouse button
    const QPoint mouseDragPosition( 7, 7 );
    GTUtilsMSAEditorSequenceArea::moveTo( os, mouseDragPosition );
    GTMouseDriver::press( os );
    GTUtilsMSAEditorSequenceArea::moveTo( os, mouseDragPosition + QPoint( 3, 0 ) );

    // 4. Call context menu
    GTUtilsDialog::waitForDialog( os, new GTUtilsEscClicker( os, "msa sequence area context menu" ) );
    GTMouseDriver::click( os, Qt::RightButton );
    GTGlobals::sleep( 200 );
    GTUtilsMSAEditorSequenceArea::checkSelectedRect( os, QRect( QPoint( 8, 4 ), QPoint( 13, 12 ) ) );
}

GUI_TEST_CLASS_DEFINITION( test_1886_2 )
{
    // 1. Open document "ma.aln"
    GTFileDialog::openFile( os, testDir + "_common_data/scenarios/msa", "ma.aln" );

    // 2. Select a region in the sequence area
    GTUtilsMSAEditorSequenceArea::selectArea( os, QPoint( 5, 4 ), QPoint( 10, 12 ) );

    // 3. Shift the region but don't release left mouse button
    const QPoint mouseDragPosition( 7, 7 );
    GTUtilsMSAEditorSequenceArea::moveTo( os, mouseDragPosition );
    GTMouseDriver::press( os );
    GTUtilsMSAEditorSequenceArea::moveTo( os, mouseDragPosition + QPoint( 3, 0 ) );

    // 4. Replace selected rows with reverse
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList() << MSAE_MENU_EDIT
        << "replace_selected_rows_with_reverse") );
    GTMouseDriver::click(os, Qt::RightButton);

    // 5. Obtain selection
    GTKeyboardDriver::keyClick( os, 'c', GTKeyboardDriver::key["ctrl"] );
    GTGlobals::sleep(200);
    const QString selectionContent = GTClipboard::text( os );
    CHECK_SET_ERR( "--TGAC\n--TGAT\n--AGAC\n--AGAT\n--AGAT\n"
        "--TGAA\n--CGAT\n--CGAT\n--CGAT" == selectionContent, "MSA changing is failed" );
}

GUI_TEST_CLASS_DEFINITION( test_1897 ) {
    //1) Run UGENE
    //2) Open data/samples/CLUSTALW/COI.aln
    GTFileDialog::openFile( os, dataDir + "samples/CLUSTALW", "COI.aln" );

    //3) Selected any region on alignment view using mouse or keyboard
    GTUtilsMSAEditorSequenceArea::selectArea( os, QPoint( 40, 4 ), QPoint( 50, 12 ) );

    //4) Choose Highlighting/Gaps action from context-menu
    GTUtilsDialog::waitForDialog(os, new PopupChooser(os, QStringList( ) << "Highlighting"
        << "Gaps" ) );
    GTMouseDriver::click( os, Qt::RightButton );

    //5) Look at Hightlighting/Gaps action again
    QAction *action = GTAction::findActionByText( os, "Gaps" );
    //Expected state: It must be checked
    CHECK_SET_ERR( action->isChecked( ), "Action has to be checked!" );
}

GUI_TEST_CLASS_DEFINITION(test_1908){

    // 1. Open WD
    // 2. Add "Call variants" sample
    // Expected state: datasets are avaluable

    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);
    GTUtilsWorkflowDesigner::addSample(os, "Call variants with SAMtools");
    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Read Assembly (BAM/SAM)"));
    GTMouseDriver::click(os);
    GTUtilsWorkflowDesigner::setDatasetInputFile(os, dataDir + "samples/Assembly/", "chrM.sam");

    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "Read Sequence"));
    GTMouseDriver::click(os);
    GTUtilsWorkflowDesigner::setDatasetInputFile(os, dataDir + "samples/Assembly/", "chrM.fa");

}

GUI_TEST_CLASS_DEFINITION(test_1918) {
    //1. Open WD
    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    //2. Place to the empty scheme "File List" and "File Conversion" elements
    WorkflowProcessItem *fileList = GTUtilsWorkflowDesigner::addElement(os, "File List");
    WorkflowProcessItem *converter = GTUtilsWorkflowDesigner::addElement(os, "File Format Conversion");

    //3. Bind the elements
    GTUtilsWorkflowDesigner::connect(os, fileList, converter);

    //4. Add the following input files to the "File List" dataset: "test/_common_data/mega/MegaTest_1.meg",
    //                                                             "test/_common_data/mega/MegaTest_2.meg",
    //                                                             "test/_common_data/clustal/align.aln"
    GTUtilsWorkflowDesigner::addInputFile(os, "File List", testDir + "_common_data/mega/MegaTest_1.meg");
    GTUtilsWorkflowDesigner::addInputFile(os, "File List", testDir + "_common_data/mega/MegaTest_2.meg");
    GTUtilsWorkflowDesigner::addInputFile(os, "File List", testDir + "_common_data/clustal/align.aln");

    //5. Set the following parameters of the "File Conversion" element: { Document format : nexus },
    //                                                                  { Excluded formats : clustal }
    GTUtilsWorkflowDesigner::click(os, "File Format Conversion");
    GTUtilsWorkflowDesigner::setParameter(os, "Document format", "nexus", GTUtilsWorkflowDesigner::comboValue, GTGlobals::UseMouse);
    GTUtilsWorkflowDesigner::setParameter(os, "Excluded formats", QStringList("clustal"), GTUtilsWorkflowDesigner::ComboChecks);
    GTUtilsWorkflowDesigner::setParameter(os, "Output directory", 0, GTUtilsWorkflowDesigner::comboValue);
    GTUtilsWorkflowDesigner::setParameter(os, "Custom directory", QDir().absoluteFilePath(sandBoxDir + "regression_1918")
                                          , GTUtilsWorkflowDesigner::textValue);

    //6. Run the scheme.
    GTWidget::click(os, GTAction::button(os, "Run workflow"));

    //Expected state: After workflow finish there are two output files in the dashboard: "MegaTest_1.meg.nexus",
    //                                                                                   "MegaTest_2.meg.nexus"
    GTUtilsTaskTreeView::waitTaskFinished(os);
    CHECK_SET_ERR(QFile::exists(sandBoxDir + "regression_1918/MegaTest_1.meg.nex"), "File 1 does not exist");
    CHECK_SET_ERR(QFile::exists(sandBoxDir + "regression_1918/MegaTest_2.meg.nex"), "File 2 does not exist");
    CHECK_SET_ERR(!QFile::exists(sandBoxDir + "regression_1918/align.aln.nex"), "File 3 exists");
}

GUI_TEST_CLASS_DEFINITION( test_1919 )
{
    //1) Create the WD scheme: File list -> File conversions.
    //2) Set input file: a BAM file (e.g _common_data/bam/scerevisiae.bam).
    //3) Set the result format of the converter: BAM
    //4) Run the scheme.
    //Expected: the scheme is finished well, no errors appeared.

    GTLogTracer l;

    GTUtilsWorkflowDesigner::openWorkflowDesigner(os);

    GTUtilsWorkflowDesigner::addAlgorithm( os, "File List" );
    GTUtilsWorkflowDesigner::addAlgorithm( os, "File Format Conversion" );

    WorkflowProcessItem* fileList = GTUtilsWorkflowDesigner::getWorker(os, "File List");
    WorkflowProcessItem* fileConversion = GTUtilsWorkflowDesigner::getWorker(os, "File Format Conversion");

    GTUtilsWorkflowDesigner::connect(os, fileList, fileConversion);

    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "File List"));
    GTMouseDriver::click(os);
    GTUtilsWorkflowDesigner::setDatasetInputFile(os, testDir + "_common_data/bam", "scerevisiae.bam");

    GTMouseDriver::moveTo(os, GTUtilsWorkflowDesigner::getItemCenter(os, "File Format Conversion"));
    GTMouseDriver::click(os);
    GTUtilsWorkflowDesigner::setParameter(os, "Document format", 2, GTUtilsWorkflowDesigner::comboValue);

    // add setting source url in input data

    GTWidget::click(os,GTAction::button(os,"Run workflow"));

    GTUtilsLog::check(os, l);
}

GUI_TEST_CLASS_DEFINITION( test_1921 )
{
//    1. Click rapidly on the "Show/hide log" button several (20) times (or use the Alt+3 hotkey).
    GTGlobals::sleep(2000);
    for (int i = 0; i < 20; i++) {
        GTKeyboardDriver::keyClick(os, '3', GTKeyboardDriver::key["alt"]);
        GTGlobals::sleep(20);
    }
//    Expected state: UGENE not crashes.
}

GUI_TEST_CLASS_DEFINITION( test_2006 )
{
    const int MSA_WIDTH = 30;
    const int MSA_HEIGHT = 3;

    // 1. Open "data/samples/CLUSTAL/COI.aln" and save it's part to a string
    GTFileDialog::openFile( os, dataDir + "samples/CLUSTALW/", "COI.aln" );
    GTUtilsMSAEditorSequenceArea::selectArea( os, QPoint( 0, 0 ), QPoint( MSA_WIDTH, MSA_HEIGHT ) );
    GTKeyboardDriver::keyClick( os, 'c', GTKeyboardDriver::key["ctrl"] );
    GTGlobals::sleep(200);
    const QString initialMsaContent = GTClipboard::text( os );
    GTKeyboardDriver::keyClick( os, GTKeyboardDriver::key["esc"] );

    // 2. Select the second symbol in the first line
    const QPoint initialSelectionPos( 1, 0 );
    GTUtilsMSAEditorSequenceArea::click( os, initialSelectionPos );
    GTGlobals::sleep(200);

    // 3. Drag it to the first symbol in the first line
    const QPoint mouseDragPosition( 1, 0 );
    GTUtilsMSAEditorSequenceArea::moveTo( os, mouseDragPosition );
    GTMouseDriver::press( os );
    GTGlobals::sleep( 200 );
    GTUtilsMSAEditorSequenceArea::moveTo( os, mouseDragPosition + QPoint( 0, 0 ) );
    GTMouseDriver::release( os );
    GTGlobals::sleep( 200 );

    // 4. Check that the content has not been changed
    GTUtilsMSAEditorSequenceArea::selectArea( os, QPoint( 0, 0 ), QPoint( MSA_WIDTH, MSA_HEIGHT ) );
    GTKeyboardDriver::keyClick( os, 'c', GTKeyboardDriver::key["ctrl"] );
    GTGlobals::sleep(200);
    const QString finalMsaContent = GTClipboard::text( os );
    CHECK_SET_ERR( initialMsaContent == finalMsaContent, "MSA has unexpectedly changed" );

    // 5. Check that "Undo" and "Redo" buttons are disabled
    const QAbstractButton *undo = GTAction::button( os, "msa_action_undo" );
    CHECK_SET_ERR( !undo->isEnabled( ), "Undo button is unexpectedly enabled" );
    const QAbstractButton *redo = GTAction::button( os, "msa_action_redo" );
    CHECK_SET_ERR( !redo->isEnabled( ), "Redo button is unexpectedly enabled" );
}
}

}