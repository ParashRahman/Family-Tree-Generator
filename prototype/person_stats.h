#ifndef _PERSON_STATS_H_
#define _PERSON_STATS_H_

#include <functional>
#include <string>
#include <unordered_map>

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
  static const std::unordered_map<Stat, std::string, StatEnumClassHash> stat_to_name;
  static const std::unordered_map<Stat, double, StatEnumClassHash> stat_fudge_factor;
  static const std::unordered_map<Stat, std::function<double(PersonStats, PersonStats)>, StatEnumClassHash> stat_function;
 public:
  std::unordered_map<Stat, double, StatEnumClassHash> stat_to_value;
  PersonStats();
  PersonStats(PersonStats parent1, PersonStats parent2);
};

#endif
