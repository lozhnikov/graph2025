#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <graph.hpp>
#include <oriented_graph.hpp>
#include <weighted_graph.hpp>
#include <weighted_oriented_graph.hpp>
#include <breadth_first_traversal.hpp>

using graph::Graph;
using graph::OrientedGraph;
using graph::WeightedGraph;
using graph::WeightedOrientedGraph;

namespace graph {

template<typename GraphType>
int BreadthFirstTraversalMethodHelper(const nlohmann::json& input,
    nlohmann::json* output);

int BreadthFirstTraversalMethod(const nlohmann::json& input,
    nlohmann::json* output) {
  std::string graphType = input.at("graph_type");

  if (graphType == "Graph") {
    return BreadthFirstTraversalMethodHelper<Graph>(input, output);
  } else if (graphType == "OrientedGraph") {
    return BreadthFirstTraversalMethodHelper<OrientedGraph>(input, output);
  } else if (graphType == "WeightedGraph") {
    std::string weightType = input.at("weight_type");
    if (weightType == "int") {
      return BreadthFirstTraversalMethodHelper<WeightedGraph<int>>(input,
          output);
    } else {
      return -1;
    }
  } else if (graphType == "WeightedOrientedGraph") {
    std::string weightType = input.at("weight_type");
    if (weightType == "int") {
      return BreadthFirstTraversalMethodHelper<WeightedOrientedGraph<int>>(
          input, output);
    } else {
      return -1;
    }
  }

  return -1;
}

/**
 * @brief Метод обхода графа в ширину.
 *
 * @param input Входные данные в формате JSON.
 * @param output Выходные данные в формате JSON.
 * @return Функция возвращает 0 в случае успеха и отрицательное число
 * если входные данные заданы некорректно.
 *
 * Функция запускает алгоритм обхода графа в ширину, используя входные данные
 * в JSON формате. Результат также выдаётся в JSON формате.
 */
template<typename GraphType>
int BreadthFirstTraversalMethodHelper(const nlohmann::json& input,
    nlohmann::json* output) {
  GraphType graph;
  std::vector<size_t> result;

  for (auto& vertex : input.at("vertices")) {
    graph.AddVertex(vertex);
  }

  for (auto& edge : input.at("edges")) {
    graph.AddEdge(edge.at("from"), edge.at("to"));
  }

  BreadthFirstTraversal(graph, [&result](size_t id) { result.push_back(id); });

  (*output)["result"] = result;

/* Альтернативный вариант.
  for (size_t i = 0; i < result.size(); i++) {
    (*output)["result"] = result[i];
  }
*/

  return 0;
}

}  // namespace graph
