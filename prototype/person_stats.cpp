#include <functional>
#include <string>

#include "person_stats.h"

const std::unordered_map<Stat, std::string, StatEnumClassHash> stat_to_name =
  {
    {Stat::tolerance, "tolerance"},
    {Stat::permiscuity, "promiscuity"},
    {Stat::economic, "economic"},
    {Stat::health, "health"},
    {Stat::intelligence, "intelligence"},
    {Stat::hair_color, "hair color"},
    {Stat::skin_color,  "skin color"},
    {Stat::eye_color, "eye color"},
    {Stat::height, "height"},
    {Stat::weight, "weight"}
  };

const std::unordered_map<Stat, double, StatEnumClassHash> stat_fudge_factor =
  {
    {Stat::tolerance, 0.5},
    {Stat::permiscuity, 0.5},
    {Stat::economic, 0.5},
    {Stat::health, 0.5},
    {Stat::intelligence, 1.0},
    {Stat::hair_color, 0.1},
    {Stat::skin_color,  0.1},
    {Stat::eye_color, 0.1},
    {Stat::height, 0.2},
    {Stat::weight, 0.2}
  };
const std::unordered_map<Stat, std::function<double(PersonStats, PersonStats)>, StatEnumClassHash> stat_function =
  {
    {Stat::tolerance, [](PersonStats p1, PersonStats p2)->double {return 0.5;}},
    {Stat::permiscuity, [](PersonStats p1, PersonStats p2)->double {return 0.5;}},
    {Stat::economic, [](PersonStats p1, PersonStats p2)->double {return 0.5;}},
    {Stat::health, [](PersonStats p1, PersonStats p2)->double {return 0.5;}},
    {Stat::intelligence, [](PersonStats p1, PersonStats p2)->double {return 0.5;}},
    {Stat::hair_color, [](PersonStats p1, PersonStats p2)->double {return 0.5;}},
    {Stat::skin_color,  [](PersonStats p1, PersonStats p2)->double {return 0.5;}},
    {Stat::eye_color, [](PersonStats p1, PersonStats p2)->double {return 0.5;}},
    {Stat::height, [](PersonStats p1, PersonStats p2)->double {return 0.5;}},
    {Stat::weight, [](PersonStats p1, PersonStats p2)->double {return 0.5;}}
  };

PersonStats::PersonStats() {
  stat_to_value =
    {
      {Stat::tolerance, 0},
      {Stat::permiscuity, 0},
      {Stat::economic, 0},
      {Stat::health, 0},
      {Stat::intelligence, 0},
      {Stat::hair_color, 0},
      {Stat::skin_color,  0},
      {Stat::eye_color, 0},
      {Stat::height, 0},
      {Stat::weight, 0}
    };
}

PersonStats::PersonStats(PersonStats parent1, PersonStats parent2) {
  //TODO: do
}
