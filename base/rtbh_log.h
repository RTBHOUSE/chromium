
#ifndef BASE_RTBH_LOG_H_
#define BASE_RTBH_LOG_H_

#include <iostream>
#include <map>

#include "base/time/time.h"

namespace rtbh {

    std::string time_now();

    std::string addr_to_str(const void* addr);

    template <typename T>
    std::string to_string(T t) {
        std::stringstream ss;
        ss << t;
        return ss.str();
    }

    void log_debug(const std::string& mssg, const std::map<std::string, std::string>& values);


    void log_debug(const std::string& mssg);
};

# endif  // BASE_RTBH_LOG_H_
