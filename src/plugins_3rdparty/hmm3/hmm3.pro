include (hmm3.pri)

# Input
HEADERS += src/uHMM3Plugin.h \
           src/build/uhmm3build.h \
           src/build/uHMM3BuildDialogImpl.h \
           src/build/uHMM3BuildTask.h \
           src/format/uHMMFormat.h \
           src/format/uHMMFormatReader.h \
           src/gobject/uHMMObject.h \
           src/hmmer3/hmmer.h \
           src/hmmer3/hmmer3_funcs.h \
           src/hmmer3/p7_config.h \
           src/phmmer/uhmm3phmmer.h \
           src/phmmer/uHMM3PhmmerDialogImpl.h \
           src/phmmer/uhmm3PhmmerTask.h \
           src/search/uhmm3search.h \
           src/search/uHMM3SearchDialogImpl.h \
           src/search/uhmm3SearchResult.h \
           src/search/uHMM3SearchTask.h \
           src/search/uhmm3QDActor.h \
           src/task_local_storage/uHMMSearchTaskLocalData.h \
           src/task_local_storage/uHMMSearchTaskLocalStorage.h \
           src/tests/uhmmer3BuildTests.h \
           src/tests/uhmmer3PhmmerTests.h \
           src/tests/uhmmer3SearchTests.h \
           src/tests/uhmmer3Tests.h \
           src/util/uhmm3Utilities.h \
           src/hmmer3/easel/easel.h \
           src/hmmer3/easel/esl_alphabet.h \
           src/hmmer3/easel/esl_cluster.h \
           src/hmmer3/easel/esl_config.h \
           src/hmmer3/easel/esl_dirichlet.h \
           src/hmmer3/easel/esl_distance.h \
           src/hmmer3/easel/esl_dmatrix.h \
           src/hmmer3/easel/esl_exponential.h \
           src/hmmer3/easel/esl_gumbel.h \
           src/hmmer3/easel/esl_histogram.h \
           src/hmmer3/easel/esl_hmm.h \
           src/hmmer3/easel/esl_keyhash.h \
           src/hmmer3/easel/esl_minimizer.h \
           src/hmmer3/easel/esl_msa.h \
           src/hmmer3/easel/esl_msacluster.h \
           src/hmmer3/easel/esl_msaweight.h \
           src/hmmer3/easel/esl_random.h \
           src/hmmer3/easel/esl_randomseq.h \
           src/hmmer3/easel/esl_ratematrix.h \
           src/hmmer3/easel/esl_rootfinder.h \
           src/hmmer3/easel/esl_scorematrix.h \
           src/hmmer3/easel/esl_sq.h \
           src/hmmer3/easel/esl_sse.h \
           src/hmmer3/easel/esl_stack.h \
           src/hmmer3/easel/esl_stats.h \
           src/hmmer3/easel/esl_tree.h \
           src/hmmer3/easel/esl_vectorops.h \
           src/hmmer3/easel/esl_wuss.h \
           src/hmmer3/impl_sse/impl_sse.h \
           src/workers/HMM3IOWorker.h \
           src/workers/HMM3BuildWorker.h \
           src/workers/HMM3SearchWorker.h
FORMS += src/build/UHMM3BuildDialog.ui \
         src/phmmer/UHMM3PhmmerDialog.ui \
         src/search/UHMM3SearchDialog.ui
