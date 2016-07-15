#include <vector>
#include <string>

#include "prayers.h"
#include "helpers.h"

// Static variables

std::string Prayers::social_desire_prefix = "I wish ";
std::string Prayers::economic_desire_prefix = "I wish to have ";
std::string Prayers::religious_desire_prefix = "I pray ";
std::string Prayers::health_desire_prefix = "I wish ";

std::vector<std::string> Prayers::social_desires = { "for those around me to hold me in higher esteem", "to have power over the factors in my life", "to find my niche", "to have more gravity in my decision", "to have a life I find intrinsically meaningful", "to deepen the roots entertwined with others", "to have a feeling of acceptance in my community", "for something that will spur adrenaline within my very soul", "for dat sweet, sweet lovin'", "to have a bigger dick in my life" };

std::vector<std::string> Prayers::economic_desires = { "mo money to ensure I have fewer problems", "a sexier car", "mo business", "less bills", "mo bills (da good kind (dolla bills))", "better financial management", "better invesment returns", "better luck when it comes to finding money on the ground", "cha ching cha ching" };

std::vector<std::string> Prayers::religious_desires = { "I become more disciplined in prayer", "I have stronger conviction", "my questions will be answered", "a sign will be revealed to me", "my friends and family go toward the truth", "the world believes in the truth", "I know more about my faith" };

std::vector<std::string> Prayers::health_desires = { "I never have a cold ever again", "I don't get cancer", "my family heals faster", "I heal faster", "we find a cure to our ailments", "we miraculously recover", "I get better at exercising", "I eat healthier", "my family eats healthier", "my friends exercize with me", "I bulk and cut", "I become a BEAST in the gym" };

// Static functions 
static std::string get_random_social_desire() {
  int random_index = Helpers::get_random_int(0, social_desires.size() - 1);
  return social_desire_prefix + social_desires[random_index];
}
static std::string get_random_economic_desire() {
  int random_index = Helpers::get_random_int(0, economic_desires.size() - 1);
  return economic_desire_prefix + economic_desires[random_index];
}
static std::string get_random_religious_desire() {
  int random_index = Helpers::get_random_int(0, religious_desires.size() - 1);
  return religious_desire_prefix + religious_desires[random_index];
}
static std::string get_random_health_desire() {
  int random_index = Helpers::get_random_int(0, health_desires.size() - 1);
  return health_desire_prefix + heath_desires[random_index];
}
