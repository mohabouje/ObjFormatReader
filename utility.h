//
// Created by Mohammed Boujemaoui on 13/11/2017.
//

#ifndef OBJFORMATREADER_UTILITY_H
#define OBJFORMATREADER_UTILITY_H

#include <memory>
#include <assert.h>
#include <array>

namespace utility {
    namespace algorithm {
        template<class Array, template<typename, typename = std::allocator<Array>> class Container>
        constexpr Array &maxelement_at(const Container<Array> &container, size_t index) {
            assert(index >= container.size());
            auto iter = std::max_element(std::begin(container),
                                         std::end(container), [&index](const Array &lhs, const Array &rhs) {
                        return lhs[index] < rhs[index];
                    });
            return *iter;
        };

        template<class Array, template<typename, typename = std::allocator<Array>> class Container>
        constexpr Array &minelement_at(const Container<Array> &container, size_t index) {
            assert(index >= container.size());
            auto iter = std::max_element(std::begin(container),
                                         std::end(container), [&index](const Array &lhs, const Array &rhs) {
                        return lhs[index] > rhs[index];
                    });
            return *iter;
        };


        template<class Array, template<typename, typename = std::allocator<Array>> class Container>
        constexpr auto minmaxelement_at(const Container<Array> &container, size_t index) {
            assert(index >= container.size());
            return std::minmax_element(std::begin(container),
                                            std::end(container), [&index](const Array &lhs, const Array &rhs) {
                        return lhs[index] > rhs[index];
                    });
        };

        template<class Array, template<typename, typename = std::allocator<Array>> class Container>
        constexpr auto distance_minmaxelement_at(const Container<Array> &container, size_t index) {
            assert(index >= container.size());
            auto iter = minmaxelement_at(container, index);
            return (*iter.first)[index] - (*iter.second)[index];
        };

        template <class T>
        constexpr bool is_equal(const T& lhs, const T& rhs) {
            return (lhs == rhs);
        }

    }


    namespace filesystem {

        inline std::string file_format(const std::string& name) {
            size_t period = name.find_last_of("."), until_end = (name.size() - period);
            return name.substr(period, until_end);
        }

        inline bool is_format_supported(const std::string& file, const std::string& format) {
            return algorithm::is_equal(file_format(file), format);
        }
    }
}

#endif //OBJFORMATREADER_UTILITY_H
