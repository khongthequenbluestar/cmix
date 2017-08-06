#ifndef BYTE_MIXER_H
#define BYTE_MIXER_H

#include "../models/byte-model.h"
#include "lstm.h"

class ByteMixer : public ByteModel {
 public:
  ByteMixer(unsigned int num_models, unsigned int num_cells,
      unsigned int num_layers, int horizon, float learning_rate,
      const unsigned int& bit_context, const std::vector<bool>& vocab,
      unsigned int vocab_size);
  void SetInput(int index, float val);
  void ByteUpdate();

 private:
  const unsigned int& byte_;
  Lstm lstm_;
  std::vector<float> inputs_;
  std::vector<int> byte_map_;
  std::valarray<float> outputs_;
  unsigned int num_models_, vocab_size_, offset_;
};

#endif
