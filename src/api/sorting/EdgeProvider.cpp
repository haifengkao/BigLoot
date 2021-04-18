#include "EdgeProvider.h"
#include <api/game/game.h>
#include <api/helpers/logging.h>
#include <api/sorting/plugin_graph.h>


namespace loot {

EdgeProvider::EdgeProvider(Game& game,
                           const std::vector<std::string>& loadOrder) {

    this->graph = new PluginGraph();
  graph->AddPluginVertices(game, loadOrder);

  auto logger = getLogger();
  if (logger) {
    logger->info("Edge Provider Current load order: ");
    for (const auto& plugin : loadOrder) {
      logger->info("\t\t{}", plugin);
    }
  }
}

EdgeProvider::~EdgeProvider() {
    if (graph != NULL) {
    delete graph;
        graph = NULL;
    }
    
}

EdgeItems EdgeProvider::GetSpecificEdges() { return graph->GetSpecificEdges(); }

}
