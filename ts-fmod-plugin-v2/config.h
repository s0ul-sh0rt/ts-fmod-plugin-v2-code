#pragma once

#include "includes_windows.h"
#include "nlohmann/json.hpp"
#include <scssdk/scssdk.h>

class config
{
    const uint32_t current_config_version_ = 3;
    scs_log_t scs_log_;
    const std::filesystem::path& config_path_;

public:
    double master = 0.5;
    double engine = 0.25;
    double exhaust = 0.25;
    double turbo = 0.25;
    double effects = 0.75;
    double interior_buttons = 0.75;
    double windows_closed = 0.5;
    double navigation = 0.75;
    double menu_music = 0.5;

private:
    template <class T>
    bool read_value(const nlohmann::json& j, const char* key, T* out_value) const;

public:
    config(scs_log_t scs_log, const std::filesystem::path& config_file_path);
    bool load_config();
    bool save_config();
};