include (U2View.pri)

# Input
HEADERS += src/LicenseDialog.h \
           src/UndoRedoFramework.h \
           src/WebWindow.h \
           src/ov_assembly/AddReadsToDocumentTask.h \
           src/ov_assembly/AssemblyAnnotationsArea.h \
           src/ov_assembly/AssemblyBrowser.h \
           src/ov_assembly/AssemblyBrowserFactory.h \
           src/ov_assembly/AssemblyBrowserSettings.h \
           src/ov_assembly/AssemblyBrowserState.h \
           src/ov_assembly/AssemblyBrowserTasks.h \
           src/ov_assembly/AssemblyCellRenderer.h \
           src/ov_assembly/AssemblyConsensusArea.h \
           src/ov_assembly/AssemblyConsensusTask.h \
           src/ov_assembly/AssemblyCoverageGraph.h \
           src/ov_assembly/AssemblyInfoWidget.h \
           src/ov_assembly/AssemblyModel.h \
           src/ov_assembly/AssemblyNavigationWidget.h \
           src/ov_assembly/AssemblyReadsArea.h \
           src/ov_assembly/AssemblyReadsAreaHint.h \
           src/ov_assembly/AssemblyReferenceArea.h \
           src/ov_assembly/AssemblyRuler.h \
           src/ov_assembly/AssemblySettingsWidget.h \
           src/ov_assembly/AssemblyVariantHint.h \
           src/ov_assembly/AssemblyVariantRow.h \
           src/ov_assembly/CalculateCoveragePerBaseTask.h \
           src/ov_assembly/CoverageInfo.h \
           src/ov_assembly/CoveredRegionsManager.h \
           src/ov_assembly/ExportConsensusDialog.h \
           src/ov_assembly/ExportConsensusTask.h \
           src/ov_assembly/ExportConsensusVariationsDialog.h \
           src/ov_assembly/ExportConsensusVariationsTask.h \
           src/ov_assembly/ExportCoverageDialog.h \
           src/ov_assembly/ExportCoverageTask.h \
           src/ov_assembly/ExportReadsDialog.h \
           src/ov_assembly/ExtractAssemblyRegionDialog.h \
           src/ov_assembly/ExtractAssemblyRegionTask.h \
           src/ov_assembly/ZoomableAssemblyOverview.h \
           src/ov_msa/AlignmentLogo.h \
           src/ov_msa/Clipboard/SubalignmentToClipboardTask.h \
           src/ov_msa/ColorSchemaDialogController.h \
           src/ov_msa/ColorSchemaSettingsController.h \
           src/ov_msa/Common/RefSeqCommonWidget.h \
           src/ov_msa/CreateSubalignmentDialogController.h \
           src/ov_msa/DeleteGapsDialog.h \
           src/ov_msa/Export/MSAImageExportTask.h \
           src/ov_msa/ExportConsensus/MSAExportConsensusTab.h \
           src/ov_msa/ExportConsensus/MSAExportConsensusTabFactory.h \
           src/ov_msa/ExportHighlightedDialogController.h \
           src/ov_msa/General/McaGeneralTab.h \
           src/ov_msa/General/McaGeneralTabFactory.h \
           src/ov_msa/General/MSAGeneralTab.h \
           src/ov_msa/General/MSAGeneralTabFactory.h \
           src/ov_msa/Highlighting/MsaHighlightingSavableTab.h \
           src/ov_msa/Highlighting/MSAHighlightingTab.h \
           src/ov_msa/Highlighting/MSAHighlightingTabFactory.h \
           src/ov_msa/MaEditor.h \
           src/ov_msa/MaEditorFactory.h \
           src/ov_msa/McaEditor.h \
           src/ov_msa/McaEditorSequenceArea.h \
           src/ov_msa/MSACollapsibleModel.h \
           src/ov_msa/MSAEditor.h \
           src/ov_msa/MSAEditorConsensusArea.h \
           src/ov_msa/MSAEditorConsensusCache.h \
           src/ov_msa/MsaEditorSimilarityColumn.h \
           src/ov_msa/MSAEditorNameList.h \
           src/ov_msa/MSAEditorOffsetsView.h \
           src/ov_msa/MSAEditorOverviewArea.h \
           src/ov_msa/MSAEditorSequenceArea.h \
           src/ov_msa/MSAEditorState.h \
           src/ov_msa/MSAEditorStatusBar.h \
           src/ov_msa/MSAEditorTasks.h \
           src/ov_msa/MsaUpdatedWidgetInterface.h \
           src/ov_msa/MsaOpSavableTab.h \
           src/ov_msa/MSASelectSubalignmentDialog.h \
           src/ov_msa/MsaEditorUserModStepController.h \
           src/ov_msa/AlignSequencesToAlignment/AlignSequencesToAlignmentTask.h \
           src/ov_msa/Overview/MaGraphCalculationTask.h \
           src/ov_msa/Overview/MaGraphOverview.h \
           src/ov_msa/Overview/MaOverview.h \
           src/ov_msa/Overview/MaOverviewContextMenu.h \
           src/ov_msa/Overview/MaOverviewImageExportTask.h \
           src/ov_msa/Overview/MaSangerOverview.h \
           src/ov_msa/Overview/MaSimpleOverview.h \
           src/ov_msa/PairAlign/PairAlign.h \
           src/ov_msa/PairAlign/PairAlignFactory.h \
           src/ov_msa/PhyTrees/MSAEditorMultiTreeViewer.h \
           src/ov_msa/PhyTrees/MSAEditorTreeManager.h \
           src/ov_msa/PhyTrees/MsaEditorTreeTabArea.h \
           src/ov_msa/PhyTrees/MSAEditorTreeViewer.h \
           src/ov_msa/SaveSelectedSequenceFromMSADialogController.h \
           src/ov_msa/SeqStatistics/SeqStatisticsWidget.h \
           src/ov_msa/SeqStatistics/SeqStatisticsWidgetFactory.h \
           src/ov_msa/SequenceSelectorWidgetController.h \
           src/ov_msa/TreeOptions/TreeOptionsWidget.h \
           src/ov_msa/TreeOptions/TreeOptionsWidgetFactory.h \
           src/ov_msa/view_rendering/MaEditorSelection.h \
           src/ov_msa/view_rendering/MaEditorSequenceArea.h \
           src/ov_msa/view_rendering/MaEditorUtils.h \
           src/ov_msa/view_rendering/MaEditorWgt.h \
           src/ov_msa/view_rendering/SequenceAreaRenderer.h \
           src/ov_msa/view_rendering/SequenceWithChromatogramAreaRenderer.h \
           src/ov_phyltree/CreateBranchesTask.h \
           src/ov_phyltree/CreateCircularBranchesTask.h \
           src/ov_phyltree/CreateRectangularBranchesTask.h \
           src/ov_phyltree/CreateUnrootedBranchesTask.h \
           src/ov_phyltree/GraphicsBranchItem.h \
           src/ov_phyltree/GraphicsButtonItem.h \
           src/ov_phyltree/GraphicsCircularBranchItem.h \
           src/ov_phyltree/GraphicsRectangularBranchItem.h \
           src/ov_phyltree/GraphicsUnrootedBranchItem.h \
           src/ov_phyltree/TreeSettings.h \
           src/ov_phyltree/TreeViewer.h \
           src/ov_phyltree/TreeViewerFactory.h \
           src/ov_phyltree/TreeViewerState.h \
           src/ov_phyltree/TreeViewerTasks.h \
           src/ov_phyltree/TreeViewerUtils.h \
           src/ov_sequence/ADVAnnotationCreation.h \
           src/ov_sequence/ADVClipboard.h \
           src/ov_sequence/ADVConstants.h \
           src/ov_sequence/ADVGraphModel.h \
           src/ov_sequence/ADVSequenceObjectContext.h \
           src/ov_sequence/ADVSequenceWidget.h \
           src/ov_sequence/ADVSingleSequenceWidget.h \
           src/ov_sequence/ADVSplitWidget.h \
           src/ov_sequence/ADVSyncViewManager.h \
           src/ov_sequence/ADVUtils.h \
           src/ov_sequence/AnnotatedDNAView.h \
           src/ov_sequence/AnnotatedDNAViewFactory.h \
           src/ov_sequence/AnnotatedDNAViewState.h \
           src/ov_sequence/AnnotatedDNAViewTasks.h \
           src/ov_sequence/AnnotationsTreeView.h \
           src/ov_sequence/AutoAnnotationUtils.h \
           src/ov_sequence/CreateRulerDialogController.h \
           src/ov_sequence/DetView.h \
           src/ov_sequence/GSequenceGraphView.h \
           src/ov_sequence/GSequenceGraphViewWithFactory.h \
           src/ov_sequence/GSequenceLineView.h \
           src/ov_sequence/GSequenceLineViewAnnotated.h \
           src/ov_sequence/GraphLabelModel.h \
           src/ov_sequence/GraphLabelsSelectDialog.h \
           src/ov_sequence/GraphMenu.h \
           src/ov_sequence/GraphSettingsDialog.h \
           src/ov_sequence/Overview.h \
           src/ov_sequence/PanView.h \
           src/ov_sequence/PanViewRows.h \
           src/ov_sequence/SaveGraphCutoffsDialogController.h \
           src/ov_sequence/SaveGraphCutoffsTask.h \
           src/ov_sequence/SearchQualifierDialog.h \
           src/ov_sequence/WindowStepSelectorWidget.h \
           src/ov_sequence/annot_highlight/AnnotHighlightSettings.h \
           src/ov_sequence/annot_highlight/AnnotHighlightTree.h \
           src/ov_sequence/annot_highlight/AnnotHighlightTreeItem.h \
           src/ov_sequence/annot_highlight/AnnotHighlightWidget.h \
           src/ov_sequence/annot_highlight/AnnotHighlightWidgetFactory.h \
           src/ov_sequence/codon_table/CodonTable.h \
           src/ov_sequence/find_pattern/FindPatternTask.h \
           src/ov_sequence/find_pattern/FindPatternWidget.h \
           src/ov_sequence/find_pattern/FindPatternWidgetFactory.h \
           src/ov_sequence/find_pattern/FindPatternWidgetSavableTab.h \
           src/ov_sequence/image_export/SequenceExportSettingsWidget.h \
           src/ov_sequence/image_export/SequencePainter.h \
           src/ov_sequence/image_export/ExportImagePainter.h \
           src/ov_sequence/image_export/SingleSequenceImageExportController.h \
           src/ov_sequence/image_export/SingleSequenceImageExportTask.h \
           src/ov_sequence/sequence_info/CharOccurTask.h \
           src/ov_sequence/sequence_info/DNAStatisticsTask.h \
           src/ov_sequence/sequence_info/DinuclOccurTask.h \
           src/ov_sequence/sequence_info/SequenceInfo.h \
           src/ov_sequence/sequence_info/SequenceInfoFactory.h \
           src/ov_sequence/view_rendering/DetViewMultiLineRenderer.h \
           src/ov_sequence/view_rendering/DetViewRenderer.h \
           src/ov_sequence/view_rendering/DetViewSingleLineRenderer.h \
           src/ov_sequence/view_rendering/PanViewRenderer.h \
           src/ov_sequence/view_rendering/SequenceViewAnnotatedRenderer.h \
           src/ov_sequence/view_rendering/SequenceViewRenderer.h \
           src/ov_text/SimpleTextObjectView.h \
           src/ov_text/SimpleTextObjectViewTasks.h \
           src/phyltree/BaseSettingsDialog.h \
           src/phyltree/BranchSettingsDialog.h \
           src/phyltree/CreatePhyTreeDialogController.h \
           src/phyltree/CreatePhyTreeWidget.h \
           src/phyltree/PhyTreeDisplayOptionsWidget.h \
           src/phyltree/TextSettingsDialog.h \
           src/phyltree/TreeSettingsDialog.h \
           src/util_dna_assembly/BuildIndexDialog.h \
           src/util_dna_assembly/ConvertAssemblyToSamDialog.h \
           src/util_dna_assembly/DnaAssemblyDialog.h \
           src/util_dna_assembly/DnaAssemblyGUIExtension.h \
           src/util_dna_assembly/DnaAssemblyUtils.h \
           src/util_dna_assembly/GenomeAssemblyDialog.h \
           src/util_msa_align/AlignmentAlgorithmGUIExtension.h \
           src/util_sec_struct_predict/SecStructDialog.h \
           src/util_sec_struct_predict/SecStructPredictUtils.h \
           src/util_smith_waterman/SmithWatermanDialog.h \
           src/util_smith_waterman/SmithWatermanDialogImpl.h \
           src/util_smith_waterman/SubstMatrixDialog.h
