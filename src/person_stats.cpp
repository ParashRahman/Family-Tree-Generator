#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "person_stats.h"
#include "random_handler.h"

std::function<double(double,double)> PersonStats::default_average = [](double p1, double p2)->double {return (p1+p2)/2;};

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
    {Stat::tolerance, default_average},
    {Stat::permiscuity, default_average},
    {Stat::economic, default_average},
    {Stat::health, default_average},
    {Stat::social, default_average},
    {Stat::intelligence, default_average},
    {Stat::hair_color, default_average},
    {Stat::skin_color,  default_average},
    {Stat::eye_color, default_average},
    {Stat::height, default_average},
    {Stat::weight, default_average}
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
  RandomHandler rh;
  
  for (Stat s : iterable_stat_enum) {
    stat_to_value[s] = stat_function[s](ps1.stat_to_value[s], ps2.stat_to_value[s])
      + rh.randdoubl(-1 * stat_fudge_factor[s], stat_fudge_factor[s]);
    stat_to_value[s] = std::max(std::min(stat_to_value[s], 1.0), 0.0);
  }
}

