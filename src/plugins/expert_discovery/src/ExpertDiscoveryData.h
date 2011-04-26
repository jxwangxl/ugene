#ifndef _EXPERTDISCOVERIDATAHEADER_
#define _EXPERTDISCOVERIDATAHEADER_


#include "DDisc/Sequence.h"
#include "DDisc/MetaInfo.h"


#include "ExpertDiscoveryCSUtil.h"
#include "ExpertDiscoveryTreeWidgets.h"


#include <U2Core/GObject.h>
#include <QObject>

namespace U2 {

using namespace DDisc;

class EDProjectItem;
class EDPICS;

const int ED_UPDATE_ALL			    = 0;
const int ED_CURRENT_ITEM_CHANGED	= 1;
const int ED_ITEM_NAME_CHANGED		= 2;
const int ED_ITEM_STATE_CHANGED	    = 3;
const int ED_ITEM_ADDED			    = 4;
const int ED_ITEM_DELETED			= 5;
const int ED_UPDATE_CHILDREN		= 6;
const int ED_PROPERTY_CHANGED		= 7;
const int ED_MRK_UPDATE		        = 8;

class ExpertDiscoveryData : public QObject{
	Q_OBJECT
public:
	static const std::string FAMILY_LETTERS;
	static const std::string FAMILY_LETTERS_METHOD;

	ExpertDiscoveryData ();

	void setPosBase(const QList<GObject*> &);
	void setNegBase(const QList<GObject*> &);
	void setConBase(const QList<GObject*> &);

	void markupLetters(void);
	void markupLetters(SequenceBase& rBase, MarkingBase& rAnn);
	bool isLettersMarkedUp(void) const;
	void clearScores();

	const MetaInfoBase& getDescriptionBase() const { return desc;}
	SequenceBase& getPosSeqBase() {return posBase;}
	SequenceBase& getNegSeqBase() {return negBase;}
    SequenceBase& getConSeqBase() {return conBase;}

    MarkingBase& getPosMarkBase() {return posAnn;}
    MarkingBase& getNegMarkBase() {return negAnn;}
    MarkingBase& getConMarkBase() {return conAnn;}

    void clearContrBase();
    void clearContrAnnot();

    CSFolder& getRootFolder(){return rootFolder;}

    bool updateScore(Sequence& rSeq);
    double getRecognizationBound() const { return recognizationBound; }
    void setRecBound(double val){recognizationBound = val;}
    void optimizeRecognizationBound();

    void setRecBound();
    bool updateScores();

    bool isSignalSelected(const EDProjectItem* pItem);
    void switchSelection(EDProjectItem* pItem, bool upd);
    SelectedSignalsContainer& getSelectedSignalsContainer() { return selectedSignals; }

    void onSetCurrentSignalParamsAsPrior(EDPICS *pItem, bool bUpdate);
    void onClearSignalPriorParams(EDPICS *pItem);
    
    double recognizationBound;
private:
	SequenceBase posBase;
	SequenceBase negBase;
	SequenceBase conBase;

	MetaInfoBase	desc;
	MarkingBase		posAnn;
	MarkingBase		negAnn;
	MarkingBase		conAnn;

    CSFolder        rootFolder;

    RecognizationDataStorage recDataStorage;

	inline Sequence prerareSequence(const GObject* obj) const;

	static std::string char2string(char ch);

    SelectedSignalsContainer	selectedSignals;


};
}//namespace

#endif