FORMS += src/ov_assembly/ExportConsensusDialog.ui \
         src/ov_assembly/ExportCoverageDialog.ui \
         src/ov_assembly/ExportReadsDialog.ui \
         src/ov_assembly/ExtractAssemblyRegionDialog.ui \
         src/ov_msa/CreateSubalignmentDialog.ui \
         src/ov_msa/ColorSchemaDialog.ui \
         src/ov_msa/ColorSchemaSettingsWidget.ui \
         src/ov_msa/CreateMSAScheme.ui \
         src/ov_msa/DeleteGapsDialog.ui \
         src/ov_msa/ExportConsensus/ExportConsensusWidget.ui \
         src/ov_msa/ExportHighlightedDialog.ui \
         src/ov_msa/General/GeneralTabOptionsPanelWidget.ui \
         src/ov_msa/General/McaGeneralTabOptionsPanelWidget.ui \
         src/ov_msa/SeqStatistics/MSADistancesColumnSettingsWidget.ui \
         src/ov_msa/Export/MSAExportSettings.ui \
         src/ov_msa/PairAlign/PairwiseAlignmentOptionsPanelWidget.ui \
         src/ov_msa/SaveSelectedSequenceFromMSADialog.ui \
         src/ov_msa/SelectSubalignmentDialog.ui \
         src/ov_msa/SequenceSelectorWidget.ui \
         src/ov_msa/TreeOptions/TreeOptionsWidget.ui \
         src/ov_sequence/annot_highlight/AnnotHighlightSettings.ui \
         src/ov_sequence/find_pattern/FindPatternForm.ui \
         src/ov_sequence/image_export/SequenceImageExportSettingsWidget.ui \
         src/ov_sequence/CreateRulerDialog.ui \
         src/ov_sequence/SaveGraphCutoffsDialog.ui \
         src/ov_sequence/SearchQualifierDialog.ui \
         src/phyltree/BranchSettingsDialog.ui \
         src/phyltree/CreatePhyTreeDialog.ui \
         src/phyltree/PhyTreeDisplayOptionsWidget.ui \
         src/phyltree/TextSettingsDialog.ui \
         src/phyltree/TreeSettingsDialog.ui \
         src/LicenseDialog.ui \
         src/util_dna_assembly/AssemblyToRefDialog.ui \
         src/util_dna_assembly/AssemblyToSamDialog.ui \
         src/util_dna_assembly/BuildIndexFromRefDialog.ui \
         src/util_dna_assembly/GenomeAssemblyDialog.ui \
         src/util_sec_struct_predict/SecStructDialog.ui \
         src/util_smith_waterman/SmithWatermanDialogBase.ui \
         src/util_smith_waterman/SubstMatrixDialogBase.ui
