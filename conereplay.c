/*
 struct pcap_pkthdr {
     struct timeval ts;  
     bpf_u_int32 caplen; 
     bpf_u_int32 len;    
 };
*/



#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <signal.h>
#include <pthread.h>
#include <net/ethernet.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>
#include <sched.h>
#include <sys/un.h>
#include <pcap.h>

#define FILENAME "test.pcap"

int main(int argc, char **argv) {

    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr header;
    const uint8_t *packet;

    handle = pcap_open_offline(FILENAME, errbuf);
    if (handle == NULL) {
        printf("Could not open file %s: %s\n", FILENAME, errbuf);
        exit(-1);
    }

    while(packet = pcap_next(handle, &header)) {
        printf("got one packet\n");
    }

    pcap_close(handle);

    return 0;
}
