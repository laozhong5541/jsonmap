#include <string>
#include <vector>
#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <fstream>

#pragma once

struct door {
    std::string code;
    bool enable;
    int no;
    int type;
};

struct line {
    int belong_node_id;
    bool converse;
    door door;
    bool high_precision;
    double len;
    int link_node_id;
    double max_height;
    double max_velocity;
    double max_width;
    int obs_limit_enable;
    double obs_limit_length;
    double obs_limit_width;
    double pod_angle;
    bool turn;
    int type;
};

struct static_area {
    int area_id;
    int avoid;
    bool calibration;
    std::string code;
    bool high_precision;
    int id;
    std::vector<line> lines;
    double offset_x;
    double offset_y;
    double park_angle;
    double pod_angle;
    bool pod_turn_allow;
    std::vector<double> position;
    double tray_angle;
    bool tray_turn_allow;
    bool turn_allow;
    int type;
};

struct param {
    bool auto_assign_robot;
    bool auto_back_trace;
};

struct area_remark {
    std::string color;
    double height;
    std::vector<double> position;
    double transparent;
    double width;
};

struct map_size {
    double height;
    double width;
};

struct root {
    int area_id;
    std::vector<area_remark> area_remarks;
    int map_id;
    std::string map_name;
    map_size map_size;
    std::string map_type;
    std::vector<double> origin_point;
    param param;
    std::vector<double> resolution;
    std::vector<static_area> static_areas;
};
