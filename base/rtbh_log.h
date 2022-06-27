
#ifndef BASE_RTBH_LOG_H_
#define BASE_RTBH_LOG_H_

#include <iostream>
#include <map>

#include "base/time/time.h"
#include "third_party/abseil-cpp/absl/types/optional.h"

namespace rtbh {

    std::string time_now();

    std::string addr_to_str(const void* addr);

    template <typename T>
    std::string to_string(T t) {
        std::stringstream ss;
        ss << t;
        return ss.str();
    }

    template <typename C>
    std::string collection_to_string(const C& coll) {
        std::stringstream ss;
        ss << '[';
        for (const auto& k: coll) {
            ss << k << ", ";
        }
        ss << ']';
        return ss.str();
    }

    template <typename T>
    std::string optional_to_string(absl::optional<T> t) {
        std::stringstream ss;
        if (t.has_value()) {
           ss << *t;
        } else {
           ss << "none";
        }
        return ss.str();
    }

    template <typename C>
    std::string optional_collection_to_string(absl::optional<C> c) {
        return c.has_value() ? collection_to_string(*c) : "none";
    }

    void log_debug(const std::string& mssg, const std::map<std::string, std::string>& values);


    void log_debug(const std::string& mssg);
};

# endif  // BASE_RTBH_LOG_H_
