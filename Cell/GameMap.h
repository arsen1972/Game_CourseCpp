#pragma once

#include "Cell.h"
#include <vector>

using std::vector;

Cell c1 (0, 0, "plain");
Cell c2 (0, 1, "plain");
Cell c3 (1, 0, "forest");
Cell c4 (1, 1, "forest");

static vector <vector <Cell*> > gameMap = {{ &c1, &c2 },{ &c3, &c4 }};