#pragma once

#include "Arduino.h"
#include "Packet.hpp"
#include "../ParsingInformation.hpp"
#include "../Callbacks.hpp"

namespace AsyncMqttClientInternals {
class PubRelPacket : public Packet {
 public:
  explicit PubRelPacket(ParsingInformation* parsingInformation, OnPubRelCallback callback);
  ~PubRelPacket();

  void parseVariableHeader(char* data, size_t* currentBytePosition);
  void parsePayload(char* data, size_t* currentBytePosition);

 private:
  ParsingInformation* _parsingInformation;
  OnPubRelCallback _callback;

  uint8_t _bytePosition;
  char _packetIdMsb;
  uint16_t _packetId;
};
}  // namespace AsyncMqttClientInternals
