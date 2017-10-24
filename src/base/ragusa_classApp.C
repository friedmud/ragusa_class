#include "ragusa_classApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<ragusa_classApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

ragusa_classApp::ragusa_classApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ragusa_classApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ragusa_classApp::associateSyntax(_syntax, _action_factory);
}

ragusa_classApp::~ragusa_classApp() {}

// External entry point for dynamic application loading
extern "C" void
ragusa_classApp__registerApps()
{
  ragusa_classApp::registerApps();
}
void
ragusa_classApp::registerApps()
{
  registerApp(ragusa_classApp);
}

void
ragusa_classApp::registerObjectDepends(Factory & /*factory*/)
{
}

// External entry point for dynamic object registration
extern "C" void
ragusa_classApp__registerObjects(Factory & factory)
{
  ragusa_classApp::registerObjects(factory);
}
void
ragusa_classApp::registerObjects(Factory & /*factory*/)
{
}

void
ragusa_classApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

// External entry point for dynamic syntax association
extern "C" void
ragusa_classApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  ragusa_classApp::associateSyntax(syntax, action_factory);
}
void
ragusa_classApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
