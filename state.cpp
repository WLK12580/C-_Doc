#include <condition_variable>
#include <iostream>
typedef enum class State {
  STATE_1,
  STATE_2,
  STATE_3,
} state;
class StateMachine {
 public:
  void transition(state next_state) {
    std::cout << "STATE=" << int(next_state) << std::endl;
    current_state = next_state;
  }
  void Process();

 private:
  state current_state=state::STATE_1;
};
void StateMachine::Process() {
  switch (current_state) {
    case state::STATE_1:
      transition(state::STATE_2);
      break;
    case state::STATE_2:
      transition(state::STATE_3);
      break;
    case state::STATE_3:
      transition(state::STATE_1);
      break;
    default:
      std::cout << "unkown" << std::endl;
      break;
  }
}
int main() {
  StateMachine statemachine;
  for (int i = 0; i < 5; i++) {
    statemachine.Process();
  }
  return 0;
}
