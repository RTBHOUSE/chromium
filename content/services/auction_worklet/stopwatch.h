#include "base/time/time.h"

class Stopwatch { 
public:
    Stopwatch()
        : first_(base::TimeTicks::Now()),
          last_(first_) {
    }

    float checkpoint() {
        base::TimeTicks now = base::TimeTicks::Now();
        float elapsed = (now - last_).InMillisecondsF();
        last_ = now;
        return elapsed;
    }

    float total() {
        return (last_ - first_).InMillisecondsF();
    }

private:
    base::TimeTicks first_, last_;
};
