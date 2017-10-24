#include "ragusa_classTestApp.h"
#include "ragusa_classApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<ragusa_classTestApp>()
{
  InputParameters params = validParams<ragusa_classApp>();
  return params;
}

ragusa_classTestApp::ragusa_classTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ragusa_classApp::registerObjectDepends(_factory);
  ragusa_classApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ragusa_classApp::associateSyntaxDepends(_syntax, _action_factory);
  ragusa_classApp::associateSyntax(_syntax, _action_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    ragusa_classTestApp::registerObjects(_factory);
    ragusa_classTestApp::associateSyntax(_syntax, _action_factory);
  }
}

ragusa_classTestApp::~ragusa_classTestApp() {}

// External entry point for dynamic application loading
extern "C" void
ragusa_classTestApp__registerApps()
{
  ragusa_classTestApp::registerApps();
}
void
ragusa_classTestApp::registerApps()
{
  registerApp(ragusa_classApp);
  registerApp(ragusa_classTestApp);
}

// External entry point for dynamic object registration
extern "C" void
ragusa_classTestApp__registerObjects(Factory & factory)
{
  ragusa_classTestApp::registerObjects(factory);
}
void
ragusa_classTestApp::registerObjects(Factory & /*factory*/)
{
}

// External entry point for dynamic syntax association
extern "C" void
ragusa_classTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  ragusa_classTestApp::associateSyntax(syntax, action_factory);
}
void
ragusa_classTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
