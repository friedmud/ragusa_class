#ifndef RAGUSA_CLASSTESTAPP_H
#define RAGUSA_CLASSTESTAPP_H

#include "MooseApp.h"

class ragusa_classTestApp;

template <>
InputParameters validParams<ragusa_classTestApp>();

class ragusa_classTestApp : public MooseApp
{
public:
  ragusa_classTestApp(InputParameters parameters);
  virtual ~ragusa_classTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* RAGUSA_CLASSTESTAPP_H */
