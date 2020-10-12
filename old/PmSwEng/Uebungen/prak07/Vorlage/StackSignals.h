#ifndef STACKEVENT_H
#define STACKEVENT_H

#include <QObject>

class StackSignals : public QObject {
  Q_OBJECT
 public:
  virtual ~StackSignals()
  {
  }

 signals:
  void itemPushed();
  void itemPopped();
};

#endif  // STACKEVENT_H
