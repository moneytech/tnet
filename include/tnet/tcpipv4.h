#ifndef TNET_TCPIPv4_H
#define TNET_TCPIPv4_H

#include <stdint.h>

#include "tnet/tcp.h"

typedef struct {
  // Private
  TNET_tcp_State state;
  uint16_t sequenceNumber;
  uint32_t sourceIPAddress;
  uint16_t sourcePort;
  uint32_t destIPAddress;
  uint16_t destPort;
} TNET_tcpipv4_Connection;

typedef struct TNET_tcpipv4_TCPIPv4 TNET_tcpipv4_TCPIPv4;
struct TNET_tcpipv4_TCPIPv4 {
  // Private
  TNET_tcpipv4_Connection *connections;
  int count;
  int filled;

  // Public
  void (*Serve)(TNET_tcpipv4_TCPIPv4 *tcpipv4, TNET_netif_Netif *netif,
                TNET_ethernet_Frame *frame);
  void (*Cleanup)(TNET_tcpipv4_TCPIPv4 *tcpipv4);
};

#endif
