#ifndef CS2GAME_H
#define CS2GAME_H

#ifdef _KERNEL_MODE
extern "C" int _fltused;
#endif

#include "cs2.h"
#include <cstdint>
#include <memory>

namespace cs2::features {
    void run();
    void reset();
}

// Modern interface for client implementations
namespace client {
    // Mouse control interface
    struct MouseController {
        virtual void move(int32_t x, int32_t y) = 0;
        virtual void button1_down() = 0;
        virtual void button1_up() = 0;
        virtual ~MouseController() = default;
    };

    // Drawing interface
    struct Renderer {
        struct Color {
            uint8_t r, g, b, a;
        };

        virtual void drawRect(void* hwnd, int32_t x, int32_t y, int32_t w, int32_t h, Color color) = 0;
        virtual void drawFilledRect(void* hwnd, int32_t x, int32_t y, int32_t w, int32_t h, Color color) = 0;
        virtual ~Renderer() = default;
    };

    // Global interface accessors
    extern std::shared_ptr<MouseController> getMouseController();
    extern std::shared_ptr<Renderer> getRenderer();
}

namespace cs2 {
    inline void run() {
        if (cs2::running()) {
            features::run();
        } else {
            features::reset();
        }
    }
}

#endif // CS2GAME_H
