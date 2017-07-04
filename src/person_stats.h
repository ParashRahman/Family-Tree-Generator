#ifndef _PERSON_STATS_H_
#define _PERSON_STATS_H_

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

struct StatEnumClassHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

enum class Stat { tolerance, permiscuity, social,
      economic, health, intelligence,
      hair_color, skin_color, eye_color,
      height, weight };

class PersonStats {
 private:
  static std::unordered_map<Stat, double, StatEnumClassHash> stat_fudge_factor;
  static std::unordered_map<Stat, std::function<double(double, double)>, StatEnumClassHash> stat_function;
 public:
  static std::vector<Stat> iterable_stat_enum;
  static std::unordered_map<Stat, std::string, StatEnumClassHash> stat_to_name;
  std::unordered_map<Stat, double, StatEnumClassHash> stat_to_value;
  PersonStats();
  PersonStats(PersonStats ps, bool trash);
  PersonStats(PersonStats ps1, PersonStats ps2);
};

#endif
