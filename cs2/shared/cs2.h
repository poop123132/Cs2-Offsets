#ifndef CS2_H
#define CS2_H

#include "../../library/vm/vm.h"
#include "../../library/math.h"

// Enables global debug messages
#ifndef LOGGER
#define LOGGER

#ifndef _KERNEL_MODE
#define DEBUG
#include <cstdio>
#ifdef DEBUG
#define LOG(...) std::printf("[EC] " __VA_ARGS__)
#else
#define LOG(...) // __VA_ARGS__
#endif

#else

// #define DEBUG
#ifdef DEBUG
#define LOG(...) DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, "[EC] " __VA_ARGS__)
#else
#define LOG(...) // __VA_ARGS__
#endif

#endif

#endif

namespace cs2
{
    extern vm_handle game_handle;

    enum class WEAPON_CLASS {
        Invalid = 0,
        Knife = 1,
        Grenade = 2,
        Pistol = 3,
        Sniper = 4,
        Rifle = 5,
        Shotgun = 6, // Added for 2025
        SMG = 7, // Added for 2025
        Heavy = 8, // Added for 2025
        Melee = 9, // Added for 2025
        Unknown = 10 // Added for 2025
    };

    struct WINDOW_INFO {
        float x, y, w, h;
    };

    namespace sdl
    {
        QWORD get_window(void);
        BOOL get_window_info(QWORD window, WINDOW_INFO *info);
        QWORD get_window_data(QWORD window);
        QWORD get_hwnd(QWORD window_data);
        QWORD get_hdc(QWORD window_data);

        QWORD get_mouse(void);
        BOOL get_mouse_button(QWORD sdl_mouse);
    }

    namespace engine
    {
        QWORD get_convar(const char *name);
        DWORD get_current_ms(void);
        vec2 get_viewangles(void);
        view_matrix_t get_viewmatrix(void);
        // Added for 2025
        float get_fov(void);
        void set_fov(float fov);
    }

    namespace entity
    {
        QWORD get_local_player_controller(void);
        QWORD get_client_entity(int index);
        BOOL is_player(QWORD controller);
        QWORD get_player(QWORD controller);
        BOOL has_defuser(QWORD player);
    }

    int get_crosshairalpha(void);

    namespace mouse
    {
        float get_sensitivity(void);
        // Added for 2025
        void set_sensitivity(float sensitivity);
    }

    namespace input
    {
        BOOL is_button_down(DWORD button);
        void move(int x, int y);
    }

    namespace gamemode
    {
        BOOL is_ffa(void);
        // Added for 2025
        BOOL is_competitive(void);
        BOOL is_casual(void);
    }

    namespace player
    {
        DWORD get_health(QWORD player);
        DWORD get_team_num(QWORD player);
        int get_life_state(QWORD player);
        vec3 get_origin(QWORD player);
        float get_vec_view(QWORD player);
        vec3 get_eye_position(QWORD player);
        DWORD get_shots_fired(QWORD player);
        float get_fov_multiplier(QWORD player);
        vec2 get_vec_punch(QWORD player);
        vec2 get_viewangle(QWORD player);
        WEAPON_CLASS get_weapon_class(QWORD player);
        QWORD get_node(QWORD player);
        QWORD get_weapon_address(QWORD player);
        BOOL is_defusing(QWORD player);
        BOOL is_valid(QWORD player, QWORD node);

        // Added for 2025
        float get_armor(QWORD player);
        void set_armor(QWORD player, float armor);
    }

    namespace node
    {
        BOOLEAN get_dormant(QWORD node);
        vec3 get_origin(QWORD node);
        BOOL get_bone_position(QWORD node, int index, vec3 *data);
    }

    BOOL running(void);
}

#endif /* cs2.h */
