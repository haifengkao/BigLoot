#pragma once

#include "EdgeItem.h"
#include <api/sorting/plugin_graph.h>

namespace loot {

class EdgeProvider {
private:
  PluginGraph* graph;

public:
  EdgeProvider(Game& game, const std::vector<std::string>& loadOrder);

  ~EdgeProvider();

  EdgeItems GetSpecificEdges();
};
}
