/*
 * Copyright (c) 2024, Sönke Holz <sholz8530@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/HashMap.h>
#include <Kernel/Firmware/DeviceTree/Driver.h>
#include <Libraries/LibDeviceTree/DeviceTree.h>

namespace Kernel::DeviceTree {

class Management {
public:
    static void initialize();
    static Management& the();

    static ErrorOr<void> register_driver(NonnullOwnPtr<DeviceTree::Driver>&&);

    ErrorOr<void> scan_node_for_devices(::DeviceTree::DeviceTreeNodeView const& node);

private:
    static bool attach_device_to_driver(Device&, Driver const&, StringView compatible_entry);

    HashMap<StringView, NonnullOwnPtr<Driver>> m_drivers;
    HashMap<::DeviceTree::DeviceTreeNodeView const*, Device> m_devices;
};

}