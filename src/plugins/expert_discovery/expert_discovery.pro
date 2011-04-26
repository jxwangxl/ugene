include (expert_discovery.pri)

# Input
HEADERS += 	src/ExpertDiscoveryPlugin.h \
		src/ExpertDiscoveryView.h \
		src/ExpertDiscoveryViewCtx.h \
		src/ExpertDiscoveryPosNegDialog.h \
		src/ExpertDiscoveryControlDialog.h \
		src/ExpertDiscoveryAdvSetDialog.h \
	        src/ExpertDiscoverySetupRecBoundDialog.h \
		src/ExpertDiscoveryPropTable.h \
		src/ExpertDiscoveryTask.h \
		src/ExpertDiscoveryData.h \
		src/ExpertDiscoverySet.h \
		src/ExpertDiscoveryExtSigWiz.h \
		src/ExpertDiscoveryCSUtil.h \
		src/ExpertDiscoveryTreeWidgets.h \
		src/ExpertDiscoveryTreeWidgetsCtrl.h \
	   	src/DDisc/Definitions.h \
		src/DDisc/statmath.h \
		src/DDisc/Signal.h  \
		src/DDisc/Sequence.h  \
		src/DDisc/MetaInfo.h  \
		src/DDisc/Extractor.h  \
		src/DDisc/Context.h  

FORMS +=   src/ui/ExpertDiscoveryPosNegDialog.ui \
	   src/ui/ExpertDiscoveryControlDialog.ui \
	   src/ui/ExpertDiscoveryAdvSetDialog.ui \
	   src/ui/ExpertDiscoverySigExtrWiz.ui \
	   src/ui/ExpertDiscoverySetupRecBoundDialog.ui

SOURCES += 	src/ExpertDiscoveryPlugin.cpp \
		src/ExpertDiscoveryView.cpp \
		src/ExpertDiscoveryViewCtx.cpp \
		src/ExpertDiscoveryPosNegDialog.cpp \
		src/ExpertDiscoveryControlDialog.cpp \
		src/ExpertDiscoveryAdvSetDialog.cpp \
	        src/ExpertDiscoverySetupRecBoundDialog.cpp \
		src/ExpertDiscoveryPropTable.cpp \
		src/ExpertDiscoveryTask.cpp \
		src/ExpertDiscoveryData.cpp \
		src/ExpertDiscoverySet.cpp \
		src/ExpertDiscoveryExtSigWiz.cpp \
		src/ExpertDiscoveryCSUtil.cpp \
		src/ExpertDiscoveryTreeWidgets.cpp \
		src/ExpertDiscoveryTreeWidgetsCtrl.cpp \
	   	src/DDisc/Definitions.cpp \
		src/DDisc/statmath.cpp \
		src/DDisc/Signal.cpp  \
		src/DDisc/Sequence.cpp  \
		src/DDisc/MetaInfo.cpp  \
		src/DDisc/Extractor.cpp  \
		src/DDisc/Context.cpp  
RESOURCES += expert_discovery.qrc
TRANSLATIONS += transl/english.ts transl/russian.ts


