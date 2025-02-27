/**
 * @file tests/test.hpp
 * @author Mikhail Lozhnikov
 *
 * Заголовочный файл для объявлений основных тестовых функций.
 */

#ifndef TESTS_TEST_HPP_
#define TESTS_TEST_HPP_

#include <httplib.h>

/**
 * @brief Набор тестов для класса graph::Graph.
 */
void TestGraph();

/**
 * @brief Набор тестов для класса graph::OrientedGraph.
 */
void TestOrientedGraph();

/**
 * @brief Набор тестов для класса graph::WeightedGraph.
 */
void TestWeightedGraph();

/**
 * @brief Набор тестов для функции graph::WeightedOrientedGraph().
 */
void TestWeightedOrientedGraph();

/* Сюда нужно добавить объявления тестовых функций. */



/* Конец вставки. */

#endif  // TESTS_TEST_HPP_
