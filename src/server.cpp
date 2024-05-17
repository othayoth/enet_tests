#include <enet/enet.h>
#include <iostream>
#include <cstdlib> 
#include <cstdio>
#include <ctime> // Include the C time library

#define MAX_CLIENTS 32
#define NUM_CHANNELS 2

ENetAddress address;
ENetHost * server;
ENetEvent event;

int main (int argc, char ** argv) 
{
    if (enet_initialize () != 0)
    {
        fprintf (stderr, "An error occurred while initializing ENet.\n");
        return EXIT_FAILURE;
    }
    else{
        printf("ENet initialized successfully\n");

        address.host = ENET_HOST_ANY;   // bind to default localhost
        address.port = 1122;            // bind the server to port 7777

        server = enet_host_create (& address, MAX_CLIENTS, NUM_CHANNELS, 0, 0); // last two are in/out bandwidth
        if (server == NULL){
            fprintf (stderr, "An error occurred while trying to create an ENet server host.\n");
            exit (EXIT_FAILURE);
        }
        else {
            printf("Server started successfully\n");
        }

        while (enet_host_service(server, &event, 1000) > 0) {
            switch (event.type) {
                case ENET_EVENT_TYPE_CONNECT:
                    printf("A new client connected from %x:%u.\n",  event.peer->address.host, event.peer->address.port);
                    /* Store any relevant client information here. */
                    // event.peer->data = "Client information";
                    break;

                case ENET_EVENT_TYPE_RECEIVE:
                    printf("A packet of length %lu containing %s was received from %s on channel %u.\n",
                            event.packet->dataLength,
                            event.packet->data,
                            event.peer->data,
                            event.channelID);
                    /* Clean up the packet now that we're done using it. */
                    enet_packet_destroy (event.packet);
                    break;

                case ENET_EVENT_TYPE_DISCONNECT:
                    printf("%s disconnected.\n", event.peer->data);
                    /* Reset the peer's client information. */
                    event.peer->data = NULL;
                    break;

                case ENET_EVENT_TYPE_NONE:
                    break;
            }
     }
    }

    #include <unistd.h> // Include the header file for sleep function

    // ...

    // Wait for 10 seconds
    sleep(10);

    // ...
    enet_host_destroy (server);
    atexit (enet_deinitialize);

    
    
}