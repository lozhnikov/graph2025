/**
 * @file methods/methods.hpp
 * @author Mikhail Lozhnikov
 *
 * Объявления функий для серверной части алгоритмов. Эти функции должны
 * считать JSON, который прислал клиент, выполнить алгоритм и отправить клиенту
 * JSON с результатом работы алгоритма.
 */

#ifndef METHODS_METHODS_HPP_
#define METHODS_METHODS_HPP_

namespace graph {

/* Сюда нужно вставить объявление серверной части алгоритма. */

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
int BreadthFirstTraversalMethod(const nlohmann::json& input,
    nlohmann::json* output);


/* Конец вставки. */

}  // namespace graph

#endif  // METHODS_METHODS_HPP_
