#ifndef _ABOUT_DIALOG_TESTS_H_
#define _ABOUT_DIALOG_TESTS_H_

#include "GUITests.h"

#include <QtCore/QString>

namespace U2 {

class AboutDialogTests: public GUITest {
public:
    AboutDialogTests(const QString &name): GUITest(name) {}
    void openDialogByMenu();
    void openDialogByShortcut();
    QPoint getButtonPos(const QString& buttonObjName);
};

class Test1AboutDialog: public AboutDialogTests {
public:
    Test1AboutDialog(const QString &name):
      AboutDialogTests(name){}
      void execute();
      void checkResult();
};

class Test2AboutDialog: public AboutDialogTests {
public:
    Test2AboutDialog(const QString &name):
      AboutDialogTests(name){}
      void execute();
      void checkResult();
};

class Test3AboutDialog: public AboutDialogTests {
public:
    Test3AboutDialog(const QString &name):
      AboutDialogTests(name){}
      void execute();
      void checkResult();
};
class Test4AboutDialog: public AboutDialogTests {
public:
    Test4AboutDialog(const QString &name):
      AboutDialogTests(name){}
      void execute();
      void checkResult();
};

class Test5AboutDialog: public AboutDialogTests {
public:
    Test5AboutDialog(const QString &name):
      AboutDialogTests(name){}
      void execute();
      void checkResult();
};

}

#endif
