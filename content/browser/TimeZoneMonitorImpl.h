
#ifndef content_browser_time_zone_monitor_h
#define content_browser_time_zone_monitor_h

#include "services/device/public/mojom/time_zone_monitor.mojom-blink.h"
#include "mojo/public/cpp/bindings/receiver.h"

namespace content {

class TimeZoneMonitorImpl : public device::mojom::blink::TimeZoneMonitor {
public:
    void AddClient(::mojo::PendingRemote<device::mojom::blink::TimeZoneMonitorClient> client) override
    {
        //         device::mojom::blink::TimeZoneMonitorClient** ptr_addr = client.PassPtrAddrT();
        //         device::mojom::blink::TimeZoneMonitorClient* client2 = (*ptr_addr);
        //OutputDebugStringA("TimeZoneMonitorImpl::AddClient not impl\n");
    }

    mojo::Receiver<device::mojom::blink::TimeZoneMonitor> m_receiver { this };
};

}

#endif // content_browser_time_zone_monitor_h