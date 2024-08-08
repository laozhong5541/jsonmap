#include "map_parser.h"

void parse_door(const rapidjson::Value& value, door& d) {
    d.code = value["code"].GetString();
    d.enable = value["enable"].GetBool();
    d.no = value["no"].GetInt();
    d.type = value["type"].GetInt();
}

void parse_line(const rapidjson::Value& value, line& l) {
    l.belong_node_id = value["belongNodeId"].GetInt();
    l.converse = value["converse"].GetBool();
    parse_door(value["door"], l.door);
    l.high_precision = value["highPrecision"].GetBool();
    l.len = value["len"].GetDouble();
    l.link_node_id = value["linkNodeId"].GetInt();
    l.max_height = value["maxHeight"].GetDouble();
    l.max_velocity = value["maxVelocity"].GetDouble();
    l.max_width = value["maxWidth"].GetDouble();
    l.obs_limit_enable = value["obsLimitEnable"].GetInt();
    l.obs_limit_length = value["obsLimitLength"].GetDouble();
    l.obs_limit_width = value["obsLimitWidth"].GetDouble();
    l.pod_angle = value["podAngle"].GetDouble();
    l.turn = value["turn"].GetBool();
    l.type = value["type"].GetInt();
}

void parse_static_area(const rapidjson::Value& value, static_area& sa) {
    sa.area_id = value["areaId"].GetInt();
    sa.avoid = value["avoid"].GetInt();
    sa.calibration = value["calibration"].GetBool();
    sa.code = value["code"].GetString();
    sa.high_precision = value["highPrecision"].GetBool();
    sa.id = value["id"].GetInt();
    for (const auto& _line : value["line"].GetArray()) {
        line l;
        parse_line(_line, l);
        sa.lines.push_back(l);
    }
    sa.offset_x = value["offsetX"].GetDouble();
    sa.offset_y = value["offsetY"].GetDouble();
    sa.park_angle = value["parkAngle"].GetDouble();
    sa.pod_angle = value["podAngle"].GetDouble();
    sa.pod_turn_allow = value["podTurnAllow"].GetBool();
    for (const auto& pos : value["position"].GetArray()) {
        sa.position.push_back(pos.GetDouble());
    }
    sa.tray_angle = value["trayAngle"].GetDouble();
    sa.tray_turn_allow = value["trayTurnAllow"].GetBool();
    sa.turn_allow = value["turnAllow"].GetBool();
    sa.type = value["type"].GetInt();
}

void parse_param(const rapidjson::Value& value, param& p) {
    p.auto_assign_robot = value["autoAssignRobot"].GetBool();
    p.auto_back_trace = value["autoBackTrace"].GetBool();
}

void parse_area_remark(const rapidjson::Value& value, area_remark& ar) {
    ar.color = value["color"].GetString();
    ar.height = value["height"].GetDouble();
    for (const auto& pos : value["position"].GetArray()) {
        ar.position.push_back(pos.GetDouble());
    }
    ar.transparent = value["transparent"].GetDouble();
    ar.width = value["width"].GetDouble();
}

void parse_map_size(const rapidjson::Value& value, map_size& ms) {
    ms.height = value["height"].GetDouble();
    ms.width = value["width"].GetDouble();
}

void parse_root(const rapidjson::Value& value, root& r) {
    r.area_id = value["areaId"].GetInt();
    for (const auto& _area_remark : value["areaRemark"].GetArray()) {
        area_remark _ar;
        parse_area_remark(_area_remark, _ar);
        r.area_remarks.push_back(_ar);
    }
    r.map_id = value["mapId"].GetInt();
    r.map_name = value["mapName"].GetString();
    parse_map_size(value["mapSize"], r.map_size);
    r.map_type = value["mapType"].GetString();
    for (const auto& origin : value["originPoint"].GetArray()) {
        r.origin_point.push_back(origin.GetDouble());
    }
    parse_param(value["param"], r.param);
    for (const auto& res : value["resolution"].GetArray()) {
        r.resolution.push_back(res.GetDouble());
    }
    for (const auto& _static_area : value["staticArea"].GetArray()) {
        static_area sa;
        parse_static_area(_static_area, sa);
        r.static_areas.push_back(sa);
    }
}
