#include "ManowarApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<ManowarApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

ManowarApp::ManowarApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ManowarApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ManowarApp::associateSyntax(_syntax, _action_factory);
}

ManowarApp::~ManowarApp() {}

// External entry point for dynamic application loading
extern "C" void
ManowarApp__registerApps()
{
  ManowarApp::registerApps();
}
void
ManowarApp::registerApps()
{
  registerApp(ManowarApp);
}

// External entry point for dynamic object registration
extern "C" void
ManowarApp__registerObjects(Factory & factory)
{
  ManowarApp::registerObjects(factory);
}
void
ManowarApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void
ManowarApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  ManowarApp::associateSyntax(syntax, action_factory);
}
void
ManowarApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
