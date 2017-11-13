//
// Created by Mohammed Boujemaoui on 13/11/2017.
//

#ifndef OBJFORMATREADER_UTILITY_H
#define OBJFORMATREADER_UTILITY_H

class value;

#include <memory>
#include <assert.h>
#include <array>
#include <type_traits>
#include <sys/stat.h>
#include <sstream>

namespace utility {
    namespace algorithm {
        template<class Array, template<typename, typename = std::allocator<Array>> class Container>
        constexpr auto maxelement_at(const Container<Array> &container, size_t index) {
            assert(index >= container.size());
            auto iter = std::max_element(std::begin(container),
                                         std::end(container), [&index](const Array &lhs, const Array &rhs) {
                        return lhs[index] < rhs[index];
                    });
            return *iter;
        };

        template<class Array, template<typename, typename = std::allocator<Array>> class Container>
        constexpr auto minelement_at(const Container<Array> &container, size_t index) {
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
        constexpr typename Array::value_type distance_minmaxelement_at(const Container<Array> &container, size_t index) {
            assert(index >= container.size());
            auto iter = minmaxelement_at(container, index);
            return (*iter.first)[index] - (*iter.second)[index];
        };

        template <class T>
        constexpr bool is_equal(const T& lhs, const T& rhs) {
            return (lhs == rhs);
        }

    }

    namespace parser {
        template<class _Container, typename _InputArray = std::string>
        inline typename std::enable_if<std::is_same<std::basic_string<char>, _InputArray>::value ||
                                       std::is_same<char const *, _InputArray>::value, _Container>::type
        split_space(const _InputArray &sequence) {
            _Container list;
            std::istringstream iss(sequence);
            std::copy(std::istream_iterator<std::string>(iss),
                      std::istream_iterator<std::string>(),
                      std::back_inserter(list));
            return list;
        }


        template<class _Container, typename _InputArray = std::string>
        inline typename std::enable_if<std::is_same<std::basic_string<char>, _InputArray>::value ||
                                       std::is_same<char const *, _InputArray>::value, _Container>::type
        split(const _InputArray& sequence, char separator) {
            _Container list;
            std::istringstream ss(sequence);
            std::string token;
            while(std::getline(ss, token, separator)) {
                list.emplace_back(token);
            }
            return list;
        }

        template<class _Container, typename _InputArray = std::string>
        inline typename std::enable_if<std::is_same<std::basic_string<char>, _InputArray>::value ||
                                       std::is_same<char const *, _InputArray>::value, _Container>::type
        split_slash(const std::string &sequence) {
            return split<_Container, _InputArray>(sequence, '/');
        }


        template <class _InputIterator>
        inline std::string join(const  _InputIterator& first, const  _InputIterator& last, const std::string& delimiter) {
            std::ostringstream imploded;
            std::copy(first, last, std::ostream_iterator<std::string>(imploded, delimiter.c_str()));
            return imploded.str();
        }

    }


    namespace filesystem {

        template<typename T>
        inline typename std::enable_if<std::is_same<std::basic_string<char>, T>::value ||
                                std::is_same<char const*, T>::value, bool>::type
        file_exist(const T& name) {
            struct stat buffer;
            return (stat (&name[0], &buffer) == 0);
        }

        inline std::string file_format(const std::string& name) {
            size_t period = name.find_last_of('.'), until_end = (name.size() - period);
            return name.substr(period, until_end);
        }

        inline bool is_format_supported(const std::string& file, const std::string& format) {
            return algorithm::is_equal(file_format(file), format);
        }
    }
}

#endif //OBJFORMATREADER_UTILITY_H
