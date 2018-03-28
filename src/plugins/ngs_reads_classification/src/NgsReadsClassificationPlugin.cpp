/**
 * UGENE - Integrated Bioinformatics Tools.
 * Copyright (C) 2008-2017 UniPro <ugene@unipro.ru>
 * http://ugene.net
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

#include <U2Core/AppContext.h>
#include <U2Core/DataPathRegistry.h>
#include <U2Core/U2SafePoints.h>

#include "NgsReadsClassificationPlugin.h"
#include "ClassificationFilterWorker.h"
#include "EnsembleClassificationWorker.h"
#include "GetReadListWorker.h"

namespace U2 {

const QString NgsReadsClassificationPlugin::PLUGIN_NAME = QObject::tr("NGS reads classification");
const QString NgsReadsClassificationPlugin::PLUGIN_DESCRIPRION = QObject::tr("The plugin supports data and utility for the NGS reads classifiers");

const QString NgsReadsClassificationPlugin::TAXONOMY_PATH = "ngs_classification/taxonomy";
const QString NgsReadsClassificationPlugin::TAXONOMY_DATA_ID = "taxonomy_data";
const QString NgsReadsClassificationPlugin::TAXON_PROTEIN_MAP_ITEM_ID = "prot.accession2taxid.gz";
const QString NgsReadsClassificationPlugin::TAXON_NODES_ITEM_ID = "nodes.dmp";
const QString NgsReadsClassificationPlugin::TAXON_NAMES_ITEM_ID = "names.dmp";

const QString NgsReadsClassificationPlugin::CLARK_VIRAL_DATABASE_PATH = "ngs_classification/clark/viral_database";
const QString NgsReadsClassificationPlugin::CLARK_VIRAL_DATABASE_DATA_ID = "clark_viral_database";
const QString NgsReadsClassificationPlugin::CLARK_VIRAL_DATABASE_ITEM_ID = "viral_database";

const QString NgsReadsClassificationPlugin::CLARK_BACTERIA_VIRAL_DATABASE_PATH = "ngs_classification/clark/bacteria_viral_database";
const QString NgsReadsClassificationPlugin::CLARK_BACTERIA_VIRAL_DATABASE_DATA_ID = "clark_bacteria_viral_database";
const QString NgsReadsClassificationPlugin::CLARK_BACTERIA_VIRAL_DATABASE_ITEM_ID = "bacteria_viral_database";

const QString NgsReadsClassificationPlugin::MINIKRAKEN_4_GB_PATH = "ngs_classification/kraken/minikraken";
const QString NgsReadsClassificationPlugin::MINIKRAKEN_4_GB_DATA_ID = "minikraken_4gb";
const QString NgsReadsClassificationPlugin::MINIKRAKEN_4_GB_ITEM_ID = "minikraken";

const QString NgsReadsClassificationPlugin::DIAMOND_UNIPROT_50_DATABASE_PATH = "ngs_classification/diamond/uniref/uniref50.dmnd";
const QString NgsReadsClassificationPlugin::DIAMOND_UNIPROT_50_DATABASE_DATA_ID = "diamond_uniprot_50";
const QString NgsReadsClassificationPlugin::DIAMOND_UNIPROT_50_DATABASE_ITEM_ID = "uniref50.dmnd";

const QString NgsReadsClassificationPlugin::DIAMOND_UNIPROT_90_DATABASE_PATH = "ngs_classification/diamond/uniref/uniref90.dmnd";
const QString NgsReadsClassificationPlugin::DIAMOND_UNIPROT_90_DATABASE_DATA_ID = "diamond_uniprot_90";
const QString NgsReadsClassificationPlugin::DIAMOND_UNIPROT_90_DATABASE_ITEM_ID = "uniref90.dmnd";

const QString NgsReadsClassificationPlugin::REFSEQ_HUMAN_PATH = "ngs_classification/refseq/human";
const QString NgsReadsClassificationPlugin::REFSEQ_HUMAN_DATA_ID = "refseq_human";

const QString NgsReadsClassificationPlugin::REFSEQ_BACTERIA_PATH = "ngs_classification/refseq/bacteria";
const QString NgsReadsClassificationPlugin::REFSEQ_BACTERIA_DATA_ID = "refseq_bacteria";

const QString NgsReadsClassificationPlugin::REFSEQ_VIRAL_PATH = "ngs_classification/refseq/viral";
const QString NgsReadsClassificationPlugin::REFSEQ_VIRAL_DATA_ID = "refseq_viral";

const QString NgsReadsClassificationPlugin::WORKFLOW_ELEMENTS_GROUP = QObject::tr("NGS: Reads Classification");

extern "C" Q_DECL_EXPORT Plugin* U2_PLUGIN_INIT_FUNC() {
    NgsReadsClassificationPlugin *plugin = new NgsReadsClassificationPlugin();
    return plugin;
}

class LoadTaxonomyTreeTask : public Task {
public:
    LoadTaxonomyTreeTask() : Task(NgsReadsClassificationPlugin::tr("Loading NCBI taxonomy data"), TaskFlag_None) {}
    void run() {
         LocalWorkflow::TaxonomyTree::getInstance();
    }
};

NgsReadsClassificationPlugin::NgsReadsClassificationPlugin()
    : Plugin(PLUGIN_NAME, PLUGIN_DESCRIPRION)
{
    registerData(TAXONOMY_DATA_ID, TAXONOMY_PATH, tr("NCBI taxonomy classification data"), false, true);
    registerData(CLARK_VIRAL_DATABASE_DATA_ID, CLARK_VIRAL_DATABASE_PATH, tr("CLARK viral database"), true);
    registerData(CLARK_BACTERIA_VIRAL_DATABASE_DATA_ID, CLARK_BACTERIA_VIRAL_DATABASE_PATH, tr("CLARK bacteria and viral database"), true);
    registerData(MINIKRAKEN_4_GB_DATA_ID, MINIKRAKEN_4_GB_PATH, tr("Minikraken 4Gb database"), true);
    registerData(DIAMOND_UNIPROT_50_DATABASE_DATA_ID, DIAMOND_UNIPROT_50_DATABASE_PATH, tr("DIAMOND database built from UniProt50"));
    registerData(DIAMOND_UNIPROT_90_DATABASE_DATA_ID, DIAMOND_UNIPROT_90_DATABASE_PATH, tr("DIAMOND database built from UniProt90"));
    registerData(REFSEQ_HUMAN_DATA_ID, REFSEQ_HUMAN_PATH, tr("RefSeq release human data from NCBI"));
    registerData(REFSEQ_BACTERIA_DATA_ID, REFSEQ_BACTERIA_PATH, tr("RefSeq release bacteria data from NCBI"));
    registerData(REFSEQ_VIRAL_DATA_ID, REFSEQ_VIRAL_PATH, tr("RefSeq release viral data from NCBI"));

    LocalWorkflow::ClassificationFilterWorkerFactory::init();
    LocalWorkflow::GetReadsListWorkerFactory::init();
    LocalWorkflow::EnsembleClassificationWorkerFactory::init();

    CandidatesSplitterRegistry::instance()->registerSplitter(new LocalWorkflow::SeReadsListSplitter());
    CandidatesSplitterRegistry::instance()->registerSplitter(new LocalWorkflow::PeReadsListSplitter());

    // Pre-load taxonomy data
    TaskScheduler *scheduler = AppContext::getTaskScheduler();
    CHECK(NULL != scheduler, );
    scheduler->registerTopLevelTask(new LoadTaxonomyTreeTask);
}

NgsReadsClassificationPlugin::~NgsReadsClassificationPlugin() {
    CandidatesSplitterRegistry::instance()->unregisterSplitter(LocalWorkflow::SeReadsListSplitter::ID);
    CandidatesSplitterRegistry::instance()->unregisterSplitter(LocalWorkflow::PeReadsListSplitter::ID);

    LocalWorkflow::EnsembleClassificationWorkerFactory::cleanup();
    LocalWorkflow::GetReadsListWorkerFactory::cleanup();
    LocalWorkflow::ClassificationFilterWorkerFactory::cleanup();

    foreach (const QString &dataId, registeredData) {
        unregisterData(dataId);
    }
}

void NgsReadsClassificationPlugin::registerData(const QString &dataId, const QString &relativePath, const QString &description, bool addAsFolder, bool verbose) {
    U2DataPathRegistry* dataPathRegistry = AppContext::getDataPathRegistry();
    const QString path = QFileInfo(QString(PATH_PREFIX_DATA) + ":" + relativePath).absoluteFilePath();
    const U2DataPath::Options options = addAsFolder ? U2DataPath::AddOnlyFolders | U2DataPath::AddTopLevelFolder : U2DataPath::None;
    U2DataPath *dataPath = new U2DataPath(dataId, path, description, options);
    bool ok = dataPathRegistry->registerEntry(dataPath);
    if (!ok) {
        if (verbose) {
            coreLog.error(tr("Failed to find the %1").arg(description));
        }
        delete dataPath;
    } else {
        if (verbose) {
            coreLog.trace(tr("Found the %1 at %2").arg(description).arg(path));
        }
        registeredData << dataId;
    }
}

void NgsReadsClassificationPlugin::unregisterData(const QString &dataId) {
    U2DataPathRegistry* dataPathRegistry = AppContext::getDataPathRegistry();
    CHECK(NULL != dataPathRegistry, );
    dataPathRegistry->unregisterEntry(dataId);
    registeredData.removeAll(dataId);
}

}   // namespace U2
