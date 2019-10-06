#pragma once

#include "Cell.h"
#include <vector>

static const std::vector<std::vector<Cell*>> gameMap = 

{{ new Cell(0, 0, "plain"),  new Cell(0, 1, "plain"),  new Cell(0, 2, "sea"),    new Cell(0, 3, "sea"),    new Cell(0, 4, "sea") },
 { new Cell(1, 0, "plain"),  new Cell(1, 1, "plain"),  new Cell(1, 2, "sea"),    new Cell(1, 3, "sea"),    new Cell(1, 4, "sea") },
 { new Cell(2, 0, "plain"),  new Cell(2, 1, "plain"),  new Cell(2, 2, "plain"),  new Cell(2, 3, "sea"),    new Cell(2, 4, "sea") },
 { new Cell(3, 0, "forest"), new Cell(3, 1, "forest"), new Cell(3, 2, "plain"),  new Cell(3, 3, "plain"),  new Cell(3, 4, "plain") },
 { new Cell(4, 0, "forest"), new Cell(4, 1, "forest"), new Cell(4, 2, "forest"), new Cell(4, 3, "forest"), new Cell(4, 4, "forest") },
 
};