/*
 * Copyright (c) 2019 REV Robotics
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of REV Robotics nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <string>

#include "rev/CANMessage.h"
#include "rev/CANStatus.h"

namespace rev {
namespace usb {

class CANDevice {
public:
    CANDevice() {}
    ~CANDevice() {}

    virtual std::string GetName() const = 0;
    virtual std::wstring GetDescriptor() const {return std::wstring();}

    virtual int GetId() const = 0;

    virtual CANStatus SendCANMessage(const CANMessage& msg, int periodMs) = 0;
    virtual CANStatus RecieveCANMessage(CANMessage& msg, uint32_t messageMask, uint32_t& timestamp) = 0;
    virtual CANStatus OpenStreamSession() = 0;
    virtual CANStatus CloseStreamSession() = 0;
    virtual CANStatus ReadStreamSession() = 0;

    virtual CANStatus GetCANStatus() = 0;

    virtual bool IsConnected() = 0;
};

} // namespace usb
} // namespace rev