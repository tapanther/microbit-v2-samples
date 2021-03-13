//
// Created by jsierra on 3/12/2021.
//

#include <vector>
#include "radioHelper.h"
#include "MicroBit.h"

ManagedString getManagedStringFromPacketBuffer(PacketBuffer p_buffer)
{
    std::vector<uint8_t> byte_vector;
    int i = 0;
    uint8_t byte = p_buffer.getByte(i);

    while (byte != 0)
    {
        byte_vector.push_back(byte);
        i++;
        byte = p_buffer.getByte(i);
    }

    ManagedBuffer mb = ManagedBuffer(byte_vector.data(), byte_vector.size());
    ManagedString st = ManagedString(mb);

    return st;
}
