// ---------------------------------------------------------------------
//
// Copyright (C) 2002 - 2016 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE at
// the top level of the deal.II distribution.
//
// ---------------------------------------------------------------------



// check the Patterns::List pattern

#include "../tests.h"
#include <deal.II/base/parameter_handler.h>

void check (const char *p)
{
  ParameterHandler prm;
  prm.declare_entry ("test_1", "-1,0",
                     Patterns::List(Patterns::Integer(-1,1),2,3));

  std::ifstream in(p);
  prm.parse_input (in);

  deallog << "test_1=" << prm.get ("test_1") << std::endl;
}


int main ()
{
  initlog();

  check (SOURCE_DIR "/prm/parameter_handler_1.prm");

  return 0;
}
