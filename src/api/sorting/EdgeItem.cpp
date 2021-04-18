#include "EdgeItem.h"

namespace loot {
EdgeItem::EdgeItem(EdgeVertex parent, EdgeVertex child, EdgeType edgeType) :
    parent(parent), child(child), edgeType(edgeType) {}

EdgeItem::~EdgeItem() {}
}