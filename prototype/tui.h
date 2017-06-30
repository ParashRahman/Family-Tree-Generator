#ifndef _TUI_H_
#define _TUI_H_

#include "family_tree.h"

class TUI {
 private:
  FamilyTree ft;
  std::shared_ptr<FamilyNode> current_node;
  void print_current_state();
  void process_user_input();
 public:
  TUI();
  void start_tui();
};

#endif
