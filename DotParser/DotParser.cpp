#include "./DotParser.h"


DOTParser::Graph DOTParser::parseDot(const std::string& dot) {
    Graph graph;
    std::smatch match;

    // Determine if it's directed or undirected
    std::regex typeRegex(R"((digraph|graph)\s+\w*\s*\{)");
    if (std::regex_search(dot, match, typeRegex)) {
        graph.directed = match[1] == "digraph";
    }
    else {
        throw std::runtime_error("DOT file must start with 'graph' or 'digraph'");
    }

    // Match all node/edge statements inside the braces
    std::regex stmtRegex(R"(([a-zA-Z0-9_]+)\s*(->|--)\s*([a-zA-Z0-9_]+))");
    auto begin = std::sregex_iterator(dot.begin(), dot.end(), stmtRegex);
    auto end = std::sregex_iterator();

    for (auto i = begin; i != end; ++i) {
        std::string from = (*i)[1];
        std::string to = (*i)[3];

        graph.nodes.insert(from);
        graph.nodes.insert(to);
        graph.edges.emplace_back(from, to);
    }

    return graph;
}