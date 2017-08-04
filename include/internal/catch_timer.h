/*
 *  Created by Phil on 05/08/2013.
 *  Copyright 2013 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef TWOBLUECUBES_CATCH_TIMER_H_INCLUDED
#define TWOBLUECUBES_CATCH_TIMER_H_INCLUDED

#include <stdint.h>

namespace Catch {

    auto getCurrentMicrosecondsSinceEpoch() -> uint64_t;

    class Timer {
        uint64_t m_microSeconds = 0;
    public:
        void start() {
           m_microSeconds = getCurrentMicrosecondsSinceEpoch();
        }
        auto getElapsedMicroseconds() const -> unsigned int {
            return static_cast<unsigned int>(getCurrentMicrosecondsSinceEpoch() - m_microSeconds);
        }
        auto getElapsedMilliseconds() const -> unsigned int {
            return static_cast<unsigned int>(getElapsedMicroseconds()/1000);
        }
        auto getElapsedSeconds() const -> double {
            return getElapsedMicroseconds()/1000000.0;
        }
    };

} // namespace Catch

#endif // TWOBLUECUBES_CATCH_TIMER_H_INCLUDED
