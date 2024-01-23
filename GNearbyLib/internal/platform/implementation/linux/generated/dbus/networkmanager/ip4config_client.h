
/*
 * This file was automatically generated by sdbus-c++-xml2cpp; DO NOT EDIT!
 */

#ifndef __sdbuscpp__networkmanager_ip4config_client_glue_h__proxy__H__
#define __sdbuscpp__networkmanager_ip4config_client_glue_h__proxy__H__

#include <sdbus-c++/sdbus-c++.h>
#include <string>
#include <tuple>

namespace org {
namespace freedesktop {
namespace NetworkManager {

class IP4Config_proxy
{
public:
    static constexpr const char* INTERFACE_NAME = "org.freedesktop.NetworkManager.IP4Config";

protected:
    IP4Config_proxy(sdbus::IProxy& proxy)
        : proxy_(proxy)
    {
    }

    ~IP4Config_proxy() = default;

public:
    std::vector<std::vector<uint32_t>> Addresses()
    {
        return proxy_.getProperty("Addresses").onInterface(INTERFACE_NAME);
    }

    std::vector<std::map<std::string, sdbus::Variant>> AddressData()
    {
        return proxy_.getProperty("AddressData").onInterface(INTERFACE_NAME);
    }

    std::string Gateway()
    {
        return proxy_.getProperty("Gateway").onInterface(INTERFACE_NAME);
    }

    std::vector<std::vector<uint32_t>> Routes()
    {
        return proxy_.getProperty("Routes").onInterface(INTERFACE_NAME);
    }

    std::vector<std::map<std::string, sdbus::Variant>> RouteData()
    {
        return proxy_.getProperty("RouteData").onInterface(INTERFACE_NAME);
    }

    std::vector<uint32_t> Nameservers()
    {
        return proxy_.getProperty("Nameservers").onInterface(INTERFACE_NAME);
    }

    std::vector<std::map<std::string, sdbus::Variant>> NameserverData()
    {
        return proxy_.getProperty("NameserverData").onInterface(INTERFACE_NAME);
    }

    std::vector<std::string> Domains()
    {
        return proxy_.getProperty("Domains").onInterface(INTERFACE_NAME);
    }

    std::vector<std::string> Searches()
    {
        return proxy_.getProperty("Searches").onInterface(INTERFACE_NAME);
    }

    std::vector<std::string> DnsOptions()
    {
        return proxy_.getProperty("DnsOptions").onInterface(INTERFACE_NAME);
    }

    int32_t DnsPriority()
    {
        return proxy_.getProperty("DnsPriority").onInterface(INTERFACE_NAME);
    }

    std::vector<uint32_t> WinsServers()
    {
        return proxy_.getProperty("WinsServers").onInterface(INTERFACE_NAME);
    }

    std::vector<std::string> WinsServerData()
    {
        return proxy_.getProperty("WinsServerData").onInterface(INTERFACE_NAME);
    }

private:
    sdbus::IProxy& proxy_;
};

}}} // namespaces

#endif
