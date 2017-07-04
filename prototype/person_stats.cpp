#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "person_stats.h"
#include "random_handler.h"

std::unordered_map<Stat, std::string, StatEnumClassHash> PersonStats::stat_to_name =
  {
    {Stat::tolerance, "tolerance"},
    {Stat::permiscuity, "promiscuity"},
    {Stat::economic, "economic"},
    {Stat::health, "health"},
    {Stat::social, "social"},
    {Stat::intelligence, "intelligence"},
    {Stat::hair_color, "hair color"},
    {Stat::skin_color,  "skin color"},
    {Stat::eye_color, "eye color"},
    {Stat::height, "height"},
    {Stat::weight, "weight"}
  };

std::unordered_map<Stat, double, StatEnumClassHash> PersonStats::stat_fudge_factor =
  {
    {Stat::tolerance, 0.5},
    {Stat::permiscuity, 0.5},
    {Stat::economic, 0.5},
    {Stat::health, 0.5},
    {Stat::social, 0.5},
    {Stat::intelligence, 1.0},
    {Stat::hair_color, 0.1},
    {Stat::skin_color,  0.1},
    {Stat::eye_color, 0.1},
    {Stat::height, 0.2},
    {Stat::weight, 0.2}
  };

std::unordered_map<Stat, std::function<double(double, double)>, StatEnumClassHash> PersonStats::stat_function =
  {
    {Stat::tolerance, [](double p1, double p2)->double {return 0.5;}},
    {Stat::permiscuity, [](double p1, double p2)->double {return 0.5;}},
    {Stat::economic, [](double p1, double p2)->double {return 0.5;}},
    {Stat::health, [](double p1, double p2)->double {return 0.5;}},
    {Stat::social, [](double p1, double p2)->double {return 0.5;}},
    {Stat::intelligence, [](double p1, double p2)->double {return 0.5;}},
    {Stat::hair_color, [](double p1, double p2)->double {return 0.5;}},
    {Stat::skin_color,  [](double p1, double p2)->double {return 0.5;}},
    {Stat::eye_color, [](double p1, double p2)->double {return 0.5;}},
    {Stat::height, [](double p1, double p2)->double {return 0.5;}},
    {Stat::weight, [](double p1, double p2)->double {return 0.5;}}
  };

std::vector<Stat> PersonStats::iterable_stat_enum =
  {
    Stat::tolerance, Stat::permiscuity,
    Stat::social, Stat::economic,
    Stat::health, Stat::intelligence,
    Stat::hair_color, Stat::skin_color,
    Stat::eye_color, Stat::height,
    Stat::weight
  };

PersonStats::PersonStats() {
  RandomHandler rh;
  
  for (Stat s : iterable_stat_enum) {
    stat_to_value[s] = rh.randdoubl(0.0, 1.0);
  }
}

PersonStats::PersonStats(PersonStats ps, bool trash) {
  for (Stat s : iterable_stat_enum) {
    stat_to_value[s] = ps.stat_to_value[s];
  }
}

PersonStats::PersonStats(PersonStats ps1, PersonStats ps2) {
  for (Stat s : iterable_stat_enum) {
    stat_to_value[s] = stat_function[s](ps1.stat_to_value[s], ps2.stat_to_value[s]);
  }
}
