#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <regex>

namespace DOTParser {
    struct Graph {
        std::unordered_set<std::string> nodes;
        std::vector<std::pair<std::string, std::string>> edges;
        bool directed = true;
    };

    Graph parseDot(const std::string& dot);

}