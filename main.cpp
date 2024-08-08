#include "map_parser.h"

int main() {
    std::ifstream ifs("C:\\Users\\drago\\Desktop\\JsonParser\\build\\Debug\\test.json");

    rapidjson::IStreamWrapper isw(ifs);
    rapidjson::Document doc;
    doc.ParseStream(isw);

    root r;
    parse_root(doc, r);

    std::cout << "Map Name: " << r.map_name << std::endl;
    std::cout << "Map Type: " << r.map_type << std::endl;
    std::cout << "Map Size: " << r.map_size.width << "x" << r.map_size.height << std::endl;

    return 0;
}