SOURCES += src/uHMM3Plugin.cpp \
           src/build/uhmm3build.cpp \
           src/build/uHMM3BuildDialogImpl.cpp \
           src/build/uHMM3BuildTask.cpp \
           src/format/uHMMFormat.cpp \
           src/format/uHMMFormatReader.cpp \
           src/gobject/uHMMObject.cpp \
           src/hmmer3/build.cpp \
           src/hmmer3/emit.cpp \
           src/hmmer3/errors.cpp \
           src/hmmer3/evalues.cpp \
           src/hmmer3/eweight.cpp \
           src/hmmer3/hmmer.cpp \
           src/hmmer3/hmmer3_funcs.cpp \
           src/hmmer3/logsum.cpp \
           src/hmmer3/modelconfig.cpp \
           src/hmmer3/modelstats.cpp \
           src/hmmer3/p7_alidisplay.cpp \
           src/hmmer3/p7_bg.cpp \
           src/hmmer3/p7_builder.cpp \
           src/hmmer3/p7_domaindef.cpp \
           src/hmmer3/p7_gmx.cpp \
           src/hmmer3/p7_hmm.cpp \
           src/hmmer3/p7_pipeline.cpp \
           src/hmmer3/p7_prior.cpp \
           src/hmmer3/p7_profile.cpp \
           src/hmmer3/p7_spensemble.cpp \
           src/hmmer3/p7_tophits.cpp \
           src/hmmer3/p7_trace.cpp \
           src/hmmer3/seqmodel.cpp \
           src/hmmer3/tracealign.cpp \
           src/phmmer/uhmm3phmmer.cpp \
           src/phmmer/uHMM3PhmmerDialogImpl.cpp \
           src/phmmer/uhmm3PhmmerTask.cpp \
           src/search/uhmm3search.cpp \
           src/search/uHMM3SearchDialogImpl.cpp \
           src/search/uhmm3SearchResult.cpp \
           src/search/uHMM3SearchTask.cpp \
           src/search/uhmm3QDActor.cpp \
           src/task_local_storage/uHMMSearchTaskLocalData.cpp \
           src/task_local_storage/uHMMSearchTaskLocalStorage.cpp \
           src/tests/uhmmer3BuildTests.cpp \
           src/tests/uhmmer3PhmmerTests.cpp \
           src/tests/uhmmer3SearchTests.cpp \
           src/tests/uhmmer3Tests.cpp \
           src/util/uhmm3Utilities.cpp \
           src/hmmer3/easel/easel.cpp \
           src/hmmer3/easel/esl_alphabet.cpp \
           src/hmmer3/easel/esl_cluster.cpp \
           src/hmmer3/easel/esl_dirichlet.cpp \
           src/hmmer3/easel/esl_distance.cpp \
           src/hmmer3/easel/esl_dmatrix.cpp \
           src/hmmer3/easel/esl_exponential.cpp \
           src/hmmer3/easel/esl_gumbel.cpp \
           src/hmmer3/easel/esl_histogram.cpp \
           src/hmmer3/easel/esl_hmm.cpp \
           src/hmmer3/easel/esl_keyhash.cpp \
           src/hmmer3/easel/esl_minimizer.cpp \
           src/hmmer3/easel/esl_msa.cpp \
           src/hmmer3/easel/esl_msacluster.cpp \
           src/hmmer3/easel/esl_msaweight.cpp \
           src/hmmer3/easel/esl_random.cpp \
           src/hmmer3/easel/esl_randomseq.cpp \
           src/hmmer3/easel/esl_ratematrix.cpp \
           src/hmmer3/easel/esl_rootfinder.cpp \
           src/hmmer3/easel/esl_scorematrix.cpp \
           src/hmmer3/easel/esl_sq.cpp \
           src/hmmer3/easel/esl_sse.cpp \
           src/hmmer3/easel/esl_stack.cpp \
           src/hmmer3/easel/esl_stats.cpp \
           src/hmmer3/easel/esl_tree.cpp \
           src/hmmer3/easel/esl_vectorops.cpp \
           src/hmmer3/easel/esl_wuss.cpp \
           src/hmmer3/impl_sse/decoding.cpp \
           src/hmmer3/impl_sse/fwdback.cpp \
           src/hmmer3/impl_sse/msvfilter.cpp \
           src/hmmer3/impl_sse/null2.cpp \
           src/hmmer3/impl_sse/optacc.cpp \
           src/hmmer3/impl_sse/p7_omx.cpp \
           src/hmmer3/impl_sse/p7_oprofile.cpp \
           src/hmmer3/impl_sse/stotrace.cpp \
           src/hmmer3/impl_sse/vitfilter.cpp \
           src/workers/HMM3IOWorker.cpp  \
           src/workers/HMM3BuildWorker.cpp \
           src/workers/HMM3SearchWorker.cpp 
RESOURCES += hmm3.qrc
TRANSLATIONS += transl/english.ts transl/russian.ts
