This project generates a reaper extension which acts as a receiver for api calls. The communication is via tcp where Reaper acts as client and another software acts as server.

To make a connection, you have to trigger the action in reaper called _TCPCOMMAND, i.ex. via osc. Reaper will then connect to a server at localhost at port 9501. Then you send packets containing function number (see reaper_tcp_api.h) and the arguments as binary via this connection, and receive the answer as binary.
