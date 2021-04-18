#pragma once
#include <string>
#include "loot/api_decorator.h"
#include "loot/enum/edge_type.h"
namespace loot {
typedef std::string EdgeVertex;
class EdgeItem {
private:
  EdgeVertex parent;
  EdgeVertex child;
  EdgeType edgeType;

public:
  LOOT_API explicit EdgeItem(EdgeVertex parent,
                             EdgeVertex child,
                             EdgeType edgeType);
  ~EdgeItem();
};

typedef std::vector<EdgeItem> EdgeItems;
}

