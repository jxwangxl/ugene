/**
 * UGENE - Integrated Bioinformatics Tools.
 * Copyright (C) 2008-2012 UniPro <ugene@unipro.ru>
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

#ifndef _U2_CUFFDIFF_WORKER_H
#define _U2_CUFFDIFF_WORKER_H

#include <U2Lang/LocalDomain.h>
#include <U2Lang/WorkflowUtils.h>

#include "CuffdiffSupportTask.h"

namespace U2 {
namespace LocalWorkflow {

class CuffdiffPrompter : public PrompterBase<CuffdiffPrompter>
{
    Q_OBJECT

public:
    CuffdiffPrompter(Actor* parent = 0);

protected:
    QString composeRichDoc();
};

class CuffdiffWorker : public BaseWorker {
    Q_OBJECT
public:
    CuffdiffWorker(Actor *actor);

    void init();
    bool isReady();
    Task * tick();
    void cleanup();

private slots:
    void sl_taskFinished();

private:
    CommunicationChannel *inAssembly;
    CommunicationChannel *inTranscript;
    IntegralBus *output;
    QList<SharedDbiDataHandler> assemblies;

private:
    CuffdiffSettings scanParameters() const;
    CuffdiffSettings takeSettings();
    QVariantMap createMessageData(CuffdiffSupportTask *task) const;
    void takeAssembly();
    template<class T> T param(const QString &paramId) const;
};

class CuffdiffWorkerFactory : public DomainFactory
{
public:
    static const QString ACTOR_ID;
    static void init();
    CuffdiffWorkerFactory() : DomainFactory(ACTOR_ID) {}
    virtual Worker* createWorker(Actor* actor) { return new CuffdiffWorker(actor); }
};

/************************************************************************/
/* Template definitions */
/************************************************************************/
template<class T>
T CuffdiffWorker::param(const QString &paramId) const {
    Attribute *attr = actor->getParameter(paramId);
    if (NULL == attr) {
        return T();
    }
    return attr->getAttributeValue<T>(context);
}

} // namespace LocalWorkflow
} // namespace U2

#endif
