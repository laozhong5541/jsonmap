#include "map_define.h"

#pragma once

void parse_door(const rapidjson::Value& value, door& d);

void parse_line(const rapidjson::Value& value, line& l);

void parse_static_area(const rapidjson::Value& value, static_area& sa);

void parse_param(const rapidjson::Value& value, param& p);

void parse_area_remark(const rapidjson::Value& value, area_remark& ar);

void parse_map_size(const rapidjson::Value& value, map_size& ms);

void parse_root(const rapidjson::Value& value, root& r);
