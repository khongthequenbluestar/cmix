#ifndef SHARED_INDIRECT_H
#define SHARED_INDIRECT_H

#include "model.h"
#include "../states/state.h"

#include <vector>
#include <array>

class SharedIndirect : public Model {
 public:
  SharedIndirect(const State& state,
      const unsigned long long& byte_context,
      const unsigned int& bit_context, float delta,
      std::vector<unsigned char>& map);
  float Predict();
  void Perceive(int bit);
  void ByteUpdate();

 private:
  const unsigned long long& byte_context_;
  const unsigned int& bit_context_;
  unsigned long long map_index_, map_offset_;
  float divisor_;
  const State& state_;
  std::vector<unsigned char>& map_;
  std::array<float, 256> predictions_;
};

#endif
