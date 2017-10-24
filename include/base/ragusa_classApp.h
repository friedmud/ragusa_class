#ifndef RAGUSA_CLASSAPP_H
#define RAGUSA_CLASSAPP_H

#include "MooseApp.h"

class ragusa_classApp;

template <>
InputParameters validParams<ragusa_classApp>();

class ragusa_classApp : public MooseApp
{
public:
  ragusa_classApp(InputParameters parameters);
  virtual ~ragusa_classApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void registerObjectDepends(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void associateSyntaxDepends(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* RAGUSA_CLASSAPP_H */
