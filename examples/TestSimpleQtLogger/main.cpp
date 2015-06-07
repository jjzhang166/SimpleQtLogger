/*
  Test Simple Logger for Qt

  Mario Ban, 05.2015

  Tested using: Qt 5.4.2 (Community Open Source), Clang 6.0 (Apple) 64 bit

*/

#include <QCoreApplication>
#include <QTimer>

#include "task.h"
#include "simpleQtLogger.h"

SimpleQtLogger simpleQtLogger_;

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  // initialize SimpleQtLogger
  simpleQtLogger_.setLogFileName("testSimpleQtLogger.log", 10000, 10); // TODO test
  SQT_LOG_ENABLE_DEBUG = false;
  SQT_LOG_ENABLE_FUNCTION = true;

  // start and initialize the main task
  Task *task = new Task(&a);
  QObject::connect(task, SIGNAL(finished()), &a, SLOT(quit()));
  QTimer::singleShot(0, task, SLOT(init()));

  return a.exec();
}