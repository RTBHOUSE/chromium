#include <sstream>

#include "base/rtbh_log.h"

namespace rtbh {

    std::string time_now() {
        std::stringstream ss;
        ss << base::Time::Now();
        return ss.str().substr(11, 12);
    }

    std::string addr_to_str(const void* addr) {
        std::stringstream ss;
        ss << addr;
        return ss.str();
        
    }

    void log_debug(const std::string& mssg, const std::map<std::string, std::string>& values) {
        std::cerr << "[RTB_PERF_DEBUG] " << time_now() << ' ' << mssg;
        for (auto const& pair: values) {
            std::cerr << ", " << pair.first << "=" << pair.second;
        }
        std::cerr << std::endl;
    }


    void log_debug(const std::string& mssg) {
        log_debug(mssg, {});
    }
};
