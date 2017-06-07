#ifndef MANOWARAPP_H
#define MANOWARAPP_H

#include "MooseApp.h"

class ManowarApp;

template <>
InputParameters validParams<ManowarApp>();

class ManowarApp : public MooseApp
{
public:
  ManowarApp(InputParameters parameters);
  virtual ~ManowarApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MANOWARAPP_H */