SOURCES += src/LicenseDialog.cpp \
           src/UndoRedoFramework.cpp \
           src/WebWindow.cpp \
           src/ov_assembly/AddReadsToDocumentTask.cpp \
           src/ov_assembly/AssemblyAnnotationsArea.cpp \
           src/ov_assembly/AssemblyBrowser.cpp \
           src/ov_assembly/AssemblyBrowserFactory.cpp \
           src/ov_assembly/AssemblyBrowserSettings.cpp \
           src/ov_assembly/AssemblyBrowserState.cpp \
           src/ov_assembly/AssemblyBrowserTasks.cpp \
           src/ov_assembly/AssemblyCellRenderer.cpp \
           src/ov_assembly/AssemblyConsensusArea.cpp \
           src/ov_assembly/AssemblyConsensusTask.cpp \
           src/ov_assembly/AssemblyCoverageGraph.cpp \
           src/ov_assembly/AssemblyInfoWidget.cpp \
           src/ov_assembly/AssemblyModel.cpp \
           src/ov_assembly/AssemblyNavigationWidget.cpp \
           src/ov_assembly/AssemblyReadsArea.cpp \
           src/ov_assembly/AssemblyReadsAreaHint.cpp \
           src/ov_assembly/AssemblyReferenceArea.cpp \
           src/ov_assembly/AssemblyRuler.cpp \
           src/ov_assembly/AssemblySettingsWidget.cpp \
           src/ov_assembly/AssemblyVariantHint.cpp \
           src/ov_assembly/AssemblyVariantRow.cpp \
           src/ov_assembly/CalculateCoveragePerBaseTask.cpp \
           src/ov_assembly/CoverageInfo.cpp \
           src/ov_assembly/CoveredRegionsManager.cpp \
           src/ov_assembly/ExportConsensusDialog.cpp \
           src/ov_assembly/ExportConsensusTask.cpp \
           src/ov_assembly/ExportConsensusVariationsDialog.cpp \
           src/ov_assembly/ExportConsensusVariationsTask.cpp \
           src/ov_assembly/ExportCoverageDialog.cpp \
           src/ov_assembly/ExportCoverageTask.cpp \
           src/ov_assembly/ExportReadsDialog.cpp \
           src/ov_assembly/ExtractAssemblyRegionDialog.cpp \
           src/ov_assembly/ExtractAssemblyRegionTask.cpp \
           src/ov_assembly/ZoomableAssemblyOverview.cpp \
           src/ov_msa/AlignmentLogo.cpp \
           src/ov_msa/Clipboard/SubalignmentToClipboardTask.cpp \
           src/ov_msa/ColorSchemaDialogController.cpp \
           src/ov_msa/ColorSchemaSettingsController.cpp \
           src/ov_msa/Common/RefSeqCommonWidget.cpp \
           src/ov_msa/CreateSubalignmentDialogController.cpp \
           src/ov_msa/DeleteGapsDialog.cpp \
           src/ov_msa/Export/MSAImageExportTask.cpp \
           src/ov_msa/ExportHighlightedDialogController.cpp \
           src/ov_msa/General/McaGeneralTab.cpp \
           src/ov_msa/General/McaGeneralTabFactory.cpp \
           src/ov_msa/General/MSAGeneralTab.cpp \
           src/ov_msa/General/MSAGeneralTabFactory.cpp \
           src/ov_msa/Highlighting/MsaHighlightingSavableTab.cpp \
           src/ov_msa/Highlighting/MSAHighlightingTab.cpp \
           src/ov_msa/Highlighting/MSAHighlightingTabFactory.cpp \
           src/ov_msa/MaEditor.cpp \
           src/ov_msa/MaEditorFactory.cpp \
           src/ov_msa/McaEditor.cpp \
           src/ov_msa/McaEditorSequenceArea.cpp \
           src/ov_msa/MSACollapsibleModel.cpp \
           src/ov_msa/MSAEditor.cpp \
           src/ov_msa/MSAEditorConsensusArea.cpp \
           src/ov_msa/MSAEditorConsensusCache.cpp \
           src/ov_msa/MsaEditorSimilarityColumn.cpp \
           src/ov_msa/MSAEditorNameList.cpp \
           src/ov_msa/MSAEditorOffsetsView.cpp \
           src/ov_msa/MSAEditorOverviewArea.cpp \
           src/ov_msa/MSAEditorSequenceArea.cpp \
           src/ov_msa/MSAEditorState.cpp \
           src/ov_msa/MSAEditorStatusBar.cpp \
           src/ov_msa/MSAEditorTasks.cpp \
           src/ov_msa/MsaOpSavableTab.cpp \
           src/ov_msa/MSASelectSubalignmentDialog.cpp \
           src/ov_msa/MsaEditorUserModStepController.cpp \
           src/ov_msa/ExportConsensus/MSAExportConsensusTab.cpp \
           src/ov_msa/ExportConsensus/MSAExportConsensusTabFactory.cpp \
           src/ov_msa/AlignSequencesToAlignment/AlignSequencesToAlignmentTask.cpp \
           src/ov_msa/Overview/MaGraphOverview.cpp \
           src/ov_msa/Overview/MaGraphCalculationTask.cpp \
           src/ov_msa/Overview/MaOverview.cpp \
           src/ov_msa/Overview/MaOverviewContextMenu.cpp \
           src/ov_msa/Overview/MaOverviewImageExportTask.cpp \
           src/ov_msa/Overview/MaSangerOverview.cpp \
           src/ov_msa/Overview/MaSimpleOverview.cpp \
           src/ov_msa/PairAlign/PairAlign.cpp \
           src/ov_msa/PairAlign/PairAlignFactory.cpp \
           src/ov_msa/TreeOptions/TreeOptionsWidget.cpp \
           src/ov_msa/TreeOptions/TreeOptionsWidgetFactory.cpp \
           src/ov_msa/PhyTrees/MSAEditorMultiTreeViewer.cpp \
           src/ov_msa/PhyTrees/MSAEditorTreeManager.cpp \
           src/ov_msa/PhyTrees/MsaEditorTreeTabArea.cpp \
           src/ov_msa/PhyTrees/MSAEditorTreeViewer.cpp \
           src/ov_msa/SaveSelectedSequenceFromMSADialogController.cpp \
           src/ov_msa/SeqStatistics/SeqStatisticsWidget.cpp \
           src/ov_msa/SeqStatistics/SeqStatisticsWidgetFactory.cpp \
           src/ov_msa/SequenceSelectorWidgetController.cpp \
           src/ov_msa/view_rendering/MaEditorSelection.cpp \
           src/ov_msa/view_rendering/MaEditorSequenceArea.cpp \
           src/ov_msa/view_rendering/MaEditorUtils.cpp \
           src/ov_msa/view_rendering/MaEditorWgt.cpp \
           src/ov_msa/view_rendering/SequenceAreaRenderer.cpp \
           src/ov_msa/view_rendering/SequenceWithChromatogramAreaRenderer.cpp \
           src/ov_phyltree/CreateCircularBranchesTask.cpp \
           src/ov_phyltree/CreateRectangularBranchesTask.cpp \
           src/ov_phyltree/CreateUnrootedBranchesTask.cpp \
           src/ov_phyltree/GraphicsBranchItem.cpp \
           src/ov_phyltree/GraphicsButtonItem.cpp \
           src/ov_phyltree/GraphicsCircularBranchItem.cpp \
           src/ov_phyltree/GraphicsRectangularBranchItem.cpp \
           src/ov_phyltree/GraphicsUnrootedBranchItem.cpp \
           src/ov_phyltree/TreeViewer.cpp \
           src/ov_phyltree/TreeViewerFactory.cpp \
           src/ov_phyltree/TreeViewerState.cpp \
           src/ov_phyltree/TreeViewerTasks.cpp \
           src/ov_phyltree/TreeViewerUtils.cpp \
           src/ov_sequence/ADVAnnotationCreation.cpp \
           src/ov_sequence/ADVClipboard.cpp \
           src/ov_sequence/ADVGraphModel.cpp \
           src/ov_sequence/ADVSequenceObjectContext.cpp \
           src/ov_sequence/ADVSequenceWidget.cpp \
           src/ov_sequence/ADVSingleSequenceWidget.cpp \
           src/ov_sequence/ADVSyncViewManager.cpp \
           src/ov_sequence/ADVUtils.cpp \
           src/ov_sequence/AnnotatedDNAView.cpp \
           src/ov_sequence/AnnotatedDNAViewFactory.cpp \
           src/ov_sequence/AnnotatedDNAViewState.cpp \
           src/ov_sequence/AnnotatedDNAViewTasks.cpp \
           src/ov_sequence/AnnotationsTreeView.cpp \
           src/ov_sequence/AutoAnnotationUtils.cpp \
           src/ov_sequence/CreateRulerDialogController.cpp \
           src/ov_sequence/DetView.cpp \
           src/ov_sequence/GraphLabelModel.cpp \
           src/ov_sequence/GraphLabelsSelectDialog.cpp \
           src/ov_sequence/GraphMenu.cpp \
           src/ov_sequence/GraphSettingsDialog.cpp \
           src/ov_sequence/GSequenceGraphView.cpp \
           src/ov_sequence/GSequenceGraphViewWithFactory.cpp \
           src/ov_sequence/GSequenceLineView.cpp \
           src/ov_sequence/GSequenceLineViewAnnotated.cpp \
           src/ov_sequence/Overview.cpp \
           src/ov_sequence/PanView.cpp \
           src/ov_sequence/PanViewRows.cpp \
           src/ov_sequence/SaveGraphCutoffsDialogController.cpp \
           src/ov_sequence/SaveGraphCutoffsTask.cpp \
           src/ov_sequence/SearchQualifierDialog.cpp \
           src/ov_sequence/WindowStepSelectorWidget.cpp \
           src/ov_sequence/annot_highlight/AnnotHighlightSettings.cpp \
           src/ov_sequence/annot_highlight/AnnotHighlightTree.cpp \
           src/ov_sequence/annot_highlight/AnnotHighlightTreeItem.cpp \
           src/ov_sequence/annot_highlight/AnnotHighlightWidget.cpp \
           src/ov_sequence/annot_highlight/AnnotHighlightWidgetFactory.cpp \
           src/ov_sequence/codon_table/CodonTable.cpp \
           src/ov_sequence/find_pattern/FindPatternTask.cpp \
           src/ov_sequence/find_pattern/FindPatternWidget.cpp \
           src/ov_sequence/find_pattern/FindPatternWidgetFactory.cpp \
           src/ov_sequence/find_pattern/FindPatternWidgetSavableTab.cpp \
           src/ov_sequence/image_export/SequenceExportSettingsWidget.cpp \
           src/ov_sequence/image_export/SequencePainter.cpp \
           src/ov_sequence/image_export/SingleSequenceImageExportController.cpp \
           src/ov_sequence/image_export/SingleSequenceImageExportTask.cpp \
           src/ov_sequence/sequence_info/CharOccurTask.cpp \
           src/ov_sequence/sequence_info/DinuclOccurTask.cpp \
           src/ov_sequence/sequence_info/DNAStatisticsTask.cpp \
           src/ov_sequence/sequence_info/SequenceInfo.cpp \
           src/ov_sequence/sequence_info/SequenceInfoFactory.cpp \
           src/ov_sequence/view_rendering/DetViewMultiLineRenderer.cpp \
           src/ov_sequence/view_rendering/DetViewRenderer.cpp \
           src/ov_sequence/view_rendering/DetViewSingleLineRenderer.cpp \
           src/ov_sequence/view_rendering/PanViewRenderer.cpp \
           src/ov_sequence/view_rendering/SequenceViewAnnotatedRenderer.cpp \
           src/ov_sequence/view_rendering/SequenceViewRenderer.cpp \
           src/ov_text/SimpleTextObjectView.cpp \
           src/ov_text/SimpleTextObjectViewTasks.cpp \
           src/phyltree/BaseSettingsDialog.cpp \
           src/phyltree/BranchSettingsDialog.cpp \
           src/phyltree/CreatePhyTreeDialogController.cpp \
           src/phyltree/CreatePhyTreeWidget.cpp \
           src/phyltree/PhyTreeDisplayOptionsWidget.cpp \
           src/phyltree/TextSettingsDialog.cpp \
           src/phyltree/TreeSettingsDialog.cpp \
           src/util_dna_assembly/BuildIndexDialog.cpp \
           src/util_dna_assembly/ConvertAssemblyToSamDialog.cpp \
           src/util_dna_assembly/DnaAssemblyDialog.cpp \
           src/util_dna_assembly/DnaAssemblyGUIExtension.cpp \
           src/util_dna_assembly/DnaAssemblyUtils.cpp \
           src/util_dna_assembly/GenomeAssemblyDialog.cpp \
           src/util_msa_align/AlignmentAlgorithmGUIExtension.cpp \
           src/util_sec_struct_predict/SecStructDialog.cpp \
           src/util_sec_struct_predict/SecStructPredictUtils.cpp \
           src/util_smith_waterman/SmithWatermanDialog.cpp \
           src/util_smith_waterman/SubstMatrixDialog.cpp
TRANSLATIONS += transl/english.ts \
                transl/russian.ts